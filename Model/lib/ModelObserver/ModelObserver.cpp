#include "include/ModelObserver/ModelObserver.h"

bool Polaris::ModelObserver::Subscribe(
        std::shared_ptr< ModelSubscriber > & subscriber )
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
        std::shared_ptr< ModelSubscriber > & subscriber )
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

void Polaris::ModelObserver::MetaAdded( const Polaris::Meta & meta )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onMetaAdded( meta );
}

void Polaris::ModelObserver::MetaChanged( const Polaris::Meta & meta )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onMetaChanged( meta );
}
void Polaris::ModelObserver::MetaRemoved( const Polaris::Meta & meta )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onMetaRemoved( meta );
}

void Polaris::ModelObserver::NodeAdded( const Polaris::GraphNode & node )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onNodeAdded( node );
}

void Polaris::ModelObserver::NodeRemoved( const Polaris::GraphNode & node )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onNodeRemoved( node );
}

void Polaris::ModelObserver::ConnectionRemoved(
        const Polaris::GraphConnection & connection )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onConnectionRemoved( connection );
}

void Polaris::ModelObserver::ConnectionAdded(
        const Polaris::GraphConnection & connection )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onConnectionAdded( connection );
}

void Polaris::ModelObserver::PathFound(
        std::vector< Meta > & path,
        std::vector< GraphConnection > & connections )
{
    // Loop through subscribers and notify them.
    for( const auto & sub : subscribers_ )
        sub->onPathFound( path, connections );
}
