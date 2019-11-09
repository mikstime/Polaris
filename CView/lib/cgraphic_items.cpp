#include "include/cgraphic_items.h"

using namespace Polaris;

CGraphicConnection::CGraphicConnection( GraphConnection & connection_info, const QLineF & line,
                                        QGraphicsItem * parent )
    : QGraphicsLineItem( line, parent )
{

}

void CGraphicConnection::mousePressEvent( QMoveEvent * event )
{

}

CGraphicRoom::CGraphicRoom( GraphNode & node_info, const QRectF &rect,
                                  QGraphicsItem * parent )
    : QGraphicsEllipseItem( rect, parent )
{

}

void CGraphicRoom::mousePressEvent( QMoveEvent * event )
{

}
