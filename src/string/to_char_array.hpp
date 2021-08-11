#ifndef STRIN_TO_CHAR_ARRAY_HPP
#define STRIN_TO_CHAR_ARRAY_HPP

#include <memory>
#include <string>

namespace String
{
    std::unique_ptr<char[]> toCharArray(std::string str)
    {
        std::unique_ptr<char[]> chArr(new char[str.length()]);;

        strcpy(chArr.get(), str.c_str());

        return chArr;
    }
} // namespace String



#endif /* end of include guard :  STRIN_TO_CHAR_ARRAY_HPP */
