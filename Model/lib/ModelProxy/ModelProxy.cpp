#include "include/Search/Search.h"
#include "include/ModelProxy/ModelProxy.h"

using namespace Polaris;
/******************************************************************************
 * AddConnection Methods
 *****************************************************************************/
bool ModelProxy::AddConnection( const GraphConnection & connection,
                                Model & model,
                                std::shared_ptr< ModelObserver > & observer )
{
    // Try to add connection
    if( model.graph.AddConnection( connection ) )
    {
        // Notify on success, return true
        observer->ConnectionAdded( connection );
        return true;
    }
    return false; // false on fail
}

bool ModelProxy::AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                                const ConnectionParams & params,
                                Model & model,
                                std::shared_ptr< ModelObserver > & observer )
{
    // Try to add connection
    if( model.graph.AddConnection( firstNodeId, lastNodeId, params ) )
    {
        // Notify
        auto c( model.graph.getConnection( firstNodeId, lastNodeId ) );
        observer->ConnectionAdded( c );
        return true;
    }
    return false;
}
/******************************************************************************
 * RemoveConnection Methods
 *****************************************************************************/
bool ModelProxy::RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   Model & model,
                                   std::shared_ptr< ModelObserver > & observer )
{
    // Delegate to RemoveConnection( Id, Id, model, observer )
    return RemoveConnection( firstNode.GetId(), lastNode.GetId(),
                             model, observer );
}

bool ModelProxy::RemoveConnection( const Id & firstNodeId,
                                   const Id & lastNodeId,
                                   Model & model,
                                   std::shared_ptr< ModelObserver > & observer )
{
    // Connection exists
    if( !model.graph.AreConnected( firstNodeId, lastNodeId ) )
        return false; // failed
    // Get connection
    auto connection( model.graph.getConnection( firstNodeId, lastNodeId ) );
    // Try to remove from graph
    if( model.graph.RemoveConnection( firstNodeId, lastNodeId ) )
    {
        // Notify
        observer->ConnectionRemoved( connection );
        return true;
    }
    return false; // won't trigger unless bullshit happens
}
/******************************************************************************
 * AddNode Methods
 *****************************************************************************/
bool ModelProxy::AddNode( GraphNode & node, Model & model,
                          std::shared_ptr< ModelObserver > & observer )
{
    // Try to add node in graph
    if( model.graph.AddNode( node ) )
    {
        // notify
        observer->NodeAdded( node );
        Meta new_meta{};
        // create meta.
        new_meta.graph_node_id = node.GetId();
        model.meta[ new_meta.graph_node_id ] = new_meta;
        // notify again
        observer->MetaAdded( new_meta );
        return true;
    }
    return false;
}
/******************************************************************************
 * RemoveNode Methods
 *****************************************************************************/
bool ModelProxy::RemoveNode( GraphNode & node, Model & model,
                             std::shared_ptr< ModelObserver > & observer )
{
    // Try to remove Node
    if( model.graph.RemoveNode( node ) )
    {
        observer->NodeRemoved( node );
        // remove meta.
        Meta meta = model.meta[ node.GetId() ];
        model.meta.erase( node.GetId() );
        // Notify
        observer->MetaRemoved( meta );
        return true;
    }
    return false;
}

bool ModelProxy::RemoveNode( Id nodeId, Model & model,
                             std::shared_ptr< ModelObserver > & observer )
{
    // No node in graph.
    if( !model.graph.HasNode( nodeId ) )
        return false;
    auto node = model.graph.getNode( nodeId );
    // Notify about removing connections related to node
    for( auto n : node.neighbors )
    {
        if( model.graph.AreConnected( nodeId, n ) )
        {
            observer->ConnectionRemoved(
                    model.graph.getConnection( nodeId, n ) );
        }
        if( model.graph.AreConnected( n, nodeId ) )
        {
            observer->ConnectionRemoved(
                    model.graph.getConnection( n, nodeId ) );
        }
    }
    // Try to remove node
    if( model.graph.RemoveNode( nodeId ) )
    {
        // Notify about node removal
        observer->NodeRemoved( node );
        // remove meta.
        Meta meta = model.meta[ nodeId ];
        model.meta.erase( nodeId );
        // Notify
        observer->MetaRemoved( meta );
        return true;
    }
    return false;
}
/******************************************************************************
 * FindPath Methods
 *****************************************************************************/
bool ModelProxy::FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode,
                           Model & model,
                           std::shared_ptr< ModelObserver > & observer )
{
    // Delegate to FindPath( Id, Id, model, observer )
    return FindPath( firstNode.GetId(), lastNode.GetId(), model, observer );
}
bool ModelProxy::FindPath( Id firstNodeId, Id lastNodeId,
                           Model & model,
                           std::shared_ptr< ModelObserver > & observer )
{
    // Find path
    std::vector< GraphNode > path = Search::FindPath(
            model.graph, firstNodeId, lastNodeId );
    // Retrieve graph
    Graph g = model.graph.getGraph();
    // To store transformed path and connections
    std::vector< Meta > newPath;
    std::vector< GraphConnection > newConnections;
    if( !path.empty() ) {
        // Prepare meta and connections.
        for( auto it = path.begin(); it != path.end() - 1; it++ )
        {
            newPath.push_back( model.meta[ it->GetId() ] );
            newConnections.push_back(
                    model.graph.getConnection(
                            it->GetId(),
                            ( it + 1 )->GetId() ) );
        }
        newPath.push_back( model.meta[ (path.end() - 1)->GetId() ] );
    }
    observer->PathFound(newPath, newConnections );
    return !newPath.empty();
}
/******************************************************************************
 * Observer Methods
 *****************************************************************************/
bool ModelProxy::Subscribe( std::shared_ptr< ModelSubscriber > & subscriber,
                            const Model & model,
                            std::shared_ptr< ModelObserver > & observer )
{
    return observer->Subscribe( subscriber );
}

bool ModelProxy::Unsubscribe( std::shared_ptr< ModelSubscriber > & subscriber,
                              const Model & model,
                              std::shared_ptr< ModelObserver > & observer )
{
    return observer->unSubscribe( subscriber );
}
/******************************************************************************
 * ChangeMeta Methods
 *****************************************************************************/
bool ModelProxy::ChangeMeta( const Id & nodeId, const Meta & meta,
                             Model & model,
                             std::shared_ptr< ModelObserver > & observer )
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
