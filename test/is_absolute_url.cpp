#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/is_absulte_url.hpp"

#include <vector>
#include <string>
#include <array>


struct TestStruct
{
    std::string val;
    bool actual;

    TestStruct(std::string val, bool actual)
        : val(val), actual(actual)
    {
    }
};

TEST_CASE("Absolute Url", "[is_absolute_url]")
{
    std::vector<TestStruct> testVec{
        {
            "https://google.com",
            true
        },
        {
            "ftp://www.myserver.net",
            true
        },
        {
            "/foo/bar",
            false
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(String::absolute(var.val) == var.actual);
    }
}
