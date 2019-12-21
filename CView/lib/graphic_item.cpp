#include "include/graphic_item.h"

#include <QDebug>

using Polaris::GraphicItem;

GraphicItem::GraphicItem()
: id_( 0 ),
floor_( 0 ),
role_( Role::CONNECTION )
{
}

GraphicItem::GraphicItem( const size_t & id, const int8_t & floor, const Polaris::Role & role )
: id_( id ),
floor_( floor ),
role_( role )
{

}

bool GraphicItem::IsSelected() const
{
    return cur_color_ != def_color_;
}

size_t GraphicItem::GetId() const
{
    return id_;
}

int8_t GraphicItem::GetFloor() const
{
    return floor_;
}

//bool GraphicItem::OnTheFloor( const int8_t floor ) const
//{
//    return floor_ == floor;
//}

Polaris::Role GraphicItem::GetRole() const
{
    return role_;
}

QColor GraphicItem::GetColor() const
{
    return cur_color_;
}

void GraphicItem::SetDefaultColor()
{
    cur_color_ =  def_color_;
}

void GraphicItem::SetDefaultColor( const QColor & nw_def_color )
{
    def_color_ = cur_color_ = nw_def_color;
}