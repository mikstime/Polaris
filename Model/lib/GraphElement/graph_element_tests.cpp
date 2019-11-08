#define CATCH_CONFIG_MAIN
#include "include/GraphElement/GraphElement.h"
#include <catch2/catch.hpp>

TEST_CASE( "ID generation test", "[GraphElement]" ) {
    auto ge = Polaris::GraphElement();
    REQUIRE(ge.getId() == 0);
}