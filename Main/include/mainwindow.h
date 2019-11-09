#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "../../CView/include/cview.h"

namespace Polaris
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

private:
    CGraphicsView * view;

    QPushButton * add_button_;
    QPushButton * delete_button_;
    QPushButton * move_button_;
    QPushButton * find_route_button_;
    QPushButton * change_floor_button_;

signals:

public slots:
};

} // namespace Polaris

#endif // MAINWINDOW_H
