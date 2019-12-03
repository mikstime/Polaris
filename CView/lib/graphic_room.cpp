#include "include/graphic_item.h"
#include "include/graphic_room.h"
#include <string>
#include <QPainter>

using std::string;
using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom( const Meta & node, const QRectF & size )
: GraphicItem( node.graph_node_id, node.floor, node.role ),
info_( node.room_number ),
size_( size ),
color_( Qt::blue )
{
    // TODO инициализация
    ResetColor();
    setPos( node.x, node.y );
    this->show();
}

GraphicRoom::GraphicRoom()
:GraphicItem( 0, 0, "mark" )
{
    // TODO инициализация
    ResetColor();
    setPos( 0, 0 );
}

std::string GraphicRoom::GetInfo() const
{
    return info_;
}

void GraphicRoom::SetColor( const QColor & color )
{
    color_ = color;
}

void GraphicRoom::ResetColor()
{
    color_ = Qt::blue;
}

void GraphicRoom::SetSelection()
{
    SetColor( Qt::yellow );
}

void GraphicRoom::ResetSelection()
{
    ResetColor();
}

void GraphicRoom::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setPen( Qt::black );
    painter->setBrush( color_ );
    painter->drawEllipse( size_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicRoom::boundingRect() const
{
    return QRectF( size_ ).normalized();
}