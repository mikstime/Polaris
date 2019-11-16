#include "include/graph_parser.h"

using Polaris::GraphParser;

GraphParser::GraphParser(std::shared_ptr<ItemController> item_controller)
: item_cotroller_( item_controller )
{
}

void GraphParser::BuildItems( const Meta & meta, const std::vector< GraphConnection > & graph )
{

}

void GraphParser::RefreshItems( const Meta & meta, const std::vector< GraphConnection > & graph, std::vector< int > change_list)
{

}

void GraphParser::DrawThePath( std::vector< size_t > path )
{

}