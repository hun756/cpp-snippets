#ifndef ARRAY_CONTAINS_HPP
#define ARRAY_CONTAINS_HPP

#include <algorithm>

namespace Array
{
    template <typename T, typename U>
    static bool contains(T arr, U findVal)
    {
        return std::find(arr.begin(), arr.end(), findVal) != arr.end();
    }
} // namespace Array

#endif /* end of include guard :  ARRAY_CONTAINS_HPP */