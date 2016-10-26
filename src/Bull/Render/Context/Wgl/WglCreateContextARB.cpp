#include <windows.h>

#include <Bull/Render/Context/GlContext.hpp>

namespace Bull
{
    namespace prv
    {
        HGLRC (WINAPI* wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList) = nullptr;

        bool loadCreateContextARB()
        {
            wglCreateContextAttribsARB = reinterpret_cast<HGLRC (WINAPI*)(HDC, HGLRC, const int*)>(GlContext::getFunction("wglCreateContextAttribsARB"));

            return wglCreateContextAttribsARB != nullptr;
        }
    }
}
