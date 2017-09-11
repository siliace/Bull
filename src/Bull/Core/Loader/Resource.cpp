#include <Bull/Core/Exception/InvalidArgument.hpp>
#include <Bull/Core/Loader/Resource.hpp>

namespace Bull
{
    Resource::~Resource() = default;

    Resource& Resource::setFilePath(const Path& filePath)
    {
        if(!filePath.isFile())
        {
            throw InvalidArgument("File path must be a file");
        }

        m_path = filePath;

        return (*this);
    }

    const Path& Resource::getFilePath() const
    {
        return m_path;
    }
}