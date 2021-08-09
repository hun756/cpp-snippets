#ifndef ARRAY_FILTER_HPP
#define ARRAY_FILTER_HPP

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

namespace Array
{
    template <typename T>
    std::vector<T> filter(std::vector<T>& arr, std::function<bool(const T&)> Fn)
    {
        std::vector<T> res;
        std::copy_if(arr.begin(), arr.end(), std::back_inserter(res), Fn);
        return res;        
    }
} // namespace Array


#endif /* end of include guard :  ARRAY_FILTER_HPP */