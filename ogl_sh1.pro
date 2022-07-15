QT       += core gui opengl
LIBS += -lopengl32
QT += openglwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#CONFIG += c++2a
CONFIG += c++17
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    myglwidget.cpp

HEADERS += \
    mainwindow.h \
    myglwidget.h

FORMS += \
    mainwindow.ui

LIBS += -lopengl32 -lglu32

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
