#ifndef STRING_IS_ALPHA_HPP
#define STRING_IS_ALPHA_HPP

#include <string>
#include <regex>

namespace String
{
    static bool isAlpha(std::string& str)
    {
        return std::regex_match(str, std::regex("([a-z]|[A-Z])+"));
    }
} // namespace String
    

#endif /* end of include guard :  STRING_IS_ALPHA_HPP */
