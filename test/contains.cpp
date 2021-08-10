#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/contains.hpp"

#include <vector>
#include <string>
#include <array>

template <typename T>
struct TestStruct
{
    std::vector<T> val;
    T findVal;
    bool actual;

    TestStruct(std::vector<T> val, T findVal, bool actual)
        : val(val), actual(actual), findVal(findVal)
    {
    }
};

TEST_CASE("Array Contains With Integer Vector", "[contains]")
{
    std::vector<TestStruct<int>> testVec{
        {
            {1, 2, 3, 4, 5, 6},
            5,
            true
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::contains(var.val, var.findVal) == var.actual);
    }
}



template <typename T, int _tVal>
struct TestStruct2
{
    std::array<T, _tVal> val;
    T findVal;
    bool actual;

    TestStruct2(std::array<T, _tVal> val, T findVal, bool actual)
        : val(val), actual(actual), findVal(findVal)
    {
    }
};


TEST_CASE("Array Contains With String Array", "[contains]")
{
    std::vector<TestStruct2<std::string, 3>> testVec{
        {
            {"melon", "watermelon", "cherry"},
            "melon",
            true
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::contains(var.val, var.findVal) == var.actual);
    }
}
