#include "include/graphic_door.h"
#include <limits>
#include <string>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QPainterPath>

using std::vector;

using Polaris::GraphicDoor;

GraphicDoor::GraphicDoor()
: GraphicItem( 0, 0, Polaris::Role::POLYGON )
{
    ResetColor();
    setPos( 40, 40 );
    this->show();
}

GraphicDoor::GraphicDoor( const size_t  id, const size_t floor, const QPointF & left, const QPointF & right )
: GraphicItem( id, floor, Polaris::Role::POLYGON  ),
left_( left ),
right_( right )
{
    ResetColor();
    this->show();
}

void GraphicDoor::SetColor(const QColor & color )
{
    cur_color_ = color;
}

void GraphicDoor::ResetColor()
{
    cur_color_ = def_color_ = "#a83636";
}

void GraphicDoor::SetSelection()
{
}

void GraphicDoor::ResetSelection()
{
    SetDefaultColor();
}

void GraphicDoor::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setRenderHints( QPainter::Antialiasing );
    QPen nw_pen( cur_color_ );
    nw_pen.setWidth( 4 );

    painter->setPen( nw_pen );
    painter->drawLine( left_, right_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicDoor::boundingRect() const
{
    return QRectF( left_, right_ ).normalized();
}

QPainterPath GraphicDoor::shape() const
{
    QPainterPath path;
    return path;
}