#define CATCH_CONFIG_MAIN
#include "GraphElement/GraphElement.h"
#include <catch2/catch.hpp>

TEST_CASE( "GraphElement ID generation test", "[GraphElement]" ) {

    for(size_t i = 0; i < 1000; i++)
    {
        auto ge = Polaris::GraphElement();
        REQUIRE( ge.GetId() == i + 1 );
    }

}
TEST_CASE( "GraphElement copy constructor test", "[GraphElement]" ) {

    auto ge = Polaris::GraphElement();
    auto ge_c = Polaris::GraphElement( ge );
    REQUIRE( ge.GetId() == ge_c.GetId() );
    auto ge_1 = Polaris::GraphElement( ge_c );
    REQUIRE( ge_1.GetId() == ge.GetId() );
    REQUIRE( ge_1.GetId() == ge_c.GetId() );
    auto ge_3 = Polaris::GraphElement();
    REQUIRE( ge_3.GetId() == ge.GetId() + 1 );
}