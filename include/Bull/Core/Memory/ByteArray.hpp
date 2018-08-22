#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <vector>

#include <Bull/Core/Memory/AbstractBuffer.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API ByteArray : public AbstractBuffer
    {
    public:

        /*! \brief Create a ByteArray from a String
         *
         * \param string The String
         *
         * \return The created ByteArray
         *
         */
        static ByteArray fromString(const String& string);

        /*! \brief Create a ByteArray from a copy of a memory area
         *
         * \param data   The memory area
         * \param length The length of the memory area
         *
         * \return The created ByteArray
         *
         * \throw InvalidParameter
         *
         */
        static ByteArray memoryCopy(const void* data, std::size_t length);

    public:

        /*! \brief Default constructor
         *
         */
        ByteArray() = default;

        /*! \brief Constructor
         *
         * \param length The length of the ByteArray
         *
         */
        explicit ByteArray(std::size_t length);

        /*! \brief Create the ByteArray
         *
         * \param capacity The capacity of the ByteArray to create
         *
         */
        void create(std::size_t capacity) override;

        /*! \brief Fill the ByteArray
         *
         * \param data   Data to insert in the ByteArray
         * \param size   The length of data
         * \param offset The offset of the data in the ByteArray
         *
         */
        void fill(const void* data, std::size_t size, std::size_t offset) override;

        /*! \brief Change the size of the ByteArray
         *
         *  If the new size is lower than the current size, lasts elements are discarded
         *
         * \param length The new size
         */
        void resize(std::size_t length);

        /*! \brief Clear the ByteArray
         *
         */
        void clear() override;

        /*! \brief Get the capacity of the ByteArray
         *
         * \return The capacity
         *
         */
        size_t getCapacity() const override;

        /*! \brief Get a pointer to the underlying buffer of the ByteArray
         *
         * \return The pointer
         *
         */
        const Uint8* getBuffer() const;

        /*! \brief Convert the ByteArray to a String
         *
         * \return The String
         *
         */
        String toString() const;

        /*! \brief Access operator
         *
         * \param index The index of the element to access
         *
         * \return A reference to the element
         *
         * \throw InvalidParameter
         *
         */
        Uint8& operator[](std::size_t index);

        /*! \brief Access operator
         *
         * \param index The index of the element to access
         *
         * \return A reference to the element
         *
         * \throw InvalidParameter
         *
         */
        const Uint8& operator[](std::size_t index) const;

    private:

        std::vector<Uint8> m_array;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
