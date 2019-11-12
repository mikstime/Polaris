//
// Created by MBTSKY on 09.11.2019.
//

#include "include/ModelObserver/ModelObserver.h"

void Polaris::ModelObserver::Subscribe(
        const Polaris::ModelSubscriber & subscriber )
{

}

void Polaris::ModelObserver::unSubscribe(
        const Polaris::ModelSubscriber & subscriber )
{

}

void Polaris::ModelObserver::MetaChanged( const Polaris::Meta & newMeta,
                                          const Polaris::Model & modelState )
{

}

void Polaris::ModelObserver::ConnectionAdded(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode,
        const Polaris::Model & modelState )
{

}

void Polaris::ModelObserver::ConnectionRemoved(
        const Polaris::GraphNode & firstNode,
        const Polaris::GraphNode & lastNode,
        const Polaris::Model & modelState )
{

}

void Polaris::ModelObserver::NodeAdded( const Polaris::GraphNode & node,
                                        const Polaris::Model & modelState )
{

}

void Polaris::ModelObserver::NodeRemoved( const Polaris::GraphNode & node,
                                          const Polaris::Model & modelState )
{

}
