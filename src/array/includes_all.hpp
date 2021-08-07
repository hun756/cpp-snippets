#ifndef ARRAY_INCLUDES_ANY_HPP
#define ARRAY_INCLUDES_ANY_HPP

#include <vector>

namespace Array
{
    template <typename T>
    static bool includesAll(std::vector<T>& nums, std::vector<T>& incs)
    {
        for (auto &&_incVars : incs)
            if (std::find(nums.begin(), nums.end(), _incVars) == nums.end())
                return false;

        return true;
    }
} // namespace Array


#endif /* end of include guard :  ARRAY_INCLUDES_ANY_HPP */
