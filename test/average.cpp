#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/average.hpp"

#include <vector>

template <typename T>
struct TestStruct
{
    std::vector<T> arr;
    T actual;

    TestStruct(std::vector<T> arr, T actual)
        :   arr(arr), actual(actual)
    {
    }
};

TEST_CASE("Average Test", "<average>")
{
    std::vector<TestStruct<int>> testVec {
        {
            {2, 6},
            4
        },
        {
            {2, 4, 6, 8},
            5
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(Math::average(var.arr.begin(), var.arr.end()) == var.actual);
    }
}