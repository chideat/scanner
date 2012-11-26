#ifndef TYPES_H
#define TYPES_H
#include <pthread.h>

typedef enum{TD_RUNNING = 0, TD_FINISHED} TDSTAT;

typedef struct {
    pthread_t thread;
    int from;//from which port
    int to;//to which port
    char *ptr;//point to the port arr
}Port;


typedef struct {
    char host[1024];
    int from;
    int to;
}TDScan;
#endif // TYPES_H
