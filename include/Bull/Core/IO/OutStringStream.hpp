#ifndef BULL_CORE_IO_OUTSTRINGSTREAM_HPP
#define BULL_CORE_IO_OUTSTRINGSTREAM_HPP

#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_CORE_API OutStringStream : public OutStream
    {
    public:

        /*! \brief Destructor
         *
         */
        ~OutStringStream();

        /*! \brief Flush the OutStringStream
         *
         */
        void clear();

        /*! \brief Write a String into the OutStringStream
         *
         * \param string The String to write
         *
         * \return The number of bytes written
         *
         */
        std::size_t write(const String& string);

        /*! \brief Write data into the OutStringStream
         *
         * \param data A pointer to the memory area to write
         * \param size The size of the memory area to write
         *
         * \return Return the number of written bytes
         *
         */
        std::size_t write(const void* data, std::size_t size) override;

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
        OutStringStream& operator<<(int right);

        /*! \brief Adds the representation of a boolean
         *
         * \param right The boolean to add
         *
         * \return Return a reference to this
         *
         */
        OutStringStream& operator<<(bool right);

        /*! \brief Adds the representation of an char
         *
         * \param right The char to add
         *
         * \return Return a reference to this
         *
         */
        OutStringStream& operator<<(char right);

        /*! \brief Adds the representation of an char array
         *
         * \param right The char array to add
         *
         * \return Return a reference to this
         *
         */
        OutStringStream& operator<<(const char* right);

        /*! \brief Adds the representation of a String
         *
         * \param right The String to add
         *
         * \return Return a reference to this
         *
         */
        OutStringStream& operator<<(const String& right);

        /*! \brief Convert the OutStringStream to a String
         *
         * \return Return the representation of this as a String
         *
         */
        explicit operator const String&() const;

    private:

        String m_content;
    };
}

#endif // BULL_CORE_IO_OUTSTRINGSTREAM_HPP
