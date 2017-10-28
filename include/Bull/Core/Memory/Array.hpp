#ifndef BULL_CORE_MEMORY_ARRAY_HPP
#define BULL_CORE_MEMORY_ARRAY_HPP

#include <vector>

#include <Bull/Core/Memory/AbstractBuffer.hpp>

namespace Bull
{
    template <typename T>
    class Array : public AbstractBuffer
    {
    public:

        /*! \brief Default constructor
         *
         */
        Array() = default;

        /*! \brief Constructor
         *
         * \param size The size of the Array
         *
         */
        explicit Array(Index size);

        /*! \brief Constructor
         *
         * \param size  The size of the Array
         * \param value The value to the Array
         *
         */
        Array(Index size, T value);

        /*! \brief Create the Array
         *
         * \param capacity The capacity of the Array to create
         *
         * \return True if the Array was created successfully
         *
         */
        bool create(Index capacity) override;

        /*! \brief Fill the buffer
         *
         * \param data   Data to insert in the Array
         * \param size   The length of data
         * \param offset The offset of the data in the Array
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, Index size, Index offset = 0) override;

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        T& at(Index index);

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        const T& at(Index index) const;

        /*! \brief Resize the Array
         *
         * \param size The size
         *
         */
        void resize(Index size);

        /*! \brief Flush the Array
         *
         */
        void flush() override;

        /*! \brief Destroy the Array
         *
         */
        void destroy() override;

        /*! \brief Tell whether the Array is empty
         *
         * \return True if the Array is empty
         *
         */
        bool isEmpty() const;

        /*! \brief Get a pointer to the Array
         *
         * \return The pointer
         *
         */
        const T* getBuffer() const;

        /*! \brief Get the capacity of the Array
         *
         * \return The capacity
         *
         */
        Index getCapacity() const override;

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        T& operator[](Index index);

        /*! \brief Access operator
         *
         * \param index The value to get from the Array
         *
         * \return The value
         *
         */
        const T& operator[](Index index) const;

    private:

        std::vector<T> m_array;
    };
}

#include <Bull/Core/Memory/Array.inl>

#endif // BULL_CORE_MEMORY_ARRAY_HPP
