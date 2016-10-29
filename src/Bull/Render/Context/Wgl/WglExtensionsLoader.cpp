#include <windows.h>

#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/Context/Wgl/WglExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        /// We need a extension to check if any extension is available (Seems logic...)
        const char* (WINAPI* wglGetExtensionsStringARB)(HDC hdc);

        /*! \brief Get a list of supported extensions
         *
         * \param handler The surface to use to check whether an extension is supported
         *
         * \return Return the list
         *
         */
        std::vector<String> WglExtensionsLoader::getExtensions(SurfaceHandler handler)
        {
            std::vector<String> extensions;
            wglGetExtensionsStringARB = reinterpret_cast<const char* (WINAPI*)(HDC)>(GlContext::getFunction("wglGetExtensionsStringARB"));

            if(wglGetExtensionsStringARB)
            {
                extensions = String(wglGetExtensionsStringARB(handler)).explode(' ');
            }

            return extensions;
        }
    }
}
