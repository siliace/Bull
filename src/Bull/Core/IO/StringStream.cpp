#include <Bull/Core/IO/StringStream.hpp>

namespace Bull
{
    /*! \brief Default constructor
     *
     */
    StringStream::StringStream() :
        m_bufferSize(0)
    {
        /// Nothing
    }

    /*! \brief Empty the stream content
     *
     */
    void StringStream::clear()
    {
        m_content.clear();
        m_bufferSize = 0;
    }

    /*! \brief Get the size of the content of the stream
     *
     * \return Return the size of the content of the stream
     *
     */
    std::size_t StringStream::getSize() const
    {
        return m_bufferSize;
    }

    /*! \brief Get the content of the stream
     *
     * \return Return the content of the stream
     *
     */
    String StringStream::toString() const
    {
        String str;
        str.reserve(m_bufferSize);

        for(const String& chuck : m_content)
        {
            str += chuck;
        }

        return str;
    }

    /*! \brief Adds the representation of an integer
     *
     * \param right The integer to add
     *
     * \return Return a reference to this
     *
     */
    StringStream& StringStream::operator<<(int right)
    {
        m_content.push_back(String::number(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    /*! \brief Adds the representation of a boolean
     *
     * \param right The boolean to add
     *
     * \return Return a reference to this
     *
     */
    StringStream& StringStream::operator<<(bool right)
    {
        m_content.push_back(String::boolean(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    /*! \brief Adds the representation of an char
     *
     * \param right The char to add
     *
     * \return Return a reference to this
     *
     */
    StringStream& StringStream::operator<<(char right)
    {
        m_content.push_back(String(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    /*! \brief Adds the representation of an char array
     *
     * \param right The char array to add
     *
     * \return Return a reference to this
     *
     */
    StringStream& StringStream::operator<<(const char* right)
    {
        m_content.push_back(String(right));
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    /*! \brief Adds the representation of a String
     *
     * \param right The String to add
     *
     * \return Return a reference to this
     *
     */
    StringStream& StringStream::operator<<(const String& right)
    {
        m_content.push_back(right);
        m_bufferSize += m_content.back().getSize();

        return (*this);
    }

    /*! \brief Convert the StringStream to a String
     *
     * \return Return the representation of this as a String
     *
     */
    StringStream::operator String() const
    {
        return toString();
    }
}
