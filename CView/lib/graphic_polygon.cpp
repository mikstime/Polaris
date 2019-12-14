#include "include/graphic_polygon.h"
#include <limits>
#include <string>
#include <QGraphicsSceneHoverEvent>
#include <QPainter>
#include <QPainterPath>

using std::vector;

using Polaris::GraphicPolygon;

GraphicPolygon::GraphicPolygon()
: GraphicItem( 0, 0, Polaris::Role::POLYGON )
{
    // TODO инициализация стандартной формы
    ResetColor();
    setPos( 40, 40 );
    this->show();
}

GraphicPolygon::GraphicPolygon( const size_t floor, const std::vector< QPointF > & points )
: GraphicItem( 0, floor, Polaris::Role::POLYGON  ),
form_( points )
{
    // TODO инициализация
    ResetColor();
    this->show();
}

GraphicPolygon & GraphicPolygon::operator = ( const GraphicPolygon & room )
{
    //TODO присваивание
//    this->floor_ = room.floor_;
//    this->role_ = room.role_;
//    this->info_ = room.info_;
//    this->size_ = room.size_;
//    this->cur_color_ = room.cur_color_;
//    this->setPos( room.pos() );
//    qInfo() << "&";

    return * this;
}

GraphicPolygon & GraphicPolygon::operator = ( const GraphicPolygon && room )
{
    //TODO присваивание
//    this->floor_ = room.floor_;
//    this->role_ = room.role_;
//    this->info_ = std::move( room.info_ );
//    this->size_ = std::move( room.size_ );
//    this->cur_color_ = std::move(room.cur_color_ );
//    this->setPos( room.pos() );
//    qInfo() << "&&";

    return * this;
}

const vector< QPointF > & GraphicPolygon::GetForm() const
{
    return form_;
}

void GraphicPolygon::SetColor( const QColor & color )
{
    cur_color_ = color;
}

void GraphicPolygon::ResetColor()
{
    cur_color_ = def_color_ = Qt::darkBlue;
}

void GraphicPolygon::SetSelection()
{
//    SetColor( Qt::yellow );
}

void GraphicPolygon::ResetSelection()
{
    SetDefaultColor();
}

void GraphicPolygon::paint( QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
    painter->setPen( Qt::black );
    painter->setBrush(cur_color_ );
    painter->drawPolygon( QVector< QPointF >().fromStdVector( form_ ) );

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF GraphicPolygon::boundingRect() const
{
    //TODO rect
//    QPointF left = * std::min_element( form_.begin(), form_.end() );
//    QPointF right = * std::max_element( form_.begin(), form_.end() );
    QPointF left( -20, -20 );
    QPointF right( 20, 20 );
    return QRectF( left, right ).normalized();
}

QPainterPath GraphicPolygon::shape() const
{
    QPainterPath path;
    path.addPolygon( QVector< QPointF >().fromStdVector( form_ ) );
    return path;
}