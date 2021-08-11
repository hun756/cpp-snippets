#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/is_alpha.hpp"

#include <vector>
#include <string>


struct TestStruct
{
    std::string val;
    bool actual;

    TestStruct(std::string val, bool actual)
        : val(val), actual(actual)
    {
    }
};

TEST_CASE("Is Alpha Test", "[is_alpha]")
{
    std::vector<TestStruct> testVec{
        {
            "sampleInput",
            true
        },
        {
            "It will fail",
            false
        },
        {
            "456",
            false
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(String::isAlpha(var.val) == var.actual);
    }
}
