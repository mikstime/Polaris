#ifndef GRAPHSEARCH_GRAPHNODE_HPP
#define GRAPHSEARCH_GRAPHNODE_HPP

#include "include/GraphElement/GraphElement.h"
#include "include/GraphConnection/GraphConnection.h"
#include <vector>

namespace Polaris
{
class GraphNode: public GraphElement
{
using Connections = std::vector< GraphConnection >;
public:
    Connections connections;
public:
    GraphNode();
    GraphNode( GraphNode const & );
    GraphNode( GraphNode && ) noexcept ;
    ~GraphNode();

    void AddNeighbor( const GraphNode & );
    void RemoveNeighbor( const GraphNode & );
    void AddConnection( const GraphConnection & );
    void RemoveConnection( const GraphConnection & );
    bool HasNeighbor( const GraphNode & );
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPHNODE_HPP
