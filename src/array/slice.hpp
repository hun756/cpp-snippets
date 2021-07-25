#ifndef ARRAY_SLICE_HPP
#define ARRAY_SLICE_HPP


#include <vector>

namespace Array
{
    template<typename T>
    static std::vector<T> slice(std::vector<T>& vec, size_t first, size_t second) 
    {
        return std::vector<T>(vec.begin() + first, vec.begin() + second);
    }


    //> Overoading
    template<typename T>
    static std::vector<T> slice(std::vector<T>& vec, size_t num) 
    {
        return slice(vec, num, vec.size());
    }
    
} // namespace Array


#endif /* end of include guard :  ARRAY_SLICE_HPP */
