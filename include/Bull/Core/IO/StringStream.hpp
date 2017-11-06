#ifndef BULL_CORE_IO_STRINGSTREAM_HPP
#define BULL_CORE_IO_STRINGSTREAM_HPP

#include <vector>

#include <Bull/Core/IO/CursorAwareOutStream.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API StringStream : public CursorAwareOutStream
    {
    public:

        /*! \brief Default constructor
         *
         */
        StringStream();

        /*! \brief Destructor
         *
         */
        ~StringStream();

        /*! \brief Flush the StringStream
         *
         */
        void clear();

        /*! \brief Write a String into the StringStream
         *
         * \param string The String to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const String& string);

        /*! \brief Write data into the StringStream
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        std::size_t write(const void* data, std::size_t size) override;

        /*! \brief Set the reading position in the stream
         *
         * \param position The position to seek to
         *
         * \return Return the actual position
         *
         */
        std::size_t setCursor(std::size_t position) override;

        /*! \brief Get the reading position in the stream
         *
         * \return Return the current position
         *
         */
        std::size_t getCursor() const override;

        /*! \brief Get the size of the stream
         *
         * \return Return the size of the stream
         *
         */
        std::size_t getSize() const override;

        /*! \brief Get the content of the stream
         *
         * \return Return the content of the stream
         *
         */
        const String& toString() const;

        /*! \brief Adds the representation of an integer
         *
         * \param right The integer to add
         *
         * \return Return a reference to this
         *
         */
        StringStream& operator<<(int right);

        /*! \brief Adds the representation of a boolean
         *
         * \param right The boolean to add
         *
         * \return Return a reference to this
         *
         */
        StringStream& operator<<(bool right);

        /*! \brief Adds the representation of an char
         *
         * \param right The char to add
         *
         * \return Return a reference to this
         *
         */
        StringStream& operator<<(char right);

        /*! \brief Adds the representation of an char array
         *
         * \param right The char array to add
         *
         * \return Return a reference to this
         *
         */
        StringStream& operator<<(const char* right);

        /*! \brief Adds the representation of a String
         *
         * \param right The String to add
         *
         * \return Return a reference to this
         *
         */
        StringStream& operator<<(const String& right);

        /*! \brief Convert the StringStream to a String
         *
         * \return Return the representation of this as a String
         *
         */
        explicit operator const String&() const;

    private:

        std::size_t m_cursor;
        String m_content;
    };
}

#endif // BULL_CORE_IO_STRINGSTREAM_HPP
