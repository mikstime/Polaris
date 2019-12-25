#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpacerItem>

#include "include/view_controller.h"
#include "include/graph_controller.h"
#include "include/graphic_view.h"
#include "include/button_click_handler.h"
#include "include/connection_form.h"
#include "include/view_sub.h"
#include "include/ModelSubscriber/ModelSubscriber.h"

namespace Polaris
{

const short SIDE_PANEL_WIDTH = 200;
const short SIDE_PANEL_HEIGHT = 400;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param graph_controller - pointer to GraphController object
     * @param model - pointer to Model object
     * @param parent - pointer to parent object
     */
    MainWindow( GraphController * graph_controller, ModelInterface * model, QWidget * parent = nullptr );
    /**
     * Destructor
     */
    ~MainWindow();
    /**
     * Copy constructor
     */
    MainWindow( const MainWindow & ) = delete;
    /**
     * Copy assignment operator
     */
    MainWindow & operator=( const MainWindow & ) = delete;

private:
    // Pointers to other objects
    std::shared_ptr< GraphicView > view_;
    std::shared_ptr< ViewController > view_controller_;
    std::shared_ptr< NodeForm > node_form_;
    std::shared_ptr< ConnectionForm > connection_form_;
    std::shared_ptr< ModelInterface > model_;

    std::shared_ptr< ModelSubscriber > view_sub_;
    std::shared_ptr< QWidget > button_panel_;
    std::shared_ptr< ButtonClickHandler > button_click_handler_;

    std::unordered_map< std::string, QPushButton * > buttons_;

    void ConnectButtons();
};

} // namespace Polaris

#endif // MAINWINDOW_H
