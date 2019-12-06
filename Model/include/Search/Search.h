#ifndef DEV_SEARCH_H
#define DEV_SEARCH_H

#include <vector>
#include "include/Graph/Graph.h"
#include "GraphNode/GraphNode.h"
#include "include/GraphInterface/GraphInterface.h"
#include "include/Search/PriorityQueue.h"
#include <Meta/Meta.h>
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
    static Path FindPath( GraphInterface &, GraphNode &, GraphNode & );
    static Path FindPath( GraphInterface &, const ID & , const ID & );
//    Path FindPath( Graph &, const std::vector< Meta > & meta, const GraphNode &, const GraphNode & );
//    Path FindPath( Graph &, const std::vector< Meta > & meta, const ID & , const ID & );
};
}//namespace Polaris

#endif //DEV_SEARCH_H
