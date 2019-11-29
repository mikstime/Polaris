#include "include/graphic_item.h"

using Polaris::GraphicItem;

GraphicItem::GraphicItem( const size_t & id, const int8_t & floor, const std::string & role )
: id_( id ),
floor_( floor ),
role_( role )
{

}

size_t GraphicItem::GetId() const
{
    return id_;
}

int8_t GraphicItem::GetFloor() const
{
    return floor_;
}

std::string GraphicItem::GetRole() const
{
    return role_;
}