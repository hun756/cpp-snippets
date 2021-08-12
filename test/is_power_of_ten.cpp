#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/is_power_of_ten.hpp"

TEST_CASE("Is Power Of Ten Test","[power_of_ten]")
{
        REQUIRE(Math::isPowerOfTen(10) == true);
        REQUIRE(Math::isPowerOfTen(1) == true);
        REQUIRE(Math::isPowerOfTen(100) == true);
        REQUIRE(Math::isPowerOfTen(100.0) == true);
        REQUIRE(Math::isPowerOfTen(20) == false);
        REQUIRE(Math::isPowerOfTen(1000000000) == true);
        REQUIRE(Math::isPowerOfTen(10000000000000000000) == true);
}