#ifndef MATH_IS_POWER_OF_TEN_HPP
#define MATH_IS_POWER_OF_TEN_HPP

#include <sstream>
#include <string>

namespace Math
{

    template <typename T>
    static bool isPowerOfTen(T num)
    {
        std::stringstream ss;
        std::string numVal;

        ss << num;
        ss >> numVal;

        if(numVal[0] != '1')
            return false;

        for (size_t i = 1; i < numVal.length(); i++)
            if (numVal[i] != '0')
                return false;

        return true;
    }
} // namespace Math

#endif /* end of include guard :  MATH_IS_POWER_OF_TEN_HPP */
