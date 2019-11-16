#include "include/view_sub.h"

using Polaris::ViewSub;

ViewSub::ViewSub( View * view )
: view_( view )
{

}

void ViewSub::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void ViewSub::DrawThePath( std::vector < size_t > path )
{

}

void ViewSub::OnMetaChanged( const Meta & meta )
{

}

void ViewSub::OnMetaAdded( const Meta & meta )
{

}

void ViewSub::OnMetaRemoved( const Meta & meta )
{

}

void ViewSub::OnConnectionAdded( const GraphConnection & connection )
{

}

void ViewSub::OnConnectionRemoved( const GraphConnection & connection )
{

}