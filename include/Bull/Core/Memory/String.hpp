#ifndef BULL_CORE_MEMORY_STRING_HPP
#define BULL_CORE_MEMORY_STRING_HPP

#include <string>
#include <vector>

#include <Bull/Core/Memory/AbstractBuffer.hpp>

namespace Bull
{
    class BULL_CORE_API String : public AbstractBuffer
    {
    public:

        static constexpr char NullByte = '\0';

        static constexpr std::size_t InvalidPosition = std::basic_string<char>::npos;

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

        /*! \brief Convert a number to a String
         *
         * \param number The number to convert
         *
         * \return The number converted as a String
         *
         */
        template <typename T, typename = std::enable_if<std::is_arithmetic<T>::value>>
        static String number(T number)
        {
            return std::to_string(number).c_str();
        }

        static String boolean(bool boolean);

    public:

        /*! \brief Default constructor
         *
         * Create an empty String
         *
         */
        String() = default;

        /*! \brief Constructor
         *
         * \param character The character in the String
         * \param repeat    The number of character in the String
         *
         */
        String(char character);

        /*! \brief Constructor
         *
         * Create a String by coping a null terminated pointer
         *
         * \param string The C style string to copy
         *
         */
        String(const char* string);

        /*! \brief Constructor
         *
         * Create a String by coping a pointer
         *
         * \param string The C style string to copy
         * \param size   The length of the C style string
         *
         */
        String(const char* string, std::size_t size);

        /*! \brief Constructor
         *
         * Create a String filled with NullByte
         *
         * \param size     The size of the String
         * \param capacity The total capacity of the String
         *
         */
        String(std::size_t size, std::size_t capacity);

        String& setSize(std::size_t size);

        /*! \brief Create the String
         *
         * \param capacity The capacity of the String to create
         *
         * \return True if the String was created successfully
         *
         */
        bool create(std::size_t capacity) override;

        /*! \brief Fill the String
         *
         * \param data   Data to insert in the String
         * \param size   The length of data
         * \param offset The offset of the data in the String
         *
         * \return True if the String was filled successfully
         *
         */
        bool fill(const void* data, std::size_t size, std::size_t offset = 0) override;

        std::size_t first(const String& search) const;
        std::size_t last(const String& search) const;

        String& insert(const String& string, size_t position);
        String& append(const String& string);

        String& subString(std::size_t begin, std::size_t end = InvalidPosition);
        String getSubString(std::size_t begin, std::size_t end = InvalidPosition) const;

        std::vector<String> explode(char separator, bool ignoreEmpty = true);

        /*! \brief Tell whether the String is empty
         *
         * A String is considered empty if there is no character inside but can have memory allocated
         *
         * \return True if the String is empty
         */
        bool isEmpty() const;

        /*! \brief Access to a character of the String
         *
         * Get the character of the String at a given index.
         * If the index is bigger than the String capacity, throw OutOfRange
         *
         * \param index The index of the character in the String
         *
         * \return A reference to the character
         *
         * \throw OutOfRange
         *
         */
        char& at(std::size_t index);

        /*! \brief Access to a character of the String
         *
         * Get the character of the String at a given index.
         * If the index is bigger than the String capacity, throw OutOfRange
         *
         * \param index The index of the character in the String
         *
         * \return A reference to the character
         *
         * \throw OutOfRange
         *
         */
        const char& at(std::size_t index) const;

        /*! \brief Access to a character of the String
         *
         * Get the character of the String at a given index.
         * If the index is bigger than the String capacity, throw OutOfRange
         *
         * \param index The index of the character in the String
         *
         * \return A reference to the character
         *
         * \throw OutOfRange
         *
         */
        char& operator[](std::size_t index);

        /*! \brief Access to a character of the String
         *
         * Get the character of the String at a given index.
         * If the index is bigger than the String capacity, throw OutOfRange
         *
         * \param index The index of the character in the String
         *
         * \return A reference to the character
         *
         * \throw OutOfRange
         *
         */
        const char& operator[](std::size_t index) const;

        /*! \brief Flush the String
         *
         */
        void flush() override;

        /*! \brief Destroy the String
         *
         */
        void destroy() override;

        /*! \brief Get the buffer of the String
         *
         * The returned buffer is a pointer to the internal String
         *
         * \return The buffer
         *
         */
        const char* getBuffer() const;

        /*! \brief Get the size of the String
         *
         * The size is the length (e.g the number of character) in the String
         *
         * \return The size
         *
         */
        std::size_t getSize() const;

        /*! \brief Get the capacity of the String
         *
         * The capacity is the size of the memory area allocated by the String
         *
         * \return The capacity
         *
         */
        std::size_t getCapacity() const override;

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this and right are equal
         *
         */
        bool operator==(const String& right) const;

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this and right are not equal
         *
         */
        bool operator!=(const String& right) const;

        bool operator<(const String& right) const;
        bool operator>(const String& right) const;
        bool operator<=(const String& right) const;
        bool operator>=(const String& right) const;

        /*! \brief Concatenate two String
         *
         * \param right The String to concatenate to this
         *
         * \return The concatenation of this and right
         *
         */
        String& operator+=(const String& right);

        friend String operator+(const String& left, const String& right);

    private:

        std::basic_string<char> m_string;
    };
}

#endif // BULL_CORE_MEMORY_STRING_HPP
