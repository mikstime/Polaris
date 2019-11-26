#ifndef GRAPHNODE_HPP
#define GRAPHNODE_HPP

#include "GraphConnection/GraphConnection.h"
#include "typedefs.h"
namespace Polaris
{
/******************************************************************************
 * GraphNode - structure to store id of node in a graph.
 * GraphNode has no specific data. Only id_  inherited from GraphElement
 *****************************************************************************/
struct GraphNode: public GraphElement
{
    /**************************************************************************
     * default constructor.
     *************************************************************************/
     GraphNode() = default;
    /**************************************************************************
     * copy constructor
     *************************************************************************/
     GraphNode( const GraphNode & ) = default;
    /**************************************************************************
     * move constructor
     *************************************************************************/
     GraphNode( GraphNode && ) = default;
    /**************************************************************************
     * default destructor
     *************************************************************************/
     ~GraphNode() = default;
    /**************************************************************************
     * Create Node with specified Id.
     *************************************************************************/
    explicit GraphNode( const Id & id ): GraphElement( id ) {};
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHNODE_HPP
