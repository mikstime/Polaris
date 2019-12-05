#include "include/view_controller.h"
#include "include/graph_controller.h"
#include "include/button_click_handler.h"
#include "include/node_data.h"

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * form, ViewController * view_controller, GraphController * graph_controller )
    : form_( form ), view_controller_( view_controller ), graph_controller_( graph_controller )
{
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    std::pair< int, int > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second == EMPTY )
    {
        // One room selected, creating room
        std::pair< int, int > first_coords = view_controller_->GetNodeCoords().first;
        graph_controller_->AddNode( first_coords );
    }
    else if( ids.first != EMPTY && ids.second != EMPTY )
    {
        // Two rooms selected, creating connection
        graph_controller_->AddConnection( ids.first, ids.second );
    }
}

void Polaris::ButtonClickHandler::DeleteButtonClick()
{
    std::pair< int, int > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second == EMPTY )
    {
        // One room selected, deleting room
        graph_controller_->DeleteNode( ids.first );
    }
    else if( ids.first != EMPTY && ids.second != EMPTY )
    {
        // Two rooms selected, deleting connection
        graph_controller_->DeleteConnection( ids.first, ids.second );
    }
}

void Polaris::ButtonClickHandler::MoveButtonClick()
{
    int first_id = view_controller_->GetNodeIds().first;
    if( first_id != EMPTY )
    {
        std::pair< int, int > first_coords = view_controller_->GetNodeCoords().first;
        graph_controller_->MoveNode( first_id, first_coords );
    }
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    int first_id = view_controller_->GetNodeIds().first;
    if( first_id != EMPTY )
    {
        std::pair< int, int > first_coords = view_controller_->GetNodeCoords().first;
        Meta meta;
        graph_controller_->ChangeNode( first_id, meta );
    }
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
    std::pair< int, int > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second != EMPTY )
        graph_controller_->FindRoute( ids.first, ids.second );
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
}
