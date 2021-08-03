#include<ghost.h>
#include<ui_mainwindow.h>
void ghost::red_ghost()
{
    if(stop);
    else {
        //cross wall
        if(red_x==7)
        {
            red_x=832;
        }
        int i=red_x/33;
        int j=red_y/32;
        //qDebug()<<red_x<<" "<<red_y<<endl;

        if(move[i-1][j]==1)
        {
            red_x-=33;
            label3->setGeometry(red_x,red_y,60,60);
            //QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
            //movie3->start();
            return;
        }
        else if(move[i-1][j]==0 && move[i][j+1]==1)
        {
            if(i==17 && move[i][j-1]==1)
            {
                red_y-=32;
                label3->setGeometry(red_x,red_y,60,60);
                //QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
                //movie3->start();
                return;
            }
            else
            {
                red_y+=32;
                label3->setGeometry(red_x,red_y,60,60);
                //QMovie *movie3 =new QMovie(":/new/prefix1/red.gif");
                //movie3->start();
                return;
            }

        }
    }




}
