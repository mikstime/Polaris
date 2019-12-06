#include "include/button_click_handler.h"

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * form, ViewController * view_controller, GraphController * graph_controller, QWidget * button_panel )
    : form_( form ), view_controller_( view_controller ), graph_controller_( graph_controller ), button_panel_( button_panel )
{
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    std::pair< int, int > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second == EMPTY )
    {
        // One room selected, creating room
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        graph_controller_->AddNode( first_coords );

        // Opening node form
        form_->SetCurrentNodeParams( ids.first, first_coords.first, first_coords.second );
        form_->show();
    }
    else if( ids.first != EMPTY && ids.second != EMPTY )
    {
        // Two rooms selected, creating connection
        graph_controller_->AddConnection( ids.first, ids.second );
    }
    form_->show();
    button_panel_->hide();
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
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        graph_controller_->MoveNode( first_id, first_coords );
    }
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    int first_id = view_controller_->GetNodeIds().first;
    if( first_id != EMPTY )
    {
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        Meta meta;
        graph_controller_->ChangeNode( first_id, meta );
    }
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second != EMPTY )
        graph_controller_->FindRoute( ids.first, ids.second );
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
}
