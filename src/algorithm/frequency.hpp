#ifndef ALGORITHM_FREQUENCY_HPP
#define ALGORITHM_FREQUENCY_HPP

#include <unordered_map>

namespace Algorithm
{
    template <typename T, typename U>
    std::unordered_map<T, size_t> frequency(U val)
    {
        std::unordered_map<T, size_t> mp;
        for (auto&& var : val)
            mp[var]++;

        return mp;
    }
} // namespace Algorithm


#endif /* end of include guard :  ALGORITHM_FREQUENCY_HPP */