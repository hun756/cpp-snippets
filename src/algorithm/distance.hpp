#ifndef ALFORITHM_DISTANCE_HPP_cQUhGm
#define ALFORITHM_DISTANCE_HPP_cQUhGm

#include <cmath>
#include <utility>
#include <tuple>

namespace Algorithm 
{
    template<typename T>
    class Point 
    {
    public:
        T x, y;

        Point(T x, T y) : x(x), y(y) {}

        template<typename U>
        double distanceTo(const Point<U>& other) const 
        {
            return std::hypot(other.x - x, other.y - y);
        }
    };

    template<typename T, typename U>
    double distance(const Point<T>& p1, const Point<U>& p2) 
    {
        return p1.distanceTo(p2);
    }

    template<typename T, typename U>
    double distance(const std::pair<T, T>& p1, const std::pair<U, U>& p2) 
    {
        return std::hypot(p2.first - p1.first, p2.second - p1.second);
    }

    template<typename T, typename U>
    double distance(const std::tuple<T, T>& p1, const std::tuple<U, U>& p2) 
    {
        return std::hypot(std::get<0>(p2) - std::get<0>(p1), std::get<1>(p2) - std::get<1>(p1));
    }

} // namespace Algorıthm


#endif /* end of include guard :  ALFORITHM_DISTANCE_HPP_cQUhGm */