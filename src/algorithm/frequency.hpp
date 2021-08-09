#ifndef ALGORITHM_FREQUENCY_HPP
#define ALGORITHM_FREQUENCY_HPP

#include <unordered_map>

namespace Algorithm
{
    template <typename T>
    std::unordered_map<T, int> frequency(T val)
    {
        std::unordered_map<T, int> mp;
        for (auto&& var : val)
            mp[var]++;
    }
} // namespace Algorithm


#endif /* end of include guard :  ALGORITHM_FREQUENCY_HPP */