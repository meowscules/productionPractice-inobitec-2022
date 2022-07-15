#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget* parent):
    QOpenGLWidget(parent)
{
    this->rad=0.1;
    this->hi=0.1;
    zoom=-2;
    start_x=0;
    start_y=0;
    xRot=0;
    yRot=0;
}

void MyGLWidget::initializeGL()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
}

void MyGLWidget::resizeGL(int nWidth, int nHeight)
{
    glViewport(0,0,nWidth,nHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,60);
}

void MyGLWidget::paintGL()
{
    float zAlfa=0;
    float ugol = -zAlfa/180*M_PI;
    float speed = 0;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    if(GetKeyState('W')<0)speed =0.1;
    if(GetKeyState('S')<0)speed =-0.1;
    if (GetKeyState('A')<0){speed =0.1; ugol -= M_PI*0.5;}
    if (GetKeyState('D')<0){speed =0.1; ugol += M_PI*0.5;}
    if(speed!=0)
    {
        pos.x += sin(ugol)*speed;
        pos.y += cos(ugol)*speed;
    }
    glTranslatef(-pos.x,-pos.y,zoom);
    glRotatef(xRot,1,0,0);
    glRotatef(yRot,0,1,0);

    if(count == num)
    {
        for (int i = 0; i<num*2; i+=2)
        {
            if(i==0)
            {
                point = 0.0;
            }
            else if (i==2)
            {
                point = myVector[1];
            }
            else if (i>2)
            {
                point = point + myVector[i-1];
            }
            draw_cylinder(myVector[i], myVector[i+1], point, R, G, B);
        }
    }

    update();
}

void MyGLWidget::draw_cylinder(GLfloat radius, GLfloat height, GLfloat point, GLubyte R, GLubyte G, GLubyte B)
{
    GLfloat x              = 0.0;
    GLfloat y              = 0.0;
    GLfloat angle          = 0.0;
    GLfloat angle_stepsize = 0.1;


    glColor3ub(128,128,128);
    glBegin(GL_QUAD_STRIP);
    angle = 0.0;
        while( angle < 2*M_PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , height+point);
            glVertex3f(x, y , point);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, height+point);
        glVertex3f(radius, 0.0, point);
    glEnd();

    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*M_PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , point+height);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, point+height);
    glEnd();

    glColor3ub(R,G,B);
    glBegin(GL_POLYGON);
    angle = 0.0;
        while( angle < 2*M_PI ) {
            x = radius * cos(angle);
            y = radius * sin(angle);
            glVertex3f(x, y , point);
            angle = angle + angle_stepsize;
        }
        glVertex3f(radius, 0.0, point);
    glEnd();
}

void MyGLWidget::wheelEvent(QWheelEvent *event)
{
    QPoint numDegrees = event->angleDelta() / 8;

        if (numDegrees.y() > 0)
        {
            zoom+=0.2;
        }
        else
        {
            zoom-=0.2;
        }
}

void MyGLWidget::mousePressEvent(QMouseEvent *e)
{
    start_x=e->pos().x();
    start_y=e->pos().y();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
    xRot = xRot + (e->pos().y() - start_y)/5;
    yRot = yRot + (e->pos().x() - start_x)/5;
    start_x=e->pos().x();
    start_y=e->pos().y();
    update();
}
