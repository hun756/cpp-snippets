#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/is_null_or_whitespace.hpp"

#include <vector>
#include <string>

TEST_CASE("Is Null Or White Space Test", "[Is Prime]")
{
    struct TestStruct
    {
        std::string val;
        bool actual;

        TestStruct(std::string val, bool actual)
            : val(val), actual(actual) {}
    };

    std::vector<TestStruct> testVec;

    testVec.emplace_back("", true);
    testVec.emplace_back(" ", true);
    testVec.emplace_back("\t", true);
    testVec.emplace_back("\r", true);
    testVec.emplace_back("  \t   ", true);
    testVec.emplace_back("                ", true);
    testVec.emplace_back(" \t mehmet", false);
    testVec.emplace_back("mehmet", false);
    testVec.emplace_back("mehmet\nmehmet", false);
    testVec.emplace_back("mehmet\tmehmet", false);
    testVec.emplace_back(" mehmet", false);
    testVec.emplace_back("mehmet ", false);

    for (auto &&var : testVec)
    {
        REQUIRE(String::isNullOrWhiteSpace(var.val) == var.actual);
    }
}