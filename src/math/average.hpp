#ifndef MATH_AVERAGE_HPP
#define MATH_AVERAGE_HPP

#include <cassert>
#include <numeric>

namespace Math
{
    template <class FwIterator>
    auto average(FwIterator _first, FwIterator _end)
    {
        assert(_first != _end);

        return std::accumulate(_first, _end, 0.0) 
                / std::distance(_first, _end);
    }
} // namespace Math


#endif /* end of include guard :  MATH_AVERAGE_HPP */