#ifndef BULL_CORE_MEMORY_RANGECHECK_HPP
#define BULL_CORE_MEMORY_RANGECHECK_HPP

#include <Bull/Core/Export.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    class BULL_CORE_API RangeCheck
    {
    public:

        /*! \brief Constructor
         *
         * \param index The index
         * \param max   The max value of the index
         *
         */
        explicit RangeCheck(Index max);

        /*! \brief Constructor
         *
         * \param index The index
         * \param max   The max value of the index
         *
         */
        RangeCheck(Index index, Index max);

        /*! \brief Perform range check
         *
         * \param index The index to test
         *
         * \return This
         *
         */
        RangeCheck& apply(Index index);

    private:

        Index m_max;
    };
}

#endif // BULL_CORE_MEMORY_RANGECHECK_HPP
