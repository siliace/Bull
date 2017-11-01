#include <Bull/Core/Exception/OutOfRange.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    RangeCheck::RangeCheck(std::size_t max) :
        m_max(max)
    {
        /// Nothing
    }

    RangeCheck::RangeCheck(std::size_t index, std::size_t max) :
        RangeCheck(max)
    {
        apply(index);
    }

    RangeCheck& RangeCheck::apply(std::size_t index)
    {
        if(index >= m_max)
        {
            throw OutOfRange("std::size_t out of range", index, 0, m_max - 1);
        }

        return (*this);
    }
}