#include <Bull/Core/Exception/OutOfRange.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    RangeCheck::RangeCheck(Index max) :
        m_max(max)
    {
        /// Nothing
    }

    RangeCheck::RangeCheck(Index index, Index max) :
        RangeCheck(max)
    {
        apply(index);
    }

    RangeCheck& RangeCheck::apply(Index index)
    {
        if(index >= m_max)
        {
            throw OutOfRange("Index out of range", index, 0, m_max - 1);
        }

        return (*this);
    }
}