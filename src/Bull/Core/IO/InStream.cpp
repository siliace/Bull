#include <Bull/Core/IO/InStream.hpp>

namespace Bull
{
    String InStream::readAll()
    {
        String content;
        content.reserve(getSize() + 1);

        read(&content[0], content.getCapacity());

        return content;
    }
}
