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

        /*! \brief Convert a boolean to a String
         *
         * The boolean with be converted to "true" or "false"
         *
         * \param boolean The boolean
         *
         * \return The String
         *
         */
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
        String(char character, std::size_t repeat = 1);

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

        /*! \brief Set the size of the String
         *
         * Resize the String (result getSize() will be modified). If the new size if lower than the current size,
         * the String will be truncated, otherwise the string will be extended and filled with NullByte
         *
         * \param size The new size of the String
         *
         * \return This
         *
         */
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

        /*! \brief The the first occurence of a String
         *
         * \param search The String to search
         *
         * \return The position of int String if the searched String was found, InvalidPosition otherwise
         *
         */
        std::size_t first(const String& search) const;

        /*! \brief The the last occurence of a String
         *
         * \param search The String to search
         *
         * \return The position of String if found, InvalidPosition otherwise
         *
         */
        std::size_t last(const String& search) const;

        /*! \brief Find a substring in the String
         *
         * \param search The String to find
         *
         * \return The position of String if found, InvalidPosition otherwise
         *
         */
        std::size_t find(const String& search) const;

        /*! \brief Insert a String at a given position
         *
         * \param string   The String to insert
         * \param position The position where insert the String
         *
         */
        void insert(const String& string, size_t position);

        /*! \brief Append a String at the end this
         *
         * \param string The String to append to this
         *
         */
        void append(const String& string);

        /*! \brief Get a sub String from the String
         *
         * \param begin The index where start the sub String
         * \param end   The index where end the sub String
         *
         * \return The sub String
         *
         */
        String subString(std::size_t begin, std::size_t end = InvalidPosition) const;

        /*! \brief Explose the String to tokens
         *
         * \param separator   The character between two tokens
         * \param ignoreEmpty True to ignore empty tokens
         *
         * \return Tokens
         *
         */
        std::vector<String> explode(char separator, bool ignoreEmpty = true);

        /*! \brief Replace a piece of the String by another one
         *
         * \param search  The String to replace
         * \param replace The String to use to replace
         *
         * \return The number of replacement made
         *
         */
        std::size_t replace(const String& search, const String& replace);

        /*! \brief Tell whether the String is empty
         *
         * A String is considered empty if there is no character inside but can have memory allocated
         *
         * \return True if the String is empty
         *
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

        /*! \brief Clear the String
         *
         * Make the String empty (but some memory can be still allocated)
         *
         */
        void clear() override;

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

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this is lexically prior to right
         *
         */
        bool operator<(const String& right) const;

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this is lexically superior to right
         *
         */
        bool operator>(const String& right) const;

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this is lexically prior or equal to right
         *
         */
        bool operator<=(const String& right) const;

        /*! \brief Compare two String
         *
         * \param right The String to compare to this
         *
         * \return True if this is lexically superior or equal to right
         *
         */
        bool operator>=(const String& right) const;

        /*! \brief Concatenate two String
         *
         * \param right The String to concatenate to this
         *
         * \return The concatenation of this and right
         *
         */
        String& operator+=(const String& right);

        /*! \brief Concatenate two String
         *
         * \param left  The left String
         * \param right The right String
         *
         * \return The concatenation of left and right
         *
         */
        friend String operator+(const String& left, const String& right);

    private:

        std::basic_string<char> m_string;
    };
}

#endif // BULL_CORE_MEMORY_STRING_HPP
