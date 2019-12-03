#ifndef MAINAPP_GRAPH_CONTROLLER_H
#define MAINAPP_GRAPH_CONTROLLER_H

#include <vector>
#include "controller.h"

namespace Polaris
{

class GraphController : public Controller
{
public:
    GraphController();
    void AddNode( std::vector< int > node_coords ) override;
    void AddConnection( int a_node_id, int b_node_id ) override;
    void DeleteNode( int node_id ) override;
    void DeleteConnection( int a_node_id, int b_node_id ) override;
    void MoveNode( int node_id, std::vector< int > node_coords ) override;
    void ChangeNode( int node_id ) override;
    void FindRoute( int a_node_id, int b_node_id ) override;
    void ChangeFloor( int floor_number ) override;

private:
};

} // namespace Polaris

#endif //MAINAPP_GRAPH_CONTROLLER_H
