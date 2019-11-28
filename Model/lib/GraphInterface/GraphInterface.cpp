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
    if( !HasNode( node ))
        return false;
//    graph_.nodes.erase()
}

bool GraphInterface::RemoveNode( Id nodeId )
{

}

bool GraphInterface::HasNode( const GraphNode & node )
{
    return false;
}

bool GraphInterface::HasNode( Id nodeId )
{
    return false;
}

bool GraphInterface::AreConnected(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return false;
}

bool GraphInterface::AreConnected( Id firstNodeId,
                                            Id lastNodeId ) {
    return false;
}

const GraphConnection & GraphInterface::getConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{
    return graph_.connections[ 0 ];
}

const GraphConnection & GraphInterface::getConnection(
        Id firstNodeId,
        Id lastNodeId )
{
    return graph_.connections[ 0 ];
}

//const GraphNode & GraphInterface::getNode(
//        Id nodeId )
//{
//    return GraphNode();
//}

bool GraphInterface::SetConnectionParams(
        Id firstNodeId,
        Id lastNodeId,
        ConnectionParams params )
{

}

bool GraphInterface::SetConnectionParams(
        const GraphNode & firstNode,
        const GraphNode & lastNode,
        ConnectionParams params )
{

}

bool GraphInterface::AddConnection(
        const GraphConnection & connection )
{

}

const GraphNode & GraphInterface::getNode( Id nodeId )
{
    //@TODO implement this.
    return graph_.nodes[ nodeId ];
}