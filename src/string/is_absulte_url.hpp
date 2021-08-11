#ifndef STRING_IS_ABSOLUTE_HPP
#define STRING_IS_ABSOLUTE_HPP

#include <string>

namespace String
{
    static bool absolute(std::string& path)
    {
        return path.find("://") != std::string::npos 
            || path.find("//") == 0;
    }
} // namespace String


#endif /* end of include guard :  STRING_IS_ABSOLUTE_HPP */
