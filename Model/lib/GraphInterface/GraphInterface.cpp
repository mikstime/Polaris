#include "include/GraphInterface/GraphInterface.h"
#include <boost/container/flat_set.hpp>

void Polaris::GraphInterface::AddConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{

}

void Polaris::GraphInterface::AddConnection(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{

}

void Polaris::GraphInterface::RemoveConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{

}

void Polaris::GraphInterface::RemoveConnection(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{

}

void Polaris::GraphInterface::AddNode( const Polaris::GraphNode & node )
{
//    graph_.nodes.insert(node);
}

void Polaris::GraphInterface::RemoveNode( const Polaris::GraphNode & node )
{

}

void Polaris::GraphInterface::RemoveNode( Polaris::Id nodeId )
{

}

bool Polaris::GraphInterface::HasNode( const Polaris::GraphNode & node )
{
    return false;
}

bool Polaris::GraphInterface::HasNode( Polaris::Id nodeId )
{
    return false;
}

bool Polaris::GraphInterface::AreConnected(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    return false;
}

bool Polaris::GraphInterface::AreConnected( Polaris::Id firstNodeId,
                                            Polaris::Id lastNodeId ) {
    return false;
}

const Polaris::GraphConnection & Polaris::GraphInterface::getConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    return graph_.connections[ 0 ];
}

const Polaris::GraphConnection & Polaris::GraphInterface::getConnection(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{
    return graph_.connections[ 0 ];
}

//const Polaris::GraphNode & Polaris::GraphInterface::getNode(
//        Polaris::Id nodeId )
//{
//    return GraphNode();
//}

void Polaris::GraphInterface::SetConnectionParams(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId,
        Polaris::ConnectionParams params )
{

}

void Polaris::GraphInterface::SetConnectionParams(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode,
        Polaris::ConnectionParams params )
{

}
