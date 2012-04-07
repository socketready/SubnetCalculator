#include <QtGui/QApplication>
#include <QPushButton>
#include "mainwindow.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    int width = w.width();
    int height = w.height();

    cout << width << "x" << height << endl;

    return a.exec();
}

