#include "include/Search/Search.h"
#include "include/Search/PriorityQueue.h"
#include <functional>
#include <unordered_map>
#include <include/GraphInterface/GraphInterface.h>
#include <algorithm>

using namespace Polaris;
using Path = std::vector< GraphNode >;

Path Search::FindPath( GraphInterface & graph, const Id & from, const Id & to )
{
    // Delegate to FindPath( graph, node, node )
    return FindPath( graph, graph.getNode( from ), graph.getNode( to ) );
}

Path Search::FindPath( GraphInterface & graph, GraphNode & from, GraphNode & to)
{
    // Store currennt path
    std::unordered_map< Id, GraphNode > came_from{};
    // Store current cost
    std::unordered_map< Id, Price > cost_so_far{};
    // Nodes to be checked
    PriorityQueue< GraphNode, Price > frontier{};
    // Start point
    frontier.put(from, 0);
    came_from[ from.GetId() ] = from;
    // Start price
    cost_so_far[ from.GetId() ] = 0;
    // Loop until path is found or no nodes left
    while( !frontier.empty() ) {
        // Node to be checked
        GraphNode current = frontier.pop();
        // path found
        if(current == to)
            break;
        /**********************************************************************
         * Dijkstra search.
         *********************************************************************/
        double new_cost = 0, cur_price = 0;
        for( Id next_id : current.neighbors )
        {
            GraphNode next = graph.getNode( next_id );
            cur_price = graph.getConnection( current.GetId(), next_id ).cost;
            new_cost = cost_so_far[ current.GetId() ] + cur_price;
            // If point has not been processed yet or a cheaper path is found
            if( cost_so_far.find( next_id ) == cost_so_far.end() ||
                new_cost < cost_so_far[ next_id ] )
            {
                // update costs and previous path.
                cost_so_far[ next_id ] = new_cost;
                came_from[ next_id ] = current;
                // Put vertex in queue to process
                frontier.put( next, new_cost );
            }
        }
    }
    Path path;
    GraphNode current = to;
    // No path found
    if( came_from.find(  current.GetId() ) == came_from.end() )
        return path;
    // Reconstruct path
    while( current != from )
    {
        path.push_back( current );
        current = came_from[ current.GetId() ];
    }
    path.push_back( from );
    std::reverse( path.begin(), path.end() );
    return path;
}
//@TODO implement A* search algorithm
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
