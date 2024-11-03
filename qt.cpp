/*
//main.cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
*///“第一个qt程序”^
/*
//main.cpp
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    Widget wa;
    wa.show();

    return a.exec();
}
*///“两个widget”^
/*
#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* vqp = new QPushButton();
    vqp->setParent(this);
    vqp->setText("按钮");
    vqp->show();
}

Widget::~Widget()
{
    delete ui;
}
*///“按钮”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QCheckBox>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QCheckBox* cb = new QCheckBox("你好", this);
    cb->show();
}

Widget::~Widget()
{
    delete ui;
}
*///“多选框”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QRadioButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QRadioButton* cb = new QRadioButton("单选", this);
    cb->show();
}

Widget::~Widget()
{
    delete ui;
}
*///“单选点”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QVector>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QVector<int>qv;
    qv.push_back(1);
    qv.push_back(10);
    qDebug() << qv[1];

}

Widget::~Widget()
{
    delete ui;
}
*///“QVector容器”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
   // QPushButton* btnp = ui->btn;
    ui->setupUi(this);
    connect(ui->btn, &QPushButton::clicked, this, &QWidget::close);
}

Widget::~Widget()
{
    delete ui;
}
*///“信号与槽”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->btn, &QPushButton::clicked, [](){
        qDebug() << "按钮";
    });
}

Widget::~Widget()
{
    delete ui;
}
*///“匿名函数”^
