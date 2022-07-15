#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int i=0;
int count=0;
void MainWindow::on_pushButton_clicked()
{
    num = ui->spinBox->value();
    this->ui->openGLWidget->num=num;
    ui->spinBox->setValue(num + 1);

    rad = (ui->doubleSpinBox->value());
    this->ui->openGLWidget->rad=rad;

    hi = (ui->doubleSpinBox_2->value());
    this->ui->openGLWidget->hi=hi;

    myVector.push_back(rad);
    myVector.push_back(hi);

    count ++;

    this->ui->openGLWidget->count=count;

    if(count==num)
    {
        this->ui->openGLWidget->myVector=myVector;
    }

    ui->tableWidget->setRowCount(num);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Радиус" << "Длина");

    QString sy = QString::number(rad);
    QString x1s = QString::number(hi);

    QTableWidgetItem *x2n = new QTableWidgetItem(sy);
    ui->tableWidget->setItem(i,0,x2n);
    QTableWidgetItem *x1n = new QTableWidgetItem(x1s);
    ui->tableWidget->setItem(i,1,x1n);
    i++;
}

void MainWindow::on_pushButton_2_clicked()
{
    num=0;
    hi=0;
    rad=0;
    i=0;
    count=0;
    myVector.clear();
    ui->tableWidget->setRowCount(0);
    ui->spinBox->setValue(1);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    value = (ui->horizontalSlider->value());
    this->ui->openGLWidget->R = value;
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    value = (ui->horizontalSlider_2->value());
    this->ui->openGLWidget->G = value;
}


void MainWindow::on_horizontalSlider_3_valueChanged(int value)
{
    value = (ui->horizontalSlider_3->value());
    this->ui->openGLWidget->B = value;
}

