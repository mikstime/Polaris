#include "include/graph_parser.h"

using Polaris::GraphParser;

GraphParser::GraphParser( ItemController * item_controller )
: item_cotroller_( item_controller )
{

}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphParser::DrawThePath( std::vector< size_t > path )
{

}

void GraphParser::OnMetaChanged( const Meta & meta )
{

}

void GraphParser::OnMetaAdded( const Meta & meta )
{

}

void GraphParser::OnMetaRemoved( const Meta & meta )
{

}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{

}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{

}