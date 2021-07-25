#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/slice.hpp"

#include <vector>
#include <string>

template<typename T>
struct TestStruct
{
    std::vector<T> nums;
    int sliceNumber;
    std::vector<T> actual;

    TestStruct(std::vector<T> nums, int sliceNumber, std::vector<T> actual)
        : nums(nums), actual(actual), sliceNumber(sliceNumber) {}
};



template<typename T>
struct TestStruct2
{
    std::vector<T> nums;
    int sliceNumberBegin;
    int sliceNumberEnd;
    std::vector<T> actual;

    TestStruct2(std::vector<T> nums, int sliceNumberBegin, int sliceNumberEnd, std::vector<T> actual)
        : nums(nums), actual(actual), sliceNumberBegin(sliceNumberBegin) ,sliceNumberEnd(sliceNumberEnd) {}
};


TEST_CASE("Slice Single Integer Array TEst", "[Slice Test]")
{
    std::vector<TestStruct<int>> testVec
    {
        {
            {5, 6, 50, 1, -5},
            2,
            {50, 1, -5}
        },
        {
            
            {5, 6},
            1,
            {6}
        },
        {
            {5},
            1,
            {}
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::slice(var.nums, var.sliceNumber) == var.actual);
    }
}


TEST_CASE("Slice Using 2 Parameter Function Test", "[Slice Test]")
{
    std::vector<std::string> animals({"ant", "bison", "camel", "duck", "elephant"});
    std::vector<TestStruct2<std::string>> testVec
    {
        {
            animals,
            0,
            2,
            {"ant", "bison"}
        },
        {
            animals,
            2,
            4,
            {"camel", "duck"}
        },
        {
            animals,
            1,
            5,
            {"bison", "camel", "duck", "elephant"}
        },
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::slice(var.nums, var.sliceNumberBegin, var.sliceNumberEnd) == var.actual);
    }
}