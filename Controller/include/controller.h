#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <gtest/gtest_prod.h>

struct GraphNode {}; // Структура комнаты
struct GraphConnection {}; // Структура соединения

namespace Polaris
{

class Controller : public QObject
{
    Q_OBJECT

public:
    explicit Controller( QObject * parent = nullptr );

protected:
    FRIEND_TEST( ::Controller, SetSelectedNode );
    FRIEND_TEST( ::Controller, SetSelectedConnection );
    int a_selected_node_id_;
    int b_selected_node_id_;
    int selected_connection_id_;

signals:
    void AddNode( const GraphNode & node ); // Сигналы для Model
    void AddConnection( const GraphNode & a_node, const GraphNode & b_node );
    void MoveNode( const GraphNode & node );
    void DeleteNode( const GraphNode & node );
    void DeleteConnection( const GraphNode & a_node, const GraphNode & b_node );
    void FindRoute( const GraphNode & a_node, const GraphNode & b_node );

public slots:
    void SetSelectedNode( int node_id ); // Обработка сигналов из View
    void SetSelectedConnection( int connection_id );
    void SaveNewNode( GraphNode & node );
    void SaveNewConnection( GraphConnection & connection );
};

} // namespace Polaris

#endif // CONTROLLER_H
