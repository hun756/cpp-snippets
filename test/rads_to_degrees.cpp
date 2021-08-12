#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/rads_to_degrees.hpp"

TEST_CASE("Rads To Degree Test","[rads_to_degree]")
{
    REQUIRE(Math::radsToDegrees(Math::PI / 2) == 90.0);
    REQUIRE(Math::radsToDegrees(Math::PI / 4) == 45.0);
}