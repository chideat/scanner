
#include "center.h"
#include "listener.h"
#include <QDebug>

#ifdef BUF_SIZE
#undef BUF_SIZE
#define BUF_SIZE 256
#endif


char buf[BUF_SIZE];

Center::Center(QWidget *parent): QThread(parent){
    
}

Center::Center(QWidget *parent, TDScan *scanner): QThread(parent) {
    this->scanner = scanner;
}


void Center::run() {
    startTimer(200);
    
    emit eFinised(FALSE);
    
    snprintf(buf, BUF_SIZE - 1,  "<font color=\"green\">Running</font>");
    eMessageSlot(buf, ERROR);
    
//    qDebug()<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
//    //exit(1);
//    this->terminate();
//    qDebug()<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
    int i;
    if((i = checkAddr()) != 0) {
        switch(i){
        case -2:
            snprintf(buf, BUF_SIZE - 1,  "<font color=\"green\">Check your network connection</font>");
            break;
        default:
            snprintf(buf, BUF_SIZE - 1,  "<font color=\"green\">Invalidate Host/IP</font>");
            break;
        }
        eMessageSlot(buf, ERROR);
        emit eFinised(TRUE);
        
        pthread_exit(NULL);
    }

    memset(&exception, 0, sizeof(Exception));
    
    pthread_create(&tid, NULL, setarget, (void*)scanner);
    exception.state = 1;
    
    //here waiting for the data
    
//    while(exception.state == 1) {
//        pthread_mutex_lock(&exmutex);
//        while(exception.count <= 0)
//            pthread_cond_wait(&excond, &exmutex);
//        for(i = 0; i < MESSAGE_BUF_SIZE && exception.count > 0; i ++){
//            if(exception.mesbuf[i] != NULL){
//                emit eMessage(exception.mesbuf[i]);
//                exception.mesbuf[i] = NULL;
//                exception.count --;
//            }
//        }
//        pthread_cond_signal(&excond);
//        pthread_mutex_unlock(&exmutex);
//    }
    
    pthread_join(tid, NULL);
    for(i = scanner->from;i <= scanner->to;i ++) {
        if(ports[i] == 1) {
            snprintf(buf , BUF_SIZE - 1,  "<font color=\"red\">Port %d is ON</font>", i);
            eMessageSlot(buf , PORT_ON);
        }
    }
    eMessageSlot("------------------------------------------------------------<br>", PORT_ON);
    
    emit eFinised(TRUE);
    eMessageSlot("Stoped", ERROR);
}

void Center::timerEvent(QTimerEvent *) {
   //if(this->isRunning())
        emit eCurrentPort(currentport);
}

void Center::tdstop(bool val) {
    if(val) {
        startTimer(0);
        to_exit = 1;
        tid = -1;
    }
}

void Center::eMessageSlot(const char *message, MES_TYPE t) {
    if(message == NULL)
        return ;
    Message *m = (Message *)malloc(sizeof(Message));
    if(!m)
        return ;
    strncpy(m->message, message, BUF_SIZE);
    m->message[BUF_SIZE - 1] = 0;
    m->type = t;
    emit eMessage(m);
}


int Center::checkAddr() {
    struct addrinfo tmp, *res;
    memset(&tmp, 0, sizeof(tmp));
    tmp.ai_family = AF_UNSPEC;
    tmp.ai_socktype = SOCK_STREAM;
    int n;
    res = NULL;
    n = getaddrinfo(scanner->host, NULL, &tmp, &res);
    if(res)
        freeaddrinfo(res);
    return n;
}