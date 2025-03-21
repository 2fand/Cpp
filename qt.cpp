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
        bwin = 0;
    }
}
*///已改动绘画事件的内部实现^
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
    this->setFixedSize(980, 980);
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
        bwin = 0;
    }
}
*///已改动游戏固定的窗口大小^
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
    this->setFixedSize(978, 978);
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
        bwin = 0;
    }
}
*///已再次改动游戏固定的窗口大小^
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
    this->setFixedSize(978, 978);
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
        bwin = 0;
    }
}
*///下次优化前的更新^
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
        ba && (lb->move(0, -465), ba = 0);
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
    this->setFixedSize(978, 978);
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
        bwin = 0;
    }
}
*///优化失败，不再进行更新^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPlainTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlainText("你有一段文字待输入");
}

Widget::~Widget()
{
    delete ui;
}
*///设置普通输入框的默认文字^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPlainTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setPlaceholderText("你有一段文字待输入");
}

Widget::~Widget()
{
    delete ui;
}
*///设置提醒用户输入的文字^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QPlainTextEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->plainTextEdit->setCursorWidth(100);
}

Widget::~Widget()
{
    delete ui;
}
*///“特宽光标”^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit, &QPlainTextEdit::textChanged, this, [=](){
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}
*///不能用的输入框^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit, &QPlainTextEdit::copyAvailable, this, [=](){
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}
*///鼠标选中文字就关^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit, &QPlainTextEdit::undoAvailable, this, [=](){
        qDebug() << "已执行一次信号";
    });
}

Widget::~Widget()
{
    delete ui;
}
*///改变输入框的可撤销状态就输入一段文字^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///一个开始界面的简单加工^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(99);
}

Widget::~Widget()
{
    delete ui;
}
*///还有1%没加载的进度条^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    QTimer::singleShot(1000, [&](){
        ui->progressBar->setValue(100);
    });
    QTimer::singleShot(1000, [&](){
        this->close();
    });
}

Widget::~Widget()
{
    delete ui;
}
*///1秒就加载完成的进度条^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setMaximum(2000);
    ui->progressBar->setValue(100);
}

Widget::~Widget()
{
    delete ui;
}
*///用了百分比的进度条^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    QTimer* time = new QTimer();
    connect(time, &QTimer::timeout, [&](){
        if (100 == ui->progressBar->value()){
            this->close();
        }
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    });
    time->start(500);
}

Widget::~Widget()
{
    delete ui;
}
*///会加载的进度条^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(0);
    QTimer* time = new QTimer();
    connect(time, &QTimer::timeout, [&](){
        if (100 == ui->progressBar->value()){
            this->close();
        }
        ui->progressBar->setValue(ui->progressBar->value() + 1);
    });
    time->start(10);
}

Widget::~Widget()
{
    delete ui;
}
*///很快就加载完成的进度条^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->progressBar->setValue(100);
    QTimer* time = new QTimer();
    connect(time, &QTimer::timeout, [&](){
        if (!ui->progressBar->value()){
            this->close();
        }
        ui->progressBar->setValue(ui->progressBar->value() - 1);
    });
    time->start(10);
}

Widget::~Widget()
{
    delete ui;
}
*///倒着加载的进度条^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
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
    QLabel* lb = new QLabel(ui->page_2);
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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    QLabel* lb = new QLabel;
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
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///显示迷宫的startgame方法^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
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
    QLabel* lb = new QLabel(ui->page_2);
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
    lb->move(11,1);
    lb->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    QLabel* lb = new QLabel;
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
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///可操控的标签^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(1);
    ui->lcdNumber->display(1);
}

Widget::~Widget()
{
    delete ui;
}
*///用电子的“晶体管”显示了“1”^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(1);
    ui->lcdNumber->display(8);
}

Widget::~Widget()
{
    delete ui;
}
*///“8”^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->display(856);
}

Widget::~Widget()
{
    delete ui;
}
*///“856”^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(9);
    ui->lcdNumber->display(103476582);
}

Widget::~Widget()
{
    delete ui;
}
*///1亿多的数字^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QShortcut>
#include <QPropertyAnimation>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
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
    QLabel* lb = new QLabel(ui->page_2);
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
    lb->move(11,1);
    lb->show();
    QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
    QShortcut* movesc[4]={
        new QShortcut(QKeySequence("W"), this, [=](){
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
            pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
            pa->start();
        }),
        new QShortcut(QKeySequence("A"), this, [=](){
            //左移操作
        }),
        new QShortcut(QKeySequence("S"), this, [=](){
            //下移操作
        }),
        new QShortcut(QKeySequence("D"), this, [=](){
            //右移操作
        })
    };

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    QLabel* lb = new QLabel;
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
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///QShortcut快捷键的新构建方法^
/*
//mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QShortcut>
#include <QPropertyAnimation>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
    static char strmaze[20][20] = {
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
    QLabel* lb = new QLabel(ui->page_2);
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
    lb->show();
    QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
    this->bmove = 1;
    this->cp = &strmaze[0][0];
    const QShortcut* movesc[4]={
        new QShortcut(QKeySequence("W"), this, [=](){
            if (this->bmove){
                lb->move(0, -276);
                this->bmove = 0;
            }
            QPixmap pms(48, 48);
            pms.load(":/Playerd.png");
            pms = pm.scaled(48, 48);
            lb->setPixmap(pms);
            pa->setEasingCurve(QEasingCurve::Linear);
            pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
            pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
            pa->start();
        }),
        new QShortcut(QKeySequence("A"), this, [=](){
            //左移操作
        }),
        new QShortcut(QKeySequence("S"), this, [=](){
            //下移操作
        }),
        new QShortcut(QKeySequence("D"), this, [=](){
            qDebug() << cp - &strmaze[0][0];
            if (19 != ((cp - &strmaze[0][0]) % 20) && '*' != cp[1]){
                if (this->bmove){
                    lb->move(0, -276);
                    this->bmove = 0;
                }
                this->cp++;
                QPixmap pms(48, 48);
                pms.load(":/Playerd.png");
                pms = pm.scaled(48, 48);
                lb->setPixmap(pms);
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        })
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    QLabel* lb = new QLabel;
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///移动逻辑无效bug已修复^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(2);
    ui->lcdNumber->display(-1);
}

Widget::~Widget()
{
    delete ui;
}
*///“-1”^
/*
//mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setDigitCount(7);
    ui->lcdNumber->display(-199999);
}

Widget::~Widget()
{
    delete ui;
}
*///“-199999”^
/*
//exit\mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setBinMode();
    ui->lcdNumber->setDigitCount(20);
    ui->lcdNumber->display(123);
}

Widget::~Widget()
{
    delete ui;
}
*///123的二进制^
/*
//exit\mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setHexMode();
    ui->lcdNumber->setDigitCount(2);
    ui->lcdNumber->display(124);
}

Widget::~Widget()
{
    delete ui;
}
*///124的十六进制^
/*
//exit\mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QLCDNumber>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->lcdNumber->setOctMode();
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->display(128);
}

Widget::~Widget()
{
    delete ui;
}
*///128的八进制^
/*
//untitled7\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QPropertyAnimation>
#include <QImage>
#include <QFileInfo>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
    static char strmaze[20][20] = {
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
    lb = new QLabel(ui->page_2);
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
    lb->show();
    QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
    this->bmove = 1;
    this->cp = &strmaze[0][0];
    const QShortcut* movesc[4]={
        new QShortcut(QKeySequence("W"), this, [=](){
            QPixmap pmPlayer(":/Playerw.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            this->lb->setPixmap(pmPlayer);
            if (((cp - &strmaze[0][0]) / 20) && '*' != cp[-20]){
                if (this->bmove){
                    this->lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp -= 20;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
        }),
        new QShortcut(QKeySequence("A"), this, [=](){
            QPixmap pmPlayer(":/Playera.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            this->lb->setPixmap(pmPlayer);
            if (((cp - &strmaze[0][0]) % 20) && '*' != cp[-1]){
                if (this->bmove){
                    this->lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp--;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        }),
        new QShortcut(QKeySequence("S"), this, [=](){
            QPixmap pmPlayer(":/Players.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            this->lb->setPixmap(pmPlayer);
            if (19 != ((cp - &strmaze[0][0]) / 20) && '*' != cp[20]){
                if (this->bmove){
                    this->lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp += 20;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
        }),
        new QShortcut(QKeySequence("D"), this, [=](){
            QPixmap pmPlayer(":/Playerd.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            this->lb->setPixmap(pmPlayer);
            if (19 != ((cp - &strmaze[0][0]) % 20) && '*' != cp[1]){
                if (this->bmove){
                    this->lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp++;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
        })
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    QLabel* lb = new QLabel;
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}
*///迷宫游戏的移动逻辑已实现^
/*
//unitited7\mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startgame();

    void paintEvent(QPaintEvent*);
signals:
    void Iswin();

private:
    Ui::MainWindow *ui;

    bool bmove;

    char* cp;
};
#endif // MAINWINDOW_H

//unitited7\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QPropertyAnimation>
#include <QImage>
#include <QFileInfo>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
    static char strmaze[20][20] = {
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
    QLabel* lb = new QLabel(ui->page_2);
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
    lb->show();
    QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
    this->bmove = 1;
    this->cp = &strmaze[0][0];
    connect(this, &MainWindow::Iswin, [=](){
        if ('G' == *this->cp){
            ui->stackedWidget->setCurrentIndex(2);
        }
    });
    const QShortcut* movesc[4]={
        new QShortcut(QKeySequence("W"), this, [=](){
            QPixmap pmPlayer(":/Playerw.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            lb->setPixmap(pmPlayer);
            if (((cp - &strmaze[0][0]) / 20) && '*' != cp[-20]){
                if (this->bmove){
                    lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp -= 20;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                pa->start();
            }
            emit Iswin();
        }),
        new QShortcut(QKeySequence("A"), this, [=](){
            QPixmap pmPlayer(":/Playera.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            lb->setPixmap(pmPlayer);
            if (((cp - &strmaze[0][0]) % 20) && '*' != cp[-1]){
                if (this->bmove){
                    lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp--;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit Iswin();
        }),
        new QShortcut(QKeySequence("S"), this, [=](){
            QPixmap pmPlayer(":/Players.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            lb->setPixmap(pmPlayer);
            if (19 != ((cp - &strmaze[0][0]) / 20) && '*' != cp[20]){
                if (this->bmove){
                    lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp += 20;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                pa->start();
            }
            emit Iswin();
        }),
        new QShortcut(QKeySequence("D"), this, [=](){
            QPixmap pmPlayer(":/Playerd.png");
            pmPlayer = pmPlayer.scaled(48, 48);
            lb->setPixmap(pmPlayer);
            if (19 != ((cp - &strmaze[0][0]) % 20) && '*' != cp[1]){
                if (this->bmove){
                    lb->move(0, -276);
                    this->bmove = false;
                }
                this->cp++;
                pa->setEasingCurve(QEasingCurve::Linear);
                pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                pa->start();
            }
            emit Iswin();
        })
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    static bool bpaint = true;
    if (bpaint){
        QPainter* painter = new QPainter(ui->page_3);
    }
}
*///只差胜利界面没有完成了^
/*
//exit\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->line->setMidLineWidth(1000);
}

Widget::~Widget()
{
    delete ui;
}
*///线的操作^
/*
//exit\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->groupBox->setTitle("Box1");
    ui->groupBox_2->setTitle("Box2");
}

Widget::~Widget()
{
    delete ui;
}
*///对GroupBox的简单操作^
/*
//exit\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->calendarWidget->setCurrentPage(2000, 1);
}

Widget::~Widget()
{
    delete ui;
}
*///对日历的简单操作^
/*
//add\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

signals:
    void add();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

//add\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSpinBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(139, 39);
    this->setWindowTitle("相加器");
    connect(ui->spinBox, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(ui->spinBox_2, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(this, &Widget::add, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()+ui->spinBox_2->value()));
    });
}

Widget::~Widget()
{
    delete ui;
}
*///相加器^
/*
//add\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSpinBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(200, 39);
    this->setWindowTitle("相加器");
    ui->spinBox->setMaximum(9999);
    ui->spinBox_2->setMaximum(9999);
    connect(ui->spinBox, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(ui->spinBox_2, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(this, &Widget::add, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()+ui->spinBox_2->value()));
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已提高两个SpinBox最大值的上限^
/*
//add\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSpinBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(200, 39);
    this->setWindowTitle("相加器");
    this->setWindowIcon(QPixmap(":/plus.png"));
    ui->spinBox->setMaximum(9999);
    ui->spinBox_2->setMaximum(9999);
    connect(ui->spinBox, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(ui->spinBox_2, &QSpinBox::valueChanged, [=](){
        emit add();
    });
    connect(this, &Widget::add, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()+ui->spinBox_2->value()));
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已设置相加器的Icon图标^
/*
//add\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

signals:
    void add();

    void sub();

    void tim();

    void div();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

//add\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QSpinBox>
#include <QDebug>
#include <QComboBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(225, 39);
    this->setWindowTitle("计算器");
    this->setWindowIcon(QPixmap(":/calc.png"));
    ui->spinBox->setMinimum(-9999);
    ui->spinBox_2->setMinimum(-9999);
    ui->spinBox->setMaximum(9999);
    ui->spinBox_2->setMaximum(9999);
    auto l = [=](){
        switch (ui->comboBox->currentIndex()){
            case 0:
                emit add();
                break;
            case 1:
                emit sub();
                break;
            case 2:
                emit tim();
                break;
            case 3:
                emit div();
                break;
            default:
                break;
        }
    };
    connect(ui->comboBox, &QComboBox::currentIndexChanged, [=](){
        l();
    });
    connect(ui->spinBox, &QSpinBox::valueChanged, [=](){
        l();
    });
    connect(ui->spinBox_2, &QSpinBox::valueChanged, [=](){
        l();
    });
    connect(this, &Widget::add, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()+ui->spinBox_2->value()));
    });
    connect(this, &Widget::sub, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()-ui->spinBox_2->value()));
    });
    connect(this, &Widget::tim, [=](){
        ui->label->setText(QString("%1").arg(ui->spinBox->value()*ui->spinBox_2->value()));
    });
    connect(this, &Widget::div, [=](){
        if (ui->spinBox_2->value()){
            ui->label->setText(QString("%1").arg(ui->spinBox->value()/ui->spinBox_2->value()));
        }
        else {
            ui->label->setText("Error");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已将相加器进化为简易计算器^
/*
//text\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

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

private:
    Ui::Widget *ui;

    QString str;
};
#endif // WIDGET_H

//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        this->str = str.append('!');
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已完成自动加感叹号器^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        this->str = str.append(str);
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///双写器已完成^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        this->str.insert(0, '<');
        this->str.append('>');
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已完成尖括号包含器^
/*
//untitled7\mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void startgame();

    void paintEvent(QPaintEvent*);
signals:
    void Iswin();

private:
    Ui::MainWindow *ui;

    bool bmove;

    bool bwin;

    bool bwait;

    char* cp;
};
#endif // MAINWINDOW_H

//untitled7\mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QShortcut>
#include <QPropertyAnimation>
#include <QSoundEffect>
#include <QTimer>

void MainWindow::startgame(){
    ui->stackedWidget->setCurrentIndex(1);
    ui->menubar->close();
    static char strmaze[20][20] = {
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
    QLabel* lb = new QLabel(ui->page_2);
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
    lb->show();
    QPropertyAnimation* pa = new QPropertyAnimation(lb, "geometry");
    this->bmove = true;
    this->cp = &strmaze[0][0];
    this->bwait = false;
    connect(pa, &QPropertyAnimation::finished, [=](){
        this->bwait = false;
    });
    connect(this, &MainWindow::Iswin, [=](){
        if (!this->bwin && 'G' == *this->cp){
            this->bwin = true;
            QTimer::singleShot(300, [=](){
                ui->stackedWidget->setCurrentIndex(2);
                QSoundEffect* sound = new QSoundEffect;
                sound->setSource(QUrl::fromLocalFile("C:\\Users\\Administrator\\Documents\\maze\\win.wav"));
                sound->play();
                connect(sound, &QSoundEffect::playingChanged, [=](){
                    this->close();
                });
            });
        }
    });
    const QShortcut* movesc[4] = {
        new QShortcut(QKeySequence("W"), this, [=](){
            if (!this->bwait) {
                this->bwait = true;
                QPixmap pmPlayer(":/Playerw.png");
                pmPlayer = pmPlayer.scaled(48, 48);
                lb->setPixmap(pmPlayer);
                if (this->bwait = ((cp - &strmaze[0][0]) / 20) && '*' != cp[-20]){
                    if (this->bmove){
                        lb->move(0, -484);
                        this->bmove = false;
                    }
                    this->cp -= 20;
                    pa->setEasingCurve(QEasingCurve::Linear);
                    pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                    pa->setEndValue(QRect(lb->x(), lb->y() - 48, this->width(), this->height()));
                    pa->start();
                }
                emit Iswin();
            }
        }),
        new QShortcut(QKeySequence("A"), this, [=](){
            if (!this->bwait) {
                this->bwait = true;
                QPixmap pmPlayer(":/Playera.png");
                pmPlayer = pmPlayer.scaled(48, 48);
                lb->setPixmap(pmPlayer);
                if (this->bwait = ((cp - &strmaze[0][0]) % 20) && '*' != cp[-1]){
                    if (this->bmove){
                        lb->move(0, -484);
                        this->bmove = false;
                    }
                    this->cp--;
                    pa->setEasingCurve(QEasingCurve::Linear);
                    pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                    pa->setEndValue(QRect(lb->x() - 48, lb->y(), this->width(), this->height()));
                    pa->start();
                }
                emit Iswin();
            }
        }),
        new QShortcut(QKeySequence("S"), this, [=](){
            if (!this->bwait) {
                this->bwait = true;
                QPixmap pmPlayer(":/Players.png");
                pmPlayer = pmPlayer.scaled(48, 48);
                lb->setPixmap(pmPlayer);
                if (this->bwait = 19 != ((cp - &strmaze[0][0]) / 20) && '*' != cp[20]){
                    if (this->bmove){
                        lb->move(0, -484);
                        this->bmove = false;
                    }
                    this->cp += 20;
                    pa->setEasingCurve(QEasingCurve::Linear);
                    pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                    pa->setEndValue(QRect(lb->x(), lb->y() + 48, this->width(), this->height()));
                    pa->start();
                }
                emit Iswin();
            }
        }),
        new QShortcut(QKeySequence("D"), this, [=](){
            if (!this->bwait) {
                this->bwait = true;
                QPixmap pmPlayer(":/Playerd.png");
                pmPlayer = pmPlayer.scaled(48, 48);
                lb->setPixmap(pmPlayer);
                if (this->bwait = 19 != ((cp - &strmaze[0][0]) % 20) && '*' != cp[1]){
                    if (this->bmove){
                        lb->move(0, -484);
                        this->bmove = false;
                    }
                    this->cp++;
                    pa->setEasingCurve(QEasingCurve::Linear);
                    pa->setStartValue(QRect(lb->x(), lb->y(), this->width(), this->height()));
                    pa->setEndValue(QRect(lb->x() + 48, lb->y(), this->width(), this->height()));
                    pa->start();
                }
                emit Iswin();
            }
        })
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pm(":/start.png");
    QPixmap pma(":/title.png");
    ui->label->setPixmap(pma);
    ui->toolButton->setStyleSheet("QToolButton{border:0px;}");
    ui->toolButton->setIconSize(QSize(200,200));
    ui->toolButton->setIcon(pm);
    connect(ui->toolButton, &QToolButton::clicked, [&](){
        this->startgame();
    });
    connect(ui->actionkaishi1, &QAction::triggered, [&](){
        this->startgame();
    });
    ui->actionkaishi1->setText("开始");
    ui->label_2->setPixmap(QPixmap(":/win(1).png"));
    this->bwin = false;
    this->setFixedSize(1017, 1017);
    this->setWindowIcon(QPixmap(":/icon.png"));
    this->setWindowTitle("迷宫");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    if (2 == ui->stackedWidget->indexOf(ui->stackedWidget->currentWidget())){
        QPainter* painter = new QPainter(this);
        painter->fillRect(this->rect(), Qt::white);
        painter->end();
    }
}
*///新迷宫游戏^
/*
//text\mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        this->str.push_front("//");
        while (-1 != (this->i = this->str.indexOf('\n'))){
            this->str[this->i] = (char)0;
            this->str.insert(this->i+1, "//");
        }
        while (-1 != (this->i = this->str.indexOf((char)0))){
            this->str[this->i] = '\n';
        }
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///一键注释器已完成^
/*
//text\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QString>

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

private:
    Ui::Widget *ui;

    QString str;

    int i;

    QChar tempSwap;
};
#endif // WIDGET_H

//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        for (int i = 0; i < (this->str.size() - 1) / 2; i++) {
            this->tempSwap = this->str[i];
            this->str[i] = this->str[this->str.size() - 1 - i];
            this->str[this->str.size() - 1 - i] = this->tempSwap;
        }
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///字符串反转器已完成^
/*
//text\mainwindow.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        for (int i = 0; i < (this->str.size() - 1) / 2; i++) {
            this->tempSwap = this->str[i];
            this->str[i] = this->str[this->str.size() - 1 - i];
            this->str[this->str.size() - 1 - i] = this->tempSwap;
        }
        this->str.push_front('(');
        this->str.append(')');
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///多加括号^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        if (this->str.size()){
            ui->textBrowser->setPlainText(str.back());
        }
        else {
            ui->textBrowser->setPlainText("");
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///只显示最后一个字符^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    srand(time(NULL));
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        ui->textBrowser->setPlainText(this->str.setNum(rand()));
    });
}

Widget::~Widget()
{
    delete ui;
}
*///随机数重现^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    srand(time(NULL));
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        for (int i = 0; i < this->str.size(); i++){
            this->str[i] = QChar(rand() % 95 + 33);
        }
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///随机改变字符^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->str = "";
    this->i = 0;
    srand(time(NULL));
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        this->str = ui->plainTextEdit->toPlainText();
        if (this->str.size()){
            this->str.fill(this->str[0]);
        }
        ui->textBrowser->setPlainText(this->str);
    });
}

Widget::~Widget()
{
    delete ui;
}
*///填充字符串的第一个字符^
/*
//button\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDialog>
#include <QPushButton>
#include <QWindow>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QDialog* ww = new QDialog(this);
    ww->setWindowFlag(Qt::CustomizeWindowHint);
    //QPushButton* pb = new QPushButton;
    //ww->
    ww->show();
}

Widget::~Widget()
{
    delete ui;
}
*///测试bug实现^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tab->setFixedHeight(100);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText(ui->textEdit->toPlainText());
    });
}

Widget::~Widget()
{
    delete ui;
}
*///TabWidget的使用^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tab->setFixedHeight(100);
    ui->tab_2->setFixedHeight(1);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText(ui->textEdit->toPlainText());
    });
}

Widget::~Widget()
{
    delete ui;
}
*///2行TabWidget的使用^
/*
//text\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton;
    ui->tabWidget->addTab(button, ";;;");
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->label->setText(ui->textEdit->toPlainText());
    });
}

Widget::~Widget()
{
    delete ui;
}

*///QTabWidget种addtab方法的使用^
/*
//ui\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton;
    ui->toolBox->addItem(button, "ggg");
}

Widget::~Widget()
{
    delete ui;
}
*///toolBox增加页的操作^
/*
//ui\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton;
    ui->scrollArea->addScrollBarWidget(button, Qt::AlignVCenter);
}

Widget::~Widget()
{
    delete ui;
}
*///ScrollArea的使用^
/*
//ui\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->timeEdit->setTime(QTime(11, 11));
}

Widget::~Widget()
{
    delete ui;
}
*///修改QTimeEdit的时间^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=](){

    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点一键出解器已初具雏形^
/*
//24/widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    class node{
    public:
        int value;
        node* from;
        node(int v, node* f = nullptr){
            this->value = v;
            this->from = f;
        }
    };

    QVector<QVector<node*>>v;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void disturb(QVector<node*> UF, int index, int last_index);

};
#endif // WIDGET_H

//24/widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

void Widget::disturb(QVector<node*> UF, int index, int last_index) {

}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0), new node(1), new node(2), new node(3)};
        for (int i = 0; i < 4; i++){
            disturb(UF, i, -1);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点一键出解器的方法已有一些被创建过^
/*
//24\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    class node{
    public:
        int value;
        int from;
        node(int v, int f){
            this->value = v;
            this->from = f;
        }
    };

    QVector<QVector<node*>>v;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void disturb(QVector<node*> UF, int index, int insert_index);

};
#endif // WIDGET_H
*///已改变并查集节点类的成员变量的类型^
/*
//24\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    class node{
    public:
        int value;
        bool from;
        node(int v, bool f){
            this->value = v;
            this->from = f;
        }
    };

    QVector<unsigned int>v;//根据数据位来查找数据，便于IndexOf筛出不唯一数据

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void disturb(QVector<node*> UF, int insert_index);

};
#endif // WIDGET_H

//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>

void Widget::disturb(QVector<node*> UF, int insert_index) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        for (int i = 0; i < 4; i++){
            disturb(UF, 0);
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

*///已优化并查集，并已完全实现disturb方法^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstring>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已经可以从容器中获得算式^
/*
//24\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
using namespace std;

enum Calc{
    ADD,
    SUB,
    TIM,
    DIV
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    class node{
    public:
        int value;
        bool from;
        node(int v, bool f){
            this->value = v;
            this->from = f;
        }
    };

    QVector<unsigned int>v;//根据数据位来查找数据，便于IndexOf筛出不唯一数据
    
    QVector<char>vtree;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void disturb(QVector<node*> UF, int insert_index);

};
#endif // WIDGET_H

//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstring>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStringList slClac;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        
        for (string str : slout){
            for (auto it = str.begin(); str.end() != it; it++){
                
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}

*///已为自定义24点计算器的算式识别做好准备^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstring>
#include <QStack>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStringList slClac;
        QStack<char>s;
        QString tempstr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    s.push(*it);
                    if (1 != s.size()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);   
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if (')' != tempchar || '(' != tempchar){
                            tempstr.append(tempchar);   
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);   
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已在自定义24点计算器中实现中缀表达式转后缀表达式的操作^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstring>
#include <QStack>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QVector<QString> slClac;
        QStack<char>s;
        QString tempstr;
        QStack<int>sCalc;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            slClac.push_back(tempstr);
        }
        for(QString str : slClac){
            
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已在24点计算器中准备将后缀表达式转化为结果^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstring>
#include <QStack>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QString tempstr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            for(QChar ch : tempstr){
                
                index++;
            }
        }
        
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已重新改变自定义24计算器的后缀表达式转结果的方式^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                
            }
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已即将进行自定义24点计算器的最后一步——通过栈sCalc中每一次剩下的算式结果筛选出合适的算式^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QMap>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QMap<QString, int>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.insert(tempstr, sCalc.top());
            }
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已将数据插入到m键值对树中^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已基本完成自定义24计算器^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*> UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///正在测试自定义24点计算器是否可正常运行^
/*
//24\widget.h
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QVector>
using namespace std;

enum Calc{
    ADD,
    SUB,
    TIM,
    DIV
};

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

private:
    Ui::Widget *ui;

    class node{
    public:
        int value;
        bool from;
        node(int v, bool f){
            this->value = v;
            this->from = f;
        }
    };

    QVector<unsigned int>v;//根据数据位来查找数据，便于IndexOf筛出不唯一数据

    QVector<char>vtree;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void disturb(QVector<node*>& UF, int insert_index);

};
#endif // WIDGET_H

//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, 0), new node(1, 1), new node(2, 2), new node(3, 3)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}

*///已将自定义24点计算器中的disturb方法中的UF参数的类型设为装node对象的QVector数组引用^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(0, false), new node(1, false), new node(2, false), new node(3, false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正UF节点数组中节点对象的构造方式^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data = insert_data << 8;
        }
        if (-1 != this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->spinBox_2->value(), false), new node(ui->spinBox_3->value(), false), new node(ui->spinBox_4->value(), false), new node(ui->spinBox_5->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正节点数组UF中的节点对象的值^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data <<= 8;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->spinBox_2->value(), false), new node(ui->spinBox_3->value(), false), new node(ui->spinBox_4->value(), false), new node(ui->spinBox_5->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
                m.push_back({sCalc.top(), tempstr});
            }
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }

        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器中的disturb方法中的检测元素是否重复的条件^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data <<= 8;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->spinBox_2->value(), false), new node(ui->spinBox_3->value(), false), new node(ui->spinBox_4->value(), false), new node(ui->spinBox_5->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if ('(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            m.push_back({sCalc.top(), tempstr});
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }
            end:
            sCalc.clear();
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器的一些代码^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data <<= 8;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->spinBox_2->value(), false), new node(ui->spinBox_3->value(), false), new node(ui->spinBox_4->value(), false), new node(ui->spinBox_5->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while(s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            m.push_back({sCalc.top(), tempstr});
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }
            end:
            sCalc.clear();
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正中缀表达式转后缀表达式实现中的某一个条件^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = 0;
        for (int i = 0; i < 4; i++){
            insert_data += UF[i]->value;
            insert_data <<= 8;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->spinBox_2->value(), false), new node(ui->spinBox_3->value(), false), new node(ui->spinBox_4->value(), false), new node(ui->spinBox_5->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            m.push_back({sCalc.top(), tempstr});
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }
            end:
            sCalc.clear();
        }

    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正中缀表达式转后缀表达式实现中的某一个条件^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for(QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            m.push_back({sCalc.top(), tempstr});
            for (auto it : m){
                if (ui->spinBox->value() == it.first){
                    qDebug() << it.second;
                    ui->listWidget->addItem(it.second);
                }
            }
            end:
            sCalc.clear();
        }

    });
}

Widget::~Widget()
{
    delete ui;
}

*///已修正自定义24点计算器的disturb方法，并修改了一些数字输入框ui的名字^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for (QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器的显示可行算式的功能^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[0].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for (QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器的上次计算记录保留的bug^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[i].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' == tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for (QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push(atoi(tempstr.toStdString().c_str() + index));
                    break;
                }
            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
            tempstr.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器的部分代码错误^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QString tempstr;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int index = 0;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[i].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it != str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    tempstr.append(*it);
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            tempstr.append(tempchar);
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            tempstr.append(tempchar);
                        }
                    } while('(' != tempchar);
                }
            }//修复
            while (s.size()){
                tempchar = s.top();
                s.pop();
                tempstr.append(tempchar);
            }
            index = 0;
            int ia = 0;
            int ib = 0;
            for (QChar ch : tempstr){
                switch(ch.toLatin1()){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    sCalc.push();
                    break;
                }

            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
            tempstr.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点计算器有重大bug需修复^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[i].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it < str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    while ('0' <= *it && *it <= '9'){
                        intToStr.insert(intToStr.begin(), *it++);
                        if (str.end() <= it){
                            break;
                        }
                    }
                    q.enqueue(intToStr);
                    intToStr.clear();
                }
                else if('*' == *it || '/' == *it || '(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    if (s.size() && '(' == s.top()){
                        continue;
                    }
                    s.push(*it);
                    if (1 != s.size() && '(' != s.top()){
                        do {
                            tempchar = s.top();
                            s.pop();
                            charToStr.push_back(tempchar);
                            q.enqueue(charToStr);
                            charToStr.clear();
                        } while (1 < s.size());
                    }
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            charToStr.push_back(tempchar);
                            q.enqueue(charToStr);
                            charToStr.clear();
                        }
                    } while('(' != tempchar);
                }
            }//修复
            while (s.size()){
                tempchar = s.top();
                s.pop();
                charToStr.push_back(tempchar);
                q.enqueue(charToStr);
                charToStr.clear();
            }
            int ia = 0;
            int ib = 0;
            for (string s : q){
                switch(s[0]){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    dequeStr = q.dequeue();
                    sCalc.push(atoi(dequeStr.c_str()));
                    break;
                }

            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
            q.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点计算器的重大bug已修复^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"%d%c%d%c%d%c%d",
                    "(%d%c%d)%c%d%c%d",
                    "%d%c(%d%c%d)%c%d",
                    "%d%c%d%c(%d%c%d)",
                    "(%d%c%d%c%d)%c%d",
                    "%d%c(%d%c%d%c%d)",
                    "((%d%c%d)%c%d)%c%d",
                    "(%d%c(%d%c%d))%c%d",
                    "%d%c((%d%c%d)%c%d)",
                    "%d%c(%d%c(%d%c%d))"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 7; i++){
                do {
                    sprintf(str, sl[i].toStdString().c_str(), u & 0b11111111, strCalc[0], u >> 8 & 0b11111111, strCalc[1], u >> 16 & 0b11111111, strCalc[2], u >> 24 & 0b11111111);
                    add1(cp);
                    slout.push_back(str);
                } while (strcmp("///", strCalc));
            }
        }
        for (string str : slout){
            for (auto it = str.begin(); it < str.end(); it++){
                if ('0' <= *it && *it <= '9'){
                    while ('0' <= *it && *it <= '9'){
                        intToStr.insert(intToStr.begin(), *it++);
                        if (str.end() <= it){
                            break;
                        }
                    }
                    q.enqueue(intToStr);
                    intToStr.clear();
                }
                else if('*' == *it || '/' == *it){
                    while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
                        tempchar = s.top();
                        s.pop();
                        charToStr.push_back(tempchar);
                        q.enqueue(charToStr);
                        charToStr.clear();
                    }
                    s.push(*it);
                }
                else if('(' == *it){
                    s.push(*it);
                }
                else if('+' == *it || '-' == *it) {
                    while (s.size() && '(' != s.top()) {
                        tempchar = s.top();
                        s.pop();
                        charToStr.push_back(tempchar);
                        q.enqueue(charToStr);
                        charToStr.clear();
                    }
                    s.push(*it);
                }
                else if(')' == *it){
                    do {
                        tempchar = s.top();
                        s.pop();
                        if ('(' != tempchar){
                            charToStr.push_back(tempchar);
                            q.enqueue(charToStr);
                            charToStr.clear();
                        }
                    } while('(' != tempchar);
                }
            }
            while (s.size()){
                tempchar = s.top();
                s.pop();
                charToStr.push_back(tempchar);
                q.enqueue(charToStr);
                charToStr.clear();
            }
            int ia = 0;
            int ib = 0;
            for (string s : q){
                switch(s[0]){
                case '+':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia + ib);
                    break;
                case '-':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia - ib);
                    break;
                case '*':
                    ia = sCalc.top();
                    sCalc.pop();
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push(ia * ib);
                    break;
                case '/':
                    ia = sCalc.top();
                    sCalc.pop();
                    if (!sCalc.top()){
                        goto end;
                    }
                    ib = sCalc.top();
                    sCalc.pop();
                    sCalc.push((float)ia / (float)ib);
                    break;
                default:
                    dequeStr = q.dequeue();
                    sCalc.push(atoi(dequeStr.c_str()));
                    break;
                }

            }
            toStr.clear();
            for (char ch : str){
                toStr.append(ch);
            }
            m.push_back({sCalc.top(), toStr});
            end:
            sCalc.clear();
            q.clear();
        }
        for (auto it : m){
            if (ui->spinBox->value() == it.first){
                qDebug() << it.second;
                ui->listWidget->addItem(it.second);
            }
        }
    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修改自定义24点计算器的中缀表达式转后缀表达式的一些代码^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp){
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536" "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char tempchar = 0;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10);
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(calcStr);
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(strCalc);
                } while (strcmp("///", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已翻新自定义24点计算器的代码^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10);
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(calcStr);
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器中的一个小bug^
/*
//24/widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.insert(intToStr.begin(), '0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(calcStr);
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点计算器的准确率已提高^
/*
//24\tree.h
#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

class tree
{
    string str;
    class treeNode{
    public:
        char val;
        treeNode* left;
        treeNode* right;
        treeNode(char v = 0, treeNode* l = nullptr, treeNode* r = nullptr){
            this->val = v;
            this->left = l;
            this->right = r;
        }
    };
    treeNode* root;
    string getFormula(treeNode* searchNode){

        return this->str;
    }

public:
    char rootVal();
    void unionTree(tree& troot, tree& t, tree& ta);
    string getFormula();
    tree(char ch);
};

#endif // TREE_H

//24\tree.cpp
#include "tree.h"

char tree::rootVal(){
    return this->root->val;
}
void tree::unionTree(tree& troot, tree& t, tree& ta){
    troot.root->left = t.root;
    troot.root->right = ta.root;
}
string tree::getFormula(){
    return getFormula(this->root);
}

tree::tree(char ch) {
    this->root = new treeNode(ch);
}

*///已新建tree.h和tree.cpp两个文件，并在创建tree类的同时实现了tree类的大多数方法^
/*
//24\tree.h
#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

class tree
{
    string str;
    class treeNode{
    public:
        string val;
        treeNode* left;
        treeNode* right;
        treeNode(string v = "", treeNode* l = nullptr, treeNode* r = nullptr){
            this->val = v;
            this->left = l;
            this->right = r;
        }
    };
    treeNode* root;
    string getFormula(treeNode* searchNode);

public:
    string rootVal();
    void unionTree(tree& troot, tree& t, tree& ta);
    string getFormula();
    tree(string str);
};

#endif // TREE_H

//24\tree.cpp
#include "tree.h"

string tree::rootVal(){
    return this->root->val;
}
void tree::unionTree(tree& troot, tree& t, tree& ta){
    troot.root->left = t.root;
    troot.root->right = ta.root;
}
string tree::getFormula(treeNode* searchNode){
    if (nullptr != searchNode->left){
        getFormula(searchNode->left);
    }
    this->str.append(searchNode->val);
    if (nullptr != searchNode->right){
        getFormula(searchNode->right);
    }
    if (searchNode == this->root){
        return this->str;
    }
}
string tree::getFormula(){
    this->str.clear();
    return getFormula(this->root);
}
tree::tree(string str) {
    this->root = new treeNode(str);
}

*///已实现tree类的两个getFormula方法^
/*
//24\tree.h
#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

class tree
{
    string str;
    class treeNode{
    public:
        string val;
        treeNode* left;
        treeNode* right;
        treeNode(string v = "", treeNode* l = nullptr, treeNode* r = nullptr){
            this->val = v;
            this->left = l;
            this->right = r;
        }
    };
    treeNode* root;
    string getFormula(treeNode* searchNode, bool isRight);
    string completeParentheses();

public:
    string rootVal();
    void unionTree(tree& troot, tree& t, tree& ta);
    string getFormula();
    tree(string str);
};

#endif // TREE_H

//24\tree.cpp
#include "tree.h"

string tree::rootVal(){
    return this->root->val;
}
void tree::unionTree(tree& troot, tree& t, tree& ta){
    troot.root->left = t.root;
    troot.root->right = ta.root;
}
string tree::getFormula(treeNode* searchNode, bool isRight){
    if (nullptr != searchNode->left){
        getFormula(searchNode->left, false);
    }
    if (!isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back('(');
    }
    this->str.append(searchNode->val);
    if (isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back(')');
    }
    if (nullptr != searchNode->right){
        getFormula(searchNode->right, true);
    }
    if (searchNode == this->root){
        return completeParentheses();
    }
}
string tree::completeParentheses() {
    int i = 0;
    for (char ch : this->str){
        if ('(' == ch){
            i++;
        }
        else if(')' == ch){
            i--;
        }
    }
    for (; i; i < 0 ? i++ : i--){
        if (i < 0){
            this->str.push_back(')');
        }
        else{
            this->str.insert(this->str.begin(), '(');
        }
    }
    return this->str;
}
string tree::getFormula(){
    this->str.clear();
    return getFormula(this->root, false);
}
tree::tree(string str) {
    this->root = new treeNode(str);
}

*///已新建并实现tree类的completeParentheses方法，并完善了tree类的getFormula有参重载方法^
/*
//24\tree.cpp
#include "tree.h"

string tree::rootVal(){
    return this->root->val;
}
void tree::unionTree(tree& troot, tree& t, tree& ta){
    troot.root->left = t.root;
    troot.root->right = ta.root;
}
string tree::getFormula(treeNode* searchNode, bool isRight){
    if (nullptr != searchNode->left){
        getFormula(searchNode->left, false);
    }
    if (!isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back('(');
    }
    this->str.append(searchNode->val);
    if (isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back(')');
    }
    if (nullptr != searchNode->right){
        getFormula(searchNode->right, true);
    }
    if (searchNode == this->root){
        return completeParentheses();
    }
    return "";
}
string tree::completeParentheses() {
    int i = 0;
    for (char ch : this->str){
        if ('(' == ch){
            i++;
        }
        else if(')' == ch){
            i--;
        }
    }
    for (; i; i < 0 ? i++ : i--){
        if (i < 0){
            this->str.push_back(')');
        }
        else{
            this->str.insert(this->str.begin(), '(');
        }
    }
    return this->str;
}
string tree::getFormula(){
    this->str.clear();
    return getFormula(this->root, false);
}
tree::tree(string str) {
    this->root = new treeNode(str);
}

//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QQueue<tree>qTree;
        QVector<QPair<int, QString>>m;
        QString toStr;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.insert(intToStr.begin(), '0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(calcStr);
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}

*///已widget.cpp导入tree.h类文件，tree.cpp中的getFormula方法的无返回值bug已修复^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        QString toStr;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    vTree.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.insert(intToStr.begin(), '0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        vTree.push_back(tree(s));
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            vTree.back().unionTree(vTree[vTree.size() - 1], vTree[vTree.size() - 2]);
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            vTree.back().unionTree(vTree[vTree.size() - 1], vTree[vTree.size() - 2]);
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            vTree.back().unionTree(vTree[vTree.size() - 1], vTree[vTree.size() - 2]);
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            vTree.back().unionTree(vTree[vTree.size() - 1], vTree[vTree.size() - 2]);
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已实现后缀表达式转中缀表达式的基础^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        QVector<tree>popTrees;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        QString toStr;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        QString calcStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    calcStr.clear();
                    vTree.clear();
                    popTrees.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.insert(intToStr.begin(), '0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            calcStr.append(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                            calcStr.append(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        default:
                            dequeStr = q.dequeue();
                            sCalc.push(atoi(dequeStr.c_str()));
                            vTree.push_back(tree(s));
                            break;
                        }
                    }
                    toStr.clear();
                    for (char ch : str){
                        toStr.append(ch);
                    }
                    m.push_back({sCalc.top(), toStr});
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///自定义24点计算器已基本完成^
/*
//tree.h
#ifndef TREE_H
#define TREE_H

#include <string>
using namespace std;

class tree
{
    string str;
    class treeNode{
    public:
        string val;
        treeNode* left;
        treeNode* right;
        treeNode(string v = "", treeNode* l = nullptr, treeNode* r = nullptr){
            this->val = v;
            this->left = l;
            this->right = r;
        }
    };
    treeNode* root;
    string getFormula(treeNode* searchNode, bool isRight);
    string completeParentheses();

public:
    string& rootVal();
    void unionTree(tree& t, tree& ta);
    string getFormula();
    tree();
    tree(string str);
    tree(const tree& t);
    tree& operator=(const tree& t);
    ~tree();
};

#endif // TREE_H

//tree.cpp
#include "tree.h"

string& tree::rootVal(){
    return this->root->val;
}
void tree::unionTree(tree& t, tree& ta){
    this->root->left = t.root;
    this->root->right = ta.root;
}
string tree::getFormula(treeNode* searchNode, bool isRight){
    if (nullptr != searchNode->left){
        getFormula(searchNode->left, false);
    }
    if (!isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back('(');
    }
    this->str.append(searchNode->val);
    if (isRight && '0' <= searchNode->val[0] && '9' >= searchNode->val[0]){
        this->str.push_back(')');
    }
    if (nullptr != searchNode->right){
        getFormula(searchNode->right, true);
    }
    if (searchNode == this->root){
        return completeParentheses();
    }
    return "";
}
string tree::completeParentheses() {
    int i = 0;
    for (char ch : this->str){
        if ('(' == ch){
            i++;
        }
        else if(')' == ch){
            i--;
        }
    }
    for (; i; i < 0 ? i++ : i--){
        if (i > 0){
            this->str.push_back(')');
        }
        else{
            this->str.insert(this->str.begin(), '(');
        }
    }
    return this->str;
}
string tree::getFormula(){
    this->str.clear();
    return getFormula(this->root, false);
}
tree::tree(string str) {
    this->root = new treeNode(str);
}
tree::tree(){
    this->root = new treeNode("");
}
tree::tree(const tree& t){
    this->root = new treeNode(t.root->val);
    this->root->left = t.root->left;
    this->root->right = t.root->right;
}
tree& tree::operator=(const tree& t){
    this->root->val = t.root->val;
    this->root->left = t.root->left;
    this->root->right = t.root->right;
    return *this;
}
tree::~tree() {
    delete this->root;
    this->root = nullptr;
}
*///已新添tree类的析构方法^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        QVector<tree>popTrees;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    vTree.clear();
                    popTrees.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.push_back('0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ib - ia);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        default:
                            sCalc.push(atoi(s.c_str()));
                            vTree.push_back(tree(s));
                            break;
                        }
                    }
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已为自定义24点计算器删除多余的变量^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        QVector<tree>popTrees;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        char str[16] = "";
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    vTree.clear();
                    popTrees.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.push_back('0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia + ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia - ib);
                            popTrees.push_back(vTree.back());
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ia * ib);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ia / (float)ib);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        default:
                            sCalc.push(atoi(s.c_str()));
                            vTree.push_back(tree(s));
                            break;
                        }
                    }
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已调整自定义24点计算器后缀表达式转中缀表达式中popTree的插入方式^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<int>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        QVector<tree>popTrees;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        int ia = 0;
        int ib = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    vTree.clear();
                    popTrees.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.push_back('0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ib + ia);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '-':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ib - ia);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '*':
                            ia = sCalc.top();
                            sCalc.pop();
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push(ib * ia);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '/':
                            ia = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            ib = sCalc.top();
                            sCalc.pop();
                            sCalc.push((float)ib / (float)ia);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        default:
                            sCalc.push(atoi(s.c_str()));
                            vTree.push_back(tree(s));
                            break;
                        }
                    }
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///已修正自定义24点计算器中后缀表达式求结果的方式^
/*
//24\widget.cpp
#include "widget.h"
#include "ui_widget.h"
#include "tree.h"
#include <QDebug>
#include <QPushButton>
#include <QStringList>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <QStack>
#include <QPair>
#include <QQueue>

void Widget::disturb(QVector<node*>& UF, int insert_index = 0) {
    if (4 == insert_index){
        unsigned int insert_data = UF[0]->value;
        for (int i = 1; i < 4; i++){
            insert_data <<= 8;
            insert_data += UF[i]->value;
        }
        if (-1 == this->v.indexOf(insert_data)) {
            this->v.push_back(insert_data);
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        if (!UF[i]->from){
            UF[i]->from = true;
            UF.swapItemsAt(insert_index, i);
            disturb(UF, insert_index + 1);
            UF.swapItemsAt(insert_index, i);
            UF[i]->from = false;
        }
    }
}

void add1(char* cp, int digit = 0){
    if (digit >= 3){
        return;
    }
    switch(*cp){
    case '+':
        *cp = '-';
        break;
    case '-':
        *cp = '*';
        break;
    case '*':
        *cp = '/';
        break;
    case '/':
        *cp = '+';
        add1(cp - 1, digit + 1);
        break;
    default:
        break;
    }
}

void iterator_swap(string::iterator& it, const unsigned int index, const unsigned int indexa){
    char temp = *(it + index);
    *(it + index) = *(it + indexa);
    *(it + indexa) = temp;
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList sl={"0123456", "0124356", "0124536", "0142536", "0142356"};
    connect(ui->pushButton, &QPushButton::clicked, [=](){
        ui->listWidget->clear();
        this->v.clear();
        QVector<node*>UF = {new node(ui->num1->value(), false), new node(ui->num2->value(), false), new node(ui->num3->value(), false), new node(ui->num4->value(), false)};
        QVector<string> slout;
        QStack<char>s;
        QStack<float>sCalc;
        QQueue<string>q;
        QVector<tree>vTree;
        QVector<tree>popTrees;
        tree t = tree();
        tree ta = tree();
        QVector<QPair<int, QString>>m;
        char strCalc[4] = "+++";
        char* cp = strCalc + 2;
        disturb(UF);
        int i = 0;
        float fa = 0;
        float fb = 0;
        int itemp = 0;
        int index = 0;
        string intToStr;
        string charToStr;
        string dequeStr;
        for (unsigned int u : this->v){
            for (i = 0; i < 5; i++){
                do {
                    vTree.clear();
                    popTrees.clear();
                    for (index = 0; index < 7; index++){
                        if ('4' > sl[i][index]) {
                            itemp = u >> ((sl[i][index].toLatin1() - '0') * 8) & 0b11111111;
                            if (!itemp){
                                intToStr.push_back('0');
                            }
                            while (itemp){
                                intToStr.insert(intToStr.begin(), itemp % 10 + '0');
                                itemp /= 10;
                            }
                            q.enqueue(intToStr);
                            intToStr.clear();
                        }
                        else {
                            charToStr = strCalc[sl[i][index].toLatin1() - '4'];
                            q.enqueue(charToStr);
                        }
                    }
                    for (string s : q){
                        switch(s[0]){
                        case '+':
                            fa = sCalc.top();
                            sCalc.pop();
                            fb = sCalc.top();
                            sCalc.pop();
                            sCalc.push(fb + fa);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '-':
                            fa = sCalc.top();
                            sCalc.pop();
                            fb = sCalc.top();
                            sCalc.pop();
                            sCalc.push(fb - fa);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '*':
                            fa = sCalc.top();
                            sCalc.pop();
                            fb = sCalc.top();
                            sCalc.pop();
                            sCalc.push(fb * fa);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        case '/':
                            fa = sCalc.top();
                            sCalc.pop();
                            if (!sCalc.top()){
                                goto end;
                            }
                            fb = sCalc.top();
                            sCalc.pop();
                            sCalc.push(fb / fa);
                            popTrees.push_back(vTree[vTree.size() - 2]);
                            popTrees.push_back(vTree.back());
                            vTree.pop_back();
                            vTree.back().rootVal() = s;
                            vTree.back().unionTree(popTrees[popTrees.size() - 2], popTrees.back());
                            break;
                        default:
                            sCalc.push(atoi(s.c_str()));
                            vTree.push_back(tree(s));
                            break;
                        }
                    }
                    if (ui->spinBox->value() == sCalc.top()){
                        ui->listWidget->addItem(QString(vTree.back().getFormula().c_str()));
                    }
                end:
                    sCalc.clear();
                    q.clear();
                    add1(cp);
                } while (strcmp("+++", strCalc));
            }
        }
        // for (string str : slout){
        //     for (auto it = str.begin(); it < str.end(); it++){
        //         if ('0' <= *it && *it <= '9'){
        //             while ('0' <= *it && *it <= '9'){
        //                 intToStr.insert(intToStr.begin(), *it++);
        //                 if (str.end() <= it){
        //                     break;
        //                 }
        //             }
        //             q.enqueue(intToStr);
        //             intToStr.clear();
        //         }
        //         else if('*' == *it || '/' == *it){
        //             while (s.size() && '(' != s.top() && '+' != s.top() && '-' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if('(' == *it){
        //             s.push(*it);
        //         }
        //         else if('+' == *it || '-' == *it) {
        //             while (s.size() && '(' != s.top()) {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 charToStr.push_back(tempchar);
        //                 q.enqueue(charToStr);
        //                 charToStr.clear();
        //             }
        //             s.push(*it);
        //         }
        //         else if(')' == *it){
        //             do {
        //                 tempchar = s.top();
        //                 s.pop();
        //                 if ('(' != tempchar){
        //                     charToStr.push_back(tempchar);
        //                     q.enqueue(charToStr);
        //                     charToStr.clear();
        //                 }
        //             } while('(' != tempchar);
        //         }
        //     }
        //     while (s.size()){
        //         tempchar = s.top();
        //         s.pop();
        //         charToStr.push_back(tempchar);
        //         q.enqueue(charToStr);
        //         charToStr.clear();
        //     }


    });
}

Widget::~Widget()
{
    delete ui;
}
*///整个自定义24点计算器工程已正式完成，qt每日已正式毕业^
