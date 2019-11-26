#include "include/graphic_room.h"
#include <QPainter>

using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom( const Meta & node, const QRectF & size )
    : size_( size )
{
}

std::string GraphicRoom::GetInfo() const
{
    return info_;
}

size_t GraphicRoom::GetId() const
{
    return id_;
}

int8_t GraphicRoom::GetFloor() const
{
    return floor_;
}

std::string GraphicRoom::GetRole() const
{
    return role_;
}

void GraphicRoom::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setPen( Qt::black );
    painter->setBrush( Qt::blue );
    painter->drawEllipse( size_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicRoom::boundingRect() const
{
    return QRectF( size_ ).normalized();
}