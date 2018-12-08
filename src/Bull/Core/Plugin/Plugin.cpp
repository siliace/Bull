#include <Bull/Core/Plugin/Plugin.hpp>
#include <Bull/Core/RunTime.hpp>

namespace Bull
{
    Plugin::Plugin(const Path& path, const String& entryPoint) :
        m_library(path.toString())
    {
        call<void>(entryPoint, RunTime::getInstance());
    }
}