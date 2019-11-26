#ifndef POLARISMODEL_MODELPROXY_H
#define POLARISMODEL_MODELPROXY_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "include/ModelObserver/ModelObserver.h"
#include "include/GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include <cstddef>//std::size_t

namespace Polaris
{
class ModelSubscriber;
using Id = std::size_t;
struct GraphNode;
struct Model;
/******************************************************************************
 * ModelProxy class responsible for managing Model data
 * and sending notifications.
 *****************************************************************************/
class ModelProxy
{
public:
    /**************************************************************************
     * GetMetaByNodeId
     * Arguments:
     * node Id - id of node related to meta.
     * model - model to search in
     *************************************************************************/
    void GetMetaByNodeId( Id GraphNodeId, const Model & model,
                          const ModelObserver & observer );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to connect.
     * Warning! Nodes must be contained in graph.
     * model - model to connect in
     *************************************************************************/
    virtual void AddConnection( const GraphNode & firstNode,
                                const GraphNode & lastNode,
                                const Model & model,
                                const ModelObserver & observer );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * node Id - id of node contained in graph.
     * model - model to search in
     *************************************************************************/
    virtual void AddConnection( Id firstNodeId, Id lastNodeId,
                                const Model & model,
                                const ModelObserver & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - nodes to remove connections from.
     * Warning! Nodes must be contained in graph.
     * model - model to remove in
     *************************************************************************/
    virtual void RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   const Model & model,
                                   const ModelObserver & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - id of nodes to remove connections from.
     * model - model to remove in
     *************************************************************************/
    virtual void RemoveConnection( Id firstNodeId, Id lastNodeId,
                                   const Model & model,
                                   const ModelObserver & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to insert in graph.
     * model - model to add in
     *************************************************************************/
    virtual void AddNode( const GraphNode & node, const Model & model,
                          const ModelObserver & observer );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual void RemoveNode( const GraphNode & node, const Model & model,
                             const ModelObserver & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node Id - Id of node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual void RemoveNode( Id nodeId, const Model & model,
                             const ModelObserver & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodes - nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual void FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode, const Model & model,
                           const ModelObserver & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last node Ids - Id of nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual void FindPath( Id firstNodeId, Id lastNodeId, const Model & model,
                           const ModelObserver & observer );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual void Subscribe( const ModelSubscriber * & subscriber,
                            const Model & model,
                            ModelObserver & observer ) const;
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual void Unsubscribe( const ModelSubscriber * & subscriber,
                              const Model & model,
                              ModelObserver & observer ) const;
};
} //namespace Polaris

#endif //POLARISMODEL_MODELPROXY_H
