#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/includes_all.hpp"

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

TEST_CASE("Include All Test", "[include_all]")
{
    std::vector<TestStruct<int>> testVec {
        {
            {1, 2, 3, 3, 3, 3},
            {1, 5},
            false
        },
        {
            {-5, 3, 6, 7, 8, 9, 11},
            {-5, 76, 54},
            false
        },
        {
            {1, 2, 3, 4, 5, 6},
            {1, 2, 4},
            true
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::includesAll(var.nums, var.incs) == var.actual);
    }
}