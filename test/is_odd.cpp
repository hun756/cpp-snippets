#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/is_odd.hpp"


TEST_CASE("Is Odd Test", "[is_odd]")
{
    REQUIRE(Math::isOdd(3) == true);
    REQUIRE(Math::isOdd(6) == false);
}