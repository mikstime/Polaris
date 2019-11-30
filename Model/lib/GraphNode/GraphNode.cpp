#include "include/GraphNode/GraphNode.h"

using namespace Polaris;

GraphNode::GraphNode()
{

}

GraphNode::GraphNode( Polaris::GraphNode && ) noexcept
{

}

GraphNode::GraphNode( const Polaris::GraphNode & )
{

}

GraphNode::~GraphNode()
{

}

void GraphNode::AddNeighbor( const Polaris::GraphNode & ) {

}

void GraphNode::RemoveNeighbor( const Polaris::GraphNode & ) {

}

void GraphNode::AddConnection( const Polaris::GraphConnection & )
{

}

void GraphNode::RemoveConnection( const Polaris::GraphConnection & )
{

}

bool GraphNode::HasNeighbor( const Polaris::GraphNode & )
{
    return false;
}