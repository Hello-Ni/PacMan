#include"ghost.h"
#include"ui_mainwindow.h"

void ghost::strong()
{

   for(int i=0;i<4;++i)
   {
       if(big_dick[i]==0)
       {


           //已經吃過了
           big_dick[i]=2;
           repaint();
           QMovie *blue = new QMovie(":/new/prefix1/ghost blue.gif");
           label2->setMovie(blue);
           label3->setMovie(blue);
           label4->setMovie(blue);
           label5->setMovie(blue);

           blue->start();

           //避免memory leak

           //movie2->stop();
           //movie3->stop();
           /*delete movie2;
           delete movie3;
           delete movie4;
           delete movie5;
           movie2 = nullptr;
           movie3 = nullptr;
           movie4 = nullptr;
           movie5 = nullptr;*/



           green_flag=1;
           red_flag=1;
           pink_flag=1;
           orange_flag=1;
           big_flag=1;

           //disconnect(big_time,SIGNAL(timeout()),this,SLOT(strong_time()));

       }








   }

}
void ghost::strong_time()
{


    if(big_flag)
    {
        ++T;

        if(T==10)
        {
            qDebug()<<"disconnect successfully!!!!!!!!!"<<endl;
            T=0;
            //只有4次應該記憶體不會爆掉吧!?相信我的電腦
            if(green_flag)
            {
                QMovie *movie2 =new QMovie(":/new/prefix1/green.gif");
                label2->setMovie(movie2);
                movie2->start();
            }
            if(red_flag)
            {
                QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
                label3->setMovie(movie3);
                movie3->start();
            }

            if(pink_flag)
            {
                QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
                label4->setMovie(movie4);
                movie4->start();
            }

            if(orange_flag)
            {
                QMovie *movie5 =new QMovie(":/new/prefix1/orange.gif");
                label5->setMovie(movie5);
                movie5->start();
            }


            big_flag=0;

        }
    }

}
