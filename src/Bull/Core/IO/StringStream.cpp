#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    StringStream::StringStream() :
        m_cursor(0)
    {
        /// Nothing
    }

    StringStream::~StringStream() = default;

    void StringStream::clear()
    {
        m_content.clear();
    }

    std::size_t StringStream::write(const String& string)
    {
        std::size_t oldSize = getSize();

        m_content.insert(string, getCursor());
        m_cursor += string.getSize();

        return getSize() - oldSize;
    }

    std::size_t StringStream::write(const void* data, std::size_t size)
    {
        String string(reinterpret_cast<const char*>(data), size);

        return write(string);
    }

    std::size_t StringStream::setCursor(std::size_t position)
    {
        m_cursor = std::min(position, getSize());

        return m_cursor;
    }

    std::size_t StringStream::getCursor() const
    {
        return m_cursor;
    }

    std::size_t StringStream::getSize() const
    {
        return m_content.getSize();
    }

    const String& StringStream::toString() const
    {
        return m_content;
    }

    StringStream& StringStream::operator<<(int right)
    {
        write(String::number(right));

        return (*this);
    }

    StringStream& StringStream::operator<<(bool right)
    {
        write(String::boolean(right));

        return (*this);
    }

    StringStream& StringStream::operator<<(char right)
    {
        write(String(right));

        return (*this);
    }

    StringStream& StringStream::operator<<(const char* right)
    {
        write(String(right));

        return (*this);
    }

    StringStream& StringStream::operator<<(const String& right)
    {
        write(right);

        return (*this);
    }

    StringStream::operator const String&() const
    {
        return toString();
    }
}
