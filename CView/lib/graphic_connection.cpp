#include "include/graphic_connection.h"
#include <QPainter>

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & pos )
: GraphicItem(),
size_( -8, -8, 16, 16 ),
connection_number_( 0 )
{
    this->setFlag( QGraphicsItem::ItemIgnoresTransformations, true );
    ResetColor();
    this->setPos( pos );
    this->show();
}

GraphicConnection::~GraphicConnection()
{
    if( connection_number_ != 0 )
        connection_number_counter_--;
}

void GraphicConnection::SetColor( const QColor & color )
{
    cur_color_ = color;
}

void GraphicConnection::SetSelection()
{
    connection_number_ = ++ connection_number_counter_;
    SetColor( "#FFC700" );
}

QPolygonF GraphicConnection::GetSize() const
{
    return QPolygonF( size_ );
}

void GraphicConnection::ResetColor()
{
    def_color_ = cur_color_ = "#595959";
}

void GraphicConnection::ResetSelection()
{
    if(  connection_number_ != 0)
    {
        connection_number_ = 0;
        connection_number_counter_--;
    }

    SetDefaultColor();
}

void GraphicConnection::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget )
{
    painter->setRenderHints( QPainter::Antialiasing );
    painter->setPen( Qt::black );
    painter->setBrush( cur_color_ );
    painter->drawEllipse( size_ );
    if( connection_number_ != 0 )
        painter->drawText(size_, Qt::AlignCenter, QString::number( connection_number_ ) );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicConnection::boundingRect() const
{
    return size_.normalized();
}

QPainterPath GraphicConnection::shape() const
{
    QPainterPath path;
    path.addRect( size_ );
    return path;
}

size_t GraphicConnection::connection_number_counter_ = 0;