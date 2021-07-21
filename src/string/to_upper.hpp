#ifndef TO_UPPER_HPP
#define TO_UPPER_HPP

#include <algorithm>
#include <string>

namespace String
{
    static std::string toUpper(std::string& str)
    {
        std::transform(
            str.begin(),
            str.end(),
            str.begin(),
            [](unsigned char c)
            {
                return ::toupper(c);
            }
        );

        return str;
    }
}

#endif /* end of include guard : TO_UPPER_HPP */