#ifndef MAINAPP_GRAPH_CONTROLLER_H
#define MAINAPP_GRAPH_CONTROLLER_H

#include <utility>
#include "../../Model/include/ModelInterface/ModelInterface.h"
#include "controller.h"
#include "../../Utils/typedefs.h"

namespace Polaris
{

class GraphController : public Controller
{
public:
    GraphController( ModelInterface * model );
    void AddNode( std::pair< int, int > node_coords ) override;
    void AddConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    void DeleteNode( Polaris::Id node_id ) override;
    void DeleteConnection( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    void MoveNode( Polaris::Id node_id, std::pair< int, int > node_coords ) override;
    void ChangeNode( Polaris::Id node_id ) override;
    void FindRoute( Polaris::Id a_node_id, Polaris::Id b_node_id ) override;
    void ChangeFloor( int floor_number ) override;

private:
    ModelInterface * model_;
};

} // namespace Polaris

#endif //MAINAPP_GRAPH_CONTROLLER_H
