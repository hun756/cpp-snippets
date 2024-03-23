#define CATCH_CONFIG_MAIN
#include "../src/algorithm/frequency.hpp"
#include "../external/catch2/catch.hpp"

#include <functional>
#include <string>
#include <vector>

class NonDefaultConstructible
{
private:
    int value;

public:
    explicit NonDefaultConstructible(int v) : value(v) {}

    bool operator==(const NonDefaultConstructible& other) const { return value == other.value; }

    bool operator<(const NonDefaultConstructible& other) const { return value < other.value; }

    int getValue() const { return value; }
};

namespace std
{
    template <>
    struct hash<NonDefaultConstructible> {
        std::size_t operator()(const NonDefaultConstructible& ndc) const noexcept
        {
            return std::hash<int>()(ndc.getValue());
        }
    };
} // namespace std

TEST_CASE("Frequency counts are correct for vector of ints", "[frequency]")
{
    std::vector<int> vec = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    auto freq = Algorithm::frequency<int>(vec);

    REQUIRE(freq[1] == 1);
    REQUIRE(freq[2] == 2);
    REQUIRE(freq[3] == 3);
    REQUIRE(freq[4] == 4);
}

TEST_CASE("Frequency counts are correct for list of chars", "[frequency]")
{
    std::list<char> lst = {'a', 'b', 'b', 'c', 'c', 'c'};
    auto freq = Algorithm::frequency<char>(lst);

    REQUIRE(freq['a'] == 1);
    REQUIRE(freq['b'] == 2);
    REQUIRE(freq['c'] == 3);
}

TEST_CASE("Frequency function works with empty container", "[frequency]")
{
    std::vector<int> emptyVec;
    auto freq = Algorithm::frequency<int>(emptyVec);

    REQUIRE(freq.empty());
}

TEST_CASE("Frequency counts with strings", "[frequency]")
{
    std::vector<std::string> strings = {"apple", "banana", "apple", "orange", "banana", "banana"};
    auto freq = Algorithm::frequency<std::string>(strings);

    REQUIRE(freq["apple"] == 2);
    REQUIRE(freq["banana"] == 3);
    REQUIRE(freq["orange"] == 1);
}

TEST_CASE("Frequency works with non-default constructible types", "[frequency]")
{
    std::vector<NonDefaultConstructible> ndcVec = {NonDefaultConstructible(1), NonDefaultConstructible(2),
                                                   NonDefaultConstructible(2), NonDefaultConstructible(3),
                                                   NonDefaultConstructible(3), NonDefaultConstructible(3)};

    auto freq = Algorithm::frequency<NonDefaultConstructible>(ndcVec);

    REQUIRE(freq[NonDefaultConstructible(1)] == 1);
    REQUIRE(freq[NonDefaultConstructible(2)] == 2);
    REQUIRE(freq[NonDefaultConstructible(3)] == 3);
}

TEST_CASE("Frequency counts for multimap container elements", "[frequency]")
{
    std::multimap<std::string, int> multimap = {{"apple", 1}, {"banana", 2}, {"cherry", 3}, {"banana", 4}};
    auto freq = Algorithm::frequency<std::string>(multimap);

    REQUIRE(freq["apple"] == 1);
    REQUIRE(freq["banana"] == 2);
    REQUIRE(freq["cherry"] == 1);
}
