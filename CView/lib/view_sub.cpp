#include "include/view_sub.h"

using Polaris::ViewSub;

ViewSub::ViewSub( View * view )
: view_( view )
{

}

void ViewSub::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) const
{
    view_->BuildItems( meta, graph );
}

void ViewSub::DrawThePath( std::vector < size_t > path ) const
{
    view_->DrawThePath( path );
}

void ViewSub::OnMetaChanged( const Meta & meta ) const
{
    view_->OnMetaChanged( meta );
}

void ViewSub::OnMetaAdded( const Meta & meta ) const
{
    view_->OnMetaAdded( meta );
}

void ViewSub::OnMetaRemoved( const Meta & meta ) const
{
    view_->OnMetaRemoved( meta );
}

void ViewSub::OnConnectionAdded( const GraphConnection & connection ) const
{
    view_->OnConnectionAdded( connection );
}

void ViewSub::OnConnectionRemoved( const GraphConnection & connection ) const
{
    view_->OnConnectionRemoved( connection );
}