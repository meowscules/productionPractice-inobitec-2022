#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    QWidget *centralwidget;
    QMainWindow *mainWindow;
    QSpinBox *spinBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label2;
    QDoubleSpinBox *doubleSpinBox2;
    QPushButton *pushButton;
    QPushButton *pushButton2;
    QTableWidget *tableWidget;
    QFormLayout *formLayout2;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider2;
    QSlider *horizontalSlider3;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QMenuBar *menubar;
    QStatusBar *statusbar;
};

#endif // MAINWINDOW_H
