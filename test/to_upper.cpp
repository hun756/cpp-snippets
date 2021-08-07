#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/to_upper.hpp"

#include <vector>
#include <string>

TEST_CASE("Tolower Test", "[tolower]")
{
    struct TestStruct
    {
        std::string val;
        std::string actual;

        TestStruct(std::string val, std::string actual)
            : val(val), actual(actual) {}
    };

    std::vector<TestStruct> testVec;

    testVec.emplace_back("MerHaba", "MERHABA");
    testVec.emplace_back("merhaba", "MERHABA");
    testVec.emplace_back("merhaba123", "MERHABA123");
    testVec.emplace_back("merhaba\n123", "MERHABA\n123");

    for (auto &&var : testVec)
    {
        REQUIRE(String::toUpper(var.val) == var.actual);
    }
}