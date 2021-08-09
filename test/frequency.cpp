#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/algorithm/frequency.hpp"

#include <vector>
#include <string>

template <typename T, typename U>
struct TestStruct
{
    U val;

    std::unordered_map<T, size_t> actual;

    TestStruct(U val, std::unordered_map<T, size_t> actual)
        : val(val), actual(actual)
    {
    }
};

TEST_CASE("Frequency Test", "[frequency]")
{
    std::vector<TestStruct<char, std::string>> testVec{
        {"hello",
         {std::pair<char, size_t>('h', 1),
          std::pair<char, size_t>('e', 1),
          std::pair<char, size_t>('l', 2),
          std::pair<char, size_t>('o', 1)}}};

    for (auto &&var : testVec)
    {
        REQUIRE(Algorithm::frequency<char, std::string>(var.val) == var.actual);
    }
}


/*
TEST_CASE("Frequency Test With Vector Container", "[frequency]")
{
    std::vector<TestStruct<std::string, std::vector<std::string>>> testVec{
        {
            {
                "melon",
                "watermelon",
                "cheery"
                "melon"
            },
            {
                std::pair<std::string, size_t>("melon", 2),
                std::pair<std::string, size_t>("watermelon", 1),
                std::pair<std::string, size_t>("cheery", 1)
            }
        }
    };

    std::cout << "printed" << testVec[0].actual["melon"] << '\n';

    for (auto &&var : testVec)
    {
        REQUIRE(Algorithm::frequency<
                    std::string, 
                    std::vector<std::string>
                    >(var.val) == var.actual);
    }
}
*/