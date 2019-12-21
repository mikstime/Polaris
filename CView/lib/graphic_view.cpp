#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graphic_view.h"
#include "include/graph_parser.h"
#include "include/item_controller.h"
#include <memory>

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::Meta;

// Размер окна и выкладка, на которой будет размещен виджет
GraphicView::GraphicView( const QSize & size, QHBoxLayout * const layout, QWidget * parent )
{
    std::shared_ptr< ItemCollaction > collaction( new ItemCollaction );
    item_controller_ = std::make_shared< ItemController >( QRect( 0, 0, size.width(),
                                                           size.height() ), collaction );
    graph_parser_ = std::make_unique< GraphParser >( item_controller_, collaction );
    renderer_ = std::make_unique< Renderer >( item_controller_.get() );
    renderer_->setMaximumSize( size );

    if( layout != nullptr )
        layout->addWidget( renderer_.get() );
}

void GraphicView::InitMap(const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    graph_parser_->BuildItems( meta, graph );
}

void GraphicView::DrawThePath(const std::vector< Meta > & nodes,
                              const std::vector< GraphConnection > & connections )
{
    graph_parser_->DrawThePath( nodes, connections );
}

void GraphicView::ChangeRoom(const Meta & meta )
{
    graph_parser_->OnRoomChanged(meta);
    renderer_->SetFloor( meta.floor );
    item_controller_->ResetEditing();
}

void GraphicView::AddRoom(const Meta & meta )
{
    graph_parser_->OnRoomAdded(meta);
//    renderer_->SetFloor( meta.floor );
}

void GraphicView::RemoveRoom(const Meta & meta )
{
    graph_parser_->OnRoomRemoved(meta);
}

void GraphicView::AddConnection(const GraphConnection & connection )
{
    graph_parser_->OnConnectionAdded( connection );
}

void GraphicView::RemoveConnection(const GraphConnection & connection )
{
    graph_parser_->OnConnectionRemoved( connection );
}

bool GraphicView::FloorUp() 
{
    item_controller_->ResetEditing();
    return renderer_->FloorUp();
}

bool GraphicView::FloorDown()
{
    item_controller_->ResetEditing();
    return renderer_->FloorDown();
}

size_t GraphicView::GetSelectedNode() const
{
    return item_controller_->GetCurrentNode();
}

std::pair< size_t, size_t > GraphicView::GetSelectedNodes() const
{
    Id first = item_controller_->GetCurrentNode();
    Id second = item_controller_->GetPreviousNode();
    std::pair< Id, Id > result;
    if( first != 0 && second != 0 )
    {
        result = std::make_pair( first, second );
    }
    else
    {
        result = std::make_pair( 0, 0 );
    }
    return result;
}

QPointF GraphicView::GetNodeCoordinates() const
{
    return item_controller_->GetMarkDownPos();
}

int8_t GraphicView::GetFloorNumber() const
{
    return renderer_->GetFloor();
}

QPolygonF GraphicView::GetNewForm() const
{
    return item_controller_->GetNewForm();
}

void GraphicView::SetLayout( QHBoxLayout * const layout )
{
    if( layout != nullptr )
        layout->addWidget( renderer_.get() );
}

//void GraphicView::SetParser( std::unique_ptr< GraphParser > graph_parser )
//{
//    graph_parser_ = graph_parser;
//}

bool GraphicView::ChangeMode( bool edit )
{
    item_controller_->ResetCurrentNode();
    item_controller_->ResetPreviousNode();
    return item_controller_->ChangeMode( edit );
}