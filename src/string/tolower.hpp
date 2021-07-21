#ifndef TO_LOWER_HPP
#define TO_LOWER_HPP

#include <algorithm>
#include <string>

namespace String
{
    static std::string toLower(std::string& str)
    {
        std::transform(
            str.begin(),
            str.end(),
            str.begin(),
            [](unsigned char c)
            {
                return ::tolower(c);
            }
        );

        return str;
    }
}

#endif /* end of include guard : TO_LOWER_HPP */