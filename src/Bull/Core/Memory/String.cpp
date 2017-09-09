#include <cstring>

#include <Bull/Core/Memory/RangeCheck.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Memory/StringBuffer.hpp>

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
        return boolean ? String("true") : String("false");
    }

    const String::SharedString& String::getEmptyString()
    {
        static SharedString empty = std::make_shared<prv::StringBuffer>();

        return empty;
    }

    String::String() :
        m_sharedString(getEmptyString())
    {
        /// Nothing
    }

    String::String(Index size) :
        String(size, size)
    {
        /// Nothing
    }

    String::String(Index size, Index capacity)
    {
        if(capacity)
        {
            m_sharedString = std::make_shared<prv::StringBuffer>(size, capacity);
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    String::String(char character)
    {
        if(character != String::NullByte)
        {
            m_sharedString = std::make_shared<prv::StringBuffer>(1);
            m_sharedString->string[0] = character;
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    String::String(const char* string)
    {
        set(string);
    }

    String::String(const char* string, Index size)
    {
        set(string, size);
    }

    void String::set(const char* string)
    {
        set(string, (string) ? std::strlen(string) : 0);
    }

    void String::set(const char* string, Index size)
    {
        if(size > 0)
        {
            m_sharedString = std::make_shared<prv::StringBuffer>(size);

            if(string)
            {
                std::memcpy(&m_sharedString->string[0], string, size);
            }
            else
            {
                std::memset(&m_sharedString->string[0], 0, size);
            }
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    unsigned int String::count(char character, Index start, bool caseSensitive) const
    {
        if(character == String::NullByte || m_sharedString->size == 0)
        {
            return 0;
        }

        if(!caseSensitive)
        {
            character = String::toUpper(character);
        }

        unsigned int count = 0;

        for(Index i = start; i < getSize(); i++)
        {
            char toTest = m_sharedString->string[i];

            if(!caseSensitive)
            {
                toTest = String::toUpper(toTest);
            }

            if(toTest == character)
            {
                count += 1;
            }
        }

        return count;
    }

    String String::subString(Index start, Index stop) const
    {
        if(stop == String::npos)
        {
            stop = getSize();
        }

        if(start >= stop)
        {
            return "";
        }

        String substring(stop - (start - 1));

        std::memcpy(&substring.m_sharedString->string[0], &m_sharedString->string[start], substring.getSize());

        return substring;
    }

    bool String::startWith(const String& string)
    {
        return subString(0, string.getSize() - 1) == string;
    }

    bool String::endsWith(const String& string)
    {
        return subString(getSize() - string.getSize()) == string;
    }

    std::vector<String> String::explode(char delimiter) const
    {
        std::vector<String> tokens;
        String word;

        for(Index i = 0; i < getSize(); i++)
        {
            if(m_sharedString->string[i] == delimiter)
            {
                tokens.push_back(word);

                word.clear();
            }
            else
            {
                word += String(m_sharedString->string[i]);
            }
        }

        if(word.getSize() > 0)
        {
            tokens.push_back(word);
        }

        return tokens;
    }

    String& String::toUppercase(Index start, Index stop)
    {
        if(stop == String::npos)
        {
            stop = getSize() - 1;
        }

        for(Index i = start; i <= stop; i++)
        {
            m_sharedString->string[i] = String::toUpper(m_sharedString->string[i]);
        }

        return (*this);
    }

    String& String::toLowercase(Index start, Index stop)
    {
        if(stop == String::npos)
        {
            stop = getSize() - 1;
        }

        for(Index i = start; i <= stop; i++)
        {
            m_sharedString->string[i] = String::toLower(m_sharedString->string[i]);
        }

        return (*this);
    }

    String& String::insert(const String& toInsert, Index index)
    {
        if(toInsert.getSize() == 0)
        {
            return (*this);
        }

        Index start = std::min<Index>(index, getSize());

        if(getCapacity() >= getSize() + toInsert.getSize())
        {
            std::memmove(&m_sharedString->string[start + toInsert.getSize()], &m_sharedString->string[start], getSize() - start);
            std::memcpy(&m_sharedString->string[start], &toInsert[0], toInsert.getSize());

            m_sharedString->size += toInsert.getSize();
            m_sharedString->string[m_sharedString->size] = String::NullByte;
        }
        else
        {
            SharedString sharedBuffer = std::make_shared<prv::StringBuffer>(getSize() + toInsert.getSize());

            std::memcpy(&sharedBuffer->string[0], &m_sharedString->string[0], start);
            std::memcpy(&sharedBuffer->string[start], &toInsert.m_sharedString->string[0], toInsert.getSize());
            std::memcpy(&sharedBuffer->string[start + toInsert.getSize()], &m_sharedString->string[start], getSize() - start);

            sharedBuffer->string[sharedBuffer->size] = String::NullByte;

            m_sharedString = std::move(sharedBuffer);
        }

        return (*this);
    }

    void String::clear(bool keepMemory)
    {
        if(keepMemory)
        {
            std::memset(&m_sharedString->string[0], 0, getCapacity());
            m_sharedString->size = m_sharedString->capacity;
            m_sharedString->string[getSize()] = '\0';
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    void String::setSize(Index size)
    {
        SharedString sharedBuffer = std::make_shared<prv::StringBuffer>(size);

        if(size >= getSize())
        {
            std::memcpy(&sharedBuffer->string[0], &m_sharedString->string[0], getSize());
            std::memset(&sharedBuffer->string[getSize()], 0, sharedBuffer->size - getSize());
        }
        else
        {
            std::memcpy(&sharedBuffer->string[0], &m_sharedString->string[0], size);
        }

        m_sharedString = std::move(sharedBuffer);
    }

    Index String::getSize() const
    {
        return m_sharedString->size;
    }

    void String::reserve(Index capacity)
    {
        Index          size = std::min<Index>(getSize(), capacity);
        SharedString string = std::make_shared<prv::StringBuffer>(size, capacity);

        if(size >= getSize())
        {
            std::memcpy(&string->string[0], &m_sharedString->string[0], getSize());
            std::memset(&string->string[getSize()], 0, string->size - getSize());
        }

        m_sharedString = std::move(string);
    }

    Index String::getCapacity() const
    {
        return m_sharedString->capacity;
    }

    bool String::isEmpty() const
    {
        return m_sharedString->size == 0;
    }

    const char* String::getBuffer() const
    {
        return &m_sharedString->string[0];
    }

    char& String::operator[](Index index)
    {
        RangeCheck(index, getCapacity());

        return m_sharedString->string[index];
    }

    const char& String::operator[](Index index) const
    {
        RangeCheck(index, getCapacity());

        return m_sharedString->string[index];
    }

    int String::toInt() const
    {
        int number = 0;
        bool isNegatif = m_sharedString->string[0] == '-';
        Index i = isNegatif ? 1 : 0;

        while(i < getSize() && m_sharedString->string[i] >= '0' && m_sharedString->string[i] <= '9')
        {
            number *= 10;
            number += String::charToInt(m_sharedString->string[i]);

            i += 1;
        }

        if(isNegatif)
        {
            number *= -1;
        }

        return number;
    }

    bool operator==(const String& left, const String& right)
    {
        return left.getCapacity() && right.getCapacity() && std::strcmp(left.getBuffer(), right.getBuffer()) == 0;
    }

    bool operator==(const char* left, const String& right)
    {
        return left && right.getCapacity() && strcmp(left, right.getBuffer()) == 0;
    }

    bool operator==(const String& left, const char* right)
    {
        return left.getCapacity() && right && strcmp(left.getBuffer(), right) == 0;
    }

    bool operator!=(const String& left, const String& right)
    {
        return !(left == right);
    }

    bool operator!=(const char* left, const String& right)
    {
        return !(left == right);
    }

    bool operator!=(const String& left, const char* right)
    {
        return !(left == right);
    }

    bool operator<(const String& left, const String& right)
    {
        return std::strcmp(left.getBuffer(), right.getBuffer()) < 0;
    }

    bool operator<(const String& left, const char* right)
    {
        return std::strcmp(left.getBuffer(), right) < 0;
    }

    bool operator<(const char* left, const String& right)
    {
        return std::strcmp(left, right.getBuffer()) < 0;
    }

    String operator+(const String& left, const String& right)
    {
        return String(left) += right;
    }

    String& String::operator+=(const String& right)
    {
        return insert(right, getSize());
    }
}
