#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/array/filter.hpp"

#include <vector>

template <typename T>
struct TestStruct
{
    std::vector<T> val;
    std::vector<T> actual;
    std::function<bool(const T&)> Fun;

    TestStruct(std::vector<T> val, std::vector<T> actual, std::function<bool(const T&)> Fun)
        : val(val), actual(actual), Fun(Fun)
    {
    }
};

TEST_CASE("Filter Test", "[filter]")
{
    std::vector<TestStruct<int>> testVec{
        {
            {1, 2, 3, 4, 5, 6},
            {2, 4, 6},
            [](int a) {
                return a % 2 == 0;
            }
        }
    };

    for (auto &&var : testVec)
    {
        REQUIRE(Array::filter(var.val, var.Fun) == var.actual);
    }
}

struct Person
{
    std::string name;
    size_t age;

    Person() = default;

    explicit Person(std::string name, size_t age)
        :   name(name), age(age)
    {
    }
};

///< !TODO: Constructor Error

TEST_CASE("Filter User Defined Type Test", "[filter]")
{
    std::vector<TestStruct<Person>> testVec;

    testVec.emplace_back(
        std::vector<Person>({ 
                Person("Mehmet", 18),
                Person("Ali", 19),
                Person("Veli", 16),
                Person("Selami", 42),
                Person("Huseyin", 15),
                Person("Merve", 36)
            }),
            std::vector<Person>({
                Person("Ali", 19),
                Person("Selami", 42),
                Person("Merve", 36)
            }),
            [](Person& a) {
                return a.age >= 18;
            }
    );

    for (auto &&var : testVec)
    {
        REQUIRE(Array::filter(var.val, var.Fun) == var.actual);
    }
}