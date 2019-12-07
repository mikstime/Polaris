#include "include/button_click_handler.h"

#include <QDebug>

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * node_form, ConnectionForm * connection_form,
        ViewController * view_controller, GraphController * graph_controller, QWidget * button_panel ) :
        node_form_( node_form ), view_controller_( view_controller ), graph_controller_( graph_controller ), button_panel_( button_panel )
{
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    std::pair< Coordinate, Coordinate > coordinates = view_controller_->GetNodeCoords();
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();
    if( coordinates.first != 0 && coordinates.second != 0 )
    {
        qInfo() << "Add button: One node selected";
        // Creating room
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        graph_controller_->AddNode( first_coords );

        // Opening node form
        node_form_->SetCurrentNodeParams( ids.first, first_coords.first, first_coords.second );
        node_form_->show();
        button_panel_->hide();
    }
    else if( ids.first != 0 && ids.second != 0 )
    {
        qInfo() << "Add button: Two node selected";
        // Opening connection form
//        connection_form_->SetNodes( ids.first, ids.second );
//        connection_form_->show();
//        button_panel_->hide();
    }
    qInfo() << "Add button: Nodes not selected";
}

void Polaris::ButtonClickHandler::DeleteButtonClick()
{
    std::pair< int, int > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second == EMPTY )
    {
        qInfo() << "Delete button: One node selected";
        // Deleting room
        graph_controller_->DeleteNode( ids.first );
    }
    else if( ids.first != EMPTY && ids.second != EMPTY )
    {
        qInfo() << "Delete button: Two node selected";
        // Deleting connection
        graph_controller_->DeleteConnection( ids.first, ids.second );
    }
    qInfo() << "Delete button: Nodes not selected";
}

void Polaris::ButtonClickHandler::MoveButtonClick()
{
    int first_id = view_controller_->GetNodeIds().first;
    if( first_id != EMPTY )
    {
        qInfo() << "Move button: Node selected";
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        graph_controller_->MoveNode( first_id, first_coords );
    }
    qInfo() << "Move button: Node not selected";
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    int first_id = view_controller_->GetNodeIds().first;
    if( first_id != EMPTY )
    {
        qInfo() << "Change button: Node selected";
        std::pair< Coordinate, Coordinate > first_coords = view_controller_->GetNodeCoords();
        node_form_->SetCurrentNodeParams( first_id, first_coords.first, first_coords.second );
        node_form_->show();
        button_panel_->hide();
    }
    qInfo() << "Change button: Node not selected";
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();
    if( ids.first != EMPTY && ids.second != EMPTY )
    {
        qInfo() << "Find route button: Two node selected";
        graph_controller_->FindRoute( ids.first, ids.second );
    }
    qInfo() << "Find route button: Two node node selected";
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
}
