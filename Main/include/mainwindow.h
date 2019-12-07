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
     * Default destructor
     */
    ~MainWindow() = default;

private:
    std::shared_ptr< GraphicView > view_;
    std::shared_ptr< ViewController > view_controller_;
    std::shared_ptr< NodeForm > node_form_;
    std::shared_ptr< ConnectionForm > connection_form_;
    std::shared_ptr< ModelInterface > model_;

    ViewSub * view_sub_;
    std::shared_ptr< QWidget > button_panel_;
    std::shared_ptr< ButtonClickHandler > button_click_handler_;

    QPushButton * add_button_;
    QPushButton * delete_button_;
    QPushButton * move_button_;
    QPushButton * change_button_;
    QPushButton * find_route_button_;
    QPushButton * floor_up_button_;
    QPushButton * floor_down_button_;

    void ConnectButtons();
};

} // namespace Polaris

#endif // MAINWINDOW_H
