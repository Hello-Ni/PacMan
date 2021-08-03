#include"ghost.h"
#include"ui_mainwindow.h"

void ghost::green_ghost()
{


    if(stop);
    else {
        //qDebug()<<"i am ghost"<<endl;

        int i=green_x/33;
        int j=green_y/32;
        //讓他可議一直保持同個方向不會跳針
        //int direction_y;//1上 -1下
        //int direction_x;//1右 -1左
        green_direction=g_Rand_direct(i,j);


        //qDebug()<<green_direction<<endl;

        //上
       if(j-1>=0 && move[i][j-1]==1 && green_direction=='W')
       {

           green_y-=32;

           label2->setGeometry(green_x,green_y,60,60);





       }




        //右
       //qDebug()<<i<<" "<<j<<" "<<move[i-1][j]<<endl;
       if(i+1<26 && move[i+1][j]==1 && green_direction=='D')
       {
           green_x+=33;

           label2->setGeometry(green_x,green_y,60,60);




           return;
       }



        //下
       if(j+1<29 && move[i][j+1]==1 && green_direction=='S')
       {
           green_y+=32;

           label2->setGeometry(green_x,green_y,60,60);





           return;
       }




       if(i-1>=0 && move[i-1][j]==1 && green_direction=='A')
       {
           green_x-=32;
           label2->setGeometry(green_x,green_y,60,60);







           return;
       }





    }


}
char ghost::g_Rand_direct(int i, int j)
{
    if((move[i+1][j]==0 || i+1>25) && green_direction=='D')
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
    else if((move[i-1][j]==0 || i-1<0)&& green_direction=='A')
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
    else if((move[i][j-1]==0 || j-1<0) && green_direction=='W')
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
    else if((move[i][j+1]==0 || j+1>28) && green_direction=='S')
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
    return green_direction;
}
