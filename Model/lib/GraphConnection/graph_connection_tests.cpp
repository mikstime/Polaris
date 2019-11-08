#define CATCH_CONFIG_MAIN
#include "include/GraphConnection/GraphConnection.h"
#include <catch2/catch.hpp>
#include "include/GraphNode/GraphNode.h"
TEST_CASE( "GraphNode ID generation test", "[GraphConnection]" ) {
    auto gc = Polaris::GraphConnection();
    REQUIRE( gc.getId() == 0 );
}

TEST_CASE( "GraphNode field initialization test", "[GraphConnection]" ) {
    auto gc = Polaris::GraphConnection();
    gc.Neighbor = new Polaris::GraphNode();
    gc.cost = 4.23;
    REQUIRE( gc.Neighbor->getId() == 1 );
    REQUIRE( gc.cost == 4.23 );
}

TEST_CASE( "GraphNode copy constructor test", "[GraphConnection]" ) {
    auto gc = Polaris::GraphConnection();
    gc.cost = 1.23;
    gc.Neighbor = new Polaris::GraphNode();
    auto gc_c = Polaris::GraphConnection( gc );
    REQUIRE( gc.Neighbor == gc_c.Neighbor );
    REQUIRE( gc.cost == gc_c.cost );
    delete( gc.Neighbor );
    gc.Neighbor = new Polaris::GraphNode();
    REQUIRE( gc.Neighbor != gc_c.Neighbor );
}