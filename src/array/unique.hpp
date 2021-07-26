#ifndef ARRAY_UNIQUE_HPP
#define ARRAY_UNIQUE_HPP

#include <set>
#include <vector>

namespace Array
{
    template <typename T>
    static void unique(std::vector<T> &vec)
    {
        std::set<int> s(vec.begin(), vec.end());
        vec.assign(s.begin(), s.end());
    }
}

#endif /* end of include guard :  ARRAY_UNIQUE_HPP */
