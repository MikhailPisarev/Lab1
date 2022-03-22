#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void isWakeUp(const QString);

    private slots:
    void showTime();

private:
    Ui::MainWindow *ui;
    QTimer *Timer;
    int ms,s,m;
    bool flag=true;

};
#endif // MAINWINDOW_H
