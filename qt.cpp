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
