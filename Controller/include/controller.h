#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

struct GraphNode {}; // Структура комнаты
struct GraphConnection {}; // Структура соединения

namespace Polaris
{

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller( QObject *parent = nullptr );

private:
    GraphNode a_selected_node_;
    GraphNode b_selected_node_;
    GraphConnection selected_connection_;

signals:
    void AddNode( GraphNode node ); // Сигналы для Model
    void AddConnection( GraphNode a_node, GraphNode b_node );
    void MoveNode( GraphNode node );
    void DeleteNode( GraphNode node );
    void DeleteConnection( GraphNode a_node, GraphNode b_node );
    void FindRoute( GraphNode a_node, GraphNode b_node );

public slots:
    void SetSelectedNode( int node_id ); // Обработка сигналов из View
    void SetSelectedConnection( int connection_id );
    void SaveNewNode( GraphNode node );
    void SaveNewConnection( GraphConnection connection );
};

} // namespace Polaris

#endif // CONTROLLER_H
