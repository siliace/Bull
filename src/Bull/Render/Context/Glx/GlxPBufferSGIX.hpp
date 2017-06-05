#ifndef BULL_GLX_PBUFFER_SGIX_HPP
#define BULL_GLX_PBUFFER_SGIX_HPP

#define GLX_MAX_PBUFFER_WIDTH_SGIX		0x8016
#define GLX_MAX_PBUFFER_HEIGHT_SGIX		0x8017
#define GLX_MAX_PBUFFER_PIXELS_SGIX		0x8018
#define GLX_OPTIMAL_PBUFFER_WIDTH_SGIX	0x8019
#define GLX_OPTIMAL_PBUFFER_HEIGHT_SGIX	0x801A
#define GLX_PBUFFER_BIT_SGIX			0x00000004
#define GLX_PRESERVED_CONTENTS_SGIX		0x801B
#define GLX_LARGEST_PBUFFER_SGIX		0x801C
#define GLX_WIDTH_SGIX 				    0x801D
#define GLX_HEIGHT_SGIX				    0x801E
#define GLX_EVENT_MASK_SGIX			    0x801F
#define GLX_BUFFER_CLOBBER_MASK_SGIX  	0x08000000
#define GLX_DAMAGED_SGIX 			    0x8020
#define GLX_SAVED_SGIX				    0x8021
#define GLX_WINDOW_SGIX				    0x8022
#define GLX_PBUFFER_SGIX			    0x8023
#define GLX_FRONT_LEFT_BUFFER_BIT_SGIX	0x00000001
#define GLX_FRONT_RIGHT_BUFFER_BIT_SGIX	0x00000002
#define GLX_BACK_LEFT_BUFFER_BIT_SGIX	0x00000004
#define GLX_BACK_RIGHT_BUFFER_BIT_SGIX	0x00000008
#define GLX_AUX_BUFFERS_BIT_SGIX		0x00000010
#define GLX_DEPTH_BUFFER_BIT_SGIX		0x00000020
#define GLX_STENCIL_BUFFER_BIT_SGIX		0x00000040
#define GLX_ACCUM_BUFFER_BIT_SGIX		0x00000080
#define GLX_SAMPLE_BUFFERS_BIT_SGIX		0x00000100

#include <Bull/Core/Support/Xlib/Xlib.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>

namespace Bull
{
    namespace prv
    {
        GLXPbuffer (*glXCreateGLXPbuffer)(Display* dpy, GLXFBConfig config, unsigned int width, unsigned int height, int* attrib_list);
        void (*glXDestroyGLXPbuffer)(Display* dpy, GLXPbuffer pbuf);
        void (*glXQueryGLXPbuffer)(Display* dpy, GLXPbuffer pbuf, int attribute, unsigned int* value);
        void (*glXSelectEvent)(Display* dpy, GLXDrawable drawable, unsigned long mask);
        void (*glXGetSelectedEvent)(Display* dpy, GLXDrawable drawable, unsigned long *mask);

        ExtensionsLoader::Extension GlxPbuffer("GLX_SGIX_pbuffer", []
        {
            glXCreateGLXPbuffer  = reinterpret_cast<GLXPbuffer (*)(Display*, GLXFBConfig, unsigned int, unsigned int, int*)>(GlContext::getFunction("glXCreateGLXPbufferSGIX"));
            glXDestroyGLXPbuffer = reinterpret_cast<void (*)(Display*, GLXPbuffer)>(GlContext::getFunction("glXDestroyGLXPbufferSGIX"));
            glXQueryGLXPbuffer   = reinterpret_cast<void (*)(Display*, GLXPbuffer, int, unsigned int*)>(GlContext::getFunction("glXQueryGLXPbufferSGIX"));
            glXSelectEvent       = reinterpret_cast<void (*)(Display*, GLXDrawable, unsigned long)>(GlContext::getFunction("glXSelectEventSGIX"));
            glXGetSelectedEvent  = reinterpret_cast<void (*)(Display*, GLXDrawable, unsigned long*)>(GlContext::getFunction("glXGetSelectedEventSGIX"));

            return glXCreateGLXPbuffer && glXDestroyGLXPbuffer && glXQueryGLXPbuffer && glXSelectEvent && glXGetSelectedEvent;
        });
    }
}

#endif // BULL_GLX_PBUFFER_SGIX_HPP
