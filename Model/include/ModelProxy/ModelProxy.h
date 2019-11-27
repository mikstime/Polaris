#ifndef POLARISMODEL_MODELPROXY_H
#define POLARISMODEL_MODELPROXY_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "include/ModelObserver/ModelObserver.h"
#include "GraphNode/GraphNode.h"
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
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to connect.
     * Warning! Nodes must be contained in graph.
     * model - model to connect in
     *************************************************************************/
    virtual bool AddConnection( const GraphConnection & connection,
                                const Model & model,
                                ModelObserver & observer );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * node Id - id of node contained in graph.
     * model - model to search in
     *************************************************************************/
    virtual bool AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                                const ConnectionParams & params,
                                const Model & model,
                                ModelObserver & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - nodes to remove connections from.
     * Warning! Nodes must be contained in graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   const Model & model,
                                   ModelObserver & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - id of nodes to remove connections from.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveConnection( Id firstNodeId, Id lastNodeId,
                                   const Model & model,
                                   ModelObserver & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to insert in graph.
     * model - model to add in
     *************************************************************************/
    virtual bool AddNode( const GraphNode & node, const Model & model,
                          ModelObserver & observer );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveNode( const GraphNode & node, const Model & model,
                             ModelObserver & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node Id - Id of node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveNode( Id nodeId, const Model & model,
                             ModelObserver & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodes - nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual bool FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode, const Model & model,
                           ModelObserver & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last node Ids - Id of nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual bool FindPath( Id firstNodeId, Id lastNodeId, const Model & model,
                           ModelObserver & observer );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual bool Subscribe( const ModelSubscriber * & subscriber,
                            const Model & model,
                            ModelObserver & observer ) const;
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual bool Unsubscribe( const ModelSubscriber * & subscriber,
                              const Model & model,
                              ModelObserver & observer ) const;
};
} //namespace Polaris

#endif //POLARISMODEL_MODELPROXY_H
