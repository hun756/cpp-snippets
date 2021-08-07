#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/distance.hpp"

#include <vector>
#include <string>
#include <limits>
#include <cmath>


static bool isSame(double x, double y)
{
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon() ;
}


TEST_CASE("Distance Test", "[distance]")
{
    struct TestStruct
    {
        double pointX0;
        double pointX1;
        double pointY0;
        double pointY1;

        double actual;

        TestStruct(double pointX0, double pointX1, 
            double pointY0,double pointY1, 
            double actual
        )   :   pointX0(pointX0), pointX1(pointX1), 
                pointY0(pointY0), pointY1(pointY1),
            actual(actual) 
        {
        }
    };

    std::vector<TestStruct> testVec;

    testVec.emplace_back(1.0, 1.0, 4.0, 5.0, 5.0);

    for (auto &&var : testVec)
    {
        REQUIRE(isSame(Algorithm::distance(var.pointX0, var.pointX1, var.pointY0, var.pointY1), var.actual));
    }
}