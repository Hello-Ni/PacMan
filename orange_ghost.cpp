#include"ghost.h"

void ghost::orange_ghost()
{

    if(stop);
    else {
        int i=orange_x/33;
        int j=orange_y/32;
        //讓他可議一直保持同個方向不會跳針
        //int direction_y;//1上 -1下
        //int direction_x;//1右 -1左
        o_chase_direct(i,j);


        //qDebug()<<green_direction<<endl;

        //上
       if(j-1>=0 && move[i][j-1]==1 && orange_direction=='W')
       {

           orange_y-=32;

           label5->setGeometry(orange_x,orange_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }




        //右
       //qDebug()<<i<<" "<<j<<" "<<move[i-1][j]<<endl;
       if(i+1<26 && move[i+1][j]==1 && orange_direction=='D')
       {
           orange_x+=33;

           label5->setGeometry(orange_x,orange_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }



        //下
       if(j+1<29 && move[i][j+1]==1 && orange_direction=='S')
       {
           orange_y+=32;

           label5->setGeometry(orange_x,orange_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }




       if(i-1>=0 && move[i-1][j]==1 && orange_direction=='A')
       {
           orange_x-=32;
           label5->setGeometry(orange_x,orange_y,60,60);
           //QMovie *movie4 =new QMovie(":/new/prefix1/pink.gif");
           //movie4->start();
           return;
       }
    }


}
void ghost::o_chase_direct(int i,int j)
{
    int pac_i=coor_x/33;
    int pac_j=coor_y/32;
    if(keyboard=='D')
    {
        if(pac_i>i && move[i+1][j]==1)
        {
            orange_direction='D';
        }
        else if(pac_i<i && move[i-1][j]==1)
        {
            orange_direction='A';
        }
        else {
            if(pac_j>j && move[i][j+1]==1)
                orange_direction='S';
            else if(pac_j<j && move[i][j-1]==1)
                orange_direction='W';
        }
    }

    if(keyboard=='A')
    {
        if(pac_i<i && move[i-1][j]==1)
        {
            orange_direction='A';
        }
        else if(pac_i>i && move[i+1][j]==1)
        {
            orange_direction='D';
        }
        else {
            if(pac_j>j && move[i][j+1]==1)
                orange_direction='S';
            else if(pac_j<j && move[i][j-1]==1)
                orange_direction='W';
        }
    }

    if(keyboard=='W')
    {
        if(pac_j>j && move[i][j+1]==1)
        {
            orange_direction='S';
        }
        else if(pac_j<j && move[i][j-1]==1)
        {
            orange_direction='W';
        }
        else{
            if(pac_i>i && move[i+1][j]==1)
                orange_direction='D';
            else if(pac_i<i && move[i-1][j]==1)
                orange_direction='A';
        }
    }
    if(keyboard=='S')
    {
        if(pac_j<j && move[i][j-1]==1)
        {
            orange_direction='W';
        }
        else if(pac_j>j && move[i][j+1]==1)
        {
            orange_direction='S';
        }
        else{
            if(pac_i>i && move[i+1][j]==1)
                orange_direction='D';
            else if(pac_i<i && move[i-1][j]==1)
                orange_direction='A';
        }
    }

}
