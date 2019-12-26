#ifndef META_HPP
#define META_HPP

#include <string>
#include "typedefs.h"
#include <qpoint.h>
#include <qpolygon.h>
#include <iostream>

namespace Polaris
{
// Type used in GraphNode for id_ field;
/******************************************************************************
 * Meta structure is used to store additional information about GraphNode.
 * It is separated from GraphNode to increase flexibility
 * between project parts.
 *****************************************************************************/
struct Meta
{
public:
    Id graph_node_id;
    std::string room_number;
    std::string info;
    QPointF coordinates;
    QPolygonF size;
    int8_t floor;
    Role role;

    friend bool operator==( const Meta & a, const Meta & b )
    {
        return a.graph_node_id == b.graph_node_id &&
               a.room_number == b.room_number &&
               a.info == b.info &&
               a.coordinates == b.coordinates &&
               a.size == b.size &&
               a.floor == b.floor &&
               a.role == b.role;
    }
};

} //namespace Polaris

#endif //META_HPP