#define CATCH_CONFIG_MAIN

#include "../external/catch2/catch.hpp"
#include "../src/math/pair_prod.hpp"

#include <unordered_map>
#include <vector>

template <typename T, typename U>
struct TestStruct
{
    std::vector<T> num1;
    std::vector<U> num2;

    std::unordered_map<T, U> actual;

    TestStruct(
        std::vector<T> num1,
        std::vector<U> num2,
        std::unordered_map<T, U> actual
    )   :   num1(num1), num2(num2), actual(actual)
    {
    }
};

TEST_CASE("Pair Prod Test", "[pair_prod]")
{
    std::vector<TestStruct<int, char>> testVec {
        {
            {1, 2},
            {'a', 'b'},
            {
                {1, 'a'}, 
                {1, 'b'}, 
                {2, 'a'}, 
                {2, 'b'}
            }
        },
        {
            {1, 2, 3},
            {'a', 'b'},
            {
                {1, 'a'}, 
                {1, 'b'}, 
                {2, 'a'}, 
                {2, 'b'}, 
                {3, 'a'}, 
                {3, 'b'}
            }
        }
    };


    for (auto&& var : testVec)
    {
        REQUIRE(Math::pairProd(var.num1, var.num2) == var.actual);
    }
}