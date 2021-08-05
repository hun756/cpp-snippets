#ifndef ALGORITHM_UNION_HPP
#define ALGORITHM_UNION_HPP

#include <vector>
#include <set>

namespace Algroithm
{
    template<typename T>
    static std::vector<T> _union(std::vector<T>& vec1, std::vector<T>& vec2) {
        std::set<T> _unique;

        for (auto &&var : vec1)
            _unique.insert(var);

        for (auto &&var : vec2)
            _unique.insert(var);
        
        return {_unique.begin(), _unique.end()};
    }

} // namespace Algroithm

#endif /* end of include guard :  ALGORITHM_UNION_HPP */