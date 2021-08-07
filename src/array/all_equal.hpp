#ifndef ARRAY_ALL_EQUAL_HPP
#define ARRAY_ALL_EQUAL_HPP

#include <vector>

namespace Array
{
    template<typename T>
    static bool allEqual(std::vector<T>& vec)
    {
        for (size_t i = 1; i < vec.size(); ++i)
            if(vec[i] != vec[0])
                return false;

        return true;
    }
} // namespace Array


#endif /* end of include guard :  ARRAY_ALL_EQUAL_HPP */
