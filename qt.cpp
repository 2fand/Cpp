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
//widget.cpp
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
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug() << "QDebug";
}

Widget::~Widget()
{
    delete ui;
}
*///“QDebug”^
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
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand((unsigned int)time(NULL));
    setFixedSize(rand() % 1000 + 1, rand() % 1000 + 1);
}

Widget::~Widget()
{
    delete ui;
}
*///“随机设置固定窗口”^
/*
//widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
//widget.cpp
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::paintEvent(QPaintEvent *){
    QPainter pt(this);
    QPixmap pm(":/pixmap.png");
    pt.drawEllipse(0, 0, 100, 100);
    pt.drawPixmap(25, 25, pm);
}

Widget::~Widget()
{
    delete ui;
}
*///“绘图事件”^
/*
//widget.cpp#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    static int s_w = 31;
    static int s_h = 0;
    static int s_count = 1;
    connect(ui->btn, &QPushButton::clicked, [=](){
        QPushButton* btna = new QPushButton(QString::number(s_count++), this);
        s_w > this->width() && (s_w = 0, s_h += 23);
        btna->setGeometry(s_w, s_h, 31, 23);
        btna->show();
        s_w += 31;
    });
}

Widget::~Widget()
{
    delete ui;
}
*///“按钮数字自加1”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMenuBar* mb = menuBar();
    setMenuBar(mb);
    mb->addMenu("你好");
    QMenu* mu = mb->addMenu("再见");
    QAction* an = mu->addAction("再见");
    connect(an, &QAction::triggered, [=](){
        this->close();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“菜单栏的创建”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPixMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pm(":/pixmap.png");

    ui->label->setPixmap(pm);


}


Widget::~Widget()
{
    delete ui;
}
*///“文字标签转图片”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPixMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pm(":/pixmap.png");

    pm.fill(Qt::blue);
    ui->label->setPixmap(pm);


}


Widget::~Widget()
{
    delete ui;
}
*///“蓝图”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPixMap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap pm(100, 100);
    QPixmap pma(123, 345);

    pma.fill(Qt::red);
    pm.fill(Qt::blue);
    ui->label->setPixmap(pm);
    ui->labela->setPixmap(pma);


}


Widget::~Widget()
{
    delete ui;
}
*///“空白图片上色”^
/*
//widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>
#include <QStringList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList st={"11", "eded"};
    ui->lw->addItems(st);


}


Widget::~Widget()
{
    delete ui;
}
*///“QListWidget的使用”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“导入一些头文件”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(125);
    pms = pms.scaledToHeight(150);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");

}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“完成页面的布局”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(125);
    pms = pms.scaledToHeight(150);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        qDebug() << "开始";
    });
    connect(ui->as, &QAction::triggered, [=](){
        qDebug() << "开始a";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“检测开始功能是否正常运行”^
/*
//mainwindow.h
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QLabel>
#include <QFont>
#include <QPixmap>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    //QLabel lb(this);
    pmt = pmt.scaledToHeight(125);
    pms = pms.scaledToHeight(150);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        ui->stackedwidget->setCurrentIndex(1);
    });
    connect(ui->as, &QAction::triggered, [=](){
        ui->stackedwidget->setCurrentIndex(1);
    });
    
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“切换页面功能已成功实现”^
