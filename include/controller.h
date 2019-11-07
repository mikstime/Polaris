#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <include/mainwindow.h>

namespace Polaris
{

class CController : public QObject
{
    Q_OBJECT
public:
    explicit CController(QObject *parent = nullptr);
    void AddNode(SGraphNode node);
    void AddConnection(SGraphNode a_node, SGraphNode b_node);
    void MoveNode(SGraphNode node);
    void DeleteNode(SGraphNode node);
    void DeleteConnection(SGraphConnection connection);
    void FindRoute(SGraphNode a_node, SGraphNode b_node);

private:
    SGraphNode a_selected_node_;
    SGraphNode b_selected_node_;
    SGraphConnection selected_connection_;

signals:
    void DataChanged();

public slots:
    void SetSelectedNodes(int node_id); // Обработка сигналов из View
    void SetSelectedConnection(int connection_id);
    void SaveChangedData(SGraphNode node);
};

}

#endif // CONTROLLER_H
