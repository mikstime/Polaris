#include "include/graphic_connection.h"
#include <QPainter>

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & pos )
: GraphicItem()
{
    ResetColor();
    this->setPos( pos );
    this->show();
}

void GraphicConnection::SetColor( const QColor & color )
{
    cur_color_ = color;
}

void GraphicConnection::SetSelection()
{
    SetColor( Qt::yellow );
}

QPolygonF GraphicConnection::GetSize() const
{
    return QPolygonF( size_ );
}

void GraphicConnection::ResetColor()
{
    def_color_ = cur_color_ = Qt::black;
}

void GraphicConnection::ResetSelection()
{
    SetDefaultColor();
}

void GraphicConnection::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    painter->setPen(cur_color_ );
    painter->drawRect( size_ );
//    painter->drawText( QRectF( left_, right_ ), Qt::AlignCenter, QString::number( cost_ ) );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicConnection::boundingRect() const
{
    return size_.normalized();
}

QPainterPath GraphicConnection::shape() const
{
    // TODO проверить
    QPainterPath path;
    path.addRect( size_ );
    return path;
}