#include "window.h"

#include <QtGui>


int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QTextCodec::setCodecForTr (QTextCodec::codecForName ("UTF-8"));
    app.setApplicationName(QObject::tr("Port Scanner"));
    app.setQuitOnLastWindowClosed(true);
    app.setApplicationVersion ("1.0");

    
    Window *window = new Window;
    window->show();
    return app.exec();
}
