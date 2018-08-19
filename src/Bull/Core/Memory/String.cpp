#include <cstring>

#include <Bull/Core/IO/InStringStream.hpp>
#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    String::String(char character, std::size_t repeat)
    {
        m_string.resize(repeat, character);
    }

    String::String(const char* string) :
        String(string, std::strlen(string))
    {
        /// Nothing
    }

    String::String(const char* string, std::size_t size)
    {
        m_string.insert(0, string, size);
    }

    void String::setSize(std::size_t size)
    {
        m_string.resize(size, NullByte);
    }

    std::size_t String::first(const String& search) const
    {
        return m_string.find_first_of(search.m_string);
    }

    std::size_t String::last(const String& search) const
    {
        return m_string.find_last_of(search.m_string);
    }

    std::size_t String::find(const String& search) const
    {
        return m_string.find(search.m_string);
    }

    void String::insert(const String& string, size_t position)
    {
        m_string.insert(position, string.m_string);
    }

    void String::append(const String& string)
    {
        m_string.append(string.m_string);
    }

    String String::subString(std::size_t begin, std::size_t end) const
    {
        RangeCheck(begin, getSize());

        return String(m_string.substr(begin, end).c_str());
    }

    std::vector<String> String::explode(char separator, bool ignoreEmpty)
    {
        String              token;
        std::vector<String> tokens;
        InStringStream      iss(*this);
        TextReader          reader(iss);

        while(!iss.isAtEnd())
        {
            token = reader.readLine(separator);

            if(!token.isEmpty() || !ignoreEmpty)
            {
                tokens.emplace_back(token);
            }
        }

        return tokens;
    }

    std::size_t String::replace(const String& search, const String& replace)
    {
        std::size_t count = 0;
        std::size_t nextReplace;

        while((nextReplace = find(search)) < InvalidPosition)
        {
            m_string.replace(nextReplace, search.getSize(), replace.m_string);
        }

        return count;
    }

    bool String::isEmpty() const
    {
        return m_string.empty();
    }

    char& String::at(std::size_t index)
    {
        RangeCheck(index, getSize());

        return m_string[index];
    }

    const char& String::at(std::size_t index) const
    {
        RangeCheck(index, getSize());

        return m_string[index];
    }

    char& String::operator[](std::size_t index)
    {
        return at(index);
    }

    const char& String::operator[](std::size_t index) const
    {
        return at(index);
    }

    void String::clear()
    {
        m_string.clear();
    }

    const char* String::getBuffer() const
    {
        return m_string.c_str();
    }

    std::size_t String::getSize() const
    {
        return m_string.size();
    }

    bool String::operator==(const String& right) const
    {
        return m_string == right.m_string;
    }

    bool String::operator!=(const String& right) const
    {
        return m_string != right.m_string;
    }

    bool String::operator<(const String& right) const
    {
        return m_string < right.m_string;
    }

    bool String::operator>(const String& right) const
    {
        return m_string > right.m_string;
    }

    bool String::operator<=(const String& right) const
    {
        return m_string <= right.m_string;
    }

    bool String::operator>=(const String& right) const
    {
        return m_string >= right.m_string;
    }

    String& String::operator+=(const String& right)
    {
        append(right);

        return (*this);
    }

    String operator+(const String& left, const String& right)
    {
        return String(left) += right;
    }
}
