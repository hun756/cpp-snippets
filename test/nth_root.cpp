#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/nth_root.hpp"


TEST_CASE("nth Rooth Test", "nth_root")
{
    REQUIRE(Math::nthRoot(32.0, 2.0) == 5);
    REQUIRE(Math::nthRoot(4.0, 2.0) == 2);
    REQUIRE(Math::nthRoot(25.0, 5.0) == 2);
}