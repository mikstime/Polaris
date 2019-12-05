#ifndef DEV_SEARCH_H
#define DEV_SEARCH_H

#include <vector>
#include "Model/include/Graph/Graph.h"
#include "GraphNode/GraphNode.h"

namespace Polaris
{
class Search
{
using Path = std::vector< GraphNode >;
using ID = size_t;
public:
    Search();
    Search( Search const & );
    Search( Search && ) noexcept;
    ~Search();
    Path FindPath( const Graph &, const GraphNode &, const GraphNode & );
    Path FindPath( const Graph &, ID, ID );
};
}//namespace Polaris

#endif //DEV_SEARCH_H
