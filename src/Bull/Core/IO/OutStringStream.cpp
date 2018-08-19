#include <Bull/Core/Exception/UnsupportedOperation.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    OutStringStream::~OutStringStream() = default;

    std::size_t OutStringStream::write(const ByteArray& bytes)
    {
        m_content.append(bytes.toString());

        return bytes.getCapacity();
    }

    void OutStringStream::flush()
    {
        /// Nothing
    }

    void OutStringStream::clear()
    {
        m_content.clear();
    }

    const String& OutStringStream::toString() const
    {
        return m_content;
    }
}
