#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

struct GraphNode {}; // Структура комнаты
struct GraphConnection {}; // Структура соединения

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    GraphNode a_selected_node_;
    GraphNode b_selected_node_;
    GraphConnection selected_connection_;

signals:
    void ChangedData();

public slots:
    void SetSelectedNodes(int node_id) {} // Обработка сигналов из View
    void SetSelectedConnection(int connection_id) {}

    void AddButtonClick() {} // Обработка сигналов нажатия на кнопки
    void DeleteButtonClick() {}
    void MoveButtonClick() {}
    void FindRouteButtonClick() {}
    void ChangeFloorButtonClick() {}
};
#endif // MAINWINDOW_H
