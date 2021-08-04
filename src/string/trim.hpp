#ifndef STRING_TRIM_HPP
#define STRING_TRIM_HPP

#include <string>

namespace String
{
    static std::string trimStart(std::string source, const std::string &trimChars = " \t\n\r\v\f")
    {
        return source.erase(0, source.find_first_not_of(trimChars));
    }

    static std::string trimEnd(std::string source, const std::string &trimChars = " \t\n\r\v\f")
    {
        return source.erase(source.find_last_not_of(trimChars) + 1);
    }

    static std::string trim(std::string source, const std::string &trimChars = " \t\n\r\v\f")
    {
        return trimStart(trimEnd(source, trimChars), trimChars);
    }
}

#endif /* end of include guard :  STRING_TRIM_HPP */
