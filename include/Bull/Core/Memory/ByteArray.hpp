#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <vector>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    class BULL_CORE_API ByteArray : public AbstractBuffer
    {
        using Container = std::vector<Uint8>;

    public:

        /*! \brief Default constructor
         *
         */
        ByteArray() = default;

        /*! \brief Constructor
         *
         * \param size The size of the array
         *
         */
        explicit ByteArray(Index size);

        /*! \brief Constructor
         *
         * \param size  The size of the array
         * \param value The value to the array
         *
         */
        ByteArray(Index size, Uint8 value);

        /*! \brief Create the ByteArray
         *
         * \param capacity The capacity of the ByteArray to create
         *
         * \return True if the ByteArray was created successfully
         *
         */
        bool create(Index capacity) override;

        /*! \brief Fill the buffer
         *
         * \param data   Data to insert in the Buffer
         * \param size   The length of data
         * \param offset The offset of the data in the Buffer
         *
         * \return True if the buffer was filled successfully
         *
         */
        bool fill(const void* data, Index size, Index offset = 0) override;

        /*! \brief Access operator
         *
         * \param index The byte to get from the ByteArray
         *
         * \return The byte
         *
         */
        Uint8& at(Index index);

        /*! \brief Access operator
         *
         * \param index The byte to get from the ByteArray
         *
         * \return The byte
         *
         */
        const Uint8& at(Index index) const;

        /*! \brief Resize the ByteArray
         *
         * \param size The size
         *
         * \return This
         *
         */
        ByteArray& resize(Index size);

        /*! \brief Flush the Buffer
         *
         */
        void flush() override;

        /*! \brief Destroy the Buffer
         *
         */
        void destroy() override;

        /*! \brief Tell whether the ByteArray is empty
         *
         * \return True if the ByteArray is empty
         *
         */
        bool isEmpty() const;

        /*! \brief Get a pointer to the array
         *
         * \return The pointer
         *
         */
        const Uint8* getBuffer() const;

        /*! \brief Get the capacity of the ByteArray
         *
         * \return The capacity
         *
         */
        Index getCapacity() const override;

        /*! \brief Compare two ByteArray
         *
         * \param right The ByteArray to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const ByteArray& right) const;

        /*! \brief Compare two ByteArray
         *
         * \param right The ByteArray to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const ByteArray& right) const;

        /*! \brief Add two ByteArray
         *
         * \param right The ByteArray to add to this
         *
         * \return This
         *
         */
        ByteArray& operator+=(const ByteArray& right);

        /*! \brief Add two ByteArray
         *
         * \param right The ByteArray to add to this
         *
         * \return The sum of this and right
         *
         */
        ByteArray operator+(const ByteArray& right) const;

        /*! \brief Access operator
         *
         * \param index The byte to get from the ByteArray
         *
         * \return The byte
         *
         */
        Uint8& operator[](Index index);

        /*! \brief Access operator
         *
         * \param index The byte to get from the ByteArray
         *
         * \return The byte
         *
         */
        const Uint8& operator[](Index index) const;

        /*! \brief Convert the byte array to a String
         *
         * \return The String
         *
         */
        String toString() const;

    private:

        Container m_array;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
