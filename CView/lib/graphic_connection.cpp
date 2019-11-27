#include "include/graphic_connection.h"
#include <QPainter>

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & left, const QPointF & right, const GraphConnection & connection )
: left_( left ),
right_( right ),
color_( Qt::black )
{
    // TODO инициализация
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

void GraphicConnection::SetColor( const QColor & color )
{
    color_ = color;
}

void GraphicConnection::ResetColor()
{
    color_ = Qt::black;
}

void GraphicConnection::SetSelection()
{
    SetColor( Qt::yellow );
}

void GraphicConnection::ResetSelection()
{
    ResetColor();
}

void GraphicConnection::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    painter->setPen( color_ );
    painter->drawLine( left_, right_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicConnection::boundingRect() const
{
    return QRectF( left_, right_ ).normalized();
}