#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/nth_root.hpp"

using Math::NthRootCalculator;

TEST_CASE("Nth Root Calculation Tests", "[NthRootCalculator]") {
    SECTION("Calculate square roots") {
        REQUIRE(NthRootCalculator<double>::calculate(4, 2) == Approx(2.0).epsilon(0.001));
        REQUIRE(NthRootCalculator<double>::calculate(16, 2) == Approx(4.0).epsilon(0.001));
    }

    SECTION("Calculate cube roots") {
        REQUIRE(NthRootCalculator<double>::calculate(8, 3) == Approx(2.0).epsilon(0.001));
        REQUIRE(NthRootCalculator<double>::calculate(27, 3) == Approx(3.0).epsilon(0.001));
    }

    SECTION("Calculate nth roots for non-integer results") {
        REQUIRE(NthRootCalculator<double>::calculate(2, 2) == Approx(1.41421).epsilon(0.001));
        REQUIRE(NthRootCalculator<double>::calculate(10, 3) == Approx(2.15443).epsilon(0.001));
    }

    SECTION("Handle negative bases for odd roots") {
        REQUIRE(NthRootCalculator<double>::calculate(-27, 3) == Approx(-3.0).epsilon(0.001));
    }

    SECTION("Throw exception for negative base with even root") {
        REQUIRE_THROWS_AS(NthRootCalculator<double>::calculate(-16, 2), std::invalid_argument);
    }

    SECTION("Throw exception for zero or negative n") {
        REQUIRE_THROWS_AS(NthRootCalculator<double>::calculate(16, 0), std::invalid_argument);
        REQUIRE_THROWS_AS(NthRootCalculator<double>::calculate(16, -2), std::invalid_argument);
    }
}
