#ifndef NTH_ROOT_HPP_CzklKY
#define NTH_ROOT_HPP_CzklKY

#include <cmath>
#include <stdexcept>

namespace Math
{
    template <typename T, typename = std::enable_if_t<std::is_floating_point<T>::value>>
    class NthRootCalculator
    {
    public:
        static T calculate(T base, T n, T tolerance = static_cast<T>(0.0001))
        {
            validateInput(base, n);
            T initialGuess = base / n;
            T root = refineEstimate(base, n, initialGuess, tolerance);
            return root;
        }

    private:
        static void validateInput(T base, T n)
        {
            if (n <= 0) {
                throw std::invalid_argument("n must be greater than 0.");
            }
            if (base < 0 && static_cast<int>(n) % 2 == 0) {
                throw std::invalid_argument("Cannot calculate the even root of a negative number.");
            }
        }

        static T refineEstimate(T base, T n, T guess, T tolerance)
        {
            T newEstimate = (1 / n) * ((n - 1) * guess + base / std::pow(guess, n - 1));
            while (std::abs(newEstimate - guess) > tolerance) {
                guess = newEstimate;
                newEstimate = (1 / n) * ((n - 1) * guess + base / std::pow(guess, n - 1));
            }
            return newEstimate;
        }
    };
} // namespace Math

#endif /* end of include guard :  NTH_ROOT_HPP_CzklKY */
