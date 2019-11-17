#ifndef GRAPHSEARCH_GRAPH_H
#define GRAPHSEARCH_GRAPH_H

#include "include/GraphConnection/GraphConnection.h"
#include "include/GraphNode/GraphNode.h"
#include <cstddef> // std::size_t
#include <utility> // std::move
#include <vector> // std::vector
#include <set>
namespace Polaris
{
using Id = std::size_t;
using GraphConnections = std::vector< GraphConnection >;
using GraphNodes = std::set< GraphNode >;
/******************************************************************************
 * Graph structure stores all verticles and connections in graph.
 * Connections are stored in adjacency matrix.
 * Nodes - in sotrted by Id array.
 * All logics provided in GraphInterface class.
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
     Graph() = default;
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
    Graph( GraphNodes & a_nodes )
    : connections(), nodes(std::move( a_nodes ) ) {};
    /**************************************************************************
     * Graph( connections )
     * Arguments:
     * connections - initial state of connections. Nodes are empty.
     *************************************************************************/
    Graph( GraphConnections & a_connections )
    : connections( std::move( a_connections ) ), nodes() {};
};
} //namespace Polaris

#endif //GRAPHSEARCH_GRAPH_H
