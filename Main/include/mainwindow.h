#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct GraphNode {}; // Структура комнаты
struct GraphConnection {}; // Структура соединения

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

}

#endif // MAINWINDOW_H
