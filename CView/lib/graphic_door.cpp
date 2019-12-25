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
: GraphicItem( id, floor, Polaris::Role::POLYGON  )
{
    SetSize( left, right );
    ResetColor();
    this->show();
}

void GraphicDoor::SetColor(const QColor & color )
{
    cur_color_ = color;
}

void GraphicDoor::ResetColor()
{
//    cur_color_ = def_color_ = "#a83636";
    cur_color_ = def_color_ = "#b9b9b9";
}

void GraphicDoor::SetSelection()
{
}

void GraphicDoor::SetPic( const QPixmap & pic )
{
    pic_ = pic;
}

void GraphicDoor::ResetSelection()
{
    SetDefaultColor();
}

void GraphicDoor::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setRenderHints( QPainter::Antialiasing );
    QPen nw_pen( cur_color_ );
    nw_pen.setWidth( 6 );

    painter->setPen( nw_pen );
    painter->drawLine( left_, right_ );
    QPoint pos = boundingRect().center().toPoint() - QPoint( -10, -10 );
    painter->drawPixmap( pos.x(), pos.y(), 20, 20, pic_ );

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

void GraphicDoor::SetSize( const QPointF & left, const QPointF & right )
{
    QPointF rel_cords = right - left;
//    float angle = rel_cords.x() / rel_cords.y();

    left_ = QPointF( rel_cords.x() / 3,  rel_cords.y() / 3 );
    right_ = QPointF( rel_cords.x() * 2 / 3, rel_cords.y() * 2 / 3 );
    left_ += left;
    right_ += left;
}