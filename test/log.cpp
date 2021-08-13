#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/log.hpp"

TEST_CASE("Math Loagrithm Test", "[log]")
{
    REQUIRE(Math::log(2, 32) == 5);
    REQUIRE(Math::log(6, 36) == 2);
    REQUIRE(Math::log(10, 1) == 0);
    REQUIRE(Math::log(10, 1000000) == 6);
}