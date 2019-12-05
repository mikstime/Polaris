#include "include/Search/Search.h"
#include "include/Search/PriorityQueue.h"
#include <functional>
#include <unordered_map>
#include <include/GraphInterface/GraphInterface.h>

using namespace Polaris;
using Path = std::vector< GraphNode >;
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

Path Search::FindPath( GraphInterface & graph, const Id & from, const Id & to )
{
    return FindPath( graph, graph.getNode( from ), graph.getNode( to ) );
}

Path Search::FindPath( GraphInterface & graph, GraphNode & from, GraphNode & to)
{
    std::unordered_map< Id, GraphNode > came_from{};
    std::unordered_map< Id, Price > cost_so_far{};
    PriorityQueue< GraphNode, Price > frontier{};
    frontier.put(from, 0);

    //@TODO find node in graph.
    came_from[ from.GetId() ] = from;
    cost_so_far[ from.GetId() ] = 0;
    while (!frontier.empty()) {
        GraphNode current = frontier.pop();

        if (current == to) {
            break;
        }
        double new_cost = 0, cur_price = 0;
        for (Id next_id : current.neighbors) {
            GraphNode next = graph.getNode( next_id );
            cur_price = graph.getConnection(current.GetId(), next_id ).cost;
            new_cost = cost_so_far[current.GetId()] + cur_price;
            if (cost_so_far.find(next_id) == cost_so_far.end()
                || new_cost < cost_so_far[next_id]) {
                cost_so_far[next_id] = new_cost;
                came_from[ next_id ] = current;
                frontier.put(next, new_cost);
            }
        }
    }
    Path path;
    GraphNode current = to;
    Id cur_id;

    //@TODO fix case when no path found
    while( current != from )
    {
        path.push_back( current );
        current = came_from[ current.GetId() ];
    }
    path.push_back( from );
    std::reverse( path.begin(), path.end() );
    return path;
}
//
//Path Search::FindPath( Graph &, const std::vector< Meta > & meta,
//                       const GraphNode &, const GraphNode & ) {
//    return Polaris::Search::Path();
//}
//
//Path Search::FindPath( Graph &, const std::vector< Meta > & meta,
//                       const Search::ID &, const Search::ID & ) {
//    return Polaris::Search::Path();
//}
