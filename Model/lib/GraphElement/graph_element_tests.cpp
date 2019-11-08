#define CATCH_CONFIG_MAIN
#include "include/GraphElement/GraphElement.h"
#include <catch2/catch.hpp>

TEST_CASE( "GraphElement ID generation test", "[GraphElement]" ) {

    for(size_t i = 0; i < 1000; i++)
    {
        auto ge = Polaris::GraphElement();
        REQUIRE( ge.getId() == i );
    }

}
TEST_CASE( "GraphElement copy constructor test", "[GraphElement]" ) {

    auto ge = Polaris::GraphElement();
    auto ge_c = Polaris::GraphElement( ge );
    REQUIRE( ge.getId() == ge_c.getId() );
    auto ge_1 = Polaris::GraphElement();
    REQUIRE( ge_1.getId() == ge.getId() );
    REQUIRE( ge_1.getId() == ge_c.getId() );
}