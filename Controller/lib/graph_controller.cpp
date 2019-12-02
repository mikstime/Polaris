#include "include/graph_controller.h"
#include "../../Utils/typedefs.h"

Polaris::GraphController::GraphController( Polaris::ModelInterface * model ) : model_( model )
{
}

void Polaris::GraphController::AddNode( std::pair< int, int > node_coords )
{
    // Creating node
    GraphNode new_node = GraphNode();
    model_->AddNode( new_node );
    Polaris::Id new_node_id = new_node.GetId();

    // Creating Meta
    Meta meta;
    meta.graph_node_id = new_node_id;
    meta.x = node_coords.first;
    meta.y = node_coords.second;
    // TODO: Add other params to meta
    model_->ChangeMeta( new_node_id, meta );
}

void Polaris::GraphController::AddConnection( Id a_node_id, Id b_node_id )
{
    Price price = 0; // TODO: Add price param
    GraphConnection new_connection = GraphConnection( a_node_id, b_node_id, price );
    model_->AddConnection( new_connection );
}

void Polaris::GraphController::DeleteNode( Polaris::Id node_id )
{
    model_->RemoveNode( node_id );
}

void Polaris::GraphController::DeleteConnection( Polaris::Id a_node_id, Polaris::Id b_node_id )
{
    model_->RemoveConnection( a_node_id, b_node_id );
}

void Polaris::GraphController::MoveNode( Polaris::Id node_id, std::pair< int, int > node_coords )
{
    Meta meta;
    meta.graph_node_id = node_id;
    meta.x = node_coords.first;
    meta.y = node_coords.second;
    model_->ChangeMeta( node_id, meta );
}

void Polaris::GraphController::ChangeNode( Polaris::Id node_id )
{
    // ???
}

void Polaris::GraphController::FindRoute( Polaris::Id a_node_id, Polaris::Id b_node_id )
{
    model_->FindPath( a_node_id, b_node_id );
}

void Polaris::GraphController::ChangeFloor( int floor_number )
{
    // ???
}
