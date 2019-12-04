#include "Main/include/view_sub.h"

using Polaris::ViewSub;

ViewSub::ViewSub( View * view )
: view_( view )
{

}

void ViewSub::onPathFound( const std::vector< const GraphNode > & nodes,
                           const std::vector< const GraphConnection > & connections )
{
// TODO   view_->DrawThePath( path );
}

void ViewSub::onMetaChanged( const Meta & meta )
{
    view_->ChangeRoom(meta);
}

void ViewSub::onMetaAdded(const Meta & meta )
{
    view_->AddRoom(meta);
}

void ViewSub::onMetaRemoved(const Meta & meta )
{
    view_->RemoveRoom(meta);
}

void ViewSub::onConnectionAdded( const GraphConnection & connection )
{
    view_->AddConnection(connection);
}

void ViewSub::onConnectionRemoved( const GraphConnection & connection )
{
    view_->RemoveConnection(connection);
}