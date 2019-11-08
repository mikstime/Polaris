#define CATCH_CONFIG_MAIN
#include "include/GraphNode/GraphNode.h"
#include <catch2/catch.hpp>

TEST_CASE( "GraphNode copy constructor test", "[GraphNode]" ) {

    auto gn = Polaris::GraphNode();
    auto gn_c = Polaris::GraphNode( gn );
    REQUIRE( gn.getId() == gn_c.getId() );
    auto gn_1 = Polaris::GraphNode();
    REQUIRE( gn_1.getId() == gn.getId() );
    REQUIRE( gn_1.getId() == gn_c.getId() );
}