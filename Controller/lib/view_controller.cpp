#include "include/view_controller.h"

Polaris::ViewController::ViewController( GraphicView * view ) : view_( view ), floor_number_( 1 ),
        first_node_( EMPTY ), second_node_( EMPTY )
{
    std::pair< Coordinate, Coordinate > coords = { EMPTY, EMPTY };
    coords_ = coords;
}

void Polaris::ViewController::UpdateSelectedNodes()
{
    std::pair< Id, Id > ids = view_->GetSelectedNodes();
    first_node_ = ids.first;
    second_node_ = ids.second;
}

void Polaris::ViewController::UpdateNodeCoordinates()
{
    QPointF point = view_->GetNodeCoordinates();
    coords_.first = point.rx();
    coords_.second = point.ry();
}

std::pair< int, int > Polaris::ViewController::GetNodeIds()
{
    UpdateSelectedNodes();

    std::pair< int, int > pair = { first_node_, second_node_ };
    return pair;
}

std::pair< Polaris::Coordinate, Polaris::Coordinate > Polaris::ViewController::GetNodeCoords()
{
    UpdateNodeCoordinates();

    return coords_;
}
