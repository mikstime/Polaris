#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include "GraphConnection/GraphConnection.h"
#include <vector>
#include "typedefs.h"
namespace Polaris
{
/******************************************************************************
 * GraphNode - structure to store id of node in a graph.
 * GraphNode has no specific data. Only id_  inherited from GraphElement
 *****************************************************************************/
struct GraphNode: public GraphElement
{
public:
    std::vector< Id > neighbors;
public:
//    bool operator==(const GraphNode & __x ) const
//    {
//        return GetId() == __x.GetId();
//    }
//    bool operator!=(const GraphNode & __x ) const
//    {
//        return GetId() != __x.GetId();
//    }
    friend bool operator>( const GraphNode & l, const GraphNode & r )
    {
        return l.GetId() > r.GetId();
    }
    friend bool operator<( const GraphNode & l, const GraphNode & r )
    {
        return l.GetId() < r.GetId();
    }
    friend bool operator==( const GraphNode & l, const GraphNode & r )
    {
        return l.GetId() == r.GetId();
    }
    friend bool operator!=( const GraphNode & l, const GraphNode & r )
    {
        return l.GetId() != r.GetId();
    }
    /**************************************************************************
     * default constructor.
     *************************************************************************/
     GraphNode():GraphElement(), neighbors(){};
    /**************************************************************************
     * copy constructor
     *************************************************************************/
     GraphNode( const GraphNode & c ):GraphElement( c.GetId() ),
     neighbors( c.neighbors ){};
    /**************************************************************************
     * move constructor
     *************************************************************************/
//     GraphNode( GraphNode && ) = default;
    /**************************************************************************
     * default destructor
     *************************************************************************/
     //~GraphNode() = default;
    /**************************************************************************
     * Create Node with specified Id.
     *************************************************************************/
    explicit GraphNode( const Id & id ): GraphElement( id ), neighbors() {};
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHNODE_HPP
