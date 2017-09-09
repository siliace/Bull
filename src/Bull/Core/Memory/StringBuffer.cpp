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

        StringBuffer::StringBuffer(Index size) :
            StringBuffer(size, size)
        {
            /// Nothing
        }

        StringBuffer::StringBuffer(Index size, Index capacity) :
            size(size),
            capacity(capacity),
            string(new char[capacity + 1])
        {
            string[size] = String::NullByte;
        }
    }
}