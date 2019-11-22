#include <QApplication>

#include "Main/include/mainwindow.h"
#include "Controller/include/controller.h"
#include "Controller/include/view_controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    auto * view_controller = new Polaris::ViewController;

    auto * main_window = new Polaris::MainWindow( view_controller );
    main_window->show();

    return app.exec();
}
