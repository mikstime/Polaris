#ifndef MAINAPP_GRAPH_CONTROLLER_H
#define MAINAPP_GRAPH_CONTROLLER_H

#include <utility>
#include "Controller/include/controller.h"
#include "GraphNode/GraphNode.h"
#include "Meta/Meta.h"
#include "GraphConnection/GraphConnection.h"

namespace Polaris
{

class ModelInterface
{
public:
    void AddNode( GraphNode node ) {}
    void ChangeMeta( Id id, Meta meta ) {}
    void AddConnection( GraphConnection ) {}
    void RemoveNode( Id id ) {}
    void RemoveConnection( Id first_id, Id second_if ) {}
    void FindPath( Id first_id, Id second_id ) {}
};

class GraphController : public Controller
{
public:
    GraphController( ModelInterface * model );
    /**
     * Add node to Model
     * @param node_coords - New node coordinates
     */
    void AddNode( std::pair< int, int > node_coords ) override;
    /**
     * Add connection to Model
     * @param a_node_id - First node id
     * @param b_node_id - Second node id
     */
    void AddConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    /**
     * Delete node from Model
     * @param node_id - Deleted node id
     */
    void DeleteNode( Polaris::Id node_id ) override;
    /**
     * Delete connection from Model
     * @param a_node_id -
     * @param b_node_id
     */
    void DeleteConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    /**
     * Change node coordinates in Model
     * @param node_id - Movable node id
     * @param node_coords - Movable node new coordinates
     */
    void MoveNode( Polaris::Id node_id, std::pair< int, int > node_coords ) override;
    /**
     * Changing node Meta
     * @param node_id - Changing node id
     */
    void ChangeNode( Polaris::Id node_id ) override;
    /**
     * Find route from node to another node
     * @param a_node_id - Start node
     * @param b_node_id - Finish node
     */
    void FindRoute( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    /**
     * Changing floor
     * @param floor_number - New floor number
     */
    void ChangeFloor( int floor_number ) override;

private:
    ModelInterface * model_;
};

} // namespace Polaris

#endif //MAINAPP_GRAPH_CONTROLLER_H
