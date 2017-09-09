#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <vector>

#include <Bull/Core/Export.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/System/Integer.hpp>

namespace Bull
{
    class BULL_CORE_API ByteArray
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
        explicit ByteArray(std::size_t size);

        /*! \brief Constructor
         *
         * \param size  The size of the array
         * \param value The value to the array
         *
         */
        ByteArray(std::size_t size, Uint8 value);

        /*! \brief Resize the ByteArray
         *
         * \param size The size
         *
         * \return This
         *
         */
        ByteArray& resize(std::size_t size);

        /*! \brief Clear the array
         *
         * \param keepMemory True to delete the memory
         *
         * \return This
         *
         */
        ByteArray& clear(bool keepMemory = false);

        /*! \brief Tell whether the ByteArray is empty
         *
         * \return True if the ByteArray is empty
         *
         */
        bool isEmpty() const;

        /*! \brief Get the size of the ByteArray
         *
         * \return The size
         *
         */
        std::size_t getSize() const;

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
        Uint8& operator[](std::size_t index);

        /*! \brief Access operator
         *
         * \param index The byte to get from the ByteArray
         *
         * \return The byte
         *
         */
        const Uint8& operator[](std::size_t index) const;

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
