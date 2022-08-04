#include "mainwindow.h"
#include <QApplication>
#include <myglwidget.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
//    MyGLWidget dfg;
//    dfg.show();
    return app.exec();
}
