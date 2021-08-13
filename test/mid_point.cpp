#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/mid_point.hpp"

#include <array>
#include <vector>

template <typename T>
struct TestStruct
{
    std::array<T, 2> inputArr1;
    std::array<T, 2> inputArr2;
    std::array<double, 2> actual;

    TestStruct(
        std::array<T, 2> inputArr1,
        std::array<T, 2> inputArr2,
        std::array<double, 2> actual
    )   :   inputArr1(inputArr1),   
            inputArr2(inputArr2),
            actual(actual)
    {
    }
};

TEST_CASE("Mid Point Test", "[test]")
{
    std::vector<TestStruct<int>> testVec {
        {
            {2, 2},
            {4, 4},
            {3, 3}
        },
        {
            {4, 4},
            {6, 6},
            {5, 5}
        },
        {
            {1, 3},
            {2, 4},
            {1.5, 3.5}
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(Math::midPoint(var.inputArr1, var.inputArr2) == var.actual);
    }
}