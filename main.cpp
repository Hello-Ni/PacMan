#include "mainwindow.h"
#include"ghost.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //memory leak
    MainWindow w,*poly=&w;
    //w.set_move();
    poly->set_move();

    ghost g;
    poly=&g;
    poly->set_move();
    g.show();



    return a.exec();
}

