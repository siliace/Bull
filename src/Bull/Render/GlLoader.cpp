#include <Bull/Render/Context/GlContext.hpp>
#include <Bull/Render/GlLoader.hpp>
#include <Bull/Render/OpenGL.hpp>

PFNGLBINDBUFFERPROC               glBindBuffer               = nullptr;
PFNGLBINDVERTEXARRAYPROC          glBindVertexArray          = nullptr;
PFNGLBUFFERDATAPROC               glBufferData               = nullptr;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray = nullptr;
PFNGLENABLEVERTEXATTRIBARRAYPROC  glEnableVertexAttribArray  = nullptr;
PFNGLGENBUFFERSPROC               glGenBuffers               = nullptr;
PFNGLGENVERTEXARRAYSPROC          glGenVertexArrays          = nullptr;
PFNGLVERTEXATTRIBPOINTERPROC      glVertexAttribPointer      = nullptr;

namespace Bull
{
    namespace prv
    {
        void GlLoader::load()
        {
            static bool loaded = false;

            if(!loaded)
            {

                glBindBuffer               = reinterpret_cast<PFNGLBINDBUFFERPROC>(GlContext::getFunction("glBindBuffer"));
                glBindVertexArray          = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(GlContext::getFunction("glBindVertexArray"));
                glBufferData               = reinterpret_cast<PFNGLBUFFERDATAPROC>(GlContext::getFunction("glBufferData"));
                glDisableVertexAttribArray = reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(GlContext::getFunction("glDisableVertexAttribArray"));
                glEnableVertexAttribArray  = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(GlContext::getFunction("glEnableVertexAttribArray"));
                glGenBuffers               = reinterpret_cast<PFNGLGENBUFFERSPROC>(GlContext::getFunction("glGenBuffers"));
                glGenVertexArrays          = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(GlContext::getFunction("glGenVertexArray"));
                glVertexAttribPointer      = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(GlContext::getFunction("glVertexAttribPointer"));

            }

            loaded = true;
        }
    }
}
