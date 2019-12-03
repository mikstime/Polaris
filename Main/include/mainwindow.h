#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include "CView/include/graphic_view.h"
#include "node_form.h"
#include "button_click_handler.h"
#include "Controller/include/view_controller.h"

namespace Polaris
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( ViewController * controller, QWidget * parent = nullptr );
    ~MainWindow();

private:
    GraphicView * graphic_view_;
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

signals:

public slots:
};

} // namespace Polaris

#endif // MAINWINDOW_H
