#ifndef MATH_IS_EVEN_HPP
#define MATH_IS_EVEN_HPP


namespace Math
{
    static bool isEven(int num)
    {
        return ((num & 0x01) == 0);
    }
} // namespace AM



#endif /* end of include guard :  MATH_IS_EVEN_HPP */
