#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/all_equal.hpp"

#include <vector>
#include <string>


template<typename T>
struct TestStruct
{
    std::vector<T> nums;

    bool actual;

    TestStruct(std::vector<T> nums, bool actual)
        : nums(nums), actual(actual)
    {
    }
};

TEST_CASE("All Equal Test", "[all_equal]")
{
    std::vector<TestStruct<int>> testVec {
        {
            {1, 2, 3, 3, 3, 3},
            false
        },
        {
            {-5, 3, 6, 7, 8, 9, 11},
            false
        },
        {
            {1, 2, 3, 4, 5, 6},
            false
        },
        {
            {1, 1, 1, 1, 1, 1},
            true
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::allEqual(var.nums) == var.actual);
    }
}