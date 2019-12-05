#ifndef GRAPH_CONTROLLER_H
#define GRAPH_CONTROLLER_H

#include <utility>

#include "GraphNode/GraphNode.h"
#include "Meta/Meta.h"
#include "GraphConnection/GraphConnection.h"
#include "include/node_form.h"

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

class GraphController
{
public:
    /**
     * Constructor
     * @param model - pointer to Model object
     */
    GraphController( ModelInterface * model );
    /**
     * Add node to Model
     * @param node_coords - New node coordinates
     */
    void AddNode( const std::pair< int, int > & node_coords );
    /**
     * Add connection to Model
     * @param a_node_id - First node id
     * @param b_node_id - Second node id
     */
    void AddConnection( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id );
    /**
     * Delete node from Model
     * @param node_id - Deleted node id
     */
    void DeleteNode( const Polaris::Id & node_id );
    /**
     * Delete connection from Model
     * @param a_node_id -
     * @param b_node_id
     */
    void DeleteConnection( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id );
    /**
     * Change node coordinates in Model
     * @param node_id - Movable node id
     * @param node_coords - Movable node new coordinates
     */
    void MoveNode( const Polaris::Id & node_id, const std::pair< int, int > & node_coords );
    /**
     * Changing node Meta
     * @param node_id - Changing node id
     */
    void ChangeNode( const Polaris::Id & node_id, const Meta & meta );
    /**
     * Find route from node to another node
     * @param a_node_id - Start node
     * @param b_node_id - Finish node
     */
    void FindRoute( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id );
    /**
     * Changing floor
     * @param floor_number - New floor number
     */
    void ChangeFloor( const int & floor_number );

private:
    ModelInterface * model_;

    NodeForm * form_;
};

} // namespace Polaris

#endif // GRAPH_CONTROLLER_H
