#include "include/graph_parser.h"

using Polaris::GraphParser;

GraphParser::GraphParser( ItemController * item_controller )
: item_cotroller_( item_controller )
{

}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph ) const
{

}

void GraphParser::DrawThePath( std::vector< size_t > path ) const
{

}

void GraphParser::OnMetaChanged( const Meta & meta ) const
{

}

void GraphParser::OnMetaAdded( const Meta & meta ) const
{

}

void GraphParser::OnMetaRemoved( const Meta & meta ) const
{

}

void GraphParser::OnConnectionAdded( const GraphConnection & connection ) const
{

}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection ) const
{

}