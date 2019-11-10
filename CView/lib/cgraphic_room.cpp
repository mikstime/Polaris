#include "include/cgraphic_room.h"

using Polaris::CGraphicRoom;

CGraphicRoom::CGraphicRoom( GraphNode & node_info, const QRectF &rect,
                                  QGraphicsItem * parent )
    : QGraphicsEllipseItem( rect, parent )
{

}

size_t CGraphicRoom::GetId()
{
    return id_;
}


void CGraphicRoom::mousePressEvent( QMoveEvent * event )
{

}
