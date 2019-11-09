#include "include/cgraphic_items.h"

using namespace Polaris;

CGraphicConnection::CGraphicConnection( GraphConnection & connection_info, const QLineF & line,
                                        QGraphicsItem * parent )
    : QGraphicsLineItem( line, parent )
{

}

size_t CGraphicConnection::GetId()
{
    return id_;
}

double CGraphicConnection::GetPrice()
{
    return price_;
}

void CGraphicConnection::mousePressEvent( QMoveEvent * event )
{

}

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
