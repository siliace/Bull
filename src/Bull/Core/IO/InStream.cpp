#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    /*! \brief Get all the content of the stream
     *
     * \return Return the content of the stream
     *
     */
    String InStream::readAll()
    {
        String content;
        content.reserve(getSize() + 1);

        read(&content[0], content.getCapacity());

        return content;
    }
}
