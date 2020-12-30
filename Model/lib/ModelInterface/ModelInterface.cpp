#include "include/ModelInterface/ModelInterface.h"

/******************************************************************************
 * AddConnection Methods
 *****************************************************************************/
bool Polaris::ModelInterface::AddConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode,
        const Polaris::ConnectionParams & params )
{
    GraphConnection new_connection( firstNode.GetId(),
                                    lastNode.GetId(),
                                    params );
    return proxy_->AddConnection( new_connection,
                               model_, observer_ );
}

bool Polaris::ModelInterface::AddConnection(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId,
        const Polaris::ConnectionParams & params )
{
    return proxy_->AddConnection( firstNodeId, lastNodeId, params ,
                                model_, observer_ );
}

bool Polaris::ModelInterface::AddConnection(
        const Polaris::GraphConnection & new_connection )
{
    ConnectionParams c;
    c.cost = new_connection.cost;
    return proxy_->AddConnection( new_connection.from, new_connection.to, c,  model_, observer_ );
}
/******************************************************************************
 * RemoveConnection Methods
 *****************************************************************************/
bool Polaris::ModelInterface::RemoveConnection(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    return proxy_->RemoveConnection( firstNode.GetId(), lastNode.GetId(),
                      model_, observer_ );
}

bool Polaris::ModelInterface::RemoveConnection(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId )
{
    return proxy_->RemoveConnection( firstNodeId, lastNodeId,
                                  model_, observer_ );
}
/******************************************************************************
 * AddNode Methods
 *****************************************************************************/
bool Polaris::ModelInterface::AddNode(
        Polaris::GraphNode & node )
{
    return proxy_->AddNode( node, model_, observer_ );
}

bool Polaris::ModelInterface::AddNode(
        const Polaris::Id & node_id )
{
    GraphNode node( node_id );
    return proxy_->AddNode( node, model_, observer_ );
}
/******************************************************************************
 * RemoveNode Methods
 *****************************************************************************/
bool Polaris::ModelInterface::RemoveNode(
        const Polaris::GraphNode & node )
{
    return proxy_->RemoveNode( node.GetId(), model_, observer_ );
}

bool Polaris::ModelInterface::RemoveNode( const Polaris::Id & nodeId )
{
    return proxy_->RemoveNode( nodeId, model_, observer_ );
}
/******************************************************************************
 * FindPath Methods
 *****************************************************************************/
bool Polaris::ModelInterface::FindPath(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode )
{
    return proxy_->FindPath( firstNode.GetId(), lastNode.GetId(),
                          model_, observer_ );
}

bool Polaris::ModelInterface::FindPath(
        const Polaris::Id & firstNodeId,
        const Polaris::Id & lastNodeId )
{
    return proxy_->FindPath( firstNodeId, lastNodeId, model_, observer_ );
}
/******************************************************************************
 * Observer Methods
 *****************************************************************************/
bool Polaris::ModelInterface::Subscribe(
        std::shared_ptr< ModelSubscriber > & subscriber )
{
    return proxy_->Subscribe( subscriber, model_, observer_ );
}

bool Polaris::ModelInterface::Unsubscribe(
        std::shared_ptr< ModelSubscriber > & subscriber )
{
    return proxy_->Unsubscribe( subscriber, model_, observer_ );
}
/******************************************************************************
 * ChangeMeta Methods
 *****************************************************************************/
bool Polaris::ModelInterface::ChangeMeta(
        const Polaris::Id & nodeId,
        const Polaris::Meta & newMeta )
{
    return proxy_->ChangeMeta( nodeId, newMeta, model_, observer_ );
}

bool Polaris::ModelInterface::hasMeta( const Polaris::Id & metaId )
{
    // https://stackoverflow.com/a/15792245/11503488
    return model_.meta.count( metaId ) > 0;
}
Polaris::Meta Polaris::ModelInterface::getMeta( const Polaris::Id & metaId )
{
    return model_.meta[ metaId ];
}

void Polaris::ModelInterface::__triggerModelEvents()
{
    for( auto & node : model_.graph.getGraph().nodes )
    {
        observer_->NodeAdded( node );
    }
    for( auto & connection : model_.graph.getGraph().connections )
    {
        observer_->ConnectionAdded( connection.second );
    }
    for( auto & meta : model_.meta )
    {
        observer_->MetaAdded( meta.second );
    }
}
void Polaris::ModelInterface::clearModel()
{
    for( auto & node : model_.graph.getGraph().nodes )
    {
        observer_->NodeRemoved( node );
    }
    for( auto & connection : model_.graph.getGraph().connections )
    {
        observer_->ConnectionRemoved( connection.second );
    }
    for( auto & meta : model_.meta )
    {
        observer_->MetaRemoved( meta.second );
    }
    model_ = Model();
}
