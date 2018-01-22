#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
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
            OutStringStream oss;

            Throw(InvalidParameter, "RangeCheck::apply", "Index out of range, expected in range [0, " + String::number(index) + "[");
        }

        return (*this);
    }
}