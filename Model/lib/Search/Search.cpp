#include "include/Search/Search.h"

using namespace Polaris;

Search::Search()
{

}

Search::Search(Polaris::Search &&) noexcept
{

}

Search::Search(const Polaris::Search &)
{

}

Search::~Search()
{

}

GraphNode Search::Find(const Polaris::Graph &, size_t, size_t)
{
    return GraphNode();
}

GraphNode Search::Find(const Polaris::Graph &, const Polaris::GraphNode &, const Polaris::GraphNode &)
{
    return GraphNode();
}