#include "include/graphic_room.h"
#include "include/graphic_connection.h"
#include "include/graphic_view.h"

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphConnection;
using Polaris::GraphicConnection;
using Polaris::Meta;

GraphicView::GraphicView()
{
}

void GraphicView::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphicView::DrawThePath( std::vector< size_t > path )
{

}

void GraphicView::OnMetaChanged( const Meta & meta )
{

}

void GraphicView::OnMetaAdded( const Meta & meta )
{

}

void GraphicView::OnMetaRemoved( const Meta & meta ) {

}

void GraphicView::OnConnectionAdded( const GraphConnection & connection )
{

}

void GraphicView::OnConnectionRemoved( const GraphConnection & connection )
{

}

size_t GraphicView::GetSelectedNode() const
{

}

std::pair< size_t, size_t > GraphicView::GetSelectedNodes() const
{

}

QPoint GraphicView::GetNodeCoordinates() const
{

}

int8_t GraphicView::GetFloorNumber() const
{

}
