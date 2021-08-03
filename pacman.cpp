#include<mainwindow.h>
#include<ui_mainwindow.h>
#include<ghost.h>
void MainWindow::move_coordinate()
{
    qDebug()<<"set can move point"<<endl;
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<29;++j)
        {
            switch (i) {
                case 0:
                    if((j<8 || j>18) && j!=23 && j!=24)
                         move[i][j]=1;
                    break;
                case 5:
                    if(dot[i][j]==1 && j!=26 && j!=27)
                          move[i][j]=1;
                    break;
                case 8:
                    if(dot[i][j]==1 && (j==5 || j==6 || (j>9 && j<20) || (j>21 && j<26)|| j==28))
                         move[i][j]=1;
                    break;
                case 11:
                    if((j<8 || j>18) && j!=5 && j!=6 && j!=23 && j!=24)
                         move[i][j]=1;
                    break;
                case 17:
                    if((j==5 || j==6 || (j>9 && j<20) || (j>21 && j<26)|| j==28))
                         move[i][j]=1;
                    break;
                case 25:
                    if((j<8 || j>18) && j!=23 && j!=24)
                         move[i][j]=1;
                    break;
                case 20:
                    if(j!=26 && j!=27)
                         move[i][j]=1;
                    break;
                case 14:
                    if((j<8 || j>18) && j!=5 && j!=6 && j!=23 && j!=24)
                         move[i][j]=1;
                    break;

            }
            switch(j)
            {
                case 0:
                    if(i!=12 && i!=13)
                         move[i][j]=1;
                    break;
                case 4:

                    move[i][j]=1;
                    break;
                case 7:
                    if(i!=6 && i!=7 && i!=12 && i!=13 && i!=19 && i!=18)
                         move[i][j]=1;
                    break;
                case 19:
                    if(i!=12 && i!=13)
                         move[i][j]=1;
                    break;
                case 22:
                    if(i!=3 && i!=4 && i!=22 && i!=21)
                         move[i][j]=1;
                    break;
                case 25:
                    if(i!=6 && i!=7 && i!=12 && i!=13 && i!=19 && i!=18)
                         move[i][j]=1;
                    break;
                case 28:

                    move[i][j]=1;

                    break;

            }
            //painter.drawEllipse(40+33*i,60+32*j,10,10);
            if((i==2 || i==23) && (j==23 || j==24))
                move[i][j]=1;
            if((i==11 || i==14) && j>7 && j<11)
                move[i][j]=1;
            if(j==10 && i<18 && i>7)
                move[i][j]=1;
            if(j==16 && i<18 && i>7)
                move[i][j]=1;
            if(j==13 && (i<9 || i>16))
                move[i][j]=1;


        }
    }
}
void MainWindow::cross_wall()
{
    qDebug()<<"i can cross wall!!";
    if(keyboard=='D' && coor_x>=820)
        coor_x=-26;


    else if (keyboard=='A' && coor_x==7) {
        coor_x=864;
    }
}
void MainWindow::To_move()
{
   // qDebug()<<"coor_x="<<coor_x<<"coor_y="<<coor_y<<endl;
        int i,j;
        //如果我的下一個座標move_coordinate為0則不能移動
        if(keyboard=='D'  && coor_x+33<=832)
        {

            i=(coor_x+33)/33;
            j=(coor_y/32);
            if(move[i][j]==1)
            {

                coor_x+=33;
                label1->setGeometry(coor_x,coor_y,60,60);
                /*QMovie *movie =new QMovie(":/new/prefix1/giphy.gif");
                label1->setMovie(movie);
                movie->start();
                movie->setSpeed(100);*/


                //檢測是否可以穿牆了
                if(coor_y==444 && coor_x>=820)
                {

                    cross_wall();
                }


                //eat_rule
                eat_rule(i,j);
            }

        }


        if(keyboard=='A' && coor_x-33>=7)
        {
            i=(coor_x-33)/33;
            j=coor_y/32;
            if(move[i][j]==1)
            {
                coor_x-=33;
                label1->setGeometry(coor_x,coor_y,60,60);
                /*QMovie *movie =new QMovie(":/new/prefix1/giph(left.gif");
                label1->setMovie(movie);
                movie->start();
                movie->setSpeed(100);*/



                if(coor_y==444 && coor_x==7)
                    cross_wall();


                eat_rule(i,j);
            }

        }

        if(keyboard=='W' && coor_y-32>=28)
        {
            i=coor_x/33;
            j=(coor_y-32)/32;
            if(move[i][j]==1)
            {
                coor_y-=32;
                label1->setGeometry(coor_x,coor_y,60,60);
                /*QMovie *movie =new QMovie(":/new/prefix1/giphy(up).gif");
                label1->setMovie(movie);
                movie->start();
                movie->setSpeed(100);*/
                eat_rule(i,j);
            }

        }
        if(keyboard=='S' && coor_y+32<=924)
        {


            i=coor_x/33;
            j=(coor_y+32)/32;
            if(move[i][j]==1)
            {
                coor_y+=32;
                label1->setGeometry(coor_x,coor_y,60,60);
                /*QMovie *movie =new QMovie(":/new/prefix1/giphy (down).gif");
                label1->setMovie(movie);
                movie->start();
                movie->setSpeed(100);*/

                eat_rule(i,j);

            }

        }

        //撞牆







}
void MainWindow::eat_rule(int i,int j)
{
    if(dot[i][j]==1)
    {

        dot[i][j]=0;
        score+=10;
        QString str = QString::number(score);
        dashboard->display(str);

    }
    if(i==0 && j==0 && big_dick[0]==1)
    {
        big_dick[0]=0;

    }
    if(i==25 && j==0 && big_dick[1]==1)
        big_dick[1]=0;
    if(i==25 && j==28 && big_dick[2]==1)
        big_dick[2]=0;
    if(i==0 && j==28 && big_dick[3]==1)
        big_dick[3]=0;
    repaint();




}


