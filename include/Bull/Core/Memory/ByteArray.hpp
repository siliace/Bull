#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <Bull/Core/Memory/Array.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    struct BULL_CORE_API ByteArray : public Array<Uint8>
    {
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

        /*! \brief Convert the byte array to a String
         *
         * \return The String
         *
         */
        String toString() const;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
