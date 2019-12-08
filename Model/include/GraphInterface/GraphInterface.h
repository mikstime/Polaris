#ifndef POLARISMODEL_GRAPHINTERFACE_H
#define POLARISMODEL_GRAPHINTERFACE_H

#include "GraphConnection/GraphConnection.h"
#include "GraphNode/GraphNode.h"
#include "include/Graph/Graph.h"
#include "typedefs.h"
#include <algorithm>
#include <utility>
namespace Polaris
{
/******************************************************************************
 * GraphInterface class provides access to data managment inside graph.
 *****************************************************************************/
class GraphInterface
{
private:
    Graph graph_;
public:
    GraphInterface(): graph_() {};
    explicit GraphInterface( Graph & g ): graph_( std::move( g ) ){};
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to be connected.
     * params - parameters of connection
     *************************************************************************/
    bool AddConnection( const GraphConnection & connection );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to be connected.
     * params - parameters of connection
     *************************************************************************/
    bool AddConnection( GraphNode & firstNode,
                        GraphNode & lastNode,
                        const ConnectionParams & params );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last node Ids -id of nodes to be connected.
     *************************************************************************/
    bool AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                        const ConnectionParams & params );
    /**************************************************************************
     * SetConnectionParams
     * Arguments:
     * first and last node Ids - Id of connected nodes whose information
     * must be updated
     *************************************************************************/
    bool SetConnectionParams( Id firstNodeId, Id lastNodeId,
                              const ConnectionParams & params );
    /**************************************************************************
     * SetConnectionParams
     * Arguments:
     * first and last node Ids - Id of connected nodes whose information
     * must be updated
     *************************************************************************/
    bool SetConnectionParams( const GraphNode & firstNode,
                              const GraphNode & lastNode,
                              const ConnectionParams & params );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last nodes - nodes connection between which must be destructed
     *************************************************************************/
    bool RemoveConnection( const GraphNode & firstNode,
                           const GraphNode & lastNode );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node ids - id of nodes connection between which
     * must be destructed
     *************************************************************************/
    bool RemoveConnection( Id firstNodeId, Id lastNodeId );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to be inserted in graph
     *************************************************************************/
    bool AddNode( GraphNode & node );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to be removed from graph
     *************************************************************************/
    bool RemoveNode( GraphNode & node );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node Id - id of node to be removed from graph
     *************************************************************************/
    bool RemoveNode( Id nodeId );
    /**************************************************************************
     * HasNode
     * Arguments:
     * node - check whether node is presented in graph
     * ReturnValue:
     * true if so and false if not.
     *************************************************************************/
    bool HasNode( const GraphNode & node );
    /**************************************************************************
     * HasNode
     * Arguments:
     * node id - check whether node with specified id is presented in graph
     * ReturnValue:
     * true if so and false if not.
     *************************************************************************/
    bool HasNode( Id nodeId );
    /**************************************************************************
     * AreConnected
     * Arguments:
     * first and last nodes - check if this nodes are connected
     * ReturnValue:
     * true if so and false if not.
     *************************************************************************/
    bool AreConnected( const GraphNode & firstNode,
                       const GraphNode & lastNode );
    /**************************************************************************
     * AreConnected
     * Arguments:
     * first and last node Ids - check whether nodes with specified
     * ids are connected
     * ReturnValue:
     * true if so and false if not.
     *************************************************************************/
    bool AreConnected( Id firstNodeId, Id lastNodeId );
    /**************************************************************************
     * getConnection
     * Arguments:
     * first and last nodes - connected nodes.
     * ReturnValue:
     * Connection between specified nodes
     *************************************************************************/
    const GraphConnection & getConnection( const GraphNode & firstNode,
                                           const GraphNode & lastNode );
    /**************************************************************************
     * getConnection
     * Arguments:
     * first and last node ids - ids of two connected nodes.
     * ReturnValue:
     * Connection between specified nodes
     *************************************************************************/
    const GraphConnection & getConnection( Id firstNodeId, Id lastNodeId );
    /**************************************************************************
     * getNode
     * Arguments:
     * nodeId - id of desirable node
     * ReturnValue:
     * Node with specified Id
     *************************************************************************/
    GraphNode & getNode( Id nodeId );
    /**************************************************************************
     * getGraph
     * Arguments:
     * ReturnValue:
     * graph itself
     *************************************************************************/
     Graph & getGraph() { return graph_ ; }
};
} //namespace Polaris

#endif //POLARISMODEL_GRAPHINTERFACE_H
