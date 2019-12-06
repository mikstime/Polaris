#include "include/graph_controller.h"

Polaris::GraphController::GraphController( Polaris::ModelInterface * model ) :
    model_( model )
{
}

void Polaris::GraphController::AddNode( const std::pair< int, int > & node_coords )
{
    // Creating node
    GraphNode new_node = GraphNode();
    model_->AddNode( new_node );
    Polaris::Id new_node_id = new_node.GetId();
}

void Polaris::GraphController::AddConnection( const Id & a_node_id, const Id & b_node_id )
{
    Price price = 1; // TODO: Add price param
    GraphConnection new_connection = GraphConnection( a_node_id, b_node_id, price );
    model_->AddConnection( new_connection );
}

void Polaris::GraphController::DeleteNode( const Polaris::Id & node_id )
{
    model_->RemoveNode( node_id );
}

void Polaris::GraphController::DeleteConnection( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id )
{
    model_->RemoveConnection( a_node_id, b_node_id );
}

void Polaris::GraphController::MoveNode( const Polaris::Id & node_id, const std::pair< int, int > & node_coords )
{
    Meta meta;
    meta.graph_node_id = node_id;
    meta.x = node_coords.first;
    meta.y = node_coords.second;
    model_->ChangeMeta( node_id, meta );
}

void Polaris::GraphController::ChangeNode( const Polaris::Id & node_id, const Meta & meta )
{
    // TODO: ChangeNode definition
}

void Polaris::GraphController::FindRoute( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id )
{
    model_->FindPath( a_node_id, b_node_id );
}

void Polaris::GraphController::ChangeFloor( const int & floor_number )
{
    // TODO: ChangeFloor definition
}
