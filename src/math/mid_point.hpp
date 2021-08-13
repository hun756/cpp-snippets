#ifndef MATH_MID_POINT_HPP
#define MATH_MID_POINT_HPP

#include <array>

namespace Math
{
    template <typename T>
    std::array<double, 2> midPoint(std::array<T, 2> arr1, std::array<T, 2> arr2)
    {
        return {(arr1[0] + arr2[0]) / 2.0 , (arr1[1] + arr2[1]) / 2.0};
    }
} // namespace Math


#endif /* end of include guard :  MATH_MID_POINT_HPP */
