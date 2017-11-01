#ifndef BULL_CORE_MEMORY_RANGECHECK_HPP
#define BULL_CORE_MEMORY_RANGECHECK_HPP

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API RangeCheck
    {
    public:

        /*! \brief Constructor
         *
         * \param max The max value of the index
         *
         */
        explicit RangeCheck(std::size_t max);

        /*! \brief Constructor
         *
         * \param index The index
         * \param max   The max value of the index
         *
         */
        RangeCheck(std::size_t index, std::size_t max);

        /*! \brief Perform range check
         *
         * \param index The index to test
         *
         * \return This
         *
         */
        RangeCheck& apply(std::size_t index);

    private:

        std::size_t m_max;
    };
}

#endif // BULL_CORE_MEMORY_RANGECHECK_HPP
