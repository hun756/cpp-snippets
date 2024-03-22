#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/distance.hpp"

#include <string>

// static bool isSame(double x, double y)
// {
//     return std::fabs(x - y) < std::numeric_limits<double>::epsilon() ;
// }


TEST_CASE("Distance Calculation Tests", "[distance]") {
    using namespace Algorithm;

    SECTION("Point to Point Distance") {
        Point<double> p1(0.0, 0.0);
        Point<double> p2(3.0, 4.0);

        REQUIRE(p1.distanceTo(p2) == Approx(5.0).epsilon(0.001));
    }

    SECTION("Different Types") {
        Point<int> p1(0, 0);
        Point<float> p2(3.0f, 4.0f);

        REQUIRE(p1.distanceTo(p2) == Approx(5.0).epsilon(0.001));
    }

    SECTION("Negative Coordinates") {
        Point<double> p1(-1.0, -1.0);
        Point<double> p2(-4.0, -5.0);

        REQUIRE(p1.distanceTo(p2) == Approx(5.0).epsilon(0.001));
    }

    SECTION("Extreme Values") {
        Point<long long> p1(LLONG_MIN, LLONG_MIN);
        Point<long long> p2(LLONG_MAX, LLONG_MAX);

        REQUIRE_NOTHROW(p1.distanceTo(p2));
    }

    SECTION("Using std::pair and std::tuple") {
        std::pair<int, int> p1 = {0, 0};
        std::pair<double, double> p2 = {3.0, 4.0};

        REQUIRE(Algorithm::distance(p1, p2) == Approx(5.0).epsilon(0.001));

        std::tuple<int, int> t1 = std::make_tuple(0, 0);
        std::tuple<double, double> t2 = std::make_tuple(3.0, 4.0);

        REQUIRE(Algorithm::distance(t1, t2) == Approx(5.0).epsilon(0.001));
    }
}
