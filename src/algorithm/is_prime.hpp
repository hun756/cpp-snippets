#ifndef IS_PRIME_HPP
#define IS_PRIME_HPP

#include <cmath>

namespace Extra::Math
{
    static bool isPrime(size_t num)
    {
        const size_t boundary = static_cast<size_t>(sqrt(num));
        for (size_t i = 2; i <= boundary; ++i)
            if (num % i == 0)
                return false;

        return num >= 2;
    }
}

#endif /* end of include guard : IS_PRIME_HPP */