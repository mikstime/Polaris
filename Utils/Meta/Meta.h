#ifndef META_HPP
#define META_HPP

#include <string>
#include "typedefs.h"
#include "qpoint.h"
#include "qpolygon.h"

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
    QPointF coordinates;
    QPolygonF size;
    int8_t floor;
    Role role;
};
} //namespace Polaris

#endif //META_HPP