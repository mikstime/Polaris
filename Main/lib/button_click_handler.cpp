#include "include/button_click_handler.h"

#include <QDebug>

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * node_form, ConnectionForm * connection_form,
        ViewController * view_controller, GraphController * graph_controller, QWidget * button_panel ) :
        node_form_( node_form ), connection_form_( connection_form ), view_controller_( view_controller ), graph_controller_( graph_controller ), button_panel_( button_panel )
{
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    // Pair of selected nodes ids
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();

    if( ids.first != EMPTY && ids.second != EMPTY )
    {
        qInfo() << "Add button: Two node selected";

        // Set current nodes to form
        connection_form_->SetNodes( ids.first, ids.second );

        // Show form and hide button panel
        connection_form_->show();
        button_panel_->hide();
    }
    else
    {
        // Coordinates of selected node,
        // if selected not only one node equals (EMPTY, EMPTY)
        std::pair< Coordinate, Coordinate > coordinates = view_controller_->GetNodeCoords();

        if( coordinates.first != EMPTY && coordinates.second != EMPTY )
        {
            qInfo() << "Add button: One node selected";

            // Create room and get it id
            Id id = graph_controller_->AddNode( coordinates );

            // Set current node params
            node_form_->SetCurrentNodeParams( id, coordinates.first, coordinates.second );

            // Show form and hide button panel
            node_form_->show();
            button_panel_->hide();
        }
        else
            qInfo() << "Delete button: Nodes not selected";
    }
}

void Polaris::ButtonClickHandler::DeleteButtonClick()
{
    // Pair of selected nodes ids,
    // if one node selected second node equals EMPTY
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();

    if( ids.first != EMPTY )
    {
        if ( ids.second != EMPTY )
        {
            qInfo() << "Delete button: Two nodes selected";

            // Delete connection
            graph_controller_->DeleteConnection( ids.first, ids.second );
        }
        else
        {
            qInfo() << "Delete button: One node selected";

            // Delete room
            graph_controller_->DeleteNode( ids.first );
        }
    }
    else
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
    else
        qInfo() << "Move button: Node not selected";
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    // Get selected node,
    // if node selected equals EMPTY
    Id id = view_controller_->GetNodeIds().first;

    if( id != EMPTY )
    {
        qInfo() << "Change button: Node selected";

        // Set node params
        node_form_->SetCurrentNodeParams( id );

        // Show form and hide button panel
        node_form_->show();
        button_panel_->hide();
    }
    else
        qInfo() << "Change button: Node not selected";
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
    // Pair of selected nodes ids
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();

    if( ids.first != EMPTY && ids.second != EMPTY )
    {
        qInfo() << "Find route button: Two node selected";

        graph_controller_->FindRoute( ids.first, ids.second );
    }
    else
        qInfo() << "Find route button: Two node not selected";
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
}
