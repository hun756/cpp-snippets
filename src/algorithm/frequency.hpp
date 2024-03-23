#ifndef ALGORITHM_FREQUENCY_HPP_lPJDBv
#define ALGORITHM_FREQUENCY_HPP_lPJDBv

#include <unordered_map>

namespace Algorithm 
{
    template <typename T> struct is_pair : std::false_type {};

    template <typename T, typename U>
    struct is_pair<std::pair<T, U>> : std::true_type {};

    template <typename T, typename Container>
    auto frequency(const Container &values) ->
        typename std::enable_if<is_pair<typename Container::value_type>::value,
                                std::unordered_map<T, size_t>>::type 
    {
        std::unordered_map<T, size_t> frequencies;
        for (const auto &element : values)
        {
            ++frequencies[element.first];
        }
        return frequencies;
    }

    template <typename T, typename Container>
    auto frequency(const Container &values) ->
        typename std::enable_if<!is_pair<typename Container::value_type>::value,
                                std::unordered_map<T, size_t>>::type 
    {
        std::unordered_map<T, size_t> frequencies;
        for (const auto &element : values)
        {
            ++frequencies[element];
        }
        return frequencies;
    }
} // namespace Algorithm

#endif /* end of include guard :  ALGORITHM_FREQUENCY_HPP_lPJDBv */
