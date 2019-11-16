#include "include/graph_parser.h"

using Polaris::GraphParser;

GraphParser::GraphParser( ItemController * item_controller)
: item_cotroller_( item_controller )
{
}

void GraphParser::BuildItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphParser::RefreshItems( const std::vector< Meta > & meta, const std::vector< GraphConnection > & graph,
                                std::vector< size_t > change_list)
{

}

void GraphParser::DrawThePath( std::vector< size_t > path )
{

}