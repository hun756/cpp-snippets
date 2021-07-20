#ifndef IS_NULL_OR_WHITESPACE
#define IS_NULL_OR_WHITESPACE

#include <string>

namespace String
{
    static constexpr bool isNullOrWhiteSpace(const std::string& str)
    {
        return str.empty() || std::all_of(
                                str.begin(),
                                str.end(),
                                [](char c)
                                {
                                    return ::isspace(c);
                                });
    }
}

#endif /** end of include guard: IS_NULL_OR_WHITESPACE */