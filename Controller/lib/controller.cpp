#include "include/controller.h"

Polaris::Controller::Controller( QObject * parent ) : QObject( parent )
{

}

void Polaris::Controller::SetSelectedNode( int node_id )
{

}

void Polaris::Controller::SetSelectedConnection( int connection_id )
{

}

void Polaris::Controller::SaveNewNode( GraphNode & node )
{

}

void Polaris::Controller::SaveNewConnection( GraphConnection & connection )
{

}

void Polaris::Controller::AddNode(const GraphNode &node)
{

}

void Polaris::Controller::AddConnection(const GraphNode &a_node, const GraphNode &b_node) {

}

void Polaris::Controller::MoveNode(const GraphNode &node) {

}

void Polaris::Controller::DeleteNode(const GraphNode &node) {

}

void Polaris::Controller::DeleteConnection(const GraphNode &a_node, const GraphNode &b_node) {

}

void Polaris::Controller::FindRoute(const GraphNode &a_node, const GraphNode &b_node) {

}

void Polaris::Controller::AddButtonClick()
{

}

void Polaris::Controller::DeleteButtonClick()
{

}

void Polaris::Controller::MoveButtonClick()
{

}

void Polaris::Controller::FindRouteButtonClick()
{

}

void Polaris::Controller::ChangeFloorButtonClick()
{

}
