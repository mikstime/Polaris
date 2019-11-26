#include "include/graphic_connection.h"
#include "include/graphic_room.h"
#include "include/graphic_view.h"
#include "include/graph_parser.h"
#include "include/item_controller.h"
#include <memory>
#include <QtWidgets/QVBoxLayout>

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::Meta;

GraphicView::GraphicView( const QRect & size, QVBoxLayout & layout, QWidget * parent )
: item_controller_( new ItemController( size ) ),
  renderer_( new Renderer( item_controller_.get() ) ),
  graph_parser_( new GraphParser( item_controller_.get() ) )
{
    renderer_->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    renderer_->setGeometry( size );
    renderer_->setSceneRect(0, 0, renderer_->size().width()-5, renderer_->size().height()-5);
    layout.addWidget( renderer_.get() );
};

void GraphicView::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    graph_parser_->BuildItems( meta, graph );
}

void GraphicView::DrawThePath( std::vector< size_t > path )
{
    graph_parser_->DrawThePath( path );
}

void GraphicView::OnMetaChanged( const Meta & meta )
{
    graph_parser_->OnMetaChanged( meta );
}

void GraphicView::OnMetaAdded( const Meta & meta )
{
    graph_parser_->OnMetaAdded( meta );
}

void GraphicView::OnMetaRemoved( const Meta & meta )
{
    graph_parser_->OnMetaRemoved( meta );
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
