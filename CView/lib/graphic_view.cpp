#include "include/graphic_room.h"
#include "include/graphic_connection.h"
#include "include/graphic_view.h"

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::GraphicConnection;

GraphicView::GraphicView()
{
}

void GraphicView::DrawThePath( std::vector< size_t > path )
{

}

void GraphicView::BuildItems( const Meta & meta, const GraphConnection & connection )
{

}

void GraphicView::RefreshItems( const Meta & meta, std::vector< size_t > change_list )
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

short int GraphicView::GetFloorNumber() const
{

}
