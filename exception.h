#ifndef EXCEPTION_H
#define EXCEPTION_H

/*
    define the format of the meeages

display current port
display err
display time
*/


typedef enum{END = 0, PORT_ON, ERROR, PORT}MES_TYPE;
#define MESSAGE_SIZE 256



typedef struct  {
    MES_TYPE type;
    char message[MESSAGE_SIZE];
}Message;

#define MESSAGE_BUF_SIZE 65

typedef struct{
    int count;
    int state;
    Message *mesbuf[MESSAGE_BUF_SIZE];
}Exception;

#endif // EXCEPTION_H
