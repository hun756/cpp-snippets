#ifndef MATH_RANDOM_HEX_HPP
#define MATH_RANDOM_HEX_HPP

#include <string>
#include <sstream>
#include <random>

namespace Math
{
    static std::string randomHexColor()
    {
        static const std::string chArr = "1234567890abcdef";

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, 15);

        std::stringstream ss;
        ss << '#';
        for (size_t i = 0; i < 6; i++)
            ss << chArr[(dist(gen))];
         
        return ss.str();
    }
} // namespace Math


#endif /* end of include guard :  MATH_RANDOM_HEX_HPP */
