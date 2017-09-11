#include <Bull/Core/Loader/Resource.hpp>

namespace Bull
{
    Resource::~Resource() = default;

    Resource& Resource::setFilePath(const Path& filePath)
    {
        m_path = filePath;

        return (*this);
    }

    const Path& Resource::getFilePath() const
    {
        return m_path;
    }
}