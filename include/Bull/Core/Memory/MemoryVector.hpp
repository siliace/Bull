#ifndef BULL_CORE_MEMORY_ARRAY_HPP
#define BULL_CORE_MEMORY_ARRAY_HPP

#include <cstring>
#include <vector>

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    template <typename T>
    class MemoryVector : public AbstractBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        MemoryVector() = default;

        /*! \brief Constructor
         *
         * \param size The size of the Array
         *
         */
        explicit MemoryVector(std::size_t size) :
            MemoryVector<T>(size, T())
        {
            /// nothing
        }

        /*! \brief Constructor
         *
         * \param size  The size of the Array
         * \param value The value to the Array
         *
         */
        MemoryVector(std::size_t size, T value) :
            m_array(size, value)
        {
            /// nothing
        }

        /*! \brief Create the Array
         *
         * \param capacity The capacity of the Array to create
         *
         * \return True if the Array was created successfully
         *
         */
        bool create(std::size_t capacity) override
        {
            if(isEmpty())
            {
                m_array.resize(capacity);

                return true;
            }

            return false;
        }

        /*! \brief Fill the buffer
         *
         * \param data   Data to insert in the Array
         * \param size   The length of data
         * \param offset The offset of the data in the Array
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0) override
        {
            if(data && size)
            {
                if(getCapacity() < size + offset)
                {
                    resize(size + offset);
                }

                std::memcpy(&m_array[offset], data, size);

                return true;
            }

            return false;
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        T& at(std::size_t index)
        {
            RangeCheck(index, getCapacity());

            return m_array[index];
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        const T& at(std::size_t index) const
        {
            RangeCheck(index, getCapacity());

            return m_array[index];
        }

        /*! \brief Resize the Array
         *
         * \param size The size
         *
         */
        void resize(std::size_t size)
        {
            m_array.resize(size);
        }

        /*! \brief Clear the Array
         *
         */
        void clear() override
        {
            m_array.clear();
        }

        /*! \brief Tell whether the Array is empty
         *
         * \return True if the Array is empty
         *
         */
        bool isEmpty() const
        {
            return m_array.empty();
        }

        /*! \brief Get a pointer to the Array
         *
         * \return The pointer
         *
         */
        const T* getBuffer() const
        {
            return m_array.data();
        }

        /*! \brief Get the capacity of the Array
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const override
        {
            return m_array.size();
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        T& operator[](std::size_t index)
        {
            return at(index);
        }

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        const T& operator[](std::size_t index) const
        {
            return at(index);
        }

    private:

        std::vector<T> m_array;
    };
}

#endif // BULL_CORE_MEMORY_ARRAY_HPP
