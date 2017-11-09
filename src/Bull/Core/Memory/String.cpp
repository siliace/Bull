#include <cstring>
#include <sstream>

#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    char String::toUpper(char character)
    {
        if(character >= 'a' && character <= 'z')
        {
            return character - ('a' - 'A');
        }

        return character;
    }

    char String::toLower(char character)
    {
        if(character >= 'A' && character <= 'Z')
        {
            return character + ('a' - 'A');
        }

        return character;
    }

    char String::intToChar(int integer)
    {
        return static_cast<char>(integer) + '0';
    }

    int String::charToInt(char character)
    {
        return character - '0';
    }

    String String::boolean(bool boolean)
    {
        return boolean ? "true" : "false";
    }

    String::String(char character)
    {
        m_string.resize(1, character);
    }

    String::String(const char* string) :
        String(string, std::strlen(string))
    {
        /// Nothing
    }

    String::String(const char* string, std::size_t size)
    {
        fill(string, size);
    }

    String::String(std::size_t size, std::size_t capacity)
    {
        m_string.resize(size, NullByte);
        m_string.reserve(capacity);
    }

    String& String::setSize(std::size_t size)
    {
        m_string.resize(size);

        return (*this);
    }

    bool String::create(std::size_t capacity)
    {
        if(isEmpty())
        {
            m_string.reserve(capacity);

            return true;
        }

        return false;
    }

    bool String::fill(const void* data, std::size_t size, std::size_t offset)
    {
        m_string.insert(offset, reinterpret_cast<const char*>(data), size);

        return true;
    }

    std::size_t String::first(const String& search) const
    {
        return m_string.find_first_of(search.m_string);
    }

    std::size_t String::last(const String& search) const
    {
        return m_string.find_last_of(search.m_string);
    }

    String& String::insert(const String& string, size_t position)
    {
        m_string.insert(position, string.m_string);

        return (*this);
    }

    String& String::append(const String& string)
    {
        m_string.append(string.m_string);

        return (*this);
    }

    String& String::subString(std::size_t begin, std::size_t end)
    {
        m_string = m_string.substr(begin, end);

        return (*this);
    }

    String String::getSubString(std::size_t begin, std::size_t end) const
    {
        return String(m_string.substr(begin, end).c_str());
    }

    std::vector<String> String::explode(char separator, bool ignoreEmpty)
    {
        std::string         token;
        std::vector<String> tokens;
        std::istringstream  iss(m_string);

        while(std::getline(iss, token, separator))
        {
            if(!token.empty() || !ignoreEmpty)
            {
                tokens.emplace_back(token.c_str());
            }
        }

        return tokens;
    }

    bool String::isEmpty() const
    {
        return m_string.empty();
    }

    char& String::at(std::size_t index)
    {
        RangeCheck(index, getCapacity());

        return m_string[index];
    }

    const char& String::at(std::size_t index) const
    {
        RangeCheck(index, getCapacity());

        return m_string[index];
    }

    char& String::operator[](std::size_t index)
    {
        RangeCheck(index, getCapacity());

        return m_string[index];
    }

    const char& String::operator[](std::size_t index) const
    {
        RangeCheck(index, getCapacity());

        return m_string[index];
    }

    void String::clear()
    {
        m_string.clear();
    }

    const char* String::getBuffer() const
    {
        return m_string.data();
    }

    std::size_t String::getSize() const
    {
        return m_string.size();
    }

    std::size_t String::getCapacity() const
    {
        return m_string.capacity();
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
        return append(right);
    }

    String operator+(const String& left, const String& right)
    {
        return String(left) += right;
    }
}
