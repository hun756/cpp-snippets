#ifndef MATH_LOG_HPP
#define MATH_LOG_HPP

#include <cmath>

namespace Math
{
    double log(double a, double b)
    {
        return log2(b) / log2(a);
    }
} // namespace Math


#endif /* end of include guard :  MATH_LOG_HPP */