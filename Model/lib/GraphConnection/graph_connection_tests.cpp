#define CATCH_CONFIG_MAIN
#include "include/GraphConnection/GraphConnection.h"
#include <catch2/catch.hpp>

TEST_CASE( "ID generation test", "[Polaris::GraphConnection]" ) {
    auto ge = Polaris::GraphConnection();
    REQUIRE( ge.getId() == 0 );
}