#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <Bull/Core/Memory/MemoryVector.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API ByteVector : public MemoryVector<Uint8>
    {
        /*! \brief Default constructor
         *
         */
        ByteVector() = default;

        /*! \brief Constructor
         *
         * \param size The size of the array
         *
         */
        explicit ByteVector(std::size_t size);

        /*! \brief Constructor
         *
         * \param size  The size of the array
         * \param value The value to the array
         *
         */
        ByteVector(std::size_t size, Uint8 value);

        /*! \brief Convert the byte array to a String
         *
         * \return The String
         *
         */
        String toString() const;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
