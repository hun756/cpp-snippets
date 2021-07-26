#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/unique.hpp"

#include <vector>

TEST_CASE("Array Unique Array", "[Median Test]")
{
    struct TestStruct
    {
        std::vector<int> nums;
        std::vector<int> actual;

        TestStruct(std::vector<int> nums, std::vector<int> actual)
            : nums(nums), actual(actual) {}
    };

    std::vector<TestStruct> testVec{
        {
            {5, 6, 50, 5, 1, -5}, {-5, 1, 5, 6, 50}
        }
    };


    for (auto &&var : testVec)
    {
        Array::unique(var.nums);
        REQUIRE(var.nums == var.actual);
    }
}