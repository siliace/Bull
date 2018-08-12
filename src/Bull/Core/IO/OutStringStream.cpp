#include <Bull/Core/Exception/UnsupportedOperation.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>

namespace Bull
{
    OutStringStream::~OutStringStream() = default;

    void OutStringStream::clear()
    {
        m_content.clear();
    }

    std::size_t OutStringStream::write(const String& string)
    {
        std::size_t oldSize = m_content.getSize();

        m_content.append(string);

        return m_content.getSize() - oldSize;
    }

    std::size_t OutStringStream::write(const void* data, std::size_t size)
    {
        return write(String(reinterpret_cast<const char*>(data), size));
    }

    const String& OutStringStream::toString() const
    {
        return m_content;
    }

    OutStringStream& OutStringStream::operator<<(int right)
    {
        write(StringUtils::number(right));

        return (*this);
    }

    OutStringStream& OutStringStream::operator<<(bool right)
    {
        write(StringUtils::boolean(right));

        return (*this);
    }

    OutStringStream& OutStringStream::operator<<(char right)
    {
        write(String(right));

        return (*this);
    }

    OutStringStream& OutStringStream::operator<<(const char* right)
    {
        write(String(right));

        return (*this);
    }

    OutStringStream& OutStringStream::operator<<(const String& right)
    {
        write(right);

        return (*this);
    }

    OutStringStream::operator const String&() const
    {
        return toString();
    }

    void OutStringStream::flush()
    {
        Throw(UnsupportedOperation, "OutStringStream::flush", "Impossible to flush an OutStringStream");
    }
}
