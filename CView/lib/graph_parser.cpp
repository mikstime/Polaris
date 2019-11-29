#include "include/graph_parser.h"

using Polaris::GraphParser;

GraphParser::GraphParser( ItemController * item_controller )
: item_cotroller_( item_controller )
{

}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphParser::OnPathFound( const std::vector< const GraphNode > & nodes,
                               const std::vector< const GraphConnection > & connections )
{

}

void GraphParser::OnMetaChanged( const Meta & meta )
{

}

void GraphParser::OnRoomAdded(const Meta & meta )
{

}

void GraphParser::OnRoomRemoved(const Meta & meta )
{

}

void GraphParser::OnConnectionAdded( const GraphConnection & connection )
{

}

void GraphParser::OnConnectionRemoved( const GraphConnection & connection )
{

}