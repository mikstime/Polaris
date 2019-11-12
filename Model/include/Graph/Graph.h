#ifndef GRAPHSEARCH_GRAPH_H
#define GRAPHSEARCH_GRAPH_H

#include "include/GraphConnection/GraphConnection.h"
#include "include/GraphNode/GraphNode.h"
#include <cstddef> // std::size_t
#include <utility> // std::move
#include <vector> // std::vector

namespace Polaris
{
using ID = std::size_t;
using GraphConnections = std::vector< GraphConnection >;
using GraphNodes = std::vector< GraphNode >;
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
     Graph(): connections(), nodes() {};
    /**************************************************************************
     * Graph( nodes, connections )
     * Arguments:
     * nodes - initial state of nodes
     * connections - initial state of connections
     *************************************************************************/
    Graph( const GraphNodes & a_nodes,
           const GraphConnections& a_connections )
    : connections(a_connections), nodes( a_nodes) {};
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
