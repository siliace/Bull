#include <cmath>
#include <cstring>

#include <Bull/Core/String.hpp>

namespace Bull
{
    /*! \brief Convert a lowercase character to the uppercase equivalent character
     *
     * \param character the character to convert
     *
     * \return Return the uppercase equivalent of the character
     *
     */
    char String::toUpper(char character)
    {
        if(character >= 'a' && character <= 'z')
        {
            return character - ('a' - 'A');
        }

        return character;
    }

    /*! \brief Convert a uppercase character to the lowercase equivalent character
     *
     * \param character the character to convert
     *
     * \return Return the lowercase equivalent of the character
     *
     */
    char String::toLower(char character)
    {
        if(character >= 'A' && character <= 'Z')
        {
            return character + ('a' - 'A');
        }

        return character;
    }

    /*! \brief Convert a single number to its character equivalent
     *
     * \param integer The integer value to convert as a character
     *
     * \return Return the integer as a character
     *
     */
    char String::intToChar(int integer)
    {
        return integer + '0';
    }

    /*! \brief Convert a character to its integer equivalent
     *
     * \param character The character value to convert as a integer
     *
     * \return Return the character as a integer
     *
     */
    int String::charToInt(char character)
    {
        return character - '0';
    }

    /*! \brief Create a String from a boolean
     *
     * \param boolean The boolean to represent in the String
     *
     * \return Return a String representing the boolean
     *
     */
    String String::boolean(bool boolean)
    {
        return boolean ? String("true") : String("false");
    }

    /*! \brief Create a String from a number
     *
     * \param number The number to represent in the string
     *
     * \return Return a string representing the number
     *
     */
    String String::number(int number)
    {
        String string;
        unsigned int numberCount = 1;
        int lastInsert;

        if(number < 0)
        {
            string += '-';
            number = std::abs(number);
        }

        while(number / numberCount > 10)
        {
            numberCount *= 10;
        }

        do
        {
            if(number / numberCount < 10)
            {
                string += String::intToChar(number / numberCount);
            }
            else
            {

                string += String::intToChar(number / numberCount - lastInsert * 10);
            }

            lastInsert = static_cast<int>(number / numberCount);
            numberCount /= 10;
        }while(numberCount >= 1);

        return string;
    }

    /*! \brief Get the instance of SharedString which corresponding to the empty string
     *
     * \return Return the empty SharedString
     *
     */
    const std::shared_ptr<String::SharedString>& String::getEmptyString()
    {
        static std::shared_ptr<String::SharedString> empty = std::make_shared<String::SharedString>();

        return empty;
    }

    /*! \brief Default constructor
     *
     */
    String::String() :
        m_sharedString(getEmptyString())
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param character The character to put in the string
     *
     */
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

    /*! \brief Constructor
     *
     * \param string The string to copy
     *
     */
    String::String(const char* string) :
        String(string, (string) ? std::strlen(string) : 0)
    {
        /// Nothing
    }

    /*! \brief Constructor
     *
     * \param string The string to copy
     * \param size   The size of the string
     *
     */
    String::String(const char* string, std::size_t size)
    {
        if(size > 0)
        {
            m_sharedString = std::make_shared<SharedString>(size);

            if(string)
            {
                std::memcpy(m_sharedString->m_string.get(), string, size);
            }
            else
            {
                std::memset(m_sharedString->m_string.get(), 0, size);
            }
        }
        else
        {
            m_sharedString = getEmptyString();
        }
    }

    /*! \brief Counts the occurrences of a character in the string
     *
     * \param character     The character to count
     * \param start         The index to start
     * \param caseSensitive True to be case sensitive, false otherwise
     *
     * \return Return the number of occurrences of the character in the string
     *
     */
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

    /*! \brief Get a subpart of the string
     *
     * \param start The index where the substring begins
     * \param stop  The index where the substring ends
     *
     * \return Return the substring created
     *
     */
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
        std::memcpy(substring.m_sharedString->m_string.get(), &m_sharedString->m_string[start], substring.getSize());

        return substring;
    }

    /*! \brief Check whether a String start with a specified string
     *
     * \param string The string to test
     *
     * \return Return true if this string start with string, false otherwise
     *
     */
    bool String::startWith(const String& string)
    {
        return subString(0, string.getSize() - 1) == string;
    }

    /*! \brief Check whether a String end with a specified string
     *
     * \param string The string to test
     *
     * \return Return true if this string end with string, false otherwise
     *
     */
    bool String::endWith(const String& string)
    {
        return subString(getSize() - string.getSize()) == string;
    }

    /*! \brief Splits a string into others
     *
     * \param delimiter The character between two split strings
     *
     * \return Return the splits
     *
     */
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

    /*! \brief Set the string in uppercase
     *
     * \param start The index to start to set characters in uppercase
     * \param stop  The index to stop to set characters in uppercase
     *
     * \return Return the string after the transformation
     *
     */
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

    /*! \brief Set the string in lowercase
     *
     * \param start The index to start to set characters in lowercase
     * \param stop  The index to stop to set characters in lowercase
     *
     * \return Return the string after the transformation
     *
     */
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

    /*! \brief Inset a String at the ith index
     *
     * \param toInsert The String to insert
     * \param index    The index where the String must be inserted
     *
     * \return Return this after the insert
     *
     */
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

    /*! \brief Clear the string
     *
     * \param clearMemory True to reset capacity, false to keep
     *
     */
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

    /*! \brief Set the size of the string
     *
     * \param size The new size of the string
     *
     */
    void String::setSize(std::size_t size)
    {
        std::shared_ptr<SharedString> string = std::make_shared<SharedString>(size);

        if(size >= getSize())
        {
            std::memcpy(&string->m_string[0], &m_sharedString->m_string[0], getSize());
            std::memset(&string->m_string[getSize()], 0, string->m_size - getSize());
        }

        m_sharedString = std::move(string);
    }

    /*! \brief Get the size of the string
     *
     * \return Return the size of the string
     *
     */
    std::size_t String::getSize() const
    {
        return m_sharedString->m_size;
    }

    /*! \brief Set the capacity of the string
     *
     * \param capacity Set the capacity of the string
     *
     */
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

    /*! \brief Get the capacity of the string
     *
     * \return Return the capacity of the string
     *
     */
    std::size_t String::getCapacity() const
    {
        return m_sharedString->m_capacity;
    }

    /*! \brief Check whether the string is empty
     *
     * \return Return true if the string is empty, false otherwise
     *
     */
    bool String::isEmpty() const
    {
        return m_sharedString->m_size == 0;
    }

    /*! \brief Casting operator override
     *
     * \return Return a constant pointer to the string
     *
     */
    String::operator const char*() const
    {
        return m_sharedString->m_string.get();
    }

    /*! \brief Get the ith character of the string
     *
     * \param index The index of the character to get
     *
     * \return Return the character at the ith position
     *
     */
    char& String::operator[](std::size_t index)
    {
        return m_sharedString->m_string[index];
    }

    /*! \brief Get the ith character of the string
     *
     * \param index The index of the character to get
     *
     * \return Return the character at the ith position
     *
     */
    const char& String::operator[](std::size_t index) const
    {
        return m_sharedString->m_string[index];
    }

    /*! \brief Convert a string to an integer
     *
     * \return Return an integer representing the string
     *
     */
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

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are equal, false otherwise
     *
     */
    bool operator==(const String& left, const String& right)
    {
        return strcmp(left, right) == 0;
    }

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are equal, false otherwise
     *
     */
    bool operator==(const char* left, const String& right)
    {
        return strcmp(left, right) == 0;
    }

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are equal, false otherwise
     *
     */
    bool operator==(const String& left, const char* right)
    {
        return strcmp(left, right) == 0;
    }

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are not equal, false otherwise
     *
     */
    bool operator!=(const String& left, const String& right)
    {
        return strcmp(left, right) != 0;
    }

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are not equal, false otherwise
     *
     */
    bool operator!=(const char* left, const String& right)
    {
        return strcmp(left, right) != 0;
    }

    /*! \brief Compare two Strings
     *
     * \param left The first String to compare
     * \param right The second String to compare
     *
     * \return Return true if left and right are not equal, false otherwise
     *
     */
    bool operator!=(const String& left, const char* right)
    {
        return strcmp(left, right) != 0;
    }

    /*! \brief Concatenates two Strings
     *
     * \param left  The left part of the final String
     * \param right The right part of the final String
     *
     * \return Return the concatenated String
     *
     */
    String operator+(const String& left, const String& right)
    {
        return String(left) += right;
    }

    /*! \brief Concatenates a String at the end of the string
     *
     * \param right The String to add
     *
     * \return Return this after the concatenation
     *
     */
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
