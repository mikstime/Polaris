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
     * onMetaAdded
     * Arguments:
     * new_meta - meta object
     *************************************************************************/
     virtual void onMetaAdded( const Meta & meta ) = 0;
    /**************************************************************************
     * onMetaChanged
     * Arguments:
     * newMeta - meta object that was changed
     *************************************************************************/
    virtual void onMetaChanged( const Meta & meta ) = 0;
    /**************************************************************************
     * onMetaRemoved
     * Arguments:
     * meta - removed meta
     *************************************************************************/
    virtual void onMetaRemoved( const Meta & meta ) = 0;
    /**************************************************************************
     * onConnectionAdded
     * Arguments:
     * firstNode and lastNode - nodes that was connected
     *************************************************************************/
    virtual void onConnectionAdded( const GraphConnection & connection ) = 0;
    /**************************************************************************
     * onConnectionRemoved
     * Arguments:
     * firstNode and lastNode - nodes, connection between which was deleted
     *************************************************************************/
    virtual void onConnectionRemoved( const GraphConnection & connection ) = 0;
    /**************************************************************************
     * onPathFound
     * Arguments:
     * nodes - list of nodes to be drawn
     *************************************************************************/
    virtual void onPathFound(
            std::vector< Meta > & path,
            std::vector< GraphConnection > & connections ) = 0;
    /**************************************************************************
     * onNodeAdded
     * Arguments:
     * node - node that was added
     *************************************************************************/
    virtual void onNodeAdded( const GraphNode & node ) = 0;
    /**************************************************************************
     * onNodeRemoved
     * Arguments:
     * node - node that was removed
     *************************************************************************/
    virtual void onNodeRemoved( const GraphNode & node ) = 0;
};
} //namespace Polaris

#endif //POLARISMODEL_MODELSUBSCRIBER_H
