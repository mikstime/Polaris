#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "include/Graph/Graph.h"
#include <random>

TEST_CASE( "Simple Test", "[Graph]" ) {
    auto g = Polaris::Graph();
    auto t_n = Polaris::GraphNode();
    g.AddNode( t_n );
    REQUIRE( g.HasNode( t_n.getId() ) );
}
TEST_CASE( "1000 Nodes Test", "[Graph]" ) {
    auto g = Polaris::Graph();
    for( size_t i = 0; i < 1000; i++)
    {
        auto t_n = Polaris::GraphNode();
        g.AddNode( t_n );
        REQUIRE( g.HasNode( t_n.getId() ) );
        REQUIRE( g.HasNode( random() % i ) );
    }
    for( size_t i = 0; i < 500; i++)
    {
        g.RemoveNode(i);
    }
    for( size_t i = 0; i < 500; i++)
    {
        REQUIRE(!g.HasNode(i));
    }
}