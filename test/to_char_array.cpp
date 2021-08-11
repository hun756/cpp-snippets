#define CATCH_CONFIG_MAIN
#include "../external/catch2/catch.hpp"
#include "../src/string/to_char_array.hpp"

#include <vector>
#include <string>
#include <array>
#include <initializer_list>

// struct TestStruct
// {
//     std::string val;
//     std::unique_ptr<char[]> actual;

//     TestStruct(std::string val, std::initializer_list<char> l)
//         :   val(val)
//     {
//         // assert(val.size() == l.size());
//         actual = std::make_unique<char[]>(val.length());
//         int i = 0;

//         for (auto iter = l.begin(); iter != l.end(); ++iter) {
//             actual.get()[i++] = *iter;
//         }
//     }
// };


TEST_CASE("To Char Array Test", "[to_char_array]")
{
    // std::vector<TestStruct> testVec {};

    // std::string _val = "hello";
    // // std::initializer_list<char> clist({'h', 'e', 'l', 'l', 'o'});

    // // auto arr = std::make_unique<char[]>(std::initializer_list<char>({'h', 'e', 'l', 'l', 'o'}));

    // testVec.push_back({_val, {'h', 'e', 'l', 'l', 'o'}});

    char testArr[] = {'h', 'e', 'l', 'l', 'o'};

    REQUIRE(strcmp(String::toCharArray("hello").get(), testArr));

}
