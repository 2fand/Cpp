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
