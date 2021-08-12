#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/max_element.hpp"

#include <vector>
#include <array>


template <typename T>
struct TestStruct
{
    std::vector<T> vecs;
    T actual;

    TestStruct(std::vector<T> vecs, T actual)
        :   vecs(vecs), actual(actual)
    {
    }
};

TEST_CASE("Max Element in Array <int> Array Test", "max_element")
{
    std::vector<TestStruct<int>> testVec {
        {
            {1, 2, 3, 4, -1, 5},
            5
        },
        {
            {-567, -1, -5, -54654},
            -1
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(*Math::maxElement(var.vecs.begin(), var.vecs.end()) == var.actual);
    }
}

TEST_CASE("Max Element in Array <float> Array Test", "max_element")
{
    std::vector<TestStruct<float>> testVec {
        {
            {1.5f, 2.5343f, -1.123f, 5.0f},
            5.0f
        },
        {
            {-567.0, -1.4324f, -5.432, -54654.0},
            -1.4324f
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(*Math::maxElement(var.vecs.begin(), var.vecs.end()) == var.actual);
    }
}


template <typename T, int _size>
struct TestStruct2
{
    std::array<T, _size> arr;
    T actual;

    TestStruct2(std::array<T, _size> arr, T actual)
        :   arr(arr), actual(actual)
    {
    }
};
TEST_CASE("Max Element in Array <int> Array Test with std::array<> Continer", "max_element")
{
    std::vector<TestStruct2<int, 5>> testVec {
        {
            {2, 3, 4, -1, 5},
            5
        },
        {
            {-567, -1, -5, -4324, -54654},
            -1
        }
    };

    for (auto&& var : testVec)
    {
        REQUIRE(*Math::maxElement(var.arr.begin(), var.arr.end()) == var.actual);
    }
}