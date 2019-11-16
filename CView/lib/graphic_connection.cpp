#include "include/graphic_connection.h"

using Polaris::CGraphicConnection;

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
