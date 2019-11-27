#ifndef POLARISMODEL_MODELSUBSCRIBER_H
#define POLARISMODEL_MODELSUBSCRIBER_H

#include "GraphConnection/GraphConnection.h"
#include "GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include "Meta/Meta.h"
namespace Polaris
{
struct Meta;
struct Model;
struct GraphNode;
struct GraphConnection;
/******************************************************************************
 * ModelSubscriber Class is used for subscribing on model.
 * In case of model change it receives a notification containing
 * changed data and model state.
 *****************************************************************************/
class ModelSubscriber
{
public:
    /**************************************************************************
     * onMetaChanged
     * Arguments:
     * newMeta - meta object that was changed
     *************************************************************************/
    virtual void onMetaChanged( const Meta & newMeta ) const = 0;
    /**************************************************************************
     * onConnectionAdded
     * Arguments:
     * firstNode and lastNode - nodes that was connected
     *************************************************************************/
    virtual void onConnectionAdded( const GraphConnection & newConnection )
    const = 0;
    /**************************************************************************
     * onConnectionRemoved
     * Arguments:
     * firstNode and lastNode - nodes, connection between which was deleted
     *************************************************************************/
    virtual void onConnectionRemoved( const GraphConnection & connection )
    const = 0;
    /**************************************************************************
     * onNodeAdded
     * Arguments:
     * node - node that was added
     *************************************************************************/
    virtual void onNodeAdded( const GraphNode & node ) const = 0;
    /**************************************************************************
     * onNodeRemoved
     * Arguments:
     * node - node that was removed
     *************************************************************************/
    virtual void onNodeRemoved( const GraphNode & node ) const = 0;
};
} //namespace Polaris

#endif //POLARISMODEL_MODELSUBSCRIBER_H
