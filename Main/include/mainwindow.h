#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "../../CView/include/cview.h"
#include "node_form.h"
#include "button_click_handler.h"
#include "../../Controller/include/view_controller.h"
#include "../../Controller/include/graph_controller.h"

namespace Polaris
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( ViewController * view_controller, GraphController * graph_controller, QWidget * parent = nullptr );
    ~MainWindow();

private:
    CGraphicsView * view;
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
