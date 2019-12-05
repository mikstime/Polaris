#include "include/graphic_connection.h"
#include <QPainter>

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & left, const QPointF & right, const size_t & id,
                                      const size_t & floor )
: GraphicItem( id, floor, Polaris::Role::CONNECTION ),
left_( left ),
right_( right )
{
    ResetColor();
    this->show();
}

double GraphicConnection::GetPrice() const
{
    return price_;
}

void GraphicConnection::SetColor( const QColor & color )
{
    cur_color_ = color;
}

void GraphicConnection::ResetColor()
{
    cur_color_ = Qt::black;
}

void GraphicConnection::SetSelection()
{
    SetColor( Qt::yellow );
}

void GraphicConnection::ResetSelection()
{
    SetDefaultColor();
}

void GraphicConnection::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    painter->setPen(cur_color_ );
    painter->drawLine( left_, right_ );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicConnection::boundingRect() const
{
    return QRectF( left_, right_ ).normalized();
}

QPainterPath GraphicConnection::shape() const
{
    // TODO проверить
    QPainterPath path;
    path.moveTo( left_ );
    path.lineTo( right_ );
    return path;
}