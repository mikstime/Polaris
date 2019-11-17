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
     *************************************************************************/
    void MetaChanged( const Meta & newMeta );
    /**************************************************************************
     * ConnectionAdded
     * Arguments:
     * first and last nodes - nodes that connected.
     *************************************************************************/
    void ConnectionAdded( const GraphConnection & newConnection );
    /**************************************************************************
     * ConnectionRemoved
     * Arguments:
     * first and last nodes - nodes between whose connection was deleted
     *************************************************************************/
    void ConnectionRemoved( const GraphConnection & connection );
    /**************************************************************************
     * NodeAdded
     * Arguments:
     * node - node which was inserted in graph.
     *************************************************************************/
    void NodeAdded( const GraphNode & node );
    /**************************************************************************
     * NodeRemoved
     * Arguments:
     * node - node to be removed from graph
     *************************************************************************/
    void NodeRemoved( const GraphNode & node );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELOBSERVER_H
