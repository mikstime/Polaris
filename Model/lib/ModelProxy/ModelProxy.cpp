#include "include/ModelProxy/ModelProxy.h"
#include "include/GraphInterface/GraphInterface.h"
using namespace Polaris;
bool ModelProxy::AddConnection( const GraphConnection & connection,
        const Model & model, ModelObserver * observer )
{
    GraphInterface graph( model.graph );

    if( graph.AddConnection( connection ) )
    {
        observer->ConnectionAdded( connection );
        return true;
    }
    return false;
}

bool ModelProxy::AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                                const ConnectionParams & params,
                                const Model & model, ModelObserver * observer )
{
    GraphInterface graph( model.graph );

    if( graph.AddConnection( firstNodeId, lastNodeId, params ) )
    {
        auto connection = graph.getConnection( firstNodeId, lastNodeId );
        observer->ConnectionAdded( connection );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   const Model & model,
                                   ModelObserver * observer )
{
    return RemoveConnection( firstNode.GetId(), lastNode.GetId(),
                             model, observer );
}

bool ModelProxy::RemoveConnection( Id firstNodeId, Id lastNodeId,
                                   const Model & model,
                                   ModelObserver * observer )
{
    GraphInterface graph( model.graph );

    auto connection = graph.getConnection( firstNodeId, lastNodeId );

    if( graph.RemoveConnection( firstNodeId, lastNodeId ) )
    {
        observer->ConnectionRemoved( connection );
        return true;
    }
    return false;
}

bool ModelProxy::AddNode( const GraphNode & node, const Model & model,
                          ModelObserver * observer )
{
    GraphInterface graph( model.graph );
    if( graph.AddNode( node ) )
    {
        observer->NodeAdded( node );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveNode( const GraphNode & node, const Model & model,
                             ModelObserver * observer )
{
    GraphInterface graph( model.graph );
    if( graph.RemoveNode( node ) )
    {
        observer->NodeRemoved( node );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveNode( Id nodeId, const Model & model,
                             ModelObserver * observer )
{
    GraphInterface graph( model.graph );

    auto node = graph.getNode( nodeId );

    if( graph.RemoveNode( nodeId ) )
    {
        observer->NodeRemoved( node );
        return true;
    }
    return false;
}

bool ModelProxy::FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode,
                           const Model & model, ModelObserver * observer )
{
    //@TODO implement later
}

bool ModelProxy::FindPath( Id firstNodeId, Id lastNodeId,
                           const Model & model, ModelObserver * observer )
{
    //@TODO implement later
}

bool ModelProxy::Subscribe( const ModelSubscriber * & subscriber,
                            const Model & model,
                            ModelObserver * observer ) const
{
    return observer->Subscribe( subscriber );
}

bool ModelProxy::Unsubscribe( const ModelSubscriber * & subscriber,
                              const Model & model,
                              ModelObserver * observer ) const
{
    return observer->unSubscribe( subscriber );
}