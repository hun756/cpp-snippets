#ifndef ALGORITHM_MEDIAN_HPP
#define ALGORITHM_MEDIAN_HPP

#include <vector>
#include <algorithm>
#include <cmath>

namespace Algorithm
{
    static double median(std::vector<int> &vec)
    {
        if(vec.empty()) 
            throw std::domain_error("[ Algorithm::Median(vec: std::vector<int>) > 'vec' is empty!!]");
        const auto mid = std::floor(vec.size() / 2);

        std::sort(vec.begin(), vec.end());

        return vec.size() % 2 != 0
                   ? vec[mid]
                   : (vec[mid - 1] + vec[mid]) / 2.0;
    }
}

#endif /* end of include guard :  ALGORITHM_MEDIAN_HPP */
