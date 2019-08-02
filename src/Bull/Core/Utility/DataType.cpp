#include <Bull/Core/Utility/DataType.hpp>
#include <tuple>

namespace Bull
{
    const DataType DataType::Byte = DataType::of<Int8>();
    const DataType DataType::UnsignedByte = DataType::of<Uint8>();
    const DataType DataType::Short = DataType::of<Int16>();
    const DataType DataType::UnsignedShort = DataType::of<Uint16>();
    const DataType DataType::Int = DataType::of<Int32>();
    const DataType DataType::UnsignedInt = DataType::of<Uint32>();
    const DataType DataType::Float = DataType::of<float>();
    const DataType DataType::Double = DataType::of<double>();

    size_t DataType::getSize() const
    {
        return m_size;
    }

    bool DataType::isUnsigned() const
    {
        return m_isUnsigned;
    }

    bool DataType::isFloatingPoint() const
    {
        return m_isFloatingPoint;
    }

    bool DataType::operator==(const DataType& rhs) const
    {
        return std::tie(m_size, m_isUnsigned, m_isFloatingPoint) == std::tie(rhs.m_size, rhs.m_isUnsigned, rhs.m_isFloatingPoint);
    }

    bool DataType::operator!=(const DataType& rhs) const
    {
        return std::tie(m_size, m_isUnsigned, m_isFloatingPoint) != std::tie(rhs.m_size, rhs.m_isUnsigned, rhs.m_isFloatingPoint);
    }

    DataType::DataType(size_t size, bool isUnsigned, bool isFloatingPoint) :
        m_size(size),
        m_isUnsigned(isUnsigned),
        m_isFloatingPoint(isFloatingPoint)
    {
        /// Nothing
    }
}