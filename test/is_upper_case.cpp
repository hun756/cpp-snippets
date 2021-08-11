#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/is_upper_case.hpp"

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

TEST_CASE("Is Upper Case", "[isUpper]")
{
    std::vector<TestStruct> testVec{
        {
            "ABC",
            true
        },
        {
            "A3@$",
            true
        },
        {
            "aBC",
            false
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(String::isUpperCase(var.val) == var.actual);
    }
}
