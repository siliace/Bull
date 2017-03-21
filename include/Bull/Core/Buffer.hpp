#ifndef BULL_BUFFER_HPP
#define BULL_BUFFER_HPP

#include <Bull/Core/System/Export.hpp>

namespace Bull
{
    class BULL_API Buffer
    {
    public:

        /*! \brief Create the Buffer
         *
         * @param size The size of the Buffer to create
         *
         * @return True if the Buffer was created successfully
         *
         */
        virtual bool create(std::size_t size) = 0;

        /*! \brief Fill the buffer
         *
         * @param data    Data to insert in the Buffer
         * @param size    The length of data
         * @param offset  The offset of the data in the Buffer
         * @param discard True to flush the Buffer before fill it
         *
         * @return True if the buffer was filled successfully
         *
         */
        virtual bool fill(const void* data, std::size_t size, std::size_t offset = 0, bool discard = false) = 0;

        /*! \brief Map data to a pointer
         *
         * @return A pointer to data
         *
         */
        virtual void* map() = 0;

        /*! \brief Map data to a pointer
         *
         * @return A pointer to data
         *
         */
        virtual const void* map() const = 0;

        /*! \brief Flush the Buffer
         *
         */
        virtual void flush() = 0;

        /*! \brief Destroy the Buffer
         *
         */
        virtual void destroy() = 0;

        /*! \brief Get the size of the Buffer
         *
         * @return The size
         *
         */
        virtual std::size_t getSize() const = 0;
    };
}

#endif // BULL_BUFFER_HPP
