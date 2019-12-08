#ifndef GRAPH_CONTROLLER_H
#define GRAPH_CONTROLLER_H

#include <utility>
#include <memory>

#include "GraphNode/GraphNode.h"
#include "Meta/Meta.h"
#include "GraphConnection/GraphConnection.h"
#include "include/node_form.h"
#include "include/ModelInterface/ModelInterface.h"
#include "typedefs.h"

namespace Polaris
{

class GraphController
{
public:
    /**
     * Constructor
     * @param model - pointer to Model object
     */
    explicit GraphController( ModelInterface * model );
    /**
     * Add node to Model
     * @param node_coords - New node coordinates
     */
    int AddNode( const std::pair< int, int > & node_coords );
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
     * @param meta - New node meta
     */
    void FindRoute( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id );
    /**
     * Changing floor
     * @param floor_number - New floor number
     */
    void ChangeFloor( const int & floor_number );

private:
    // Pointer to Model object
    std::shared_ptr< ModelInterface > model_;
};

} // namespace Polaris

#endif // GRAPH_CONTROLLER_H
