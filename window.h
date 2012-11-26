#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QTimerEvent>
#include <QQueue>
#include "center.h"
#include "exception.h"

namespace Ui {
class Window;
}



class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QMainWindow *parent = 0);
    ~Window();
    
public slots:
    void setEndValue(int val);
    void scan();
    void statusBar();
protected:
    void timerEvent( QTimerEvent * ); 
private:
    bool scanning;
    TDScan scanner;
    Ui::Window *ui;
    
    Center *center;
    //statusbar
    int timego;
    QLabel *labelTime;
    QLabel *labelNotification;
    QLabel *labelPort;
  //  QQueue<Message *m> queue;
public slots:
    void scanStop(bool enable);
    void exception(Message *m);
    void currentPort(int port);
    void autoScroll();
signals:
    void stop(bool val);
};



#endif // WINDOW_H
