#include "include/ModelObserver/ModelObserver.h"

bool Polaris::ModelObserver::Subscribe(
        const Polaris::ModelSubscriber * subscriber )
{
    // just add subscriber at the end of the vector
    auto it = std::find( subscribers_.begin(),
                         subscribers_.end(), subscriber );
    if( it == subscribers_.end() )
    {
        subscribers_.push_back( subscriber );
        return true;
    }
    return false;
}

bool Polaris::ModelObserver::unSubscribe(
        const Polaris::ModelSubscriber * subscriber )
{
    // find subscriber in vector
    auto it = std::find( subscribers_.begin(),
                         subscribers_.end(), subscriber );
    // remove sub if found
    if( it != subscribers_.end() )
    {
        subscribers_.erase( it );
        return true;
    }
    return false;
}

void Polaris::ModelObserver::MetaChanged( const Polaris::Meta & newMeta )
{
    // Loop through subscribers and notify them.
    for( auto sub : subscribers_ )
        sub->onMetaChanged( newMeta );
}

void Polaris::ModelObserver::NodeAdded( const Polaris::GraphNode & node )
{
    for( auto sub : subscribers_ )
        sub->onNodeAdded( node );
}

void Polaris::ModelObserver::NodeRemoved( const Polaris::GraphNode & node )
{
    for( auto sub : subscribers_ )
        sub->onNodeRemoved( node );
}

void Polaris::ModelObserver::ConnectionRemoved(
        const Polaris::GraphConnection & connection )
{
    for( auto sub : subscribers_ )
        sub->onConnectionRemoved( connection );
}

void Polaris::ModelObserver::ConnectionAdded(
        const Polaris::GraphConnection & newConnection )
{
    for( auto sub : subscribers_ )
        sub->onConnectionAdded( newConnection );
}
