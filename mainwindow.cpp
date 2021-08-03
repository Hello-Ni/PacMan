#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(1200,1000);
    button1 = new QPushButton(this);
    button1->setGeometry(950,800,100,50);
    button1->setText("開始遊戲");
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<29;++j)
        {
            dot[i][j]=1;
            move[i][j]=0;
        }
    }

    count_pacman=0;

    //my packman
    label1 = new QLabel(this);
    label1->setGeometry(403,540,60,60);
    label1->setScaledContents(true);//自適應大小


    //pacman move
    myTimer = new QTimer(this);
    //pac movie
    pac_timer = new QTimer(this);

    //showtime
    Timer = new QTimer(this);


    pac_timer->start(50);

    //這裡要設和鬼不同毫秒
    myTimer->start(300);
    Timer->start(1000);




    //算分數的
    QFont ft;
    ft.setPointSize(40);
    lab_score = new QLabel(this);
    lab_score->setGeometry(950,100,150,100);
    lab_score->setFont(ft);
    lab_score->setText("score:");
    lab_score->setScaledContents(true);//自適應大小
    dashboard = new QLCDNumber(this);
    dashboard->setGeometry(1100,100,100,100);
    dashboard->setDigitCount(4);



    myLCDNumber =  new QLCDNumber(this);
    myLCDNumber->setGeometry(950,900,100,100);
    myLCDNumber->setDigitCount(8);//設定位數

    srand(5);

    keyboard='D';

    for(int i=0;i<4;++i)
    {
        big_dick[i]=1;
    }

    coor_x=403;
    coor_y=540;

    connect(myTimer,SIGNAL(timeout()),this,SLOT(To_move()));

    connect(pac_timer,SIGNAL(timeout()),this,SLOT(pacman_movie()));
    connect(Timer,SIGNAL(timeout()),this,SLOT(showtime()));




    connect(button1, SIGNAL(clicked(bool)), this,SLOT(move_coordinate()));
}
void MainWindow::set_move()
{


    coor_x=403;
    coor_y=540;
    //qDebug()<<"coor_x="<<coor_x<<"coor_y="<<coor_y<<endl;

}
void MainWindow::pacman_movie()
{
   ++count_pacman;
   if(keyboard=='D')
   {
       switch (count_pacman) {
            case 1:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(1).png");
                    label1->setPixmap(pixmap);
                    break;
                }
            case 2:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(2).png");
                    label1->setPixmap(pixmap);
                    break;
                }
            case 3:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(3).png");
                    label1->setPixmap(pixmap);
                    break;
                }
            case 4:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(4).png");
                    label1->setPixmap(pixmap);
                    break;
                }
       }
       if(count_pacman==4)
            count_pacman=0;
   }
   if(keyboard=='S')
   {
       switch (count_pacman) {
            case 1:
                {

                    QPixmap pixmap(":/new/prefix1/pacman(1).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(90);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;

                }
            case 2:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(2).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(90);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 3:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(3).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(90);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 4:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(4).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(90);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
       }
       if(count_pacman==4)
            count_pacman=0;
   }
   if(keyboard=='A')
   {
       switch (count_pacman) {
            case 1:
                {

                    QPixmap pixmap(":/new/prefix1/pacman(1).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(180);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;

                }
            case 2:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(2).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(180);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 3:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(3).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(180);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 4:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(4).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(180);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
       }
       if(count_pacman==4)
            count_pacman=0;
   }
   if(keyboard=='W')
   {
       switch (count_pacman) {
            case 1:
                {

                    QPixmap pixmap(":/new/prefix1/pacman(1).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(270);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;

                }
            case 2:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(2).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(270);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 3:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(3).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(270);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
            case 4:
                {
                    QPixmap pixmap(":/new/prefix1/pacman(4).png");
                    QMatrix matrix;     //定義矩陣
                    matrix.rotate(270);//旋轉角度
                    label1->setPixmap(pixmap.transformed(matrix,Qt::SmoothTransformation));
                    break;
                }
       }
       if(count_pacman==4)
            count_pacman=0;
   }




}

void MainWindow::showtime()
{
    QTime time = QTime::currentTime();

    QString text=time.toString("hh,mm,ss"); //設定顯示時間格式
    myLCDNumber->display(text);
}
void MainWindow::keyPressEvent(QKeyEvent *k)
{

    //right
    //if(coor_x+33<=832)
    //{
        if(k->key()==Qt::Key_D && move[(coor_x+33)/33][coor_y/32]==1)
        {
            //qDebug()<<(coor_x+33)<<" "<<coor_y<<endl;
            keyboard='D';
        }


    //}

    //left
    //if(coor_x-33>=7)
    //{
        if(k->key()==Qt::Key_A && move[(coor_x-33)/33][coor_y/32]==1)
            keyboard='A';


    //}

    //up
    //if(coor_y+33<=924)
    //{
        if(k->key()==Qt::Key_W && move[coor_x/33][(coor_y-32)/32]==1)
            keyboard='W';

    //}



    //down
    //if(coor_y-33>=28)
    //{
        if(k->key()==Qt::Key_S && move[coor_x/33][(coor_y+32)/32]==1)
            keyboard='S';

    //}





}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(QRect(0,0,900,1000),QImage(":/new/prefix1/map.png"));


    for(int i=0;i<26;++i)
    {
        for(int j=0;j<29;++j)
        {
            painter.setBrush(Qt::yellow);
            switch (i) {
                case 0:
                    if((j<8 || j>18) && j!=23 && j!=24 && dot[i][j]==1)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 5:
                    if(dot[i][j]==1 && j!=26 && j!=27)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 8:
                    if(dot[i][j]==1 && (j==5 || j==6 || (j>9 && j<20) || (j>21 && j<26)|| j==28))
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 11:
                    if(dot[i][j]==1 && (j<8 || j>18) && j!=5 && j!=6 && j!=23 && j!=24)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 17:
                    if(dot[i][j]==1 && (j==5 || j==6 || (j>9 && j<20) || (j>21 && j<26)|| j==28))
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 25:
                    if((j<8 || j>18) && j!=23 && j!=24 && dot[i][j]==1)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 20:
                    if(dot[i][j]==1 && j!=26 && j!=27)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 14:
                    if(dot[i][j]==1 && (j<8 || j>18) && j!=5 && j!=6 && j!=23 && j!=24)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;

            }
            switch(j)
            {
                case 0:
                    if(dot[i][j]==1 && i!=12 && i!=13)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 4:
                    if(dot[i][j]==1)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 7:
                    if(dot[i][j]==1 && i!=6 && i!=7 && i!=12 && i!=13 && i!=19 && i!=18)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 19:
                    if(dot[i][j]==1 && i!=12 && i!=13)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 22:
                    if(dot[i][j]==1 && i!=3 && i!=4 && i!=22 && i!=21)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 25:
                    if(dot[i][j]==1 && i!=6 && i!=7 && i!=12 && i!=13 && i!=19 && i!=18)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;
                case 28:
                    if(dot[i][j]==1)
                        painter.drawEllipse(40+33*i,60+32*j,10,10);
                    break;

            }
            //painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(dot[i][j]==1 && (i==2 || i==23) && (j==23 || j==24))
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(dot[i][j]==1 && (i==11 || i==14) && j>7 && j<11)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(dot[i][j]==1 && j==10 && i<18 && i>7)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(dot[i][j]==1 && j==16 && i<18 && i>7)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(dot[i][j]==1 && j==13 && (i<9 || i>16))
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            //大力丸
            painter.setBrush(Qt::red);
            if(i==0 && j==0 && big_dick[0]==1)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(i==25 && j==0 && big_dick[1]==1)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(i==25 && j==28 && big_dick[2]==1)
                painter.drawEllipse(40+33*i,60+32*j,10,10);
            if(i==0 && j==28 && big_dick[3]==1)
                painter.drawEllipse(40+33*i,60+32*j,10,10);


        }
    }




    //painter.setBrush(Qt::white);
   // painter.drawEllipse(40+coor_x,60,60,60);






}

MainWindow::~MainWindow()
{
    delete ui;
}
