#include "include/ModelInterface/ModelInterface.h"
#include "typedefs.h"
/******************************************************************************
 * AddConnection Methods
 *****************************************************************************/
void Polaris::ModelInterface::AddConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode,
        const Polaris::ConnectionParams & params )
{
    GraphConnection new_connection( firstNode.GetId(),
                                    lastNode.GetId(),
                                    params );
    proxy_->AddConnection( new_connection, model_, observer_ );
}

void Polaris::ModelInterface::AddConnection(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId,
        const Polaris::ConnectionParams & params )
{
    GraphConnection new_connection( firstNodeId, lastNodeId, params );
    proxy_->AddConnection( new_connection, model_, observer_ );
}

void Polaris::ModelInterface::AddConnection(
        const Polaris::GraphConnection & new_connection )
{
    proxy_->AddConnection( new_connection, model_, observer_ );
}
/******************************************************************************
 * RemoveConnnectio Methods
 *****************************************************************************/
void Polaris::ModelInterface::RemoveConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    proxy_->RemoveConnection( firstNode.GetId(), lastNode.GetId(),
                      model_, observer_ );
}

void Polaris::ModelInterface::RemoveConnection(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId )
{
    proxy_->RemoveConnection( firstNodeId, lastNodeId, model_, observer_ );
}
/******************************************************************************
 * AddNode Methods
 *****************************************************************************/
void Polaris::ModelInterface::AddNode(
        Polaris::GraphNode & node )
{
    proxy_->AddNode( node, model_, observer_ );
}

void Polaris::ModelInterface::AddNode(
        const Polaris::Id & node_id )
{
    GraphNode node( node_id );
    proxy_->AddNode( node, model_, observer_ );
}
/******************************************************************************
 * RemoveNode Methods
 *****************************************************************************/
void Polaris::ModelInterface::RemoveNode(
        const Polaris::GraphNode & node )
{
    proxy_->RemoveNode( node.GetId(), model_, observer_ );
}

void Polaris::ModelInterface::RemoveNode( const Polaris::Id & nodeId )
{
    proxy_->RemoveNode( nodeId, model_, observer_ );
}
/******************************************************************************
 * FindPath Methods
 *****************************************************************************/
void Polaris::ModelInterface::FindPath(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    proxy_->FindPath( firstNode.GetId(), lastNode.GetId(), model_, observer_ );
}

void Polaris::ModelInterface::FindPath(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId )
{
    proxy_->FindPath( firstNodeId, lastNodeId, model_, observer_ );
}
/******************************************************************************
 * Observer Methods
 *****************************************************************************/
void Polaris::ModelInterface::Subscribe(
        Polaris::ModelSubscriber * & subscriber )
{
    proxy_->Subscribe( subscriber, model_, observer_ );
}

void Polaris::ModelInterface::Unsubscribe(
        Polaris::ModelSubscriber * & subscriber )
{
    proxy_->Unsubscribe( subscriber, model_, observer_ );
}
/******************************************************************************
 * ChangeMeta Methods
 *****************************************************************************/
void Polaris::ModelInterface::ChangeMeta(
        const Polaris::Id & nodeId,
        const Polaris::Meta & newMeta )
{
    proxy_->ChangeMeta( nodeId, newMeta, model_, observer_ );
}