#ifndef STRING_REVERSE_HPP
#define STRING_REVERSE_HPP

#include <string>
#include <algorithm>

namespace String
{

    static constexpr void reverse(const std::string &str)
    {
        std::reverse(str.begin(), str.end());
    }

    static constexpr void reverse(const std::string &str, size_t reverseSize)
    {
        std::reverse(str.begin(), str.begin() + reverseSize);
    }
}

#endif /* end of include guard :  STRING_REVERSE_HPP */