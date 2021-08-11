#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/math/is_divisible.hpp"

#include <vector>
#include <string>


struct TestStruct
{
    int val1;
    int val2;
    bool actual;

    TestStruct(int val1, int val2, bool actual)
        : val1(val1), val2(val2), actual(actual)
    {
    }
};

TEST_CASE("Divisible Test", "[is_divisible]")
{
    std::vector<TestStruct> testVec{
        {
            6,
            3,
            true
        },
        {
            5,
            2,
            false
        },
        {
            10,
            -1,
            true
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Math::isDivisble(var.val1, var.val2) == var.actual);
    }
}
