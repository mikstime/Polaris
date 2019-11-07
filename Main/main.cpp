#include "include/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Polaris::MainWindow w;
    w.show();
    return a.exec();
}
