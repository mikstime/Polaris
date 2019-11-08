#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Polaris
{

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow( QWidget *parent = nullptr );
    ~MainWindow();

signals:

public slots:
    void AddButtonClick(); // Обработка сигналов нажатия на кнопки
    void DeleteButtonClick();
    void MoveButtonClick();
    void FindRouteButtonClick();
    void ChangeFloorButtonClick();
};

} // namespace Polaris

#endif // MAINWINDOW_H
