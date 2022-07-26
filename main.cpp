#include "mainwindow.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;

    QWidget centralWidget(&w);
    centralWidget.resize(500,500);
    QLabel label1(&centralWidget);
    label1.setText("dfgdfg");
//    label1.setGeometry(100,200);
    label1.move(50,50);

    w.show();
    return app.exec();
}
