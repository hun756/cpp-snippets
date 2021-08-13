#ifndef MATH_PRIME_FACTOR_HPP
#define MATH_PRIME_FACTOR_HPP

#include <vector>

namespace Math
{
    std::vector<int> primeFactors(int num)
    {
        std::vector<int> v;
        int f = 2;

        while (num > 1)
        {
            if (num % f == 0)
            {
                v.push_back(f);
                num /= f;
            }
            else
                ++f;
        }

        return v;
    }
} // namespace Math


#endif /* end of include guard :  MATH_PRIME_FACTOR_HPP */
