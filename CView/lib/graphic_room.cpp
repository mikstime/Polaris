#include "include/graphic_room.h"
using Polaris::GraphicRoom;

GraphicRoom::GraphicRoom( const Meta & node, const QRectF & size )
    : size_( size )
{
}

std::string GraphicRoom::GetInfo() const
{
    return info_;
}

size_t GraphicRoom::GetId() const
{
    return id_;
}

int8_t GraphicRoom::GetFloor() const
{
    return floor_;
}

std::string GraphicRoom::GetRole() const
{
    return role_;
}