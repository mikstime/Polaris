#include "include/graphic_item.h"
#include "include/graphic_room.h"
#include <limits>
#include <string>
#include <QPainter>
#include <QPainterPath>

#include <QDebug>

using std::string;
using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom()
        :GraphicItem( std::numeric_limits< size_t >::max(), 0, Polaris::Role::MARK ),
         size_( QRect(-10, -10, 20, 20) )
{
    // TODO инициализация
    ResetColor();
    setPos( 40, 40 );
    this->show();
}

GraphicRoom::GraphicRoom( const Meta & node, const QRectF & rect )
: GraphicItem( node.graph_node_id, node.floor, node.role ),
info_( node.room_number ),
size_( rect )
{
    // TODO инициализация
    ResetColor();
    setPos( node.x, node.y );
    this->show();
}

GraphicRoom::GraphicRoom( const Meta & node, const QSize & size )
        : GraphicItem( node.graph_node_id, node.floor, node.role ),
          info_( node.room_number ),
          size_( - size.width() / 2, - size.height() / 2, size.width(), size.height() )
{
    ResetColor();
    setPos( node.x, node.y );
    this->show();
}

GraphicRoom & GraphicRoom::operator = ( const GraphicRoom & room )
{
    this->floor_ = room.floor_;
    this->role_ = room.role_;
    this->info_ = room.info_;
    this->size_ = room.size_;
    this->color_ = room.color_;
    this->setPos( room.pos() );
    qInfo() << "&";

    return * this;
}

GraphicRoom & GraphicRoom::operator = ( const GraphicRoom && room )
{
    this->floor_ = room.floor_;
    this->role_ = room.role_;
    this->info_ = std::move( room.info_ );
    this->size_ = std::move( room.size_ );
    this->color_ = std::move( room.color_ );
    this->setPos( room.pos() );
    qInfo() << "&&";

    return * this;
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
    //TODO цвет зависит от роли
    Polaris::Role role = this->GetRole();
    if( role == Polaris::Role::MARK )
    {
        color_ = Qt::black;
    } else if( role == Polaris::Role::ROOM )
    {
        color_ = Qt::green;
    }
    else if( role == Polaris::Role::STAIR )
    {
        color_ = Qt::red;
    }
    else if( role == Polaris::Role::HALL )
    {
        color_ = Qt::blue;
    }
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

QPainterPath GraphicRoom::shape() const
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}