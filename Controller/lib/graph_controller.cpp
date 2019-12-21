#include "include/graph_controller.h"

#include <QDebug>

Polaris::GraphController::GraphController( Polaris::ModelInterface * model ) :
    model_( model )
{
}

int Polaris::GraphController::AddNode()
{
    // Creating node
    GraphNode new_node = GraphNode();
    model_->AddNode( new_node );
    return new_node.GetId();
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
    meta.coordinates.setX(node_coords.first);
    meta.coordinates.setY(node_coords.second);
    model_->ChangeMeta( node_id, meta );
}

void Polaris::GraphController::FindRoute( const Polaris::Id & a_node_id, const Polaris::Id & b_node_id )
{
    model_->FindPath( a_node_id, b_node_id );
}

void Polaris::GraphController::ChangeFloor( const int & floor_number )
{
    // TODO: RedrawFloor definition
}
