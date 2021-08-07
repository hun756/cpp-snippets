#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/union.hpp"

#include <vector>
#include <string>

TEST_CASE("Union Test", "[union]")
{
    struct TestStruct
    {
        std::vector<int> val1;
        std::vector<int> val2;
        std::vector<int> actual;

        TestStruct(std::vector<int> val1,
                   std::vector<int> val2,
                   std::vector<int> actual)
            : val1(val1), val2(val2), actual(actual) {}
    };

    std::vector<TestStruct> testVec {
        {
            {1, 2, 3, 3, 3, 3},
            {4, 3, 2},
            {1, 2, 3, 4}
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Algroithm::_union(var.val1, var.val2) == var.actual);
    }
}