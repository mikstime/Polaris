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
using ModelSubscribers = std::vector< const ModelSubscriber * >;
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
    virtual bool Subscribe( const ModelSubscriber * subscriber );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - subscriber to be removed.
     * Return value:
     * bool - true on success, false if failed.
     *************************************************************************/
    virtual bool unSubscribe( const ModelSubscriber * subscriber );
    /**************************************************************************
     * MetaChanged
     * Arguments:
     * newMeta - updated meta
     *************************************************************************/
    virtual void MetaChanged( const Meta & newMeta );
    /**************************************************************************
     * ConnectionAdded
     * Arguments:
     * first and last nodes - nodes that connected.
     *************************************************************************/
    virtual void ConnectionAdded( const GraphConnection & newConnection );
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
};
} //namespace Polaris

#endif //POLARISMODEL_MODELOBSERVER_H
