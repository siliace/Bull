#ifndef BULL_CORE_MEMORY_BYTEARRAY_HPP
#define BULL_CORE_MEMORY_BYTEARRAY_HPP

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/ArrayList.hpp>

namespace Bull
{
    struct BULL_CORE_API ByteArray : public ArrayList<Uint8>
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
        explicit ByteArray(std::size_t size);

        /*! \brief Constructor
         *
         * \param size  The size of the array
         * \param value The value to the array
         *
         */
        ByteArray(std::size_t size, Uint8 value);

        /*! \brief Convert the byte array to a String
         *
         * \return The String
         *
         */
        String toString() const;
    };
}

#endif // BULL_CORE_MEMORY_BYTEARRAY_HPP
