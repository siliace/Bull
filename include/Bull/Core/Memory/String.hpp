#ifndef BULL_CORE_MEMORY_STRING_HPP
#define BULL_CORE_MEMORY_STRING_HPP

#include <memory>
#include <limits>
#include <string>
#include <vector>

#include <Bull/Core/Configuration/Integer.hpp>
#include <Bull/Core/Export.hpp>

namespace Bull
{
    namespace prv
    {
        struct StringBuffer;
    }

    class BULL_CORE_API String
    {
    public:

        static constexpr char NullByte = '\0';

        static constexpr Index npos = std::numeric_limits<Index>::max();

        /*! \brief Convert a lowercase character to the uppercase equivalent character
         *
         * \param character the character to convert
         *
         * \return Return the uppercase equivalent of the character
         *
         */
        static char toUpper(char character);

        /*! \brief Convert a uppercase character to the lowercase equivalent character
         *
         * \param character the character to convert
         *
         * \return Return the lowercase equivalent of the character
         *
         */
        static char toLower(char character);

        /*! \brief Convert a single number to its character equivalent
         *
         * \param integer The integer value to convert as a character
         *
         * \return Return the integer as a character
         *
         */
        static char intToChar(int integer);

        /*! \brief Convert a character to its integer equivalent
         *
         * \param character The character value to convert as a integer
         *
         * \return Return the character as a integer
         *
         */
        static int charToInt(char character);

        /*! \brief Create a String from a boolean
         *
         * \param boolean The boolean to represent in the String
         *
         * \return Return a String representing the boolean
         *
         */
        static String boolean(bool boolean);

        /*! \brief Create a String from a number
         *
         * \param number The number to represent in the String
         *
         * \return Return a String representing the number
         *
         */
        template <typename T, typename = std::enable_if_t<std::is_arithmetic<T>::value>>
        static String number(T number)
        {
            return String(std::to_string(number).c_str());
        };

    private:

        using SharedString = std::shared_ptr<prv::StringBuffer>;

        /*! \brief Get the instance of SharedString which corresponding to the empty string
         *
         * \return Return the empty SharedString
         *
         */
        static const SharedString& getEmptyString();

    public:

        /*! \brief Default constructor
         *
         */
        String();

        /*! \brief Constructor
         *
         * \param size The size of the String
         *
         */
        explicit String(Index size);

        /*! \brief Constructor
         *
         * \param size     The size of the String
         * \param capacity The capacity of the String
         *
         */
        String(Index size, Index capacity);
        
        /*! \brief Constructor
         *
         * \param character The character to put in the string
         *
         */
        String(char character);

        /*! \brief Constructor
         *
         * \param string The string to copy
         *
         */
        String(const char* string);

        /*! \brief Constructor
         *
         * \param string The string to copy
         * \param size   The size of the string
         *
         */
        String(const char* string, Index size);
        
        /*! \brief Constructor
         *
         * \param string The string to copy
         *
         */
        void set(const char* string);

        /*! \brief Constructor
         *
         * \param string The string to copy
         * \param size   The size of the string
         *
         */
        void set(const char* string, Index size);

        /*! \brief Counts occurrences of a character in the string
         *
         * \param character     The character to count
         * \param start         The index to start
         * \param caseSensitive True to be case sensitive
         *
         * \return The number of occurrences of the character in the string
         *
         */
        unsigned int count(char character, Index start = 0, bool caseSensitive = true) const;

        /*! \brief Get the index of the first iteration of a character
         *
         * \param c             The character
         * \param caseSensitive True to be case sensitive, false otherwise
         *
         * \return The index or -1 if the character was not found
         *
         */
        int first(char c, bool caseSensitive = true) const;

        /*! \brief Get the index of the last iteration of a character
         *
         * \param c             The character
         * \param caseSensitive True to be case sensitive, false otherwiseX
         *
         * \return The index or -1 if the character was not found
         *
         */
        int last(char c, bool caseSensitive = true) const;

        /*! \brief Replace every a character of the String by another one
         *
         * \param toReplace     The character to replace
         * \param other         The use to replace
         * \param start         The starting index to replace
         * \parma stop          The index to stop to replace
         * \param caseSensitive True to be case sensitive, false otherwise
         *
         * \return This
         *
         */
        String& replace(char toReplace, char other, Index start = 0, Index stop = npos, bool caseSensitive = true);

        /*! \brief Get a subpart of the string
         *
         * \param start The index where the substring begins
         * \param stop  The index where the substring ends
         *
         * \return Return the substring created
         *
         */
        String subString(Index start, Index stop = String::npos) const;

        /*! \brief Check whether a String start with a specified string
         *
         * \param string The string to test
         *
         * \return Return true if this string start with string, false otherwise
         *
         */
        bool startWith(const String& string);

        /*! \brief Check whether a String end with a specified string
         *
         * \param string The string to test
         *
         * \return Return true if this string end with string, false otherwise
         *
         */
        bool endsWith(const String& string);

        /*! \brief Splits a string into others
         *
         * \param delimiter The character between two split strings
         *
         * \return Return the splits
         *
         */
        std::vector<String> explode(char delimiter) const;

        /*! \brief Set the string in uppercase
         *
         * \param start The index to start to set characters in uppercase
         * \param stop  The index to stop to set characters in uppercase
         *
         * \return Return the string after the transformation
         *
         */
        String& toUppercase(Index start = 0, Index stop = String::npos);

        /*! \brief Set the string in lowercase
         *
         * \param start The index to start to set characters in lowercase
         * \param stop  The index to stop to set characters in lowercase
         *
         * \return Return the string after the transformation
         *
         */
        String& toLowercase(Index start = 0, Index stop = String::npos);

        /*! \brief Inset a String at the ith index
         *
         * \param toInsert The String to insert
         * \param index    The index where the String must be inserted
         *
         * \return Return this after the insert
         *
         */
        String& insert(const String& toInsert, Index index);

        /*! \brief Clear the string
         *
         * \param keepMemory True to reset capacity, false to keep
         *
         */
        void clear(bool keepMemory = false);

        /*! \brief Set the size of the string
         *
         * \param size The new size of the string
         *
         */
        void setSize(Index size);

        /*! \brief Get the size of the string
         *
         * \return Return the size of the string
         *
         */
        Index getSize() const;

        /*! \brief Set the capacity of the string
         *
         * \param capacity Set the capacity of the string
         *
         */
        void reserve(Index capacity);

        /*! \brief Get the capacity of the string
         *
         * \return Return the capacity of the string
         *
         */
        Index getCapacity() const;

        /*! \brief Check whether the string is empty
         *
         * \return Return true if the string is empty, false otherwise
         *
         */
        bool isEmpty() const;

        /*! \brief Casting operator override
         *
         * \return Return a constant pointer to the string
         *
         */
        const char* getBuffer() const;

        /*! \brief Get the ith character of the string
         *
         * \param index The index of the character to get
         *
         * \return Return the character at the ith position
         *
         */
        char& operator[](Index index);

        /*! \brief Get the ith character of the string
         *
         * \param index The index of the character to get
         *
         * \return Return the character at the ith position
         *
         */
        const char& operator[](Index index) const;

        /*! \brief Convert a string to an integer
         *
         * \return Return an integer representing the string
         *
         */
        int toInt() const;

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are equal, false otherwise
         *
         */
        friend bool operator==(const String& left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are equal, false otherwise
         *
         */
        friend bool operator==(const char* left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are equal, false otherwise
         *
         */
        friend bool operator==(const String& left, const char* right);

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are not equal, false otherwise
         *
         */
        friend bool operator!=(const String& left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are not equal, false otherwise
         *
         */
        friend bool operator!=(const char* left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left The first String to compare
         * \param right The second String to compare
         *
         * \return Return true if left and right are not equal, false otherwise
         *
         */
        friend bool operator!=(const String& left, const char* right);

        /*! \brief Compare two Strings
         *
         * \param left
         * \param right
         *
         * \return
         *
         */
        friend bool operator<(const String& left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left
         * \param right
         *
         * \return
         *
         */
        friend bool operator<(const char* left, const String& right);

        /*! \brief Compare two Strings
         *
         * \param left
         * \param right
         *
         * \return
         *
         */
        friend bool operator<(const String& left, const char* right);

        /*! \brief Concatenates two Strings
         *
         * \param left  The left part of the final String
         * \param right The right part of the final String
         *
         * \return Return the concatenated String
         *
         */
        friend String operator+(const String& left, const String& right);

        /*! \brief Concatenates a String at the end of the string
         *
         * \param right The String to add
         *
         * \return Return this after the concatenation
         *
         */
        String& operator+=(const String& right);

    private:

        SharedString m_sharedString;
    };
}

#endif // BULL_CORE_MEMORY_STRING_HPP
