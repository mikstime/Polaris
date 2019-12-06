#include "include/GraphInterface/GraphInterface.h"
#include <boost/container/flat_set.hpp>
#include <utility> //std::pair
using namespace Polaris;
bool GraphInterface::AddConnection(
        GraphNode & firstNode,
        GraphNode & lastNode,
        const ConnectionParams & params )
{
    //Delegate to AddConnection( Id, Id ).
    return AddConnection( firstNode.GetId(), lastNode.GetId(), params );
}

bool GraphInterface::AddConnection(
        const Id & firstNodeId,
        const Id & lastNodeId,
        const ConnectionParams & params )
{
    if( AreConnected( firstNodeId, lastNodeId ) )
    {
        // Connection already exists.
        return false;
    }
    //@TODO connect only if both nodes are contained in graph
    if( !HasNode( firstNodeId ) || !HasNode( lastNodeId ) )
        return false;
    // Create connection object.
    GraphConnection new_connection( firstNodeId, lastNodeId, params );
    GraphNode & n1 = getNode( firstNodeId );
    GraphNode & n2 = getNode( lastNodeId  );
    n1.neighbors.push_back( lastNodeId );
    n2.neighbors.push_back( firstNodeId );
    // Create a key ( pair ).
    std::pair< Id, Id > key( firstNodeId, lastNodeId );

    graph_.connections[ key ] = new_connection;
    return true;
}

bool GraphInterface::RemoveConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return RemoveConnection( firstNode.GetId(), lastNode.GetId() );
}

bool GraphInterface::RemoveConnection(
        Id firstNodeId,
        Id lastNodeId )
{
    if( !AreConnected( firstNodeId, lastNodeId ) )
        return false;
    std::pair< Id, Id > key( firstNodeId, lastNodeId );
    if( HasNode( firstNodeId ) )
    {
        GraphNode & n1 = getNode( firstNodeId );
        auto it = std::find( n1.neighbors.begin(), n1.neighbors.end(), lastNodeId );
        n1.neighbors.erase( it );
    }
    if( HasNode( lastNodeId ) )
    {
        GraphNode & n2 = getNode( lastNodeId );
        // Remove connection from second one
        auto it = std::find( n2.neighbors.begin(),
                             n2.neighbors.end(), firstNodeId );
        n2.neighbors.erase( it );
    }
    graph_.connections.erase( key );
    return true;
}

bool GraphInterface::AddNode( GraphNode & node )
{
    if( HasNode( node ) )
        return false;
    graph_.nodes.insert( node );
    return true;
}

bool GraphInterface::RemoveNode( GraphNode & node )
{
    // find element
    auto it = graph_.nodes.find( node );
    // return false if not found
    if( it == graph_.nodes.end() )
        return false;
    // Remove all related connections
    for( auto n_id : it->neighbors )
    {
        RemoveConnection( n_id, node.GetId() );
    }
    // delete element and return true
    graph_.nodes.erase( it );
    return true;
}

bool GraphInterface::RemoveNode( Id nodeId )
{
    GraphNode node( nodeId );
    return RemoveNode( node );
}

bool GraphInterface::HasNode( const GraphNode & node )
{
    // O(LogN)
    auto it = graph_.nodes.find( node );
    return it != graph_.nodes.end();
}
bool GraphInterface::HasNode( Id nodeId )
{
    GraphNode n( nodeId );
    return HasNode( n );
}

bool GraphInterface::AreConnected(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return AreConnected( firstNode.GetId(), lastNode.GetId() );
}

bool GraphInterface::AreConnected( Id firstNodeId,
                                            Id lastNodeId ) {
    std::pair< Id, Id > key( firstNodeId, lastNodeId );
    return graph_.connections.find( key ) != graph_.connections.end();
}

const GraphConnection & GraphInterface::getConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return getConnection( firstNode.GetId(), lastNode.GetId() );
}

const GraphConnection & GraphInterface::getConnection(
        Id firstNodeId,
        Id lastNodeId )
{
    std::pair< Id, Id > key( firstNodeId, lastNodeId );
    return graph_.connections[ key ];
}

bool GraphInterface::SetConnectionParams(
        Id firstNodeId,
        Id lastNodeId,
        const ConnectionParams & params )
{
    std::pair< Id, Id > key( firstNodeId, lastNodeId );
    // Not connected
    if( !AreConnected( firstNodeId, lastNodeId ) )
        return false;
    //@TODO should I implement method in GraphConnection for this
    graph_.connections[ key ].cost = params.cost;
    return true;
}

bool GraphInterface::SetConnectionParams(
        const GraphNode & firstNode,
        const GraphNode & lastNode,
        const ConnectionParams & params )
{
    return SetConnectionParams( firstNode.GetId(), lastNode.GetId(), params );
}

bool GraphInterface::AddConnection(
        const GraphConnection & connection )
{
    std::pair< Id, Id > key( connection.from, connection.to );
    if( graph_.connections.find( key ) != graph_.connections.end() )
        return false;
    auto & n1 = getNode( connection.from );
    auto & n2 = getNode( connection.to );
    // Update node's neighbors
    n1.neighbors.push_back( connection.to );
    n2.neighbors.push_back( connection.from );
    // Insert new connection
    graph_.connections[ key ] = connection;
    return true;
}

GraphNode & GraphInterface::getNode( Id nodeId )
{
    GraphNode n( nodeId );
    //O( LogN )
    return const_cast<GraphNode &>( * graph_.nodes.find( n ) );
}