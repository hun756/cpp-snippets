#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/rgb_to_hex.hpp"

#include <array>
#include <string>

TEST_CASE("Array Unique Array", "[Median Test]")
{
    struct TestStruct
    {
        std::array<uint8_t, 3> nums;
        std::string actual;

        TestStruct(std::array<uint8_t, 3> nums, std::string actual)
            : nums(nums), actual(actual) {}
    };

    std::vector<TestStruct> testVec{
        {
            {192, 192, 192}, "#c0c0c0"
        }
    };


    for (auto &&var : testVec)
    {
        REQUIRE(
            Algorithm::rgbToHex(
                var.nums[0], 
                var.nums[1], 
                var.nums[2]
            ) == var.actual
        );
    }
}