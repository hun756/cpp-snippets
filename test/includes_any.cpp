#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/includes_any.hpp"

#include <vector>
#include <string>


template<typename T>
struct TestStruct
{
    std::vector<T> nums;
    std::vector<T> incs;

    bool actual;

    TestStruct(std::vector<T> nums, std::vector<T> incs, bool actual)
        : nums(nums), incs(incs), actual(actual)
    {
    }
};

TEST_CASE("Include Any Test", "[include_any]")
{
    std::vector<TestStruct<int>> testVec {
        {
            {1, 2, 3, 3, 3, 3},
            {1, 5},
            true
        },
        {
            {-5, 3, 6, 7, 8, 9, 11},
            {-5, 76, 54},
            true
        },
        {
            {1, 2, 3, 4, 5, 6},
            {7, 8},
            false
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::includesAny(var.nums, var.incs) == var.actual);
    }
}