#include "include/view_controller.h"

Polaris::ViewController::ViewController()
{
}

std::pair< int, int > Polaris::ViewController::GetNodeIds()
{
    std::pair< int, int > pair = { a_node_data_.node_id_, b_node_data_.node_id_ };
    return pair;
}

std::pair< std::pair< int, int >, std::pair< int, int > > Polaris::ViewController::GetNodeCoords()
{
}

void Polaris::ViewController::SetSelectedNode( int node_id )
{
}

void Polaris::ViewController::SetNodeCoordinates( int x, int y )
{
}

void Polaris::ViewController::SetNodesCoordinates( int a_x, int a_y, int b_x, int b_y )
{
}
