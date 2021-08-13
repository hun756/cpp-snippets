#ifndef MATH_PAIR_PROD_HPP
#define MATH_PAIR_PROD_HPP

#include <vector>
#include <unordered_map>

namespace Math
{
    template <typename T, typename U>
    std::unordered_map<T, U> pairProd(std::vector<T> v1, std::vector<U> v2)
    {
        std::unordered_map<T, U> mp;
        for (auto &&var1 : v1)
            for (auto &&var2 : v2)
                mp.insert(std::pair<T, U>({var1, var2}));

        return mp;
    }
} // namespace Math

#endif /* end of include guard :  MATH_PAIR_PROD_HPP */