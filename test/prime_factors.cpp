#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/prime_factors.hpp"

#include <vector>

struct TestStruct
{
    int num;
    std::vector<int> actual;

    TestStruct(int num, std::vector<int> actual)
        :   num(num), actual(actual)
    {
    }
};

TEST_CASE("Prime Factor Test", "[prime_factors]")
{
    std::vector<TestStruct> testVec {
        {
            143,
            {11, 13}
        },
        {
            147,
            {3, 7, 7}
        },
        {
            167,
            {167}
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(Math::primeFactors(var.num) == var.actual);
    }
}