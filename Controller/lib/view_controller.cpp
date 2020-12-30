#include "include/view_controller.h"

Polaris::ViewController::ViewController( GraphicView * view ) : view_( view ), floor_number_( 1 ),
        first_node_( EMPTY ), second_node_( EMPTY )
{
}

Polaris::ViewController::~ViewController()
{
    delete view_;
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
    coords_ = view_->GetNodeCoordinates();
}

QPolygonF Polaris::ViewController::GetNodeForm()
{
    return view_->GetNewForm();
}

std::pair< int, int > Polaris::ViewController::GetNodeIds()
{
    // Update selected nodes data
    UpdateSelectedNodes();

    // Return pair of selected nodes ids
    return std::make_pair( first_node_, second_node_ );
}

QPointF Polaris::ViewController::GetNodeCoords()
{
    // Update selected node coordinates
    UpdateNodeCoordinates();

    // Return pair of coordinates
    return coords_;
}

void Polaris::ViewController::ChangeMode( bool is_editing )
{
    view_->ChangeMode( is_editing );
}

int Polaris::ViewController::GetFloorNumber()
{
    floor_number_ = view_->GetFloorNumber();
    return floor_number_;
}

int Polaris::ViewController::FloorUp()
{
    if( view_->FloorUp() )
        ++floor_number_;
    return floor_number_;
}

int Polaris::ViewController::FloorDown()
{
    if( view_->FloorDown() )
        --floor_number_;
    return floor_number_;
}
