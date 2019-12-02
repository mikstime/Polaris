#include <QApplication>

#include "Main/include/mainwindow.h"
#include "Controller/include/controller.h"
#include "Controller/include/view_controller.h"
#include "Controller/include/graph_controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Creating ViewController object
    auto * view_controller = new Polaris::ViewController;

    // Creating GraphController object
    auto * graph_controller = new Polaris::GraphController;

    // Creating MainWindow object
    auto * main_window = new Polaris::MainWindow( view_controller, graph_controller );
    main_window->show();

    return app.exec();
}
