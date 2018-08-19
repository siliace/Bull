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

        /*! \brief Write data into a OutStringStream
         *
         * \param bytes Bytes to write
         *
         * \return Return the number of bytes written
         *
         */
        std::size_t write(const ByteArray& bytes) override;

        /*! \brief Flush the OutStream
         *
         */
        void flush() override;

        /*! \brief Flush the OutStringStream
         *
         */
        void clear();

        /*! \brief Get the content of the stream
         *
         * \return Return the content of the stream
         *
         */
        const String& toString() const;

    private:

        String m_content;
    };
}

#endif // BULL_CORE_IO_OUTSTRINGSTREAM_HPP
