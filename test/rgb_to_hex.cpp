#define CATCH_CONFIG_MAIN
#include "../src/algorithm/rgb_to_hex.hpp"
#include "../external/catch2/catch.hpp"

#include <string>

TEST_CASE("RGB to Hex Conversion Tests", "[rgbToHex]")
{
    using Algorithm::rgbToHex;

    struct TestCase {
        int r, g, b;
        std::string expectedHex;
    };

    std::vector<TestCase> testCases = {
        {255, 0, 0, "#FF0000"},
        {0, 255, 0, "#00FF00"},
        {0, 0, 255, "#0000FF"},
        {255, 255, 255, "#FFFFFF"},
        {0, 0, 0, "#000000"},
        {123, 222, 32, "#7BDE20"},
        {45, 134, 245, "#2D86F5"},
        {1, 2, 3, "#010203"},
        {254, 253, 252, "#FEFDFC"}
    };

    SECTION("Test RGB to Hex Conversion")
    {
        for (const auto& testCase : testCases) {
            REQUIRE(rgbToHex(testCase.r, testCase.g, testCase.b) == testCase.expectedHex);
        }
    }
}
