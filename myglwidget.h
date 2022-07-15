#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QOpenGLWidget>
#include <QTimer>
#include <QMouseEvent>

#define _USE_MATH_DEFINES
#include <math.h>

class MyGLWidget : public QOpenGLWidget
{
   // Q_OBJECT
public:
    MyGLWidget(QWidget* parent = nullptr);
    float rad, hi;
    QVector <float> myVector;
    int num = 1;
    int count = 0;
    float point = 0.0;
    int start_x,start_y;

    int R,G,B;

protected:
    POINTFLOAT pos={0,0};
    int c1=0;

    float xRot, yRot;
    QTimer tmr;
    float zoom;
    void draw_cylinder(GLfloat, GLfloat, GLfloat, GLubyte, GLubyte, GLubyte);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void cilindr_init();
    void initializeGL( );
    void resizeGL (int nWidth, int nHeight);
    void paintGL ( );
    void wheelEvent(QWheelEvent *event);

};

#endif // MYGLWIDGET_H
