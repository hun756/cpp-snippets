#ifndef MATH_MAX_ELEMENT_HPP
#define MATH_MAX_ELEMENT_HPP

#include <cassert>

namespace Math
{
    template<class FwIterator, class Compare>
    FwIterator maxElement(FwIterator _begin, FwIterator _end, Compare cmp)
    {
        assert(_begin != _end);

        FwIterator maxElem = _begin++;

        while (_begin != _end)
        {
            if (cmp(*maxElem, *_begin))
                maxElem = _begin;
            ++_begin;
        }
        return maxElem;
    }    

    template<class FwIterator>
    FwIterator maxElement(FwIterator _begin, FwIterator _end) 
    {
        return maxElement(
                _begin, 
                _end, 
                [](auto a, auto b) { 
                    return a  < b;
                }
        );
    }

} // namespace Math


#endif /* end of include guard :  MATH_MAX_ELEMENT_HPP */