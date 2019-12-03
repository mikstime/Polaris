#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graphic_view.h"
#include "include/graph_parser.h"
#include "include/item_controller.h"
#include <memory>
#include <QtWidgets/QHBoxLayout>

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::Meta;

// Размер окна и выкладка, на которой будет размещен виджет
GraphicView::GraphicView( const QSize & size, QHBoxLayout * const layout, QWidget * parent )
: item_controller_( new ItemController( QRect(0, 0, size.width(), size.height() ) ) ),
  renderer_( new Renderer( item_controller_.get() ) ),
  graph_parser_( new GraphParser( item_controller_ ) )
{
    renderer_->setMaximumSize( size );
    layout->addWidget( renderer_.get() );
}

void GraphicView::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    graph_parser_->BuildItems( meta, graph );
}

void GraphicView::OnPathFound(const std::vector< const GraphNode > & nodes,
                              const std::vector< const GraphConnection > & connections )
{
// TODO   graph_parser_->DrawThePath( path );
}

void GraphicView::OnMetaChanged( const Meta & meta )
{
    graph_parser_->OnRoomChanged(meta);
}

void GraphicView::OnMetaAdded( const Meta & meta )
{
    graph_parser_->OnRoomAdded(meta);
}

void GraphicView::OnMetaRemoved( const Meta & meta )
{
    graph_parser_->OnRoomRemoved(meta);
}

void GraphicView::OnConnectionAdded( const GraphConnection & connection )
{
    graph_parser_->OnConnectionAdded( connection );
}

void GraphicView::OnConnectionRemoved( const GraphConnection & connection )
{
    graph_parser_->OnConnectionRemoved( connection );
}

size_t GraphicView::GetSelectedNode() const
{
    return item_controller_->GetCurrentNode();
}

std::pair< size_t, size_t > GraphicView::GetSelectedNodes() const
{
    return std::make_pair( item_controller_->GetCurrentNode(), item_controller_->GetPreviousNode() );
}

QPointF GraphicView::GetNodeCoordinates() const
{
    return item_controller_->GetMarkDownPos();
}

int8_t GraphicView::GetFloorNumber() const
{
    return renderer_->GetFloor();
}
