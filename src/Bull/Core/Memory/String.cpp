#include <cstring>

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
        return integer + '0';
    }

    int String::charToInt(char character)
    {
        return character - '0';
    }

    String String::boolean(bool boolean)
    {
        return boolean ? String("true") : String("false");
    }

    const std::shared_ptr<String::SharedString>& String::getEmptyString()
    {
        static std::shared_ptr<String::SharedString> empty = std::make_shared<String::SharedString>();

        return empty;
    }

    String::String() :
        m_sharedString(getEmptyString())
    {
        /// Nothing
    }

    String::String(char character)
    {
        if(character != String::NullByte)
        {
            m_sharedString = std::make_shared<SharedString>(1);
            m_sharedString->m_string[0] = character;
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

    String::String(const char* string, std::size_t size)
    {
        set(string, size);
    }

    void String::set(const char* string)
    {
        set(string, (string) ? std::strlen(string) : 0);
    }

    void String::set(const char* string, std::size_t size)
    {
        if(size > 0)
        {
            m_sharedString = std::make_shared<SharedString>(size);

            if(string)
            {
                std::memcpy(&m_sharedString->m_string[0], string, size);
            }
            else
            {
                std::memset(&m_sharedString->m_string[0], 0, size);
            }
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    unsigned int String::count(char character, std::size_t start, bool caseSensitive) const
    {
        if(character == String::NullByte || m_sharedString->m_size == 0)
        {
            return 0;
        }

        if(!caseSensitive)
        {
            character = String::toUpper(character);
        }

        unsigned int count = 0;

        for(std::size_t i = start; i < getSize(); i++)
        {
            char toTest = m_sharedString->m_string[i];

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

    String String::subString(std::size_t start, std::size_t stop) const
    {
        if(stop == String::npos)
        {
            stop = getSize();
        }

        if(start >= stop)
        {
            return "";
        }

        String substring;

        substring.m_sharedString = std::make_shared<SharedString>(stop - (start - 1));
        std::memcpy(&substring.m_sharedString->m_string[0], &m_sharedString->m_string[start], substring.getSize());

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

        for(std::size_t i = 0; i < getSize(); i++)
        {
            if(m_sharedString->m_string[i] == delimiter)
            {
                tokens.push_back(word);

                word.clear();
            }
            else
            {
                word += m_sharedString->m_string[i];
            }
        }

        if(word.getSize() > 0)
        {
            tokens.push_back(word);
        }

        return tokens;
    }

    String& String::toUppercase(std::size_t start, std::size_t stop)
    {
        if(stop == String::npos)
        {
            stop = getSize() - 1;
        }

        for(std::size_t i = start; i <= stop; i++)
        {
            m_sharedString->m_string[i] = String::toUpper(m_sharedString->m_string[i]);
        }

        return (*this);
    }

    String& String::toLowercase(std::size_t start, std::size_t stop)
    {
        if(stop == String::npos)
        {
            stop = getSize() - 1;
        }

        for(std::size_t i = start; i <= stop; i++)
        {
            m_sharedString->m_string[i] = String::toLower(m_sharedString->m_string[i]);
        }

        return (*this);
    }

    String& String::insert(const String& toInsert, std::size_t index)
    {
        if(toInsert.getSize() == 0)
        {
            return (*this);
        }

        std::size_t start = std::min<std::size_t>(index, getSize());

        if(getCapacity() >= getSize() + toInsert.getSize())
        {
            std::memmove(&m_sharedString->m_string[start + toInsert.getSize()], &m_sharedString->m_string[start], getSize() - start);
            std::memcpy(&m_sharedString->m_string[start], &toInsert[0], toInsert.getSize());

            m_sharedString->m_size += toInsert.getSize();
            m_sharedString->m_string[m_sharedString->m_size] = String::NullByte;
        }
        else
        {
            std::shared_ptr<SharedString> newSharedString = std::make_shared<SharedString>(getSize() + toInsert.getSize());

            std::memcpy(&newSharedString->m_string[0], &m_sharedString->m_string[0], start);
            std::memcpy(&newSharedString->m_string[start], &toInsert.m_sharedString->m_string[0], toInsert.getSize());
            std::memcpy(&newSharedString->m_string[start + toInsert.getSize()], &m_sharedString->m_string[start], getSize() - start);

            newSharedString->m_string[newSharedString->m_size] = String::NullByte;

            m_sharedString = std::move(newSharedString);
        }

        return (*this);
    }

    void String::clear(bool clearMemory)
    {
        if(clearMemory)
        {
            std::memset(&m_sharedString->m_string[0], 0, getCapacity());
            m_sharedString->m_size = m_sharedString->m_capacity;
            m_sharedString->m_string[getSize()] = '\0';
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    void String::setSize(std::size_t size)
    {
        std::shared_ptr<SharedString> string = std::make_shared<SharedString>(size);

        if(size >= getSize())
        {
            std::memcpy(&string->m_string[0], &m_sharedString->m_string[0], getSize());
            std::memset(&string->m_string[getSize()], 0, string->m_size - getSize());
        }
        else
        {
            std::memcpy(&string->m_string[0], &m_sharedString->m_string[0], size);
        }

        m_sharedString = std::move(string);
    }

    std::size_t String::getSize() const
    {
        return m_sharedString->m_size;
    }

    void String::reserve(std::size_t capacity)
    {
        std::size_t size = std::min<std::size_t>(getSize(), capacity);
        std::shared_ptr<SharedString> string = std::make_shared<SharedString>(size, capacity);

        if(size >= getSize())
        {
            std::memcpy(&string->m_string[0], &m_sharedString->m_string[0], getSize());
            std::memset(&string->m_string[getSize()], 0, string->m_size - getSize());
        }

        m_sharedString = std::move(string);
    }

    std::size_t String::getCapacity() const
    {
        return m_sharedString->m_capacity;
    }

    bool String::isEmpty() const
    {
        return m_sharedString->m_size == 0;
    }

    const char* String::getBuffer() const
    {
        return &m_sharedString->m_string[0];
    }

    char& String::operator[](std::size_t index)
    {
        if(index >= getCapacity())
        {
            throw std::out_of_range("String::operator[] Index out of range");
        }

        return m_sharedString->m_string[index];
    }

    const char& String::operator[](std::size_t index) const
    {
        if(index >= getCapacity())
        {
            throw std::out_of_range("String::operator[] Index out of range");
        }

        return m_sharedString->m_string[index];
    }

    int String::toInt() const
    {
        int number = 0;
        bool isNegatif = m_sharedString->m_string[0] == '-';
        std::size_t i = isNegatif ? 1 : 0;

        while(i < getSize() && m_sharedString->m_string[i] >= '0' && m_sharedString->m_string[i] <= '9')
        {
            number *= 10;
            number += String::charToInt(m_sharedString->m_string[i]);

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

    String::SharedString::SharedString() :
        m_size(0),
        m_capacity(0)
    {
        /// Nothing
    }

    String::SharedString::SharedString(std::size_t size) :
        m_size(size),
        m_capacity(size),
        m_string(new char[size + 1])
    {
        m_string[m_size] = String::NullByte;
    }

    String::SharedString::SharedString(std::size_t size, std::size_t capacity) :
        m_size(size),
        m_capacity(capacity),
        m_string(new char[capacity + 1])
    {
        m_string[m_size] = String::NullByte;
    }
}
