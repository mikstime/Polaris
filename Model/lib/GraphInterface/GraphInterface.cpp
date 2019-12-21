#include "include/GraphInterface/GraphInterface.h"
using namespace Polaris;
bool GraphInterface::AddConnection(
        GraphNode & firstNode,
        GraphNode & lastNode,
        const ConnectionParams & params )
{
    // Delegate to AddConnection( Id, Id ).
    return AddConnection( firstNode.GetId(), lastNode.GetId(), params );
}

bool GraphInterface::AddConnection(
        const Id & firstNodeId,
        const Id & lastNodeId,
        const ConnectionParams & params )
{
    if( AreConnected( firstNodeId, lastNodeId ) ||
        AreConnected( lastNodeId, firstNodeId ) )
    {
        // Connection already exists.
        return false;
    }
    if( !HasNode( firstNodeId ) || !HasNode( lastNodeId ) )
        return false;
    // Create connection object.
    GraphConnection new_connection( firstNodeId, lastNodeId, params );
    // update neighbors
    GraphNode & n1 = getNode( firstNodeId );
    GraphNode & n2 = getNode( lastNodeId  );
    n1.neighbors.push_back( lastNodeId );
    n2.neighbors.push_back( firstNodeId );
    // Create a key ( pair ).
    std::pair< Id, Id > key1( firstNodeId, lastNodeId );
    std::pair< Id, Id > key2( lastNodeId, firstNodeId );
    // store connection
    graph_.connections[ key1 ] = new_connection;
    graph_.connections[ key2 ] = new_connection;
    return true;
}

bool GraphInterface::RemoveConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    //Delegate to RemoveConnection( Id, Id ).
    return RemoveConnection( firstNode.GetId(), lastNode.GetId() );
}

bool GraphInterface::RemoveConnection(
        Id firstNodeId,
        Id lastNodeId )
{
    // Connection does not exists
    if( !AreConnected( firstNodeId, lastNodeId ) )
        return false;
    // Remove neighbour from first node
    if( HasNode( firstNodeId ) )
    {
        GraphNode & n1 = getNode( firstNodeId );
        auto it = std::find( n1.neighbors.begin(),
                             n1.neighbors.end(), lastNodeId );
        if( it != n1.neighbors.end() )
            n1.neighbors.erase( it );
    }
    // Remove neighbour from second node
    if( HasNode( lastNodeId ) )
    {
        GraphNode & n2 = getNode( lastNodeId );
        // Remove connection from second one
        auto it = std::find( n2.neighbors.begin(),
                             n2.neighbors.end(), firstNodeId );
        if( it != n2.neighbors.end() )
            n2.neighbors.erase( it );
    }
    // key
    std::pair< Id, Id > key1( firstNodeId, lastNodeId );
    std::pair< Id, Id > key2( lastNodeId, firstNodeId );
    graph_.connections.erase( key1 );
    graph_.connections.erase( key2 );
    return true;
}

bool GraphInterface::AddNode( GraphNode & node )
{
    // Node already exists
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
        // Remove all connections linked to node
        RemoveConnection( n_id, node.GetId() );
        RemoveConnection( node.GetId(), n_id );
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

bool GraphInterface::AreConnected( Id firstNodeId, Id lastNodeId )
{
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
    std::pair< Id, Id > key1( connection.from, connection.to );
    std::pair< Id, Id > key2( connection.to, connection.from );

    if( AreConnected( connection.from, connection.to ) )
        return false;
    if( !HasNode( connection.from ) || !HasNode( connection.to ) )
        return false;
    auto & n1 = getNode( connection.from );
    auto & n2 = getNode( connection.to );
    // Update node's neighbors
    n1.neighbors.push_back( connection.to );
    n2.neighbors.push_back( connection.from );
    // Insert new connection
    graph_.connections[ key1 ] = connection;
    graph_.connections[ key2 ] = connection;
    return true;
}

GraphNode & GraphInterface::getNode( Id nodeId )
{
    GraphNode n( nodeId );
    //O( LogN )
    return const_cast< GraphNode & >( * graph_.nodes.find( n ) );
}