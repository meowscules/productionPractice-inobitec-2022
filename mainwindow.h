#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <myglwidget.h>
#include "iostream"

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
   void createButtonClicked();
   void clearButtonClicked();
private:
    MyGLWidget *glWidget;

    QVBoxLayout *m_rightLayout;
    QWidget *centralwidget;
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_leftLayout;
    QSpinBox *m_spinBox;
    QFont font;
    QDoubleSpinBox *m_radiusDoubleSpinBox;
    QDoubleSpinBox *m_lengthDoubleSpinBox;
    QPushButton *m_createPushButton;
    QPushButton *m_clearPushButton;
    QTableWidget *m_tableWidget;
    QFormLayout *m_formColorLayout;
    QSlider *m_horizontalSliderColorRed;
    QSlider *m_horizontalSliderColorGreen;
    QSlider *m_horizontalSliderColorBlue;
    QLabel *m_labelRadius;
    QLabel *m_labelLength;
    QLabel *m_labelColorRed;
    QLabel *m_labelColorGreen;
    QLabel *m_labelColorBlue;
private:
    float m_length, m_radius;
    int m_numberShafts = 0;
    QVector <float> myVector;
};

#endif // MAINWINDOW_H
