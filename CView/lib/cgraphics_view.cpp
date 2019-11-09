#include "include/cgraphic_items.h"
#include "include/cgraphics_view.h"

using Polaris::CGraphicsView;
using Polaris::CGraphicRoom;
using Polaris::CGraphicConnection;

CGraphicsView::CGraphicsView( QWidget * parent )
    : QGraphicsView( parent )
{

}

QVector< CGraphicRoom > & CGraphicsView::GetRooms()
{
    return rooms_;
}

QVector< CGraphicConnection > & CGraphicsView::GetConnections()
{
    return connections_;
}

void CGraphicsView::BuildItems( const Meta & new_meta, const Graph & new_graph )
{

}

void CGraphicsView::RefreshItems( const Meta & new_meta, const Graph & new_graph,
                                  QVector< int > rooms_change_list )
{

}

void CGraphicsView::DrawThePath( QVector< int > path )
{

}

void CGraphicsView::CreateNewConnection()
{

}

void CGraphicsView::CreateNewRoomMeta()
{

}

void CGraphicsView::ChangeRoomMeta()
{

}
