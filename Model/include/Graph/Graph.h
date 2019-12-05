#ifndef GRAPHSEARCH_GRAPH_H
#define GRAPHSEARCH_GRAPH_H

#include "GraphConnection/GraphConnection.h"
#include "GraphNode/GraphNode.h"
#include <cstddef> // std::size_t
#include <utility> // std::move
#include <vector> // std::vector
#include <map> //std::map
//@TODO#include <pair> //std::pair
#include <set> //std::set
namespace Polaris
{
class NodeComparator
{
public:
    bool operator()( const GraphNode & a, const GraphNode & b ) const
    {
        return a.GetId() < b.GetId();
    }
};
using GraphConnections = std::map<
        std::pair< Id, Id >,
        GraphConnection >;
using GraphNodes = std::set< GraphNode >;
/******************************************************************************
 * Graph structure stores all vertices and connections in graph.
 * Connections are stored in adjacency matrix.
 * Nodes - in sorted by Id array.
 * All logic provided in GraphInterface class.
 *****************************************************************************/
struct Graph
{
public:
    GraphConnections connections;
    GraphNodes nodes;
public:
    /**************************************************************************
     * default constructor
     *************************************************************************/
     Graph():connections(), nodes(){};
//     Graph(): connections(), nodes(
//             [](const GraphNode & a, const GraphNode & b)
//             { return a.getId() < b.getId(); }, boost::container::new_allocator()
//     ) {};
    /**************************************************************************
     * Graph( nodes, connections )
     * Arguments:
     * nodes - initial state of nodes
     * connections - initial state of connections
     *************************************************************************/
    Graph( GraphNodes  a_nodes,
           GraphConnections  a_connections )
    : connections( std::move(a_connections) ), nodes( std::move( a_nodes) ) {};
    /**************************************************************************
     * Graph( nodes )
     * Arguments:
     * nodes - initial state of nodes. Connections are empty.
     *************************************************************************/
    explicit Graph( GraphNodes  a_nodes )
    : connections(), nodes(std::move( a_nodes )) {};
    /**************************************************************************
     * Graph( connections )
     * Arguments:
     * connections - initial state of connections. Nodes are empty.
     *************************************************************************/
    explicit Graph( GraphConnections  a_connections )
    : connections(std::move( a_connections )), nodes() {};
};
} //namespace Polaris

#endif //GRAPHSEARCH_GRAPH_H
