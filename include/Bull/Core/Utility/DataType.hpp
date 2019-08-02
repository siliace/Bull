#ifndef BULL_CORE_UTILITY_DATATYPE_HPP
#define BULL_CORE_UTILITY_DATATYPE_HPP

#include <numeric>

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API DataType
    {
    public:

        static const DataType Byte;
        static const DataType UnsignedByte;
        static const DataType Short;
        static const DataType UnsignedShort;
        static const DataType Int;
        static const DataType UnsignedInt;
        static const DataType Float;
        static const DataType Double;

        /*! \brief Create a DataType from a concrete type
         *
         * \tparam T The type
         * \return The DataType of T
         *
         */
        template <typename T>
        static DataType of()
        {
            return {
                    sizeof(T),
                    std::is_unsigned<T>::value,
                    std::is_floating_point<T>::value
            };
        }

    public:

        /*! \brief
         *
         * \return
         *
         */
        size_t getSize() const;

        /*! \brief
         *
         * \return
         *
         */
        bool isUnsigned() const;

        /*! \brief
         *
         * \return
         *
         */
        bool isFloatingPoint() const;

        /*! \brief
         *
         * \param rhs
         *
         * \return
         *
         */
        bool operator==(const DataType& rhs) const;

        /*! \brief
         *
         * \param rhs
         *
         * \return
         *
         */
        bool operator!=(const DataType& rhs) const;

    private:

        /*! \brief Constructor
         *
         * \param size The size (in bytes of the data type)
         * \param isUnsigned True if the DataType is an unsigned type
         * \param isFloatingPoint True is the DataType is a floating point type
         *
         */
        DataType(size_t size, bool isUnsigned, bool isFloatingPoint);

    private:

        std::size_t m_size;
        bool        m_isUnsigned;
        bool        m_isFloatingPoint;
    };
}

#endif // BULL_CORE_UTILITY_DATATYPE_HPP
