#ifndef POLARISMODEL_MODELINTERFACE_H
#define POLARISMODEL_MODELINTERFACE_H

#include "include/ModelObserver/ModelObserver.h"
#include "include/ModelProxy/ModelProxy.h"
#include "GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include "typedefs.h"
#include <cstddef>//std::size_t
#include <utility>//std::move
//@TODO getMeta method
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
    ModelObserver * observer_;
    ModelProxy * proxy_;
    Model model_;
public:
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to be connected.
     * connection params - params of connection
     * Callback is provided.
     *************************************************************************/
    bool AddConnection( const GraphNode & firstNode,
                        const GraphNode & lastNode,
                        const ConnectionParams & params );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * connection - connection between nodes contained in graph
     * Callback is provided.
     *************************************************************************/
     bool AddConnection( const GraphConnection & new_connection );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodeIds - id of nodes to be connected.
     * Callback is provided.
     *************************************************************************/
    bool AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                        const ConnectionParams & params );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last nodes - remove connection between nodes
     * Callback is provided.
     *************************************************************************/
    bool RemoveConnection( const GraphNode & firstNode,
                           const GraphNode & lastNode );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last nodeIds - remove connection between nodes
     * with specified ids
     * Callback is provided.
     *************************************************************************/
    bool RemoveConnection( const Id &firstNodeId, const Id & lastNodeId );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to be inserted in graph
     * Callback is provided.
     *************************************************************************/
    bool AddNode( GraphNode & node );
    /**************************************************************************
     * AddNode
     * Arguments:
     * nodeId - node's id to be inserted in graph
     * Callback is provided.
     *************************************************************************/
    bool AddNode( const Id & nodeId );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to be removed from graph
     * Callback is provided.
     *************************************************************************/
    bool RemoveNode( const GraphNode & node );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * nodeId - id of node to be removed from graph
     * Callback is provided.
     *************************************************************************/
    bool RemoveNode( const Id & nodeId );
    /**************************************************************************
     * FindPath find the shortest path between two nodes
     * Arguments:
     * first and last nodes - start and end vertices in graph
     * Callback is provided.
     *************************************************************************/
    bool FindPath( const GraphNode & firstNode,
                   const GraphNode & lastNode );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodeIds - ids of start and end vertices in graph
     * Callback is provided.
     *************************************************************************/
    bool FindPath( const Id & firstNodeId, const Id & lastNodeId );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - subscribe for all updates. Documented in ModelSubscriber
     *************************************************************************/
    bool Subscribe( ModelSubscriber * & subscriber );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - unsubscribe from updates
     *************************************************************************/
    bool Unsubscribe( ModelSubscriber * & subscriber );
    /**************************************************************************
     * ChangeMeta
     * Arguments:
     * nodeId - Id of Node's Meta
     * newMeta - Meta to be set
     *************************************************************************/
    bool ChangeMeta( const Id & nodeId, const Meta & newMeta );
    /**************************************************************************
     * setProxy
     * Arguments:
     * proxy - proxy to be set.
     *************************************************************************/
    void setProxy( ModelProxy * proxy ) { proxy_ = proxy; }
    /**************************************************************************
     * setProxy
     * Arguments:
     * proxy - proxy to be set.
     *************************************************************************/
    void setObserver( ModelObserver * obs ) { observer_ = obs; }
    /**************************************************************************
     * ModelInterface() - default constructor
     *************************************************************************/
    ModelInterface():
    observer_( new ModelObserver ), proxy_( new ModelProxy ), model_() {};
    /**************************************************************************
     * ModelInterface(proxy, model)
     * Arguments:
     * proxy - custom proxy can be set. Must inherit from ModelProxy.
     * model - initial state of model.
     *************************************************************************/
    ModelInterface( ModelProxy * a_proxy, ModelObserver * a_obs,
                    Model  a_model )
    :proxy_( a_proxy ), observer_( a_obs ), model_( std::move( a_model ) ){};
    /**************************************************************************
     * ModelInterface(proxy)
     * Arguments:
     * proxy - custom proxy can be set. Must inherit from ModelProxy.
     *************************************************************************/
    explicit ModelInterface( ModelProxy * a_proxy )
    :proxy_( a_proxy ), observer_(), model_() {};
    /**************************************************************************
     * ModelInterface(model)
     * Arguments:
     * model - initial state of model.
     *************************************************************************/
    explicit ModelInterface( Model a_model )
    :proxy_(), observer_(), model_( std::move( a_model ) ) {};
};
} //namespace Polaris

#endif //POLARISMODEL_MODELINTERFACE_H
