#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/is_lower_case.hpp"

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

TEST_CASE("Array Contains With Integer Vector", "[contains]")
{
    std::vector<TestStruct> testVec{
        {
            "abc",
            true
        },
        {
            "a3@$",
            true
        },
        {
            "Ab",
            false
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(String::isLowerCase(var.val) == var.actual);
    }
}
