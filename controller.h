#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <mainwindow.h>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void AddNode(GraphNode node);
    void AddConnection(GraphNode a_node, GraphNode b_node);
    void MoveNode(GraphNode node/* And some meta */);
    void DeleteNode(GraphNode node);
    void DeleteConnection(GraphConnection connection);
    void FindRoute(GraphNode a_node, GraphNode b_node);

signals:

public slots:
};

#endif // CONTROLLER_H
