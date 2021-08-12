#ifndef NTH_ROOT_HPP
#define NTH_ROOT_HPP

#include <cmath>

namespace Math
{
    static long int nthRoot(double x, double y)
    {
        return pow(x, 1.0 / y);
    }
} // namespace MAth


#endif /* end of include guard :  NTH_ROOT_HPP */