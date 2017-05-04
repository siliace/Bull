#ifndef BULL_BUFFER_HPP
#define BULL_BUFFER_HPP

#include <utility>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    struct BULL_CORE_API Buffer
    {
        /*! \brief Create the Buffer
         *
         * \param capacity The capacity of the Buffer to create
         *
         * \return True if the Buffer was created successfully
         *
         */
        virtual bool create(std::size_t capacity) = 0;

        /*! \brief Fill the buffer
         *
         * \param data    Data to insert in the Buffer
         * \param size    The length of data
         * \param offset  The offset of the data in the Buffer
         * \param discard True to flush the Buffer before fill it
         *
         * \return True if the buffer was filled successfully
         *
         */
        virtual bool fill(const void* data, std::size_t size, std::size_t offset = 0, bool discard = false) = 0;

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
        virtual std::size_t getCapacity() const = 0;
    };
}

#endif // BULL_BUFFER_HPP
