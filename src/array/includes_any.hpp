#ifndef ARRAY_INCLUDE_ANY_HPP
#define ARRAY_INCLUDE_ANY_HPP

#include <vector>
#include <algorithm>

namespace Array
{
    template <typename T>
    static bool includesAny(std::vector<T> &nums, std::vector<T> &incs)
    {
        for (auto &&_incVars : incs)
            if (std::find(nums.begin(), nums.end(), _incVars) != nums.end())
                return true;

        return false;
    }
} // namespace Array

#endif /* end of include guard :  ARRAY_INCLUDE_ANY_HPP */
