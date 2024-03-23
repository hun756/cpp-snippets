#ifndef ALGORITHM_RGB_TO_HEX_HPP
#define ALGORITHM_RGB_TO_HEX_HPP

#include <iomanip>
#include <string>
#include <sstream>

namespace Algorithm
{
    inline std::string rgbToHex(uint8_t r, uint8_t g, uint8_t b)
    {
        std::ostringstream ss;
        ss << '#' 
           << std::uppercase
           << std::hex
           << std::setfill('0')
           << std::setw(2) << static_cast<int>(r)
           << std::setw(2) << static_cast<int>(g)
           << std::setw(2) << static_cast<int>(b);
        return ss.str();
    }

} // namespace Algorithm

#endif /* end of include guard :  ALGORITHM_RGB_TO_HEX_HPP */
