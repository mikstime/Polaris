#include "include/ModelProxy/ModelProxy.h"

void Polaris::ModelProxy::GetMetaByNodeId( Polaris::Id GraphNodeId,
                                           const Polaris::Model & model,
                                           const ModelObserver & observer )
{

}

void Polaris::ModelProxy::AddConnection( const Polaris::GraphNode & firstNode,
                                         const Polaris::GraphNode & lastNode,
                                         const Polaris::Model & model,
                                         const ModelObserver & observer )
{
    //@TODO 1. Delegate creating connection to graphInterface.
    //@TODO 2. Notify about creation subscribers
    
}

void Polaris::ModelProxy::AddConnection( Polaris::Id firstNodeId,
                                         Polaris::Id lastNodeId,
                                         const Polaris::Model & model,
                                         const ModelObserver & observer )
{

}

void
Polaris::ModelProxy::RemoveConnection( const Polaris::GraphNode & firstNode,
                                       const Polaris::GraphNode & lastNode,
                                       const Polaris::Model & model,
                                       const ModelObserver & observer )
{

}

void Polaris::ModelProxy::RemoveConnection( Polaris::Id firstNodeId,
                                            Polaris::Id lastNodeId,
                                            const Polaris::Model & model,
                                            const ModelObserver & observer )
{

}

void Polaris::ModelProxy::AddNode( const Polaris::GraphNode & node,
                                   const Polaris::Model & model,
                                   const ModelObserver & observer )
{

}

void Polaris::ModelProxy::RemoveNode( const Polaris::GraphNode & node,
                                      const Polaris::Model & model,
                                      const ModelObserver & observer )
{

}

void Polaris::ModelProxy::RemoveNode( Polaris::Id nodeId,
                                      const Polaris::Model & model,
                                      const ModelObserver & observer )
{

}

void Polaris::ModelProxy::FindPath( const Polaris::GraphNode & firstNode,
                                    const Polaris::GraphNode & lastNode,
                                    const Polaris::Model & model,
                                    const ModelObserver & observer )
{

}

void Polaris::ModelProxy::FindPath(
        Polaris::Id firstNodeId, Polaris::Id lastNodeId,
        const Polaris::Model & model,
        const ModelObserver & observer )
{

}

void Polaris::ModelProxy::Subscribe( const ModelSubscriber * & subscriber,
                                     const Polaris::Model & model,
                                     ModelObserver & observer ) const
{
    observer.Subscribe( subscriber );
}

void Polaris::ModelProxy::Unsubscribe( const ModelSubscriber * & subscriber,
                                       const Polaris::Model & model,
                                       ModelObserver & observer ) const
{
    observer.unSubscribe( subscriber );
}
