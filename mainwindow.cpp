#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    this->resize(961, 699);

    centralwidget = new QWidget(this);
    centralwidget->resize(961, 699);

    spinBox = new QSpinBox(centralwidget);
    spinBox->setObjectName(QString::fromUtf8("spinBox"));
    spinBox->setEnabled(true);
    spinBox->setGeometry(QRect(-1, 630, 0, 0));
    spinBox->setReadOnly(true);
    spinBox->setMinimum(1);
    spinBox->setMaximum(100);
    spinBox->setSingleStep(1);
    spinBox->setValue(1);

    verticalLayoutWidget = new QWidget(centralwidget);
    verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
    verticalLayoutWidget->setGeometry(QRect(10, 20, 291, 621));

    verticalLayout = new QVBoxLayout(verticalLayoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    font.setPointSize(12);

    label = new QLabel(verticalLayoutWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setFont(font);
    label->setText("radius");

    verticalLayout->addWidget(label);

    doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget);
    doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
    doubleSpinBox->setFont(font);
    doubleSpinBox->setMinimum(1);
    doubleSpinBox->setValue(0.010000000000000);
    doubleSpinBox->setSingleStep(0.10);


    verticalLayout->addWidget(doubleSpinBox);

    label2 = new QLabel(verticalLayoutWidget);
    label2->setObjectName(QString::fromUtf8("label_2"));
    label2->setFont(font);
    label2->setText("length");

    verticalLayout->addWidget(label2);

    doubleSpinBox2 = new QDoubleSpinBox(verticalLayoutWidget);
    doubleSpinBox2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
    doubleSpinBox2->setFont(font);
    doubleSpinBox2->setMinimum(1);
    doubleSpinBox2->setValue(0.010000000000000);
    doubleSpinBox2->setSingleStep(0.10);

    verticalLayout->addWidget(doubleSpinBox2);

    pushButton = new QPushButton(verticalLayoutWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setFont(font);
    pushButton->setText("create");

    verticalLayout->addWidget(pushButton);

    pushButton2 = new QPushButton(verticalLayoutWidget);
    pushButton2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton2->setFont(font);
    pushButton2->setText("clear");

    verticalLayout->addWidget(pushButton2);

    tableWidget = new QTableWidget(verticalLayoutWidget);
    tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
    tableWidget->setFont(font);

    verticalLayout->addWidget(tableWidget);

    formLayout = new QFormLayout();
    formLayout->setObjectName(QString::fromUtf8("formLayout"));
    horizontalSlider = new QSlider(verticalLayoutWidget);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setMaximum(255);
    horizontalSlider->setOrientation(Qt::Horizontal);

    formLayout->setWidget(0, QFormLayout::FieldRole, horizontalSlider);

    horizontalSlider2 = new QSlider(verticalLayoutWidget);
    horizontalSlider2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
    horizontalSlider2->setMaximum(255);
    horizontalSlider2->setOrientation(Qt::Horizontal);

    formLayout->setWidget(1, QFormLayout::FieldRole, horizontalSlider2);

    horizontalSlider3 = new QSlider(verticalLayoutWidget);
    horizontalSlider3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
    horizontalSlider3->setMaximum(255);
    horizontalSlider3->setSliderPosition(0);
    horizontalSlider3->setOrientation(Qt::Horizontal);

    formLayout->setWidget(2, QFormLayout::FieldRole, horizontalSlider3);

    label3 = new QLabel(verticalLayoutWidget);
    label3->setObjectName(QString::fromUtf8("label_3"));
    label3->setText("red");

    formLayout->setWidget(0, QFormLayout::LabelRole, label3);

    label4 = new QLabel(verticalLayoutWidget);
    label4->setObjectName(QString::fromUtf8("label_4"));
    label4->setText("green");

    formLayout->setWidget(1, QFormLayout::LabelRole, label4);

    label5 = new QLabel(verticalLayoutWidget);
    label5->setObjectName(QString::fromUtf8("label_5"));
    label5->setText("blue");

    formLayout->setWidget(2, QFormLayout::LabelRole, label5);


    verticalLayout->addLayout(formLayout);
}
