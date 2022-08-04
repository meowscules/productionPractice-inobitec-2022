#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QWidget(parent)
{
    resize(640, 480);

    m_mainLayout = new QHBoxLayout;
    m_leftLayout = new QVBoxLayout;
//    m_rightLayout = new QVBoxLayout;

    setLayout(m_mainLayout);

    glWidget = new MyGLWidget(this);
//    glWidget->setGeometry(QRect(310, 20, 620, 620));
    font.setPointSize(12);

    m_mainLayout->addLayout(m_leftLayout);
    m_mainLayout->addWidget(glWidget, 1);
//    m_rightLayout->addWidget(glWidget);

    std::cout << glWidget->isEnabled() << std::endl;

    m_labelRadius = new QLabel("Radius", this);
    m_labelRadius->setFont(font);
    m_leftLayout->addWidget(m_labelRadius);

    m_spinBox = new QSpinBox(this);
    m_spinBox->setEnabled(true);
    m_spinBox->setGeometry(QRect(-1, 630, 0, 0));
    m_spinBox->setReadOnly(true);
    m_spinBox->setMinimum(1);
    m_spinBox->setMaximum(100);
    m_spinBox->setSingleStep(1);
    m_spinBox->setValue(1);

    m_radiusDoubleSpinBox = new QDoubleSpinBox(this);
    m_radiusDoubleSpinBox->setMinimum(1.0);
    m_radiusDoubleSpinBox->setValue(0.01);
    m_radiusDoubleSpinBox->setSingleStep(0.1);
    m_radiusDoubleSpinBox->setFont(font);
    m_leftLayout->addWidget(m_radiusDoubleSpinBox);

    m_labelLength = new QLabel("Length", this);
    m_labelLength->setFont(font);
    m_leftLayout->addWidget(m_labelLength);

    m_lengthDoubleSpinBox = new QDoubleSpinBox(this);
    m_lengthDoubleSpinBox->setMinimum(1.0);
    m_lengthDoubleSpinBox->setValue(0.01);
    m_lengthDoubleSpinBox->setSingleStep(0.1);
    m_lengthDoubleSpinBox->setFont(font);
    m_leftLayout->addWidget(m_lengthDoubleSpinBox);

    m_createPushButton = new QPushButton("Create",this);
    m_createPushButton->setFont(font);
    m_leftLayout->addWidget(m_createPushButton);
    connect(m_createPushButton, &QPushButton::clicked, this, &MainWindow::createButtonClicked);

    m_clearPushButton = new QPushButton("Clear",this);
    m_clearPushButton->setFont(font);
    m_leftLayout->addWidget(m_clearPushButton);
    connect(m_createPushButton, &QPushButton::clicked, this, &MainWindow::clearButtonClicked);

    m_tableWidget = new QTableWidget(this);
    m_leftLayout->addWidget(m_tableWidget);
    m_tableWidget->setColumnCount(2);
    m_tableWidget->setHorizontalHeaderLabels(QStringList() << "Радиус" << "Длина");

    m_formColorLayout = new QFormLayout;
    m_leftLayout->addLayout(m_formColorLayout);

    m_horizontalSliderColorRed = new QSlider(this);
    m_horizontalSliderColorRed->setOrientation(Qt::Horizontal);
    m_horizontalSliderColorRed->setMaximum(255);
    m_formColorLayout->setWidget(0, QFormLayout::FieldRole, m_horizontalSliderColorRed);

    m_horizontalSliderColorGreen = new QSlider(this);
    m_horizontalSliderColorGreen->setOrientation(Qt::Horizontal);
    m_horizontalSliderColorGreen->setMaximum(255);
    m_formColorLayout->setWidget(1, QFormLayout::FieldRole, m_horizontalSliderColorGreen);

    m_horizontalSliderColorBlue = new QSlider(this);
    m_horizontalSliderColorBlue->setOrientation(Qt::Horizontal);
    m_horizontalSliderColorBlue->setMaximum(255);
    m_formColorLayout->setWidget(2,QFormLayout::FieldRole, m_horizontalSliderColorBlue);

    m_labelColorRed = new QLabel("Red",this);
    m_labelColorRed->setFont(font);
    m_formColorLayout->setWidget(0, QFormLayout::LabelRole, m_labelColorRed);

    m_labelColorGreen = new QLabel("Green", this);
    m_labelColorGreen->setFont(font);
    m_formColorLayout->setWidget(1, QFormLayout::LabelRole, m_labelColorGreen);

    m_labelColorBlue = new QLabel("Blue", this);
    m_labelColorBlue->setFont(font);
    m_formColorLayout->setWidget(2, QFormLayout::LabelRole, m_labelColorBlue);


}

//int counter = 0;
//int row = 0;

void MainWindow::createButtonClicked(){    
    double radius = m_radiusDoubleSpinBox->value();
    double length = m_lengthDoubleSpinBox->value();
    m_glWidget->AddShaftSegment(radius, length);

    int row = m_tableWidget->rowCount();
    QString sy = QString::number(radius);
    QString x1s = QString::number(length);
    QTableWidgetItem *x2n = new QTableWidgetItem(sy);
    m_tableWidget->setItem(row, 0, x2n);
    QTableWidgetItem *x1n = new QTableWidgetItem(x1s);
    m_tableWidget->setItem(row, 1, x1n);
    m_tableWidget->setRowCount(row + 1);
}

void MainWindow::clearButtonClicked(){

}
