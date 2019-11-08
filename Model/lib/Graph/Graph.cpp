#include "include/Graph/Graph.h"

using namespace Polaris;

Graph::Graph()
{

}
Graph::Graph( Graph && ) noexcept
{

}

Graph::Graph( Graph const & )
{

}

Graph::~Graph()
{

}

void Graph::AddNode( const GraphNode & )
{

}

const GraphNode& Graph::getNode( ID id )
{
    return Graph_[ id ];
}

bool Graph::HasNode( ID id )
{
    //@TODO implement this later
    return false;
}

void Graph::RemoveNode( const GraphNode & )
{

}