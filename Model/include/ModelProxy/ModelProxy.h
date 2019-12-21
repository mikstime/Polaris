#ifndef POLARISMODEL_MODELPROXY_H
#define POLARISMODEL_MODELPROXY_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "include/ModelObserver/ModelObserver.h"
#include "include/GraphInterface/GraphInterface.h"
#include "GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include <memory>

namespace Polaris
{
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
                                Model & model,
                                std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * node Id - id of node contained in graph.
     * model - model to search in
     *************************************************************************/
    virtual bool AddConnection( const Id & firstNodeId, const Id & lastNodeId,
                                const ConnectionParams & params,
                                Model & model,
                                std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - nodes to remove connections from.
     * Warning! Nodes must be contained in graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveConnection( const GraphNode & firstNode,
                                   const GraphNode & lastNode,
                                   Model & model,
                                   std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - id of nodes to remove connections from.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveConnection( const Id & firstNodeId,
                                   const Id & lastNodeId,
                                   Model & model,
                                   std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to insert in graph.
     * model - model to add in
     *************************************************************************/
    virtual bool AddNode( GraphNode & node, Model & model,
                          std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * ChangeMeta
     * Arguments:
     * node - id of node it belongs to
     * meta - meta to be set.
     * model - model to add in
     *************************************************************************/
     virtual bool ChangeMeta( const Id & nodeId, const Meta & meta,
                              Model & model, std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveNode( GraphNode & node, Model & model,
                             std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node Id - Id of node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    virtual bool RemoveNode( Id nodeId, Model & model,
                             std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodes - nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual bool FindPath( const GraphNode & firstNode,
                           const GraphNode & lastNode, Model & model,
                           std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last node Ids - Id of nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    virtual bool FindPath( Id firstNodeId, Id lastNodeId, Model & model,
                           std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual bool Subscribe( std::shared_ptr< ModelSubscriber > & subscriber,
                            const Model & model,
                            std::shared_ptr< ModelObserver > & observer );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    virtual bool Unsubscribe( std::shared_ptr< ModelSubscriber > & subscriber,
                              const Model & model,
                              std::shared_ptr< ModelObserver > & observer );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELPROXY_H
