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
    //this->setFixedSize(this->size());
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    QLabel* lb = new QLabel("Player", ui->page_2);
    pmt = pmt.scaledToHeight(125);
    pms = pms.scaledToHeight(150);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    lb->show();
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
*///“已创建一个标签用来控制玩家移动”^
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

void start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel("Player", ui->page_2);
    lb->show();
    for (int i = 1; i <= 121; i++){
        lb = new QLabel("*", ui->page_2);
        lb->move(i % 11 * 50, i / 11 * 50);
        lb->show();
    }
}

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
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“标签阵列已做好”^
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

enum WASD{
    W,
    A,
    S,
    D
};

void start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    QPixmap pm(":/Playerd.png");
    pm = pm.scaled(48, 48);
    lb->setPixmap(pm);
    lb->show();
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    char* cp = &strmaze[0][0];
    for (int i = 1; i < 400; i++){
        lb = new QLabel(ui->page_2);
        lb->move(i % 20 * 48, i / 20 * 48);
        if ('*' == strmaze[i / 20][i % 20]){
            pm.load(":/wall.png");
        }
        else if('G' == strmaze[i / 20][i % 20]){
            pm.load(":/Goal.png");
        }
        else {
            pm.fill(Qt::white);
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///“迷宫已具象化”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm;
    for (int i = 0; i < 400; i++){
        lb = new QLabel(ui->page_2);
        lb->move(i % 20 * 48, i / 20 * 48);
        switch(strmaze[i / 20][i % 20]){
        case '*':
            pm.load(":/wall.png");
            break;
        case 'G':
            pm.load(":/Goal.png");
            break;
        case 'P':
            pm.load(sl[w]);
            break;
        default:
            pm.fill(Qt::white);
            break;
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    WASD w = D;
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    this->b = true;
    while ('G' == strmaze[19][19]){
        this->p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
        showmap(ui, lb, w, strmaze);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent* event){
    if (this->b){
        switch(event->key()){
            case Qt::Key_W:
                this->p.first && '*' != this->cp[-11] && (this->cp -= 11);
                break;
            case Qt::Key_A:
                this->p.second && '*' != this->cp[-1] && (this->cp--);
                break;
            case Qt::Key_S:
                19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
                break;
            case Qt::Key_D:
                19 != this->p.second && '*' != this->cp[1] && (this->cp++);
                break;
            default:
                break;
        }
    }
}
*///“Qt按键事件未能完成等待用户按下某一个键的操作”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm;
    for (int i = 0; i < 400; i++){
        lb = new QLabel(ui->page_2);
        lb->move(i % 20 * 48, i / 20 * 48);
        switch(strmaze[i / 20][i % 20]){
        case '*':
            pm.load(":/wall.png");
            break;
        case 'G':
            pm.load(":/Goal.png");
            break;
        case 'P':
            pm.load(sl[w]);
            break;
        default:
            pm.fill(Qt::white);
            break;
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    WASD w = D;
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=, &w](){
        w = W;
        this->p.first && '*' != this->cp[-11] && (this->cp -= 11);
    });
    connect(shortcut[1], &QShortcut::activated, this, [=, &w](){
        w = A;
        this->p.second && '*' != this->cp[-1] && this->cp--;
    });
    connect(shortcut[2], &QShortcut::activated, this, [=, &w](){
        w = S;
        qDebug() << "dcw";
        19 != this->p.first && '*' != this->cp[-11] && (this->cp += 11);

    });
    connect(shortcut[3], &QShortcut::activated, this, [=, &w](){
        w = D;
        19 != this->p.first && '*' != this->cp[-11] && this->cp++;
    });
    while ('G' == strmaze[19][19]){
        p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        showmap(ui, lb, w, strmaze);
        *cp = ' ';
        while (QKeyEvent::KeyPress) {
            QApplication::processEvents();
        }
        *cp = 'P';
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“键盘键入功能已启用”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm(48, 48);
    for (int i = 0; i < 400; i++){
        lb = new QLabel(ui->page_2);
        lb->move(i % 20 * 48, i / 20 * 48);
        switch(strmaze[i / 20][i % 20]){
        case '*':
            pm.load(":/wall.png");
            break;
        case 'G':
            pm.load(":/Goal.png");
            break;
        case 'P':
            pm.load(sl[w]);
            break;
        default:
            pm.fill(Qt::white);
            break;
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    this->w = D;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=](){
        this->w = W;
        this->p.first && '*' != *(this->cp - 20) && (this->cp -= 20);
        emit mazerun();
    });
    connect(shortcut[1], &QShortcut::activated, this, [=](){
        this->w = A;
        this->p.second && '*' != *(this->cp - 1) && this->cp--;
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [=](){
        this->w = S;
        19 != this->p.first && '*' != *(this->cp + 20) && (this->cp += 20);
        emit mazerun();
    });
    connect(shortcut[3], &QShortcut::activated, this, [=](){
        this->w = D;
        19 != this->p.second && '*' != *(this->cp + 1) && this->cp++;
        emit mazerun();
    });
    connect(this, &MainWindow::mazerun, [=, &lb, &strmaze](){
        *cp = 'P';
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        showmap(this->ui, lb, w, strmaze);
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, w, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“小方块已能正常走动一点”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm(48, 48);
    for (int i = 0; i < 400; i++){
        lb = new QLabel(ui->page_2);
        lb->move(i % 20 * 48, i / 20 * 48);
        switch(strmaze[i / 20][i % 20]){
        case '*':
            pm.load(":/wall.png");
            break;
        case 'G':
            pm.load(":/Goal.png");
            break;
        case 'P':
            pm.load(sl[w]);
            break;
        default:
            pm.fill(Qt::white);
            break;
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    this->w = D;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=](){
        this->w = W;
        this->p.first && '*' != *(this->cp - 20) && (this->cp -= 20);
        emit mazerun();
    });
    connect(shortcut[1], &QShortcut::activated, this, [=](){
        this->w = A;
        this->p.second && '*' != *(this->cp - 1) && this->cp--;
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [=](){
        this->w = S;
        19 != this->p.first && '*' != *(this->cp + 20) && (this->cp += 20);
        emit mazerun();
    });
    connect(shortcut[3], &QShortcut::activated, this, [=](){
        this->w = D;
        19 != this->p.second && '*' != *(this->cp + 1) && this->cp++;
        emit mazerun();
    });
    connect(this, &MainWindow::mazerun, [=, &lb, &strmaze](){
        *cp = 'P';
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        showmap(this->ui, lb, w, strmaze);
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, w, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“导入一个新的头文件”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        'P',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    this->w = D;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=, &lb](){
        this->w = W;

        this->p.first && '*' != *(this->cp - 20) && (this->cp -= 20);
        emit mazerun();
    });
    connect(shortcut[1], &QShortcut::activated, this, [=, &lb](){
        this->w = A;
        this->p.second && '*' != *(this->cp - 1) && this->cp--;
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [=, &lb](){
        this->w = S;
        19 != this->p.first && '*' != *(this->cp + 20) && (this->cp += 20);
        emit mazerun();
    });
    connect(shortcut[3], &QShortcut::activated, this, [=, &lb](){
        this->w = D;
        19 != this->p.second && '*' != *(this->cp + 1) && this->cp++;
        emit mazerun();
    });
    connect(this, &MainWindow::mazerun, [=, &strmaze](){
        *cp = 'P';
        // lb->move(123, 6);
        // lb->show();
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, w, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“lb标签已掌控‘玩家’”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const WASD w, const char strmaze[20][20]){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->stackedwidget->setCurrentIndex(1);
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    this->w = D;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=, &lb](){
        this->w = W;

        this->p.first && '*' != *(this->cp - 20) && (this->cp -= 20);
        emit mazerun();
    });
    connect(shortcut[1], &QShortcut::activated, this, [=, &lb](){
        this->w = A;
        this->p.second && '*' != *(this->cp - 1) && this->cp--;
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [=, &lb](){
        this->w = S;
        19 != this->p.first && '*' != *(this->cp + 20) && (this->cp += 20);
        emit mazerun();
    });
    connect(shortcut[3], &QShortcut::activated, this, [=, &lb](){
        this->w = D;
        19 != this->p.second && '*' != *(this->cp + 1) && this->cp++;
        emit mazerun();
    });
    connect(this, &MainWindow::mazerun, [=, &lb](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        lb->move(189, 79);
        lb->show();
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, w, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“mazerun信号接收之后的匿名槽函数要执行的代码已改变”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    QPair<int, int>p;
    b = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=, &lb](){
        this->pm.load(":/Playerw.png");
        this->pm = this->pm.scaled(48, 48);
        lb->setPixmap(this->pm);
        if (this->p.first && '*' != *(this->cp - 20)){
            this->cp -= 20;
            QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setCurrentTime(10);
            pa->setStartValue(QRect(lb->x(), lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->setEndValue(QRect(lb->x(), lb->y() - 48, ui->centralwidget->width(), ui->centralwidget->height()));
            pa->start();
        }
        emit mazerun();
    });
    connect(shortcut[1], &QShortcut::activated, this, [=, &lb](){
        this->pm.load(":/Playera.png");
        this->pm = this->pm.scaled(48, 48);
        lb->setPixmap(this->pm);
        if (this->p.second && '*' != *(this->cp - 1)){
            this->cp--;
            QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setCurrentTime(10);
            pa->setStartValue(QRect(lb->x(), lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->setEndValue(QRect(lb->x() - 48, lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->start();
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [=, &lb](){
        this->pm.load(":/Players.png");
        this->pm = this->pm.scaled(48, 48);
        lb->setPixmap(this->pm);
        if (19 != this->p.first && '*' != *(this->cp + 20)){
            this->cp += 20;
            QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setCurrentTime(10);
            pa->setStartValue(QRect(lb->x(), lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->setEndValue(QRect(lb->x(), lb->y() + 48, ui->centralwidget->width(), ui->centralwidget->height()));
            pa->start();
        }
        emit mazerun();
    });
    connect(shortcut[3], &QShortcut::activated, this, [=, &lb](){
        this->pm.load(":/Playerd.png");
        this->pm = this->pm.scaled(48, 48);
        lb->setPixmap(this->pm);
        if (19 != this->p.second && '*' != *(this->cp + 1)){
            this->cp++;
            QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setCurrentTime(10);
            pa->setStartValue(QRect(lb->x(), lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->setEndValue(QRect(lb->x() + 48, lb->y(), ui->centralwidget->width(), ui->centralwidget->height()));
            pa->start();
        }
        emit mazerun();
    });
    connect(this, &MainWindow::mazerun, [=](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (this->b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“玩家移动时的动画已完成”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    QPair<int, int>p;
    bool b = 0;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [=, &lb, &b](){
        QTimer::singleShot(b * 10, [=, &lb, &b](){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = this->p.first && '*' != *(this->cp - 20)){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[1], &QShortcut::activated, this, [=, &lb, &b](){
        QTimer::singleShot(b * 10, [=, &lb, &b](){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = this->p.second && '*' != *(this->cp - 1)){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[2], &QShortcut::activated, this, [=, &lb, &b](){
        QTimer::singleShot(b * 10, [=, &lb, &b](){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = 19 != this->p.first && '*' != *(this->cp + 20)){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[3], &QShortcut::activated, this, [=, &lb, &b](){
        QTimer::singleShot(b * 10, [=, &lb, &b](){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = 19 != this->p.first && '*' != *(this->cp + 20)){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(this, &MainWindow::mazerun, [=](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *cp = ' ';
    });
    p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“玩家延时移动效果未生效”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>

//=, &lb, &b

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    qDebug() << this->cp - &strmaze[0][0];
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“只差玩家动画执行时偏移bug没修复”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>

//=, &lb, &b

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        QTimer::singleShot(b * 10, [&](){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(10);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        });
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“玩家动画执行时偏移bug已修复”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“延时无效bug已修复”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QFont>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::keyPressEvent(QKeyEvent* event){
//     if (b){
//         switch(event->key()){
//         case Qt::Key_W:

//             break;
//         case Qt::Key_A:
//             this->p.second && '*' != this->cp[-1] && (this->cp--);
//             break;
//         case Qt::Key_S:
//             19 != this->p.first && '*' != this->cp[11] && (this->cp += 11);
//             break;
//         case Qt::Key_D:
//             19 != this->p.second && '*' != this->cp[1] && (this->cp++);
//             break;
//         default:
//             break;
//         }
//     }
// }
*///“菜单栏已在游戏开始时被删掉”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));

    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///“游戏结束后的画面已用画家类实现”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            return;
        }
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));

    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///玩家走到终点后已显出“你过关!”文字^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QSoundEffect>
#include <QAudioDevice>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            return;
        }
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QSoundEffect* s = new QSoundEffect;
    s->setSource(QUrl::fromLocalFile("win.mp3"));
    s->setVolume(1.0f);
    s->play();
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));

    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///已导入QSoundEffect类文件^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QSoundEffect>
#include <QAudioDevice>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            QSoundEffect* s = new QSoundEffect;
            s->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Documents\\maze\\win.wav"));
            s->setVolume(1.0f);
            s->play();
            connect(s, &QSoundEffect::playingChanged, this, [=](){
                this->close();
            });
            return;
        }
        QTimer::singleShot(250, [&](){
            b = 0;
        });
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///“游戏基本上已完成”^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QSoundEffect>
#include <QAudioDevice>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    QPropertyAnimation* pa = new QPropertyAnimation;
    connect(pa, &QPropertyAnimation::finished, [&](){
        b = 0;
    });
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            QSoundEffect* s = new QSoundEffect;
            s->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Documents\\maze\\win.wav"));
            s->setVolume(1.0f);
            s->play();
            connect(s, &QSoundEffect::playingChanged, this, [=](){
                this->close();
            });
        }
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///已为游戏进行进一步的优化^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QSoundEffect>
#include <QAudioDevice>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    QPropertyAnimation* pa = new QPropertyAnimation;
    connect(pa, &QPropertyAnimation::finished, [&](){
        b = 0;
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            QSoundEffect* s = new QSoundEffect;
            s->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Documents\\maze\\win.wav"));
            s->setVolume(1.0f);
            s->play();
            connect(s, &QSoundEffect::playingChanged, this, [=](){
                this->close();
            });
        }
    });
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));
    this->setWindowIcon(QIcon(QPixmap(":/icon.png")));
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///游戏窗口上的默认icon已变为非默认icon^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>
#include <QToolButton>
#include <QPixmap>
#include <QDebug>
#include <QStringList>
#include <QShortcut>
#include <QVector>
#include <QPropertyAnimation>
#include <QTimer>
#include <QPainter>
#include <QSoundEffect>
#include <QAudioDevice>

void showmap(Ui::MainWindow*& ui, QLabel*& lb, const char strmaze[20][20]){
    QPixmap pm(48, 48);
    for (int i = 0; i <= 400; i++){
        lb = new QLabel(ui->page_2);
        if (400 == i){
            lb->move(0, 0);
            pm.load(":/Playerd.png");
        }
        else {
            lb->move(i % 20 * 48, i / 20 * 48);
            switch(strmaze[i / 20][i % 20]){
            case '*':
                pm.load(":/wall.png");
                break;
            case 'G':
                pm.load(":/Goal.png");
                break;
            default:
                pm.fill(Qt::white);
                break;
            }
        }
        pm = pm.scaled(48, 48);
        lb->setPixmap(pm);
        lb->show();
    }
}

void MainWindow::start(Ui::MainWindow*& ui){
    ui->mb->close();
    QStringList sl = {":/Playerw.png", ":/Playera.png", ":/Players.png", ":/Playerd.png"};
    ui->stackedwidget->setCurrentIndex(1);
    this->pm.load(":/wall.png");
    QLabel* lb = new QLabel(ui->page_2);
    char strmaze[20][20] = {
        ' ',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ','*',
        ' ',' ',' ',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',' ','*',
        ' ',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ',' ','*',' ',' ','*','*',
        ' ','*','*',' ',' ',' ','*','*',' ','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ',' ','*',' ',' ',' ','*','*',' ','*',' ','*',' ','*',' ',' ',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',' ',' ','*',' ','*',
        ' ','*','*',' ',' ','*',' ','*',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ',' ',
        ' ',' ','*','*',' ',' ','*','*','*','*','*',' ',' ',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ',' ',' ',' ',' ',' ','*','*',' ',' ','*','*','*',' ',' ',
        ' ',' ','*',' ',' ','*',' ','*','*','*',' ',' ',' ',' ','*',' ',' ',' ',' ',' ',
        ' ','*','*',' ',' ',' ',' ','*',' ',' ','*','*','*',' ','*',' ',' ','*','*','*',
        ' ',' ','*',' ',' ','*',' ','*',' ','*',' ',' ','*',' ','*',' ',' ',' ','*',' ',
        '*',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',
        ' ','*','*',' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*','*',' ','*',' ',
        ' ','*',' ','*','*','*',' ',' ','*',' ',' ','*',' ',' ',' ','*',' ',' ',' ',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*',' ','*',' ',' ',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ','*','*',' ',
        ' ',' ','*','*','*',' ',' ','*',' ',' ',' ',' ','*',' ',' ','*',' ','*','*','*',
        ' ',' ','*',' ','*',' ','*','*','*',' ',' ','*',' ',' ',' ','*',' ',' ','*',' ',
        ' ',' ',' ',' ',' ',' ',' ',' ',' ','*',' ',' ','*',' ',' ','*','*',' ',' ','G',
    };
    this->cp = &strmaze[0][0];
    char ch = 0;
    bool b = 0;
    bool ba = 1;
    QShortcut *shortcut[4] = {new QShortcut(QKeySequence("W"), this), new QShortcut(QKeySequence("A"), this), new QShortcut(QKeySequence("S"), this), new QShortcut(QKeySequence("D"), this)};
    QPropertyAnimation* pa = new QPropertyAnimation;
    connect(pa, &QPropertyAnimation::finished, [&](){
        b = 0;
        if (' ' == strmaze[19][19]){
            ui->stackedwidget->setCurrentIndex(2);
            this->bwin = 1;
            QSoundEffect* s = new QSoundEffect;
            s->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Documents\\maze\\win.wav"));
            s->setVolume(1.0f);
            s->play();
            connect(s, &QSoundEffect::playingChanged, this, [=](){
                this->close();
            });
        }
    });
    connect(shortcut[0], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerw.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.first && '*' != *(cp - 20))){
                this->cp -= 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[1], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playera.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (this->p.second && '*' != *(cp - 1))){
                this->cp--;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }
        emit mazerun();
    });
    connect(shortcut[2], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Players.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.first && '*' != *(cp + 20))){
                this->cp += 20;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(shortcut[3], &QShortcut::activated, this, [&](){
        ba && (lb->move(0, -476), ba = 0);
        if (!bwin && !b){
            this->pm.load(":/Playerd.png");
            this->pm = this->pm.scaled(48, 48);
            lb->setPixmap(this->pm);
            if (b = (19 != this->p.second && '*' != *(cp + 1))){
                this->cp++;
                pa->setTargetObject(lb);
                pa->setPropertyName("geometry");
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setCurrentTime(1000);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit mazerun();
        }
    });
    connect(this, &MainWindow::mazerun, [&](){
        this->p = {(this->cp - &strmaze[0][0]) / 20, (this->cp - &strmaze[0][0]) % 20};
        *this->cp = ' ';
    });
    p = {(cp - &strmaze[0][0]) / 20, (cp - &strmaze[0][0]) % 20};
    showmap(ui, lb, strmaze);
    *this->cp = ' ';
    while (QKeyEvent::KeyPress) {
        QApplication::processEvents();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(970, 1000);
    this->bwin = 0;
    QPixmap pmt(":/title.png");
    QPixmap pms(":/start.png");
    pmt = pmt.scaledToHeight(300);
    ui->startl->setPixmap(pmt);
    ui->tb->setStyleSheet("QToolButton{border:0px;}");
    ui->tb->setIcon(pms);
    ui->tb->move(this->height() / 2, ui->tb->y());
    ui->ms->setTitle("开始");
    ui->as->setText("开始");
    ui->winl->setPixmap(QPixmap(":/win(1).png"));
    this->setWindowIcon(QIcon(QPixmap(":/icon.png")));
    this->setWindowTitle("迷宫");
    connect(ui->tb, &QToolButton::clicked, [=](){
        start(ui);
    });
    connect(ui->as, &QAction::triggered, [=](){
        start(ui);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (bwin){
        QPainter pr(this);
        pr.fillRect(this->rect(), Qt::white);
    }
}
*///已添加游戏窗口上的标题^
