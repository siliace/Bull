#include <Bull/Core/Exception/InvalidParameter.hpp>
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
        Expect(index < m_max, Throw(InvalidParameter, "Index out of range, expected in range [0, " + std::to_string(index) + "["));

        return (*this);
    }
}