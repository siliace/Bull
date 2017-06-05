#ifndef BULL_GLXCREATECONTEXTARB_HPP
#define BULL_GLXCREATECONTEXTARB_HPP

#include <Bull/Core/Support/Xlib/Xlib.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

#define GLX_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define GLX_CONTEXT_MINOR_VERSION_ARB             0x2092
#define GLX_CONTEXT_FLAGS_ARB                     0x2094
#define GLX_CONTEXT_PROFILE_MASK_ARB              0x9126
#define GLX_CONTEXT_CORE_PROFILE_BIT_ARB          0x00000001
#define GLX_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB 0x00000002

namespace Bull
{
    namespace prv
    {
        GLXContext (*glXCreateContextAttribs)(::Display* dpy, GLXFBConfig config, GLXContext share_context, Bool direct, const int* attrib_list) = nullptr;

        ExtensionsLoader::Extension GlxCreateContextARB("GLX_ARB_create_context", []
        {
            glXCreateContextAttribs = reinterpret_cast<GLXContext (*)(::Display*, GLXFBConfig, GLXContext, Bool, const int*)>(GlContext::getFunction("glXCreateContextAttribsARB"));

            return glXCreateContextAttribs;
        });
    }
}

#endif // BULL_GLXCREATECONTEXTARB_HPP

