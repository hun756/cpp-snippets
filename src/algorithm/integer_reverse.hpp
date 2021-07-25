#ifndef INTEGER_REVERSE_HPP
#define INTEGER_REVERSE_HPP

#include <sstream>
#include <string>
#include <algorithm>

namespace Integer
{
    template <typename T>
    static int reverse(int input)
    {
        std::stringstream ss;
        ss << x;
        std::string numberToStr = ss.str();

        std::reverse(numberToStr.begin(), numberToStr.end());

        int64_t num;

        if (numberToStr[numberToStr.size() - 1] == '-')
        {
            ss.str(numberToStr.substr(0, numberToStr.size() - 1));
            ss >> num;

            if (std::numeric_limits<int>::max() < num)
                return 0;

            return -1 * num;
        }

        ss.str(numberToStr);
        ss >> num;

        if (std::numeric_limits<int>::max() < num)
            return 0;

        return num;
    }
}

#endif /* end of include guard :  INTEGER_REVERSE_HPP */
