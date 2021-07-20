#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/is_prime.hpp"

#include <vector>

TEST_CASE("Is Prime Test", "[Is Prime]")
{
    struct TestStruct
    {
        int val;
        bool actual;

        TestStruct(int val, bool actual) 
            : val(val), actual(actual) {}
    };

    std::vector<TestStruct> testVec;

    testVec.emplace_back(-1,    false);
    testVec.emplace_back(1,     false);
    testVec.emplace_back(2,     true);
    testVec.emplace_back(5,     true);
    testVec.emplace_back(11,    true);
    testVec.emplace_back(6,     false);
    testVec.emplace_back(1000,  false);

    for (auto &&var : testVec)
    {
        REQUIRE(Extra::Math::isPrime(var.val) == var.actual);
    }
}