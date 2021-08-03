#ifndef GHOST_H
#define GHOST_H
#include"mainwindow.h"
#include"ui_mainwindow.h"
#include<QMessageBox>


class ghost : public MainWindow
{
    Q_OBJECT
public:
    ghost();
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;

    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    char g_Rand_direct(int i,int j);
    char p_Rand_direct(int i,int j);
    void o_chase_direct(int i,int j);

    virtual void set_move();

    void judge_win();


    ~ghost();
private:
    char green_direction;
    char  pink_direction;
    char orange_direction;
    int green_x,green_y;
    int red_x,red_y;
    int orange_x,orange_y;
    int pink_x,pink_y;



    bool big_flag=0;

    bool green_flag=0;//0 disconnect(pacman不能吃) 1 connect(pacman可以吃)
    bool red_flag=0;
    bool pink_flag=0;
    int orange_flag=0;


    bool stop=0;

    QMessageBox *end;


    QMovie *movie2;
    QMovie *movie3;
    QMovie *movie4;
    QMovie *movie5;
    QMovie *blue;


    QTimer *g_timer;
    QTimer *o_timer;
    QTimer *r_timer;
    QTimer *p_timer;
    QTimer *dead;
    QTimer *big_time;



    QTimer *big_dect;


    int T=0;

private slots:

    void pause();
    void restart();
    void regame();
    void pink_ghost();
    void green_ghost();

    void red_ghost();
    void orange_ghost();


    void eat_pacman();

    void strong();
    void strong_time();
};

#endif // GHOST_H
