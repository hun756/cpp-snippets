#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/is_even.hpp"


TEST_CASE("Is Even Test", "[is_even]")
{
    REQUIRE(Math::isEven(3) == false);
    REQUIRE(Math::isEven(6) == true);
}