#include "mainwindow.h"
#include <QApplication>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    cout << "here" << endl;
    QApplication a(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}
