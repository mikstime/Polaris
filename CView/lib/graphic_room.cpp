#include "include/graphic_room.h"
#include <limits>
#include <string>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QPainterPath>

#include <QDebug>

using std::string;
using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom()
        :GraphicItem( 0, 0, Polaris::Role::MARK ),
         size_( QRectF(-10, -10, 20, 20) )
{
    // TODO инициализация
    ResetColor();
    setPos( 40, 40 );
    this->hide();
}

GraphicRoom::GraphicRoom( const Meta & node )
        : GraphicItem( node.graph_node_id, node.floor, node.role ),
          room_number_( node.room_number ),
          info_( node.info ),
          size_( node.size )
{
    ResetColor();
//    setPos( node.coordinates );
    setToolTip( QString::fromUtf8( info_.c_str(), info_.size() ) );
    this->show();
}

std::string GraphicRoom::GetInfo() const
{
    return info_;
}

std::string GraphicRoom::GetRoom() const
{
    return room_number_;
}

QPolygonF GraphicRoom::GetSize() const
{
    return size_;
}

void GraphicRoom::SetColor( const QColor & color )
{
    cur_color_ = color;
}

void GraphicRoom::SetMeta( const Meta & nw_meta )
{
    setPos( nw_meta.coordinates );
    size_ = nw_meta.size;
    floor_ = nw_meta.floor;
    role_ = nw_meta.role;
    room_number_ = nw_meta.room_number;
    info_ = nw_meta.info;
    ResetColor();
}


void GraphicRoom::ResetColor()
{
    //TODO цвет зависит от роли
    Polaris::Role role = this->GetRole();
    if( role == Polaris::Role::MARK )
    {
        def_color_ = Qt::black;
    } else if( role == Polaris::Role::ROOM )
    {
        def_color_ = Qt::green;
    }
    else if( role == Polaris::Role::STAIR )
    {
        def_color_ = Qt::red;
    }
    else if( role == Polaris::Role::HALL )
    {
        def_color_ = Qt::blue;
    }
    cur_color_ = def_color_;
}

void GraphicRoom::SetSelection()
{
    SetColor( Qt::yellow );
}

void GraphicRoom::ResetSelection()
{
    SetDefaultColor();
}

void GraphicRoom::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setPen( Qt::black );
    painter->setBrush(cur_color_ );
    painter->drawPolygon( size_ );
    QPointF text_pos = this->pos();
    painter->drawText( size_.boundingRect(), Qt::AlignCenter, info_.c_str() );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicRoom::boundingRect() const
{
    return size_.boundingRect();
}

QPainterPath GraphicRoom::shape() const
{
    QPainterPath path;
    path.addPolygon( size_ );
    return path;
}