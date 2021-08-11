#ifndef STRING_IS_UPPER_CASE_HPP
#define STRING_IS_UPPER_CASE_HPP

#include <string>
#include <algorithm>

namespace String
{
    static bool isUpperCase(std::string& str)
    {
        std::string oldText = str;
        std::for_each(str.begin(), str.end(), [](char& c){ c = ::toupper(c); });

        return str == oldText;
    }
} ///< namespace String

#endif /* end of include guard :  STRING_IS_UPPER_CASE_HPP */