#include <dlfcn.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/System/Unix/LibraryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplUnix::LibraryImplUnix(const std::string& name) :
                m_handler(dlopen(name.getBuffer(), RTLD_LAZY))
        {
            Expect(m_handler, Throw(InternalError, "Failed to load library " + name));
        }

        LibraryImplUnix::~LibraryImplUnix()
        {
            dlclose(m_handler);
        }

        void* LibraryImplUnix::getSymbolPointer(const std::string& name) const
        {
            return dlsym(m_handler, name.getBuffer());
        }
    }
}
