#include "ui_window.h"
#include "window.h"

#include <QTime>
#include <QDebug>
#include <errno.h>

Window::Window(QMainWindow *parent) : QMainWindow(parent), ui(new Ui::Window)
{
    ui->setupUi(this);
    statusBar();
    setWindowTitle(tr("Port Scanner"));
    scanning = FALSE;
    center = new Center(this, &scanner);
    
    connect(center, SIGNAL(eMessage(Message *)), this, SLOT(exception(Message*)));
    connect(ui->start, SIGNAL(valueChanged(int)), this, SLOT(setEndValue(int)));
    connect(ui->scan,SIGNAL(released()), this, SLOT(scan()));
    connect(center,SIGNAL(eFinised(bool)), this, SLOT(scanStop(bool)));
    connect(center,SIGNAL(eCurrentPort(int)), this, SLOT(currentPort(int)));
    connect(this,SIGNAL(stop(bool)),center, SLOT(tdstop(bool)));
    connect(ui->result, SIGNAL(textChanged()), this, SLOT(autoScroll()));
    startTimer(998);//ms
    
    ui->result->setStyleSheet("QScrollBar:vertical {border:0px solid grey;width:4px;background:#888888;}");
    ui->host->setText("www.baidu.com");
    ui->end->setValue(65535);
}

Window::~Window()
{
    delete center;
    delete ui;
}


void Window::setEndValue(int val) 
{
    if(ui->end->value() < val)
        ui->end->setValue(val);
}

void Window::scan() {
      if(!scanning) {
        scanning = TRUE;
        ui->scan->setDisabled(true);
        ui->result->insertHtml("[");
        ui->result->insertHtml(ui->host->text());
        ui->result->insertHtml("] -- ");
        ui->result->insertHtml(QTime::currentTime().toString("[hh:mm:ss]"));
        ui->result->insertHtml("<br>");
        timego = 0;
        labelTime->setText("T: 00:00s");
        scanner.from = ui->start->value();
        scanner.to = ui->end->value();
        QByteArray byte = ui->host->text().toAscii();        
        strncpy(scanner.host, byte.data(), 1024);
        center->start();
    }
    else {
        scanning = FALSE;
        ui->scan->setDisabled(true);
        emit stop(TRUE);
        center->exit(0);
    }
}

void Window::statusBar() {
    QStatusBar *bar = ui->statusBar;
    labelNotification = new QLabel("N: Stoped");
    labelPort = new QLabel("P: None   ");
    labelTime = new QLabel("T: 00:00s");
    bar->addWidget(labelNotification, 5);
    bar->addWidget(labelPort, 0);
    bar->addWidget(labelTime, 0);
}

void Window::timerEvent(QTimerEvent *event) {
    if(scanning) {
        timego ++;
        QTime displayTime(0, timego / 60, timego % 60);
        labelTime->setText(tr("T: %1s").arg(displayTime.toString ("mm:ss")));
    }
}
 
void Window::exception(Message *m) {
    if(!m)
        return ;
        switch(m->type) {
        case PORT_ON:
            ui->result->insertHtml(tr("%1<br>").arg(m->message));
            break;
        case ERROR:
            labelNotification->setText(tr("N: %1").arg(m->message));
            break;
        case END:
            break;
        }
        free(m);
}

void Window::scanStop(bool enable){
    if(enable == TRUE){
        ui->scan->setText(tr("Scan"));
        ui->scan->setEnabled(true);
        scanning = FALSE;
    }
    else{
        ui->scan->setText(tr("Stop"));
        ui->scan->setEnabled(true);
        scanning = TRUE;
    }
}

void Window::autoScroll() {
    QTextCursor textCursor = ui->result->textCursor();
    textCursor.movePosition(QTextCursor::End);
    ui->result->setTextCursor(textCursor);
}

void Window::currentPort(int port) {
        labelPort->setText(tr("P: %1").arg(port));
}
