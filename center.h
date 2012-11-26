#ifndef CENTER_H
#define CENTER_H

#include "types.h"
#include "exception.h"
#include <QThread>
#include <QLabel>


/*
    used to connect the window and scanner together


*/


class Center : public QThread {
    Q_OBJECT
public :
    Center(QWidget *parent = NULL);
    Center(QWidget *parent, TDScan *scanner);
protected:
    void run();
    void timerEvent(QTimerEvent *);
    TDScan *scanner;
    pthread_t tid;
signals:
    void eMessage(Message *m);
    void eFinised(bool val);
    void eCurrentPort(int port);
    //void stop(bool val);
public slots:
    void tdstop(bool val);
    int checkAddr();
    void eMessageSlot(const char *message, MES_TYPE t);
};


#endif // CENTER_H
