#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include<QPainter>
#include<QPushButton>
#include<QLabel>
#include<QMovie>
#include<QKeyEvent>
#include<QTimer>
#include<QTime>
#include<QDebug>
#include<QLCDNumber>
#include<QMatrix>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    QPushButton *button1;

    QLabel *label1;
    QLabel *lab_score;

    virtual void set_move();


    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *k);



    void cross_wall();
    void eat_rule(int i,int j);





    ~MainWindow();

private:
    Ui::MainWindow *ui;


    int count_pacman;






protected:
    int dot[26][29];//設置吃的
    char keyboard;//紀錄pacman按鈕
    int coor_x,coor_y;//紀錄pacman現在位置
    int move[26][29];//設定可以移動的地方
    QTimer *pac_timer;
    QTimer *myTimer;
    QTimer *Timer;
    int big_dick[4];
    QLCDNumber *myLCDNumber;
    QLCDNumber *dashboard;

    int score=0;





private slots:
    void pacman_movie();
    void To_move();
    void showtime();
    void move_coordinate();


};

#endif // MAINWINDOW_H
