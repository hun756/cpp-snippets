#ifndef ALFORITHM_DISTANCE_HPP
#define ALFORITHM_DISTANCE_HPP

#include <cmath>

namespace Algorithm 
{
    static double distance(double x0, double y0, double x1, double y1)
    {
        return std::hypot(x1 - x0, y1 - y0);    
    }
} // namespace Algorıthm


#endif /* end of include guard :  ALFORITHM_DISTANCE_HPP */