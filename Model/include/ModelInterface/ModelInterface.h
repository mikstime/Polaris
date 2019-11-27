#ifndef POLARISMODEL_MODELINTERFACE_H
#define POLARISMODEL_MODELINTERFACE_H

#include "include/ModelObserver/ModelObserver.h"
#include "include/ModelProxy/ModelProxy.h"
#include "GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include "typedefs.h"
#include <cstddef>//std::size_t
#include <utility>//std::move

namespace Polaris
{
class ModelProxy;
struct Model;
/******************************************************************************
 * ModelInterface class provides access to data managment
 * between Model and Controller. It can also be subscribed for updates.
 *****************************************************************************/
class ModelInterface
{
private:
    ModelObserver observer_;
    ModelProxy proxy_;
    Model model_;
public:
    /**************************************************************************
     * ModelInterface() - default constructor
     *************************************************************************/
    ModelInterface(): model_(), proxy_() {};
    /**************************************************************************
     * ModelInterface(proxy, model)
     * Arguments:
     * proxy - custom proxy can be set. Must inherit from ModelProxy.
     * model - initial state of model.
     *************************************************************************/
    explicit ModelInterface( ModelProxy  a_proxy, Model  a_model )
    :proxy_( std::move( a_proxy ) ), model_( std::move( a_model ) ){};
    /**************************************************************************
     * ModelInterface(proxy)
     * Arguments:
     * proxy - custom proxy can be set. Must inherit from ModelProxy.
     *************************************************************************/
    explicit ModelInterface( ModelProxy  a_proxy )
    :proxy_( std::move( a_proxy ) ), model_() {};
    /**************************************************************************
     * ModelInterface(model)
     * Arguments:
     * model - initial state of model.
     *************************************************************************/
    explicit ModelInterface( Model a_model )
    :proxy_(), model_( std::move( a_model ) ) {};
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to be connected.
     * connection params - params of connection
     * Callback is provided.
     *************************************************************************/
    void AddConnection( const GraphNode & firstNode,
                        const GraphNode & lastNode,
                        const ConnectionParams & params );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * connection - connection between nodes contained in graph
     * Callback is provided.
     *************************************************************************/
     void AddConnection( const GraphConnection & new_connection );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodeIds - id of nodes to be connected.
     * Callback is provided.
     *************************************************************************/
    void AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                        const ConnectionParams & params );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last nodes - remove connection between nodes
     * Callback is provided.
     *************************************************************************/
    void RemoveConnection( const GraphNode & firstNode,
                           const GraphNode & lastNode );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last nodeIds - remove connection between nodes
     * with specified ids
     * Callback is provided.
     *************************************************************************/
    void RemoveConnection( const Id &firstNodeId, const Id & lastNodeId );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to be inserted in graph
     * Callback is provided.
     *************************************************************************/
    void AddNode( const GraphNode & node );
    /**************************************************************************
     * AddNode
     * Arguments:
     * nodeId - node's id to be inserted in graph
     * Callback is provided.
     *************************************************************************/
    void AddNode( const Id & nodeId );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to be removed from graph
     * Callback is provided.
     *************************************************************************/
    void RemoveNode( const GraphNode & node );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * nodeId - id of node to be removed from graph
     * Callback is provided.
     *************************************************************************/
    void RemoveNode( const Id & nodeId );
    /**************************************************************************
     * FindPath find the shortest path between two nodes
     * Arguments:
     * first and last nodes - start and end vertices in graph
     * Callback is provided.
     *************************************************************************/
    void FindPath( const GraphNode & firstNode,
                   const GraphNode & lastNode );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodeIds - ids of start and end vertices in graph
     * Callback is provided.
     *************************************************************************/
    void FindPath( const Id & firstNodeId, const Id & lastNodeId );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - subscribe for all updates. Documented in ModelSubscriber
     *************************************************************************/
    void Subscribe( const ModelSubscriber * & subscriber );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - unsubscribe from updates
     *************************************************************************/
    void Unsubscribe( const ModelSubscriber * & subscriber );
    /**************************************************************************
     * ChangeMeta
     * Arguments:
     * nodeId - Id of Node's Meta
     * newMeta - Meta to be set
     *************************************************************************/
    void ChangeMeta( const Id & nodeId, const Meta & newMeta );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELINTERFACE_H
