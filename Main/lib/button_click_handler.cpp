#include "include/button_click_handler.h"

Polaris::ButtonClickHandler::ButtonClickHandler( NodeForm * node_form, ConnectionForm * connection_form,
        ViewController * view_controller, GraphController * graph_controller, QWidget * button_panel, QPushButton * change_mode_button, QLabel * floor_label ) :
        node_form_( node_form ), connection_form_( connection_form ), view_controller_( view_controller ),
        graph_controller_( graph_controller ), button_panel_( button_panel ), change_mode_button_( change_mode_button ), floor_label_( floor_label )
{
}

Polaris::ButtonClickHandler::~ButtonClickHandler()
{
    delete change_mode_button_;
    delete floor_label_;
}

void Polaris::ButtonClickHandler::AddButtonClick()
{
    // Pair of selected nodes ids
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();

    if( ids.first != EMPTY && ids.second != EMPTY )
    {
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
        QPointF coordinates = view_controller_->GetNodeCoords();

        if( coordinates.rx() != EMPTY && coordinates.ry() != EMPTY )
        {
            // Set current node params
            node_form_->SetNode( 0, STATUS::SAVE );

            // Show form and hide button panel
            node_form_->show();
            button_panel_->hide();
        }
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
            // Delete connection
            graph_controller_->DeleteConnection( ids.first, ids.second );
        }
        else
        {
            // Delete room
            graph_controller_->DeleteNode( ids.first );
        }
    }
}

void Polaris::ButtonClickHandler::ChangeButtonClick()
{
    // Get selected node,
    // if node selected equals EMPTY
    Id id = view_controller_->GetNodeIds().first;

    if( id != EMPTY )
    {
        // Set node params
        node_form_->SetNode( id, STATUS::CHANGE );

        // Show form and hide button panel
        node_form_->show();
        button_panel_->hide();
    }
}

void Polaris::ButtonClickHandler::FindRouteButtonClick()
{
    // Pair of selected nodes ids
    std::pair< Id, Id > ids = view_controller_->GetNodeIds();

    if( ids.first != EMPTY && ids.second != EMPTY )
        graph_controller_->FindRoute( ids.first, ids.second );
}

void Polaris::ButtonClickHandler::FloorUpButtonClick()
{
    int floor = view_controller_->FloorUp();
    floor_label_->setText( "Этаж: " + QString::number( floor ) );
}

void Polaris::ButtonClickHandler::FloorDownButtonClick()
{
    int floor = view_controller_->FloorDown();
    floor_label_->setText( "Этаж: " + QString::number( floor ) );
}

void Polaris::ButtonClickHandler::ChangeModeButtonClick()
{
    if( change_mode_button_->text() == "Режим редактирования" )
    {
        view_controller_->ChangeMode( true );
        change_mode_button_->setText( "Режим просмотра" );
    }
    else if( change_mode_button_->text() == "Режим просмотра" )
    {
        view_controller_->ChangeMode( false );
        change_mode_button_->setText( "Режим редактирования" );
    }
}
