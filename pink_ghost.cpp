#include"ghost.h"
#include"ui_mainwindow.h"
void ghost::pink_ghost()
{
    if(stop);
    else {

        //qDebug()<<"i am ghost"<<endl;

        int i=pink_x/33;
        int j=pink_y/32;
        //讓他可議一直保持同個方向不會跳針
        //int direction_y;//1上 -1下
        //int direction_x;//1右 -1左
        pink_direction=p_Rand_direct(i,j);


        //qDebug()<<green_direction<<endl;

        //上
       if(j-1>=0 && move[i][j-1]==1 && pink_direction=='W')
       {

           pink_y-=32;

           label4->setGeometry(pink_x,pink_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }




        //右
       //qDebug()<<i<<" "<<j<<" "<<move[i-1][j]<<endl;
       if(i+1<26 && move[i+1][j]==1 && pink_direction=='D')
       {
           pink_x+=33;

           label4->setGeometry(pink_x,pink_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }



        //下
       if(j+1<29 && move[i][j+1]==1 && pink_direction=='S')
       {
           pink_y+=32;

           label4->setGeometry(pink_x,pink_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }




       if(i-1>=0 && move[i-1][j]==1 && pink_direction=='A')
       {
           pink_x-=32;
           label4->setGeometry(pink_x,pink_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }
    }





}
char ghost::p_Rand_direct(int i, int j)
{
    if((move[i+1][j]==0 || i+1>25) && pink_direction=='D')
    {
        //上下
        if(move[i][j-1]==1 && move[i][j+1]==1)
        {
            int r=(rand()%2)+1;
            if(r==1)
                return 'S';
            else if(r==2)
                return 'W';



        }
        //上
        else if(move[i][j-1]==1 && (move[i][j+1]==0 || j+1>28))
        {
           return 'W';


        }
        //下
        else if((move[i][j-1]==0 || j-1<0) && move[i][j+1]==1)
        {
            return 'S';
        }




    }
    else if((move[i-1][j]==0 || i-1<0)&& pink_direction=='A')
    {
        //qDebug()<<"in here!!!"<<endl;
        //往上下
        if(move[i][j-1]==1 && move[i][j+1]==1)
        {
            int r=(rand()%2)+1;
            if(r==1)
                return 'W';
            else if(r==2)
                return 'S';


        }
        //上
        else if(move[i][j-1]==1 && (move[i][j+1]==0 || j+1>28))
        {

                return 'W';
        }
        //下
        else if((move[i][j-1]==0 || j-1<0) && move[i][j+1]==1)
        {
                return 'S';
        }


    }
    else if((move[i][j-1]==0 || j-1<0) && pink_direction=='W')
    {
        //左右
        if(move[i-1][j]==1 && move[i+1][j]==1)
        {
            int r=(rand()%2)+1;
            if(r==1)
                return 'A';
            else if(r==2)
                return 'D';

        }
        //左
        else if(move[i-1][j]==1 && (move[i+1][j]==0 || i+1>25))
        {

                return 'A';
        }
        //右
        else if((move[i-1][j]==0 || i-1<0) && move[i+1][j]==1)
        {

                return 'D';
        }


    }
    else if((move[i][j+1]==0 || j+1>28) && pink_direction=='S')
    {
        //左右
        if(move[i-1][j]==1 && move[i+1][j]==1)
        {
            int r=(rand()%2)+1;
            if(r==1)
                return 'A';
            else if(r==2)
                return 'D';

        }
        //左
        else if(move[i-1][j]==1 && (move[i+1][j]==0 || i+1>25))
        {

                return 'A';



        }
        //右
        else if((move[i-1][j]==0 || i-1<0) && move[i+1][j]==1)
        {

                return 'D';




        }


    }
    return pink_direction;
}
