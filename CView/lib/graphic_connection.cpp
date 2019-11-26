#include "include/graphic_connection.h"
#include <QPainter>

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & left, const QPointF & right, const GraphConnection & connection )
    : left_( left ), right_( right )
{
}

double GraphicConnection::GetPrice() const
{
    return price_;
}

size_t GraphicConnection::GetId() const
{
    return id_;
}

int8_t GraphicConnection::GetFloor() const
{
    return floor_;
}

std::string GraphicConnection::GetRole() const
{
    return role_;
}

void GraphicConnection::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    painter->setPen( Qt::black );
    painter->drawLine( left_, right_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicConnection::boundingRect() const
{
    return QRectF( left_, right_ ).normalized();
}