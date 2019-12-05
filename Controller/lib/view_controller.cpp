#include <include/view_controller.h>

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
