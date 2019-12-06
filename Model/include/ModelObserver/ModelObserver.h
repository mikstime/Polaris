#ifndef POLARISMODEL_MODELOBSERVER_H
#define POLARISMODEL_MODELOBSERVER_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include "Meta/Meta.h"
#include <utility> //std::move
#include <vector> //std::vector

namespace Polaris
{
class ModelSubscriber;
class GraphNode;
class Meta;
class Model;
using ModelSubscribers = std::vector< ModelSubscriber * >;
/******************************************************************************
 * ModelObserver class provides subscriptions to Model
 * and notifications for subscribers.
 *****************************************************************************/
class ModelObserver
{
private:
    ModelSubscribers subscribers_;
public:
    /**************************************************************************
     * ModelObserver - default constructor
     *************************************************************************/
    ModelObserver(): subscribers_() {};
    /**************************************************************************
     * ModelObserver
     * Arguments:
     * subscribers - initial state for subscribers
     *************************************************************************/
    explicit ModelObserver( ModelSubscribers  a_subs )
    : subscribers_(std::move( a_subs )) {};
public:
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - object to be subscribed. Must inherit from ModelSubscriber.
     * Return value:
     * bool - true on success, false if failed.
     *************************************************************************/
    virtual bool Subscribe( ModelSubscriber * subscriber );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - subscriber to be removed.
     * Return value:
     * bool - true on success, false if failed.
     *************************************************************************/
    virtual bool unSubscribe( ModelSubscriber * subscriber );
    /**************************************************************************
     * MetaAdded
     * Arguments:
     * newMeta - created meta
     *************************************************************************/
     virtual void MetaAdded( const Meta & meta );
    /**************************************************************************
     * MetaChanged
     * Arguments:
     * meta - updated meta
     *************************************************************************/
    virtual void MetaChanged( const Meta & meta );
    /**************************************************************************
     * MetaRemoved
     * Arguments:
     * meta - removed meta
     *************************************************************************/
     virtual void MetaRemoved( const Meta & meta );
    /**************************************************************************
     * ConnectionAdded
     * Arguments:
     * first and last nodes - nodes that connected.
     *************************************************************************/
    virtual void ConnectionAdded( const GraphConnection & connection );
    /**************************************************************************
     * ConnectionRemoved
     * Arguments:
     * first and last nodes - nodes between whose connection was deleted
     *************************************************************************/
    virtual void ConnectionRemoved( const GraphConnection & connection );
    /**************************************************************************
     * NodeAdded
     * Arguments:
     * node - node which was inserted in graph.
     *************************************************************************/
    virtual void NodeAdded( const GraphNode & node );
    /**************************************************************************
     * NodeRemoved
     * Arguments:
     * node - node to be removed from graph
     *************************************************************************/
    virtual void NodeRemoved( const GraphNode & node );
    /**************************************************************************
     * PathFound
     * Arguments:
     * nodes - list of nodes to be drawn
     *************************************************************************/
     virtual void PathFound(
             std::vector< Meta > & path,
             std::vector< GraphConnection > & connections );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELOBSERVER_H
