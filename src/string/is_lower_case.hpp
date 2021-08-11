#ifndef STRING_IS_LOWER_CASE_HPP
#define STRING_IS_LOWER_CASE_HPP

#include <string>
#include <algorithm>

namespace String
{
    static bool isLowerCase(std::string& str)
    {
        std::string oldText = str;
        std::for_each(str.begin(), str.end(), [](char& c){ c = ::tolower(c); });

        return str == oldText;
    }
} ///< namespace String

#endif /* end of include guard :  STRING_IS_LOWER_CASE_HPP */