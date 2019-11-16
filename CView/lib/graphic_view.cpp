#include "include/graphic_room.h"
#include "include/graphic_connection.h"
#include "include/graphic_view.h"

using Polaris::GraphicView;
using Polaris::GraphicRoom;
using Polaris::CGraphicConnection;

GraphicView::GraphicView(QWidget * parent )
    : QGraphicsView( parent )
{

}

QVector< GraphicRoom > & GraphicView::GetRooms()
{
    return rooms_;
}

QVector< CGraphicConnection > & GraphicView::GetConnections()
{
    return connections_;
}

void GraphicView::BuildItems(const Meta & new_meta, const Graph & new_graph )
{

}

void GraphicView::RefreshItems(const Meta & new_meta, const Graph & new_graph,
                               QVector< int > rooms_change_list )
{

}

void GraphicView::DrawThePath(QVector< int > path )
{

}

void GraphicView::CreateNewConnection()
{

}

void GraphicView::CreateNewRoomMeta()
{

}

void GraphicView::ChangeRoomMeta()
{

}
