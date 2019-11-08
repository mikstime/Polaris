#ifndef DEV_SEARCH_H
#define DEV_SEARCH_H

#include <vector>
#include "include/Graph/Graph.h"
#include "include/GraphNode/GraphNode.h"

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
    GraphNode Find( const Graph &, const GraphNode &, const GraphNode & );
    GraphNode Find( const Graph &, ID, ID );
};
}//namespace Polaris

#endif //DEV_SEARCH_H
