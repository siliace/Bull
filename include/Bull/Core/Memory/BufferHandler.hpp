#ifndef BULL_BUFFERHANDLER_HPP
#define BULL_BUFFERHANDLER_HPP

#include <cstring>
#include <memory>

#include <Bull/Core/Pattern/NonCopyable.hpp>

namespace Bull
{
    template <typename T>
    class BufferHandler : public NonCopyable
    {
    public:

        /*! \brief Default constructor
         *
         */
        BufferHandler();

        /*! \brief Constructor
         *
         * \param capacity The capacity of the buffer
         *
         */
        BufferHandler(std::size_t capacity);

        /*! \brief Fill the buffer with a value
         *
         * \param value The value to use the fill the buffer
         *
         */
        void memset(T value);

        /*! \brief Copy a memory area into the buffer
         *
         * \param buffer Data to copy into the buffer
         * \param size   The size of data to copy
         * \param offset The offset of data into the buffer
         *
         */
        void memcpy(const T* data, std::size_t size, std::size_t offset = 0);

        /*! \brief Get the value from the buffer
         *
         * \param index The index of the value to get
         *
         * \return The indexth value of the buffer
         *
         * \throw std::out_of_range
         *
         */
        T& at(std::size_t index);

        /*! \brief Get the value from the buffer
         *
         * \param index The index of the value to get
         *
         * \return The indexth value of the buffer
         *
         * \throw std::out_of_range
         *
         */
        const T& at(std::size_t index) const;

        /*! \brief Get the capacity of the Buffer
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity();

    protected:

        /*! \brief Change the capacity of the buffer
         *
         * \param capacity The new capacity of the buffer
         *
         */
        void realloc(std::size_t capacity);

    private:

        std::unique_ptr<T[]> m_data;
        std::size_t          m_capacity;
    };
}

#include <Bull/Core/Memory/BufferHandler.inl>

#endif // BULL_BUFFERHANDLER_HPP
