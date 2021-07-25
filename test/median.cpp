#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/median.hpp"

#include <vector>

TEST_CASE("Median", "[Median Test]")
{
    struct TestStruct
    {
        std::vector<int> nums;
        double actual;

        TestStruct(std::vector<int> nums, double actual)
            : nums(nums), actual(actual) {}
    };

    std::vector<TestStruct> testVec;
    testVec.push_back({{5, 6, 50, 1, -5}, 5.0});
    testVec.push_back({{1}, 1.0});
    testVec.push_back({{1, 2}, 1.5});

    for (auto &&var : testVec)
    {
        REQUIRE(Algorithm::median(var.nums) == var.actual);
    }

    REQUIRE_THROWS(Algorithm::median({}));
}