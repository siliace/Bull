#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Memory/BadFree.hpp>

namespace Bull
{
    BadFree::BadFree(const void* pointer, bool array) :
        m_ptr(pointer),
        m_array(array)
    {
        /// Nothing
    }

    bool BadFree::isArray() const
    {
        return m_array;
    }

    const void* BadFree::getPointer() const
    {
        return m_ptr;
    }

    String BadFree::getLogMessage()
    {
        StringStream ss;

        ss << "Failed to free " << ((isArray()) ? "array" : "pointer") << " at 0x" << getPointer();

        return ss.toString();
    }
}