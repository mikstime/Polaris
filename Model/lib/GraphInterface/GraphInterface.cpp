#include "include/GraphInterface/GraphInterface.h"
#include <boost/container/flat_set.hpp>
#include <utility> //std::pair
using namespace Polaris;
bool GraphInterface::AddConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode,
        const ConnectionParams & params )
{
    //Delegate to AddConnection( Id, Id ).
    AddConnection( firstNode.GetId(), lastNode.GetId(), params );
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
    // Create connection object.
    GraphConnection new_connection( firstNodeId, lastNodeId, params );
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

    graph_.connections.erase( key );
    return true;
}

bool GraphInterface::AddNode( const GraphNode & node )
{
    if( HasNode( node ) )
        return false;
    graph_.nodes.insert( node );
    return true;
}

bool GraphInterface::RemoveNode( const GraphNode & node )
{
    // find element
    auto it = std::find( graph_.nodes.begin(), graph_.nodes.end(), node );
    // return false if not found
    if( it == graph_.nodes.end() )
        return false;
    // delete element and return true
    graph_.nodes.erase( it );
    return true;
}

bool GraphInterface::RemoveNode( Id nodeId )
{
    return RemoveNode( GraphNode( nodeId ) );
}

bool GraphInterface::HasNode( const GraphNode & node )
{
    auto it = std::find( graph_.nodes.begin(), graph_.nodes.end(), node );
    return it != graph_.nodes.end();
}

bool GraphInterface::HasNode( Id nodeId )
{
    return HasNode( GraphNode( nodeId ) );
}

bool GraphInterface::AreConnected(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return false;
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
    return graph_.connections.at( key );
}

bool GraphInterface::SetConnectionParams(
        Id firstNodeId,
        Id lastNodeId,
        const ConnectionParams & params )
{
    std::pair< Id, Id > key( firstNodeId, lastNodeId );
    // Not connected
    if( graph_.connections.find( key ) == graph_.connections.end() )
        return false;
    //@TODO should I implement method in GeaphConnection for this
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
    graph_.connections[ key ] = connection;
    return true;
}

const GraphNode & GraphInterface::getNode( Id nodeId )
{
    //@TODO implement this.
    return * graph_.nodes.find( GraphNode( nodeId ) );
}