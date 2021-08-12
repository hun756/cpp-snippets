#ifndef MATH_RADS_TO_DEGREES_HPP
#define MATH_RADS_TO_DEGREES_HPP

namespace Math
{
    static constexpr long double PI = 3.14159265358979323846;

    static double radsToDegrees(double rad)
    {
        return (rad * 180) / Math::PI;
    }    
} // namespace Math


#endif /* end of include guard :  MATH_RADS_TO_DEGREES_HPP */