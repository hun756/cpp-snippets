#ifndef ALGORITHM_RGB_TO_HEX_HPP
#define ALGORITHM_RGB_TO_HEX_HPP

#include <string>
#include <sstream>

namespace Algorithm
{
    std::string rgbToHex(uint8_t r, uint8_t g, uint8_t b)
    {
        std::stringstream ss;
        ss << '#'; 
        ss << std::hex << (r << 16 | g << 8 | b);
        return ss.str();
    }

} // namespace Algorithm

#endif /* end of include guard :  ALGORITHM_RGB_TO_HEX_HPP */
