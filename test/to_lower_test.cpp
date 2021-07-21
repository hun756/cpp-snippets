#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/to_lower.hpp"

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

    testVec.emplace_back("Merhaba", "merhaba");
    testVec.emplace_back("MerHaba", "merhaba");
    testVec.emplace_back("MERHABA", "merhaba");
    testVec.emplace_back("MERHABA123", "merhaba123");
    testVec.emplace_back("MERHABA\n123", "merhaba\n123");

    for (auto &&var : testVec)
    {
        REQUIRE(String::toLower(var.val) == var.actual);
    }

}