#ifndef META_HPP
#define META_HPP

#include "typedefs.h"

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
    std::size_t room_number;
    Coordinate x, y;
public:
    /**************************************************************************
     * default constructor.
     *************************************************************************/
    Meta() = default;
    /**************************************************************************
     * copy constructor
     *************************************************************************/
    Meta( const Meta & meta ) = default;
    /**************************************************************************
     * move constructor
     *************************************************************************/
    Meta( Meta && meta ) = default;
    /**************************************************************************
     * default destructor.
     *************************************************************************/
    ~Meta() = default;
};
} //namespace Polaris

#endif //META_HPP
