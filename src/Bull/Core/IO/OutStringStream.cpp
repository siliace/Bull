#include <Bull/Core/IO/OutStringStream.hpp>

namespace Bull
{
    OutStringStream::OutStringStream() :
        m_cursor(0)
    {
        /// Nothing
    }

    OutStringStream::~OutStringStream() = default;

    void OutStringStream::clear()
    {
        m_content.clear();
    }

    std::size_t OutStringStream::write(const String& string)
    {
        std::size_t oldSize = getSize();

        m_content.insert(string, getCursor());
        m_cursor += string.getSize();

        return getSize() - oldSize;
    }

    std::size_t OutStringStream::write(const void* data, std::size_t size)
    {
        return write(String(reinterpret_cast<const char*>(data), size));
    }

    std::size_t OutStringStream::setCursor(std::size_t position)
    {
        m_cursor = std::min(position, getSize());

        return m_cursor;
    }

    std::size_t OutStringStream::getCursor() const
    {
        return m_cursor;
    }

    std::size_t OutStringStream::getSize() const
    {
        return m_content.getSize();
    }

    const String& OutStringStream::toString() const
    {
        return m_content;
    }

    OutStringStream& OutStringStream::operator<<(int right)
    {
        write(String::number(right));

        return (*this);
    }

    OutStringStream& OutStringStream::operator<<(bool right)
    {
        write(String::boolean(right));

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
}
