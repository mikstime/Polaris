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
: GraphicItem( 0, 0, Polaris::Role::MARK ),
  size_( QRectF(-10, -10, 20, 20) ),
  reachable_(false )
{
    ResetColor();
    setPos( 40, 40 );
    this->hide();
}

GraphicRoom::GraphicRoom( const Meta & node )
: GraphicItem( node.graph_node_id, node.floor, node.role ),
  room_number_( node.room_number ),
  info_( node.info ),
  size_( node.size ),
  reachable_(false )
{
    if( role_ == Role::STAIR )
    {
        SetReachable(true);
    }
    else
    {
        ResetColor();
    }

    setPos( node.coordinates );
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
    if( role_ == Role::STAIR )
        reachable_ = true;
    room_number_ = nw_meta.room_number;
    info_ = nw_meta.info;
    setToolTip( QString::fromUtf8( info_.c_str(), info_.size() ) );

    ResetColor();
}

void GraphicRoom::SetReachable(bool reach )
{
    reachable_ = reach;
    ResetColor();
}

void GraphicRoom::SetPic( const QPixmap & pic )
{
    pic_ = pic;
    QPointF res = ! size_.isEmpty() ? size_[ 0 ] : QPointF( 0, 0 );

    size_t i = 0;
    size_t top_left = 0;
    for( ; i < size_.size(); i++ )
    {
        if( size_[ i ].x() < res.x() && size_[ i ].y() < res.y() )
        {
            res = size_[ i ];
            top_left = i;
        }
    }

    res.setX( 0 );
    res.setY( 0 );
    if( i < size_.size() - 1 )
    {
        top_left = 0;
    }
    for( size_t k = 0; k < 3; k++ )
    {
        res += size_[ ( top_left + k ) % size_.size() ];
    }
    pic_pos_.setX( res.x() / 3 );
    pic_pos_.setY( res.y() / 3 );
}

bool GraphicRoom::IsReachable() const
{
    return reachable_;
}

void GraphicRoom::ResetColor()
{
//    if( ! reachable_ )
//    {
//        def_color_ = cur_color_ = "#b9b9b9";
//        return;
//    }

    Polaris::Role role = this->GetRole();
    if( role == Polaris::Role::MARK )
    {
        def_color_ = "#FF5D5D";
    } else if( role == Polaris::Role::ROOM )
    {
//        def_color_ = "#5B659B";
        def_color_ = "#b9b9b9";
    }
    else if( role == Polaris::Role::STAIR )
    {
        def_color_ = "#3BE300";
    }
    else if( role == Polaris::Role::HALL )
    {
//        def_color_ = "#284680";
        def_color_ = "#b9b9b9";
    }
    cur_color_ = def_color_;
}

void GraphicRoom::SetSelection()
{
    SetColor( "#FFC700" );
}

void GraphicRoom::ResetSelection()
{
    SetDefaultColor();
}

void GraphicRoom::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setRenderHints( QPainter::Antialiasing );
    QPen nw_pen( Qt::black );
    nw_pen.setWidth( 4 );

    painter->setPen( nw_pen );
    painter->setBrush( cur_color_ );
    painter->drawPolygon( size_ );

    if( role_ == Role::ROOM )
    {
        painter->drawText( boundingRect(), Qt::AlignCenter, room_number_.c_str() );
    }
    else
    {
        nw_pen.setWidth( 2 );
        painter->setPen( nw_pen );
        painter->setBrush( QColor( "#b9b9b9" ) );
        painter->drawEllipse( pic_pos_.toPoint().x() - 15, pic_pos_.toPoint().y() - 15, 30, 30 );
        painter->drawPixmap( pic_pos_.toPoint().x() - 10, pic_pos_.toPoint().y() - 10, 20, 20, pic_ );
    }

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