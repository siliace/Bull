#ifndef Bull_StringStream_hpp
#define Bull_StringStream_hpp

#include <vector>

#include <Bull/Core/System/Export.hpp>
#include <Bull/Core/IO/InOutStream.hpp>
#include <Bull/Core/Memory/String.hpp>

namespace Bull
{
    class BULL_API StringStream
    {
    public:

        /*! @brief Default constructor
         *
         */
        StringStream();

        /*! @brief Empty the stream content
         *
         */
        void clear();

        /*! @brief Get the size of the content of the stream
         *
         * @return Return the size of the content of the stream
         *
         */
        std::size_t getSize() const;

        /*! @brief Get the content of the stream
         *
         * @return Return the content of the stream
         *
         */
        String toString() const;

        /*! @brief Adds the representation of an integer
         *
         * @param right The integer to add
         *
         * @return Return a reference to this
         *
         */
        StringStream& operator<<(int right);

        /*! @brief Adds the representation of a boolean
         *
         * @param right The boolean to add
         *
         * @return Return a reference to this
         *
         */
        StringStream& operator<<(bool right);

        /*! @brief Adds the representation of an char
         *
         * @param right The char to add
         *
         * @return Return a reference to this
         *
         */
        StringStream& operator<<(char right);

        /*! @brief Adds the representation of an char array
         *
         * @param right The char array to add
         *
         * @return Return a reference to this
         *
         */
        StringStream& operator<<(const char* right);

        /*! @brief Adds the representation of a String
         *
         * @param right The String to add
         *
         * @return Return a reference to this
         *
         */
        StringStream& operator<<(const String& right);

        /*! @brief Convert the StringStream to a String
         *
         * @return Return the representation of this as a String
         *
         */
        operator String() const;

    private:

        std::vector<String> m_content;
        std::size_t m_bufferSize;
    };
}

#endif // Bull_StringStream_hpp
