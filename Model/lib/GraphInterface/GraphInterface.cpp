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
        // Do nothing. Connection already exists.
        return;
    }
    // Create connection object.
    GraphConnection newConnection( firstNodeId, lastNodeId );
    // Create a key ( pair ).
    std::pair< Id, Id > key( firstNodeId, lastNodeId );

}

bool GraphInterface::RemoveConnection(
        const GraphNode & firstNode,
        const GraphNode & lastNode )
{

}

bool GraphInterface::RemoveConnection(
        Id firstNodeId,
        Id lastNodeId )
{

}

bool GraphInterface::AddNode( const GraphNode & node )
{
//    graph_.nodes.insert(node);
}

bool GraphInterface::RemoveNode( const GraphNode & node )
{

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