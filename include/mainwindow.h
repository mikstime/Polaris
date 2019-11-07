#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct SGraphNode {}; // Структура комнаты
struct SGraphConnection {}; // Структура соединения

namespace Polaris
{

class CMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    CMainWindow(QWidget *parent = nullptr);
    ~CMainWindow();

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
