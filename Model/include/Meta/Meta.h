#ifndef GRAPHSEARCH_META_HPP
#define GRAPHSEARCH_META_HPP

namespace Polaris
{
// Type used in GraphNode for id_ field;
using Id = size_t;
/******************************************************************************
 * Meta structure is used to store additional information about GraphNode.
 * It is separated from GraphNode to increase flexibility
 * between project parts.
 *****************************************************************************/
struct Meta
{
public:
    Id graph_node_id;
    size_t room_number;
    double x, y;
public:
    explicit Meta( Id a_graph_node_id, size_t a_room_number = 0,
            double a_x = 0, double a_y = 0 )
    : graph_node_id( a_graph_node_id ),
    room_number( a_room_number ),
    x( a_x ), y( a_y ){};
};
} //namespace Polaris

#endif //GRAPHSEARCH_META_HPP
