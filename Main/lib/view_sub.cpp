#include "include/view_sub.h"

using Polaris::ViewSub;

ViewSub::ViewSub( View * view )
: view_( view )
{

}

//void ViewSub::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
//{
//    view_->BuildItems( meta, graph );
//}

void ViewSub::onPathFound( std::vector< Meta > & nodes,
                           std::vector< GraphConnection > & connections )
{
    view_->DrawThePath( nodes, connections );
}

void ViewSub::onMetaChanged( const Meta & meta )
{
    view_->ChangeRoom( meta );
}

void ViewSub::onMetaAdded(const Meta & meta )
{
    view_->AddRoom( meta );
}

void ViewSub::onMetaRemoved(const Meta & meta )
{
    view_->RemoveRoom( meta );
}

void ViewSub::onConnectionAdded( const GraphConnection & connection )
{
    view_->AddConnection( connection );
}

void ViewSub::onConnectionRemoved( const GraphConnection & connection )
{
    view_->RemoveConnection( connection );
}