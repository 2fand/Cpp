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
*///“匿名函数”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QLabel* lb = new QLabel("你好", this);
}

Widget::~Widget()
{
    delete ui;
}
*///“文字标签”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSpinBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QSpinBox* sba = new QSpinBox(this);
    sba->setMaximum(1000000);
    sba->setValue(114514);
}

Widget::~Widget()
{
    delete ui;
}
*///“限输数字框”^
/*
//widget.ui
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>Widget</class>
 <widget class="QWidget" name="Widget">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>146</width>
    <height>142</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Widget</string>
  </property>
  <layout class="QHBoxLayout" name="horizontalLayout">
   <item>
    <widget class="QSpinBox" name="sb"/>
   </item>
   <item>
    <spacer name="horizontalSpacer">
     <property name="orientation">
      <enum>Qt::Orientation::Horizontal</enum>
     </property>
     <property name="sizeType">
      <enum>QSizePolicy::Policy::Fixed</enum>
     </property>
     <property name="sizeHint" stdset="0">
      <size>
       <width>2</width>
       <height>20</height>
      </size>
     </property>
    </spacer>
   </item>
   <item>
    <widget class="QPushButton" name="btn">
     <property name="text">
      <string>++</string>
     </property>
    </widget>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QSpinBox>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->sb->setMaximum(9999999);
    connect(ui->btn, &QPushButton::clicked, [=](){
        ui->sb->setValue(ui->sb->value() + 1);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///“自增1的数字框”^
