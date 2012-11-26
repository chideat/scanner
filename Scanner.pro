TARGET = ./bin/scanner
MOC_DIR = ./moc
OBJECTS_DIR = ./object

HEADERS += \
    unp.h \
    config.h \
    types.h \
    listener.h \
    window.h \
    exception.h \
    center.h

SOURCES += \
    main.cpp \
    window.cpp \
    center.cpp

INCLUDEPATH +=

FORMS += \
    window.ui
