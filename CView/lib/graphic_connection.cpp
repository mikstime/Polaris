#include "include/graphic_connection.h"

using Polaris::GraphicConnection;

GraphicConnection::GraphicConnection( const QPointF & left, const QPointF & right, const GraphConnection & connection )
    : left_( left ), right_( right )
{
}

double GraphicConnection::GetPrice() const
{
    return price_;
}

size_t GraphicConnection::GetId() const
{
    return id_;
}

int8_t GraphicConnection::GetFloor() const
{
    return floor_;
}

std::string GraphicConnection::GetRole() const
{
    return role_;
}
