 #include "ghost.h"
#include"ui_mainwindow.h"
#include<QTimer>
ghost::ghost()
{

    button2 = new QPushButton(this);
    button2->setGeometry(950,750,100,50);
    button2->setText("暫停");

    button3 = new QPushButton(this);
    button3->setGeometry(950,700,100,50);
    button3->setText("開始");
    button4 = new QPushButton(this);
    button4->setGeometry(950,600,100,50);
    button4->setText("重新開始");


    connect(button2,SIGNAL(clicked()),this,SLOT(pause()));
    connect(button3,SIGNAL(clicked()),this,SLOT(restart()));
    connect(button4,SIGNAL(clicked()),this,SLOT(regame()));

    //movie->setSpeed(0);
    label2 = new QLabel(this);
    label2->setGeometry(403,348,60,60);
    label2->setScaledContents(true);//自適應大小
    QMovie *movie2 =new QMovie(":/new/prefix1/green.gif");
    label2->setMovie(movie2);
    movie2->start();


    label3 = new QLabel(this);
    label3->setGeometry(403,348,60,60);
    label3->setScaledContents(true);//自適應大小
    QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
    movie3->start();
    label3->setMovie(movie3);

    //movie->setSpeed(0);

    label4 = new QLabel(this);
    label4->setGeometry(403,348,60,60);
    label4->setScaledContents(true);//自適應大小
    QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
    label4->setMovie(movie4);
    movie4->start();
    //movie->setSpeed(0);

    label5 = new QLabel(this);
    label5->setGeometry(370,316,60,60);
    label5->setScaledContents(true);//自適應大小
    QMovie *movie5 =new QMovie(":/new/prefix1/orange.gif");
    label5->setMovie(movie5);
    movie5->start();
    //movie->setSpeed(0);










    QTimer *g_timer = new QTimer(this);
    g_timer->start(350);
    QTimer *r_timer = new QTimer(this);
    r_timer->start(350);
    QTimer *o_timer = new QTimer(this);
    o_timer->start(285);
    QTimer *p_timer = new QTimer(this);
    p_timer->start(350);
    QTimer *dead = new QTimer(this);
    dead->start();


    QTimer *big_dect = new QTimer(this);
    big_dect->start(250);
    connect(big_dect,SIGNAL(timeout()),this,SLOT(strong()));
    QTimer *big_time = new QTimer(this);
    big_time->start(1000);
    connect(big_time,SIGNAL(timeout()),this,SLOT(strong_time()));


    connect(dead,SIGNAL(timeout()),this,SLOT(eat_pacman()));
    connect(g_timer,SIGNAL(timeout()),this,SLOT(green_ghost()));
    connect(r_timer,SIGNAL(timeout()),this,SLOT(red_ghost()));
    connect(p_timer,SIGNAL(timeout()),this,SLOT(pink_ghost()));
    connect(o_timer,SIGNAL(timeout()),this,SLOT(orange_ghost()));


}
void ghost::judge_win()
{
    int judge_dot=0;
    for(int k=0;k<26;++k)
    {
        for(int p=0;p<29;++p)
        {
            if(dot[k][p]==0)
                ++judge_dot;
            if(judge_dot>=298 && !stop)
            {

                end = new QMessageBox("end","YOU WIN!!!",QMessageBox::Information,
                                      QMessageBox::Ok | QMessageBox::Default,
                                      QMessageBox::Cancel | QMessageBox::Escape
                                      ,0);
                end->show();

                stop=1;
                myTimer->stop();

            }
        }

    }

}
void ghost::pause()
{
    myTimer->stop();
    stop=1;
}
void ghost::restart()
{
    myTimer->start(300);
    stop=0;
}
void ghost::regame()
{
    label1->setGeometry(403,540,60,60);
    label2->setGeometry(403,348,60,60);
    label3->setGeometry(403,348,60,60);
    label4->setGeometry(403,348,60,60);
    label5->setGeometry(370,316,60,60);
    green_x=403;
    green_y=348;
    red_x=403;
    red_y=348;
    orange_x=370;
    orange_y=316;
    pink_x=403;
    pink_y=348;

    green_direction='D';
    pink_direction='A';
    orange_direction='W';
    coor_x=403;
    coor_y=540;
    myTimer->start(300);


    //如果已經掛了或暫停
    if(stop || !green_flag || !red_flag || !orange_flag || !pink_flag)
        pac_timer->start();
    stop=0;


    for(int i=0;i<26;++i)
    {
        for(int j=0;j<29;++j)
        {
            dot[i][j]=1;
            move[i][j]=0;
        }
        for(int i=0;i<4;++i)
        {
            big_dick[i]=1;
        }
        repaint();
    }
}
void ghost::set_move()
{
    green_x=403;
    green_y=348;
    red_x=403;
    red_y=348;
    orange_x=370;
    orange_y=316;
    pink_x=403;
    pink_y=348;

    green_direction='D';
    pink_direction='A';
    orange_direction='W';
}
void ghost::eat_pacman()
{
    judge_win();


    //吃到威爾鋼power up

      if((green_x/33)==(coor_x/33) && (green_y/32)==(coor_y/32))
      {
         if(green_flag)
         {

            green_x=403;
            green_y=348;
            label2->setGeometry(403,348,60,60);


            score+=50;
            QString str = QString::number(score);
            dashboard->display(str);


            QMovie *movie2 =new QMovie(":/new/prefix1/green.gif");
            label2->setMovie(movie2);
            movie2->start();

            green_flag=0;
            return;
         }
         else {
             myTimer->stop();
             pac_timer->stop();
             end = new QMessageBox("end","你輸了廢物",QMessageBox::Information,
                                   QMessageBox::Ok | QMessageBox::Default,
                                   QMessageBox::Cancel | QMessageBox::Escape
                                   ,0);

             end->show();
             return;

         }


      }



      if((red_x/33)==(coor_x/33) && (red_y/32)==(coor_y/32))
      {
          if(red_flag)
          {
            label3->setGeometry(403,348,60,60);
            red_x=403;
            red_y=348;

            score+=50;
            QString str = QString::number(score);
            dashboard->display(str);


            QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
            label3->setMovie(movie3);
            movie3->start();


            red_flag=0;
            return;
          }
          else {
              myTimer->stop();
              pac_timer->stop();
              end = new QMessageBox("end","你輸了廢物",QMessageBox::Information,
                                    QMessageBox::Ok | QMessageBox::Default,
                                    QMessageBox::Cancel | QMessageBox::Escape
                                    ,0);

              end->show();
              return;
          }


      }


      if((orange_x/33)==(coor_x/33) && (orange_y/32)==(coor_y/32))
      {
          if(orange_flag==1)
          {


            label5->setGeometry(403,348,60,60);
            orange_x=370;
            orange_y=316;

            score+=50;
            QString str = QString::number(score);
            dashboard->display(str);

            QMovie *movie5 =new QMovie(":/new/prefix1/orange.gif");
            label5->setMovie(movie5);
            movie5->start();


            orange_flag=0;

            return;
          }
          else if(orange_flag==0){
              myTimer->stop();
              pac_timer->stop();
              end = new QMessageBox("end","你輸了廢物",QMessageBox::Information,
                                    QMessageBox::Ok | QMessageBox::Default,
                                    QMessageBox::Cancel | QMessageBox::Escape
                                    ,0);

              end->show();

              //防止他停在那邊跳針
              orange_flag=2;
              return;
          }


      }


      if((pink_x/33)==(coor_x/33) && (pink_y/32)==(coor_y/32))
      {
          if(pink_flag)
          {

            label4->setGeometry(403,348,60,60);
            pink_x=403;
            pink_y=348;

            score+=50;
            QString str = QString::number(score);
            dashboard->display(str);


            QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
            label4->setMovie(movie4);
            movie4->start();


            pink_flag=0;
            return;
          }
          else {
              myTimer->stop();
              pac_timer->stop();
              end = new QMessageBox("end","你輸了廢物",QMessageBox::Information,
                                    QMessageBox::Ok | QMessageBox::Default,
                                    QMessageBox::Cancel | QMessageBox::Escape
                                    ,0);

              end->show();
              return;
          }

      }








}
ghost::~ghost()
{

}
