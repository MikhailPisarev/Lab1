#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QTime>
#include<QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lcdNumber->setSegmentStyle(QLCDNumber::Filled);

    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    connect(this,SIGNAL(isWakeUp(const QString)),ui->leResult,SLOT(setText(const QString)));
    timer->start();

    ms=0;
    s=0;
    m=0;
    Timer=new QTimer(this);
    connect(Timer,SIGNAL(timeout()),this,SLOT(TimerSlot()));
    Timer->stop();
}

void MainWindow::showTime()
{
QTime time=QTime::currentTime();
QString text=time.toString("hh:mm");
if((time.second()%2)==0)
{
text[2]=' ';
}
ui->lcdNumber->display(text);
if(ui->checkBox->checkState()==Qt::Checked)
{
if(ui->sbHours->value()==time.hour()&&ui->sbMinutes->value()==time.minute())
emit isWakeUp("Пора вставать!");
else
emit isWakeUp("");
}
else ui->leResult->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

