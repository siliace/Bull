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

        void create(std::size_t capacity) override;

        void fill(const void* data, std::size_t size, std::size_t offset) override;

        void resize(std::size_t length);

        void clear() override;

        size_t getCapacity() const override;

        const Uint8* getBuffer() const;

        String toString() const;

        Uint8& operator[](std::size_t index);

        const Uint8& operator[](std::size_t index) const;

    private:

        std::vector<Uint8> m_array;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
