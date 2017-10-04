#include <dlfcn.h>

#include <Bull/Core/System/Unix/LibraryImplUnix.hpp>

namespace Bull
{
    namespace prv
    {
        LibraryImplUnix::LibraryImplUnix() :
            m_handler(nullptr)
        {
            /// Nothing
        }

        LibraryImplUnix::~LibraryImplUnix()
        {
            dlclose(m_handler);
        }

        bool LibraryImplUnix::load(const String& name)
        {
            m_handler = dlopen(name.getBuffer(), RTLD_LAZY);

            return m_handler == nullptr;
        }

        Library::LibFunction LibraryImplUnix::getFunction(const String& name)
        {
            return reinterpret_cast<Library::LibFunction>(dlsym(m_handler, name.getBuffer()));
        }
    }
}
