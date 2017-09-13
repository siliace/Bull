#include <Bull/Core/Loader/Resource.hpp>

namespace Bull
{
    Resource::~Resource() = default;

    Resource& Resource::setPath(const Path& path)
    {
        m_path = path;

        return (*this);
    }

    const Path& Resource::getPath() const
    {
        return m_path;
    }
}