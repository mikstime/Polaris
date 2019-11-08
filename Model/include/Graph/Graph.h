#ifndef GRAPHSEARCH_GRAPH_H
#define GRAPHSEARCH_GRAPH_H

#include <vector>
#include "include/GraphNode/GraphNode.h"

namespace Polaris
{
class Graph
{
using ID = size_t;
using GNArray = std::vector< Polaris::GraphNode >;
private:
    GNArray Graph_;
public:
    Graph();
    Graph( Graph const & );
    Graph( Graph && ) noexcept;
    ~Graph();

    void AddNode( const GraphNode & );
    void RemoveNode( const GraphNode & );
    void RemoveNode( ID );

    const GraphNode & getNode( ID );
    bool HasNode( ID );
};
}//namespace Polaris

#endif //GRAPHSEARCH_GRAPH_H
