#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <cstddef> //std::size_t

namespace Polaris
{
    using Id = std::size_t;
    using Price = double;
    using Coordinate = double;

    enum class Role
    {
        MARK,
        ROOM,
        HALL,
        STAIR,
        CONNECTION
    };
} //namespace Polaris

#endif