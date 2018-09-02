#include <cstring>

#include <Bull/Core/IO/InStringStream.hpp>
#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Utility/Character.hpp>
#include <Bull/Core/Utility/StringUtils.hpp>


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

    bool String::startsWith(const String& search, bool caseSensitive) const
    {
        if(caseSensitive)
        {
            return find(search) == 0;
        }

        return subString(0, search.getSize()).toUppercase() == search.toUppercase();
    }

    bool String::endsWith(const String& search, bool caseSensitive) const
    {
        if(caseSensitive)
        {
            return subString(getSize() - search.getSize()) == search;

        }

        return subString(getSize() - search.getSize()).toUppercase() == search.toUppercase();
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

    String String::toLowercase(size_t begin, size_t end) const
    {
        String lower = *this;

        for(std::size_t i = begin; i < std::min(getSize(), end); i++)
        {
            lower.at(i) = Character::toLower(at(i));
        }

        return lower;
    }

    String String::toUppercase(size_t begin, size_t end) const
    {
        String upper = *this;

        for(std::size_t i = begin; i < std::min(getSize(), end); i++)
        {
            upper.at(i) = Character::toUpper(at(i));
        }

        return upper;
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
