#ifndef META_HPP
#define META_HPP

#include <string>

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
    Coordinate x, y;
    int8_t floor;
};
} //namespace Polaris

#endif //META_HPP
