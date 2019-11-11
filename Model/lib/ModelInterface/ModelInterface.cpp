#include "include/ModelInterface/ModelInterface.h"

void Polaris::ModelInterface::GetMetaByNodeId(
        Polaris::Id GraphNodeId )
{
    proxy_.GetMetaByNodeId( GraphNodeId, model_ );
}

void Polaris::ModelInterface::AddConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    proxy_.AddConnection( firstNode, lastNode, model_ );
}

void Polaris::ModelInterface::AddConnection(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{
    proxy_.AddConnection( firstNodeId, lastNodeId, model_ );
}

void
Polaris::ModelInterface::RemoveConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    proxy_.RemoveConnection( firstNode, lastNode, model_ );
}

void Polaris::ModelInterface::RemoveConnection(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{
    proxy_.RemoveConnection( firstNodeId, lastNodeId, model_ );
}

void Polaris::ModelInterface::AddNode(
        const Polaris::GraphNode & node )
{
    proxy_.AddNode( node, model_ );
}

void Polaris::ModelInterface::RemoveNode(
        const Polaris::GraphNode & node )
{
    proxy_.RemoveNode( node, model_ );
}

void Polaris::ModelInterface::RemoveNode(
        Polaris::Id nodeId )
{
    proxy_.RemoveNode( nodeId, model_ );
}

void Polaris::ModelInterface::FindPath(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    proxy_.FindPath( firstNode, lastNode, model_ );
}

void Polaris::ModelInterface::FindPath(
        Polaris::Id firstNodeId,
        Polaris::Id lastNodeId )
{
    proxy_.FindPath(firstNodeId, lastNodeId, model_ );
}

void Polaris::ModelInterface::Subscribe(
        const Polaris::ModelSubscriber & subscriber )
{

}

void Polaris::ModelInterface::Unsubscribe(
        const Polaris::ModelSubscriber & subscriber )
{

}

void Polaris::ModelInterface::ChangeMeta(
        Polaris::Id nodeId,
        const Polaris::Meta & newMeta )
{

}
