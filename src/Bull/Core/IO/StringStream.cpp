#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    StringStream::StringStream() :
        m_bufferSize(0)
    {
        /// Nothing
    }

    void StringStream::clear()
    {
        m_content.clear();
        m_bufferSize = 0;
    }

    Index StringStream::getSize() const
    {
        return m_bufferSize;
    }

    String StringStream::toString() const
    {
        String str;
        str.reserve(m_bufferSize);

        for(const String& chuck : m_content)
        {
            str += chuck;
        }

        return str;
    }

    StringStream& StringStream::operator<<(int right)
    {
        m_content.push_back(String::number(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    StringStream& StringStream::operator<<(bool right)
    {
        m_content.push_back(String::boolean(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    StringStream& StringStream::operator<<(char right)
    {
        m_content.push_back(String(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    StringStream& StringStream::operator<<(const char* right)
    {
        m_content.push_back(String(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    StringStream& StringStream::operator<<(const String& right)
    {
        m_content.push_back(right);
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    StringStream::operator String() const
    {
        return toString();
    }
}
