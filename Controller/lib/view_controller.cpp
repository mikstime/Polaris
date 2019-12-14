#include "include/view_controller.h"

Polaris::ViewController::ViewController( GraphicView * view ) : view_( view ), floor_number_( 1 ),
        first_node_( EMPTY ), second_node_( EMPTY )
{
    std::pair< Coordinate, Coordinate > coords = { EMPTY, EMPTY };
    coords_ = coords;
}

void Polaris::ViewController::UpdateSelectedNodes()
{
    // Pair of selected nodes ids,
    // if selected less than two nodes equals (EMPTY, EMPTY)
    std::pair< Id, Id > ids = view_->GetSelectedNodes();

    if( ids.first != EMPTY && ids.second != EMPTY )
    {
        first_node_ = ids.first;
        second_node_ = ids.second;
    }
    else
    {
        // Selected node id,
        // if nodes not selected equals EMPTY
        Id id = view_->GetSelectedNode();

        if( id != EMPTY )
            first_node_ = id;
        else
            first_node_ = EMPTY;

        second_node_ = EMPTY;
    }
}

void Polaris::ViewController::UpdateNodeCoordinates()
{
    // Coordinates of selected nodes,
    // if selected not only one node equals (EMPTY, EMPTY)
    QPointF point = view_->GetNodeCoordinates();

    // Set new coordinates
    coords_.first = point.rx();
    coords_.second = point.ry();
}

int8_t Polaris::ViewController::GetCurrentFloor()
{
    return view_->GetFloorNumber();
}

std::pair< int, int > Polaris::ViewController::GetNodeIds()
{
    // Update selected nodes data
    UpdateSelectedNodes();

    // Return pair of selected nodes ids
    return std::make_pair( first_node_, second_node_ );
}

std::pair< Polaris::Coordinate, Polaris::Coordinate > Polaris::ViewController::GetNodeCoords()
{
    // Update selected node coordinates
    UpdateNodeCoordinates();

    // Return pair of coordinates
    return coords_;
}
