#ifndef POLARISMODEL_MODELSUBSCRIBER_H
#define POLARISMODEL_MODELSUBSCRIBER_H

namespace Polaris
{
struct Meta;
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
     * modelState - current state of Model
     *************************************************************************/
    virtual void onMetaChanged( const & Meta newMeta,
                                const & Model modelState ) = 0;
    /**************************************************************************
     * onConnectionAdded
     * Arguments:
     * firstNode and lastNode - nodes that was connected
     * modelState - current state of Model
     *************************************************************************/
    virtual void onConnectionAdded( const & GraphNode firstNode,
                                    const & GraphNode lastNode,
                                    const & Model modelState ) = 0;
    /**************************************************************************
     * onConnectionRemoved
     * Arguments:
     * firstNode and lastNode - nodes, connection between which was deleted
     * modelState - current state of Model
     *************************************************************************/
    virtual void onConnectionRemoved( const & GraphNode firstNode,
                                      const & GraphNode lastNode,
                                      const & Model modelState ) = 0;
    /**************************************************************************
     * onNodeAdded
     * Arguments:
     * node - node that was added
     * modelState - current state of Model
     *************************************************************************/
    virtual void onNodeAdded( const & GraphNode node,
                              const & Model modelState ) = 0;
    /**************************************************************************
     * onNodeRemoved
     * Arguments:
     * node - node that was removed
     * modelState - current state of Model
     *************************************************************************/
    virtual void onNodeRemoved( const & GraphNode node,
                                const & Model modelState ) = 0;
};
} //namespace Polaris

#endif //POLARISMODEL_MODELSUBSCRIBER_H
