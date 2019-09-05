#ifndef BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP
#define BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API AbstractBuffer
    {
        /** \brief Create the Buffer
         *
         * \param capacity The capacity of the Buffer to create
         *
         */
        virtual void create(std::size_t capacity) = 0;

        /** \brief Fill the buffer
         *
         * \param data   Data to insert in the Buffer
         * \param size   The length of data
         * \param offset The offset of the data in the Buffer
         *
         */
        virtual void fill(const void* data, std::size_t size, std::size_t offset) = 0;

        /** \brief Clear the Buffer
         *
         */
        virtual void clear() = 0;

        /** \brief Get the capacity of the Buffer
         *
         * \return The capacity
         *
         */
        virtual std::size_t getCapacity() const = 0;
    };
}

#endif // BULL_CORE_MEMORY_ABSTRACTBUFFER_HPP
