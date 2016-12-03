#ifndef Bull_DirectoryImplUnix_hpp
#define Bull_DirectoryImplUnix_hpp

#include <Bull/Core/FileSystem/DirectoryImpl.hpp>

namespace Bull
{
    namespace prv
    {
        class DirectoryImplUnix : public DirectoryImpl
        {
        public:

            bool open(const String& path) override;

            std::vector<Path> getContent(Uint32 flags) override;

            DirectoryHandler getSystemHandler() const override;
        };
    }
}

#endif // Bull_DirectoryImplUnix_hpp
