#ifndef POLARISMODEL_MODELPROXY_H
#define POLARISMODEL_MODELPROXY_H

#include "include/ModelSubscriber/ModelSubscriber.h"
#include "include/GraphNode/GraphNode.h"
#include "include/Model/Model.h"
#include <cstddef>//std::size_t

namespace Polaris
{
class ModelSubscriber;
using Id = std::size_t;
struct GraphNode;
struct Model;
/******************************************************************************
 * ModelProxy class responsible for managing Model data
 * and sending notifications.
 *****************************************************************************/
class ModelProxy
{
public:
    /**************************************************************************
     * GetMetaByNodeId
     * Arguments:
     * node Id - id of node related to meta.
     * model - model to search in
     *************************************************************************/
    void GetMetaByNodeId( Id GraphNodeId, const Model & model );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * first and last nodes - nodes to connect.
     * Warning! Nodes must be contained in graph.
     * model - model to connect in
     *************************************************************************/
    void AddConnection( const GraphNode & firstNode,
                        const GraphNode & lastNode, const Model & model );
    /**************************************************************************
     * AddConnection
     * Arguments:
     * node Id - id of node contained in graph.
     * model - model to search in
     *************************************************************************/
    void AddConnection( Id firstNodeId, Id lastNodeId, const Model & model );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - nodes to remove connections from.
     * Warning! Nodes must be contained in graph.
     * model - model to remove in
     *************************************************************************/
    void RemoveConnection( const GraphNode & firstNode,
                           const GraphNode & lastNode, const Model & model );
    /**************************************************************************
     * RemoveConnection
     * Arguments:
     * first and last node - id of nodes to remove connections from.
     * model - model to remove in
     *************************************************************************/
    void RemoveConnection( Id firstNodeId, Id lastNodeId, const Model & model );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node - node to insert in graph.
     * model - model to add in
     *************************************************************************/
    void AddNode( const GraphNode & node, const Model & model );
    /**************************************************************************
     * RemoveNode
     * Arguments:
     * node - node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    void RemoveNode( const GraphNode & node, const Model & model );
    /**************************************************************************
     * AddNode
     * Arguments:
     * node Id - Id of node to remove from graph.
     * model - model to remove in
     *************************************************************************/
    void RemoveNode( Id nodeId, const Model & model );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last nodes - nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    void FindPath( const GraphNode & firstNode,
                   const GraphNode & lastNode, const Model & model );
    /**************************************************************************
     * FindPath
     * Arguments:
     * first and last node Ids - Id of nodes to search path between
     * model - model to search in. (Only graph is used)
     *************************************************************************/
    void FindPath( Id firstNodeId, Id lastNodeId, const Model & model );
    /**************************************************************************
     * Subscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    void Subscribe( const ModelSubscriber & subscriber,
                    const Model & model );
    /**************************************************************************
     * Unsubscribe
     * Arguments:
     * subscriber - notification receiver. Must inherit from ModelSubscriber.
     * model - model to subscribe
     *************************************************************************/
    void Unsubscribe( const ModelSubscriber & subscriber,
                    const Model & model );
};
} //namespace Polaris

#endif //POLARISMODEL_MODELPROXY_H
