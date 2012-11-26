#ifndef LISTENER_H
#define LISTENER_H

#include "unp.h"
#include "types.h"
#include "exception.h"

/*
1. set the program to protocal independent
2. add an GUI
*/

#define MAX_PORT 65536
#define BUF_SIZE 8192
#define MAX_TRY_TIMES 5




Exception exception;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t exmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t excond = PTHREAD_COND_INITIALIZER;

void emitException(Message *m) {
    int i;
    pthread_mutex_lock(&exmutex);
    while(exception.count + 1 >= MESSAGE_BUF_SIZE) 
        pthread_cond_wait(&excond, &exmutex);
    for(i = 0; i < MESSAGE_BUF_SIZE; i ++) {
        if(exception.mesbuf[i] == NULL){
            exception.mesbuf[i] = m;
            exception.count ++;
        }
    }
    pthread_mutex_unlock(&exmutex);
}

char ports[65536];
int currentport;
int to_exit;
struct addrinfo hint;

int getaddr(const char *host, const char *port);
void *listener(void *arg);


//the hull
/*
    used to create threads
*/
void * setarget(void *s) {
    to_exit = 0;
    TDScan *scanner = (TDScan *)s;
    char *server;
    int from, to;

    server = scanner->host;
    from = scanner->from;
    to = scanner->to;
    
    memset(ports, 0, sizeof(ports));
    int steps = 0;
    int threadcount = 0, portcount;
    Port thread[64];
    
    portcount = to - from;
    //get host info
    if(getaddr(server, NULL) != 0){
        exception.state = 0;
        pthread_exit(NULL);
    }
    
    if(portcount <= 512) {
        threadcount = (portcount >> 6) + 1;
        steps = 64;
    }
    else if(portcount <= 2048) {
        threadcount = (portcount >> 7)  + 1;
        steps = 128;
    }
    else if(portcount <= 8192) {
        threadcount = (portcount >> 8) + 1;
        steps = 256;
    }
    else if(portcount <= 32768) {
        threadcount = (portcount >> 9) + 1;
        steps = 512;
    }
    else if(portcount <= 65536) {
        threadcount = (portcount >> 10) + 1;
        steps = 1024;
    }
    
    int i;
    for(i = 0;i < threadcount;i ++) {
        thread[i].ptr = ports;
        thread[i].from = i * steps + from;
        thread[i].to = thread[i].from + steps > to ? to : thread[i].from + steps - 1;
        pthread_create(&thread[i].thread, NULL, listener, (void *)&thread[i]);
        //pthread_detach(thread[i].thread);
        //printf("> create thread %d ------------   from  %d, to  %d\n", i, thread[i].from, thread[i].to);
    }
    
    for(i = 0; i < threadcount; i ++){
        pthread_join(thread[i].thread, NULL);
    }
    
    exception.state = 0;
    pthread_exit(NULL);
}


void *listener(void *arg) {
    Port *td = (Port *)arg;
    int from, to;
    from = td->from;
    to = td->to;
    
    //sock
    int sockfd;
    
    int flags, i = 0, result, maxfd = 0;
    int error;
    socklen_t len;
    fd_set rset, wset;
    struct timeval timeout;
    int timeflag = 1;
    struct addrinfo thint;
    memcpy(&thint, &hint, sizeof(hint));
    uint16_t ptons;
    Message *m;
    
//start here testing all the ports
    for(i = from; i <= to; i ++) {
        if(to_exit)
            pthread_exit(NULL);
start:
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        pthread_mutex_lock(&mutex);
        
        currentport = i;        
        pthread_mutex_unlock(&mutex);
        
        if(sockfd > maxfd)
            maxfd = sockfd;
        flags = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
        
        // = htons(i);//the prevous one and at the beigin of this program i forgot to set this parameter
        ptons = htons(i);
        memcpy(thint.ai_addr->sa_data, &ptons, sizeof(uint16_t));
        if((result = connect(sockfd, thint.ai_addr, thint.ai_addrlen )) < 0) {
            if(errno != EINPROGRESS) {
                //perror("--------->connect error: ");
                close(sockfd);
                continue;
            }
        }
        if(result == 0) {
            td->ptr[i] = 1;
            close(sockfd);
            continue;
        }
        
        timeout.tv_sec = 0;
        timeout.tv_usec = 200000 * timeflag;
        FD_ZERO(&rset);
        FD_ZERO(&wset);
        FD_SET(sockfd, &rset);
        wset = rset;
        
        //test for several times
        //the maxfd forgot to plus one
        while((result = select(maxfd + 1, &rset, &wset, NULL, &timeout)) == 0){
            //FD_CLR(sockfd, &rset);
            if(timeflag > MAX_TRY_TIMES)
                goto end;
            timeflag ++;
            FD_SET(sockfd, &rset);
            wset = rset;
        }
        if(FD_ISSET(sockfd, &wset)) {
            len = sizeof(error);
            if(getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
                //printf("in getsockopt error\n");
                close(sockfd);
                continue;
            }
            //printf("%d test error %d\n", i, error);
            switch(error) {
            case 0:
                td->ptr[i] = 1;
                break;
            case ECONNREFUSED:
                break;
            case EINTR: 
                i --;
                break;
            case ENETUNREACH : 
            case EHOSTUNREACH:
                break;
            case ETIMEDOUT:
                if(timeflag > MAX_TRY_TIMES)
                    timeflag = 1;
                else {
                    timeflag ++;
                    close(sockfd);
                    goto start;
                }
                break;
            }
        }
end:
        timeflag = 1;
        close(sockfd);
    }
    pthread_exit(NULL);
}

int getaddr(const char *host, const char *port) {
    struct addrinfo tmp, *res;
    memset(&tmp, 0, sizeof(tmp));
    tmp.ai_family = AF_UNSPEC;
    tmp.ai_socktype = SOCK_STREAM;
    int n;
    if((n = getaddrinfo(host, NULL, &tmp, &res)) != 0) {
//        Message * m = (Message *)malloc(sizeof(Message));
//        snprintf(m->message, MESSAGE_SIZE - 1, "<font color=\"red\">%s</font>", host, gai_strerror(n));
//        m->message[MESSAGE_SIZE - 1] = 0;
//        m->type = ERROR;
//        emitException(m);
        return 1;
    }
    memcpy(&hint, res, sizeof(hint));
    hint.ai_next = NULL;
    freeaddrinfo(res);
    return 0;
}

#endif // LISTENER_H
