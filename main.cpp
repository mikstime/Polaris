#include <QApplication>

#include "Main/include/mainwindow.h"
#include "Controller/include/graph_controller.h"

int main( int argc, char * argv[] )
{
    QApplication app( argc, argv );

    // Creating Model object
    auto * model = new Polaris::ModelInterface;

    // Creating GraphController object
    auto * graph_controller = new Polaris::GraphController( model );

    // Creating MainWindow object
    auto * main_window = new Polaris::MainWindow( graph_controller, model );
    main_window->show();

    return app.exec();
}
