#include <sstream>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Support/Win32/Windows.hpp>

#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Context/Wgl/WglExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        /// We need a extension to check if any extension is available (Seems logic...)
        const char* (WINAPI* wglGetExtensionsStringARB)(HDC hdc);

        std::vector<std::string> WglExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            wglGetExtensionsStringARB = reinterpret_cast<const char* (WINAPI*)(HDC)>(GlContext::getFunction("wglGetExtensionsStringARB"));
            Expect(wglGetExtensionsStringARB, Throw(InternalError, "Failed to load wglGetExtensionsStringARB function"));

            std::string extension;
            std::vector<std::string> extensions;
            std::istringstream iss(wglGetExtensionsStringARB(handler));
            while(std::getline(iss, extension, ' '))
                extensions.emplace_back(std::move(extension));

            return extensions;
        }
    }
}
