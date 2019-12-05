#include "include/ModelProxy/ModelProxy.h"
#include "include/GraphInterface/GraphInterface.h"
using namespace Polaris;
bool ModelProxy::AddConnection( const GraphConnection & connection,
                                Model & model, ModelObserver * observer )
{
    

    if( model.graph.AddConnection( connection ) )
    {
        observer->ConnectionAdded( connection );
        return true;
    }
    return false;
}

bool ModelProxy::AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                                const ConnectionParams & params,
                                Model & model, ModelObserver * observer )
{
    

    if( model.graph.AddConnection( firstNodeId, lastNodeId, params ) )
    {
        auto connection = model.graph.getConnection( firstNodeId, lastNodeId );
        observer->ConnectionAdded( connection );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   Model & model,
                                   ModelObserver * observer )
{
    return RemoveConnection( firstNode.GetId(), lastNode.GetId(),
                             model, observer );
}

bool ModelProxy::RemoveConnection( const Id & firstNodeId,
                                   const Id & lastNodeId,
                                   Model & model,
                                   ModelObserver * observer )
{
    auto connection = model.graph.getConnection( firstNodeId, lastNodeId );

    if( model.graph.RemoveConnection( firstNodeId, lastNodeId ) )
    {
        observer->ConnectionRemoved( connection );
        return true;
    }
    return false;
}

bool ModelProxy::AddNode( GraphNode & node, Model & model,
                          ModelObserver * observer )
{
    if( model.graph.AddNode( node ) )
    {
        observer->NodeAdded( node );
        Meta new_meta{};
        // create meta.
        new_meta.graph_node_id = node.GetId();
        model.meta[ new_meta.graph_node_id ] = new_meta;
        observer->MetaAdded( new_meta );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveNode( GraphNode & node, Model & model,
                             ModelObserver * observer )
{
    if( model.graph.RemoveNode( node ) )
    {
        observer->NodeRemoved( node );
        // remove meta.
        Meta meta = model.meta[ node.GetId() ];
        model.meta.erase( node.GetId() );
        observer->MetaRemoved( meta );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveNode( Id nodeId, Model & model,
                             ModelObserver * observer )
{
    auto node = model.graph.getNode( nodeId );

    if( model.graph.RemoveNode( nodeId ) )
    {
        observer->NodeRemoved( node );
        // remove meta.
        Meta meta = model.meta[ nodeId ];
        model.meta.erase( nodeId );
        observer->MetaRemoved( meta );
        return true;
    }
    return false;
}

bool ModelProxy::FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode,
                           const Model & model, ModelObserver * observer )
{
    //@TODO implement later
    return false;
}

bool ModelProxy::FindPath( Id firstNodeId, Id lastNodeId,
                           const Model & model, ModelObserver * observer )
{
    //@TODO implement later
    return false;
}

bool ModelProxy::Subscribe( ModelSubscriber * & subscriber,
                            const Model & model,
                            ModelObserver * observer )
{
    return observer->Subscribe( subscriber );
}

bool ModelProxy::Unsubscribe( ModelSubscriber * & subscriber,
                              const Model & model,
                              ModelObserver * observer )
{
    return observer->unSubscribe( subscriber );
}

bool ModelProxy::ChangeMeta( const Id & nodeId, const Meta & meta,
                             Model & model, ModelObserver *observer )
{
    // If meta belongs to other node
    if( meta.graph_node_id != nodeId )
        return false;
    // If no node in graph
    if( !model.graph.HasNode( nodeId ) )
        return false;
    // update meta
    model.meta[ nodeId ] = meta;
    observer->MetaChanged( meta );
    return true;
}
