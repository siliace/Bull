#include <cstring>

#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Memory/StringBuffer.hpp>

namespace Bull
{
    namespace prv
    {
        StringBuffer::StringBuffer() :
            size(0),
            capacity(0)
        {
            /// Nothing
        }

        StringBuffer::StringBuffer(std::size_t size) :
            StringBuffer(size, size)
        {
            /// Nothing
        }

        StringBuffer::StringBuffer(std::size_t size, std::size_t capacity) :
            size(size),
            capacity(capacity),
            string(new char[capacity + 1])
        {
            std::memset(string.get(), String::NullByte, capacity + 1);
        }
    }
}