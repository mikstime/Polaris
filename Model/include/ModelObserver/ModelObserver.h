#ifndef POLARISMODEL_MODELOBSERVER_H
#define POLARISMODEL_MODELOBSERVER_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "include/GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include "include/Meta/Meta.h"
#include <utility> //std::move
#include <vector> //std::vector

namespace Polaris
{
class ModelSubscriber;
class GraphNode;
class Meta;
class Model;
using ModelSubscribers = std::vector < ModelSubscriber >;
/******************************************************************************
 * ModelObserver class provides subscribtions to Model
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
     *************************************************************************/
    void Subscribe( const ModelSubscriber & subscriber );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - subscriber to be removed.
     *************************************************************************/
    void unSubscribe( const ModelSubscriber & subscriber );
    /**************************************************************************
     * MetaChanged
     * Arguments:
     * newMeta - updated meta
     * modelState - current state of model.
     *************************************************************************/
    void MetaChanged( const Meta & newMeta, const Model & modelState );
    /**************************************************************************
     * ConnectionAdded
     * Arguments:
     * first and last nodes - nodes that connected.
     * modelState - current state of model.
     *************************************************************************/
    void ConnectionAdded( const GraphNode & firstNode,
                          const GraphNode & lastNode,
                          const Model & modelState );
    /**************************************************************************
     * ConnectionRemoved
     * Arguments:
     * first and last nodes - nodes between whose connection was deleted
     * modelState - current state of model.
     *************************************************************************/
    void ConnectionRemoved( const GraphNode & firstNode,
                            const GraphNode & lastNode,
                            const Model & modelState );
    /**************************************************************************
     * NodeAdded
     * Arguments:
     * node - node which was inserted in graph.
     * modelState - current state of model.
     *************************************************************************/
    void NodeAdded( const GraphNode & node, const Model & modelState );
    /**************************************************************************
     * NodeRemoved
     * Arguments:
     * node - node to be removed from graph
     * modelState - current state of model.
     *************************************************************************/
    void NodeRemoved( const GraphNode & node, const Model & modelState );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELOBSERVER_H
