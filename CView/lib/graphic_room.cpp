#include "include/graphic_room.h"

using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom(GraphNode & node_info, const QRectF &rect,
                         QGraphicsItem * parent )
    : QGraphicsEllipseItem( rect, parent )
{

}

size_t GraphicRoom::GetId()
{
    return id_;
}


void GraphicRoom::mousePressEvent(QMoveEvent * event )
{

}
