#include "../include/view_sub.h"

using Polaris::ViewSub;

ViewSub::ViewSub( View * view )
: view_( view )
{

}

void ViewSub::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{
    view_->BuildItems( meta, graph );
}

void ViewSub::onPathFound( const std::vector< const GraphNode > & nodes,
                           const std::vector< const GraphConnection > & connections )
{
// TODO   view_->DrawThePath( path );
}

void ViewSub::OnMetaChanged( const Meta & meta )
{
    view_->OnMetaChanged( meta );
}

void ViewSub::OnMetaAdded(const Meta & meta )
{
    view_->OnMetaAdded( meta );
}

void ViewSub::OnMetaRemoved(const Meta & meta )
{
    view_->OnMetaRemoved( meta );
}

void ViewSub::OnConnectionAdded( const GraphConnection & connection )
{
    view_->OnConnectionAdded( connection );
}

void ViewSub::OnConnectionRemoved( const GraphConnection & connection )
{
    view_->OnConnectionRemoved( connection );
}