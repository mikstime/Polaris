#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "include/view_controller.h"
#include "include/graph_controller.h"
#include "include/graphic_view.h"
#include "include/button_click_handler.h"

namespace Polaris
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * Constructor
     * @param view_controller - pointer to ViewController object
     * @param graph_controller - pointer to GraphController object
     * @param parent - pointer to parent object
     */
    MainWindow( ViewController * view_controller, GraphController * graph_controller, QWidget * parent = nullptr );
    /**
     * Default destructor
     */
    ~MainWindow() = default;

private:
    GraphicView * view;
    NodeForm * node_form_;

    QHBoxLayout * main_layout_;

    QVBoxLayout * button_layout_;

    QPushButton * add_button_;
    QPushButton * delete_button_;
    QPushButton * move_button_;
    QPushButton * change_button_;
    QPushButton * find_route_button_;
    QPushButton * floor_up_button_;
    QPushButton * floor_down_button_;

    ButtonClickHandler * button_click_handler_;

    void InitButtons();
};

} // namespace Polaris

#endif // MAINWINDOW_H
