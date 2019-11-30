#include "include/Search/Search.h"

using namespace Polaris;
using Path = std::vector< GraphNode >
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

Path Search::FindPath(const Polaris::Graph &, size_t, size_t)
{
    return Path();
}

Path Search::FindPath(const Polaris::Graph &, const Polaris::GraphNode &, const Polaris::GraphNode &)
{
    return Path();
}