#ifndef BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP
#define BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP

#include <utility>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    struct BULL_CORE_API AbstractBuffer
    {
        /*! \brief Create the Buffer
         *
         * \param capacity The capacity of the Buffer to create
         *
         * \return True if the Buffer was created successfully
         *
         */
        virtual bool create(Index capacity) = 0;

        /*! \brief Fill the buffer
         *
         * \param data   Data to insert in the Buffer
         * \param size   The length of data
         * \param offset The offset of the data in the Buffer
         *
         * \return True if the buffer was filled successfully
         *
         */
        virtual bool fill(const void* data, Index size, Index offset) = 0;

        /*! \brief Flush the Buffer
         *
         */
        virtual void flush() = 0;

        /*! \brief Destroy the Buffer
         *
         */
        virtual void destroy() = 0;

        /*! \brief Get the capacity of the Buffer
         *
         * \return The size
         *
         */
        virtual Index getCapacity() const = 0;
    };
}

#endif // BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP
