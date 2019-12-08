#ifndef DEV_SEARCH_H
#define DEV_SEARCH_H

#include <vector>
#include "include/Graph/Graph.h"
#include "GraphNode/GraphNode.h"
#include "include/GraphInterface/GraphInterface.h"
#include "include/Search/PriorityQueue.h"
#include "Meta/Meta.h"
#include "typedefs.h"
namespace Polaris
{
/******************************************************************************
 * class Search
 * Provides Dijkstra algorithm for path finding in graphs
 *****************************************************************************/
class Search
{
using Path = std::vector< GraphNode >;
public:
    // Only static methods provided. No need in instances
    Search() = delete;
    Search( Search const & ) = delete;
    Search( Search && ) = delete;
    ~Search() = delete;
    static Path FindPath( GraphInterface &, GraphNode &, GraphNode & );
    static Path FindPath( GraphInterface &, const Id & , const Id & );
    //@TODO A* algorithm.
    //@TODO heuristic function based on distance between nodes (x, y, floor in Meta).
//    Path FindPath( Graph &, const std::vector< Meta > & meta, const GraphNode &, const GraphNode & );
//    Path FindPath( Graph &, const std::vector< Meta > & meta, const ID & , const ID & );
};
}//namespace Polaris

#endif //DEV_SEARCH_H
