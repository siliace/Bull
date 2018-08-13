#include <algorithm>

#include <GL/glcorearb.h>
#include <GL/glext.h>

#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Context/ExtensionsLoader.hpp>
#include <Bull/Render/Context/GlContext.hpp>

#if defined BULL_OS_WINDOWS
    #include <Bull/Render/Context/Wgl/WglExtensionsLoader.hpp>
#include "ExtensionsLoader.hpp"

typedef Bull::prv::WglExtensionsLoader ExtensionsLoaderType;
#else
    #include <Bull/Render/Context/Glx/GlxExtensionsLoader.hpp>
    typedef Bull::prv::GlxExtensionsLoader ExtensionsLoaderType;
#endif

namespace gl
{
    PFNGLACTIVETEXTUREPROC            activeTexture            = nullptr;
    PFNGLATTACHSHADERPROC             attachShader             = nullptr;
    PFNGLBEGINCONDITIONALRENDERPROC   beginConditionalRender   = nullptr;
    PFNGLBEGINQUERYPROC               beginQuery               = nullptr;
    PFNGLBINDATTRIBLOCATIONPROC       bindAttribLocation       = nullptr;
    PFNGLBINDBUFFERPROC               bindBuffer               = nullptr;
    PFNGLBINDFRAMEBUFFERPROC          bindFramebuffer          = nullptr;
    PFNGLBINDFRAGDATALOCATIONPROC     bindFragDataLocation     = nullptr;
    PFNGLBINDRENDERBUFFERPROC         bindRenderbuffer         = nullptr;
    PFNGLBINDSAMPLERPROC              bindSampler              = nullptr;
    PFNGLBINDTEXTUREPROC              bindTexture              = nullptr;
    PFNGLBINDVERTEXARRAYPROC          bindVertexArray          = nullptr;
    PFNGLBLENDFUNCPROC                blendFunc                = nullptr;
    PFNGLBLENDFUNCSEPARATEPROC        blendFuncSeparate        = nullptr;
    PFNGLBLITFRAMEBUFFERPROC          blitFramebuffer          = nullptr;
    PFNGLBUFFERDATAPROC               bufferData               = nullptr;
    PFNGLBUFFERSUBDATAPROC            bufferSubData            = nullptr;
    PFNGLCLEARPROC                    clear                    = nullptr;
    PFNGLCLEARCOLORPROC               clearColor               = nullptr;
    PFNGLCLEARDEPTHPROC               clearDepth               = nullptr;
    PFNGLCLEARSTENCILPROC             clearStencil             = nullptr;
    PFNGLCREATEPROGRAMPROC            createProgram            = nullptr;
    PFNGLCREATESHADERPROC             createShader             = nullptr;
    PFNGLCHECKFRAMEBUFFERSTATUSPROC   checkFramebufferStatus   = nullptr;
    PFNGLCOLORMASKPROC                colorMask                = nullptr;
    PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC  compressedTexSubImage1D  = nullptr;
    PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC  compressedTexSubImage2D  = nullptr;
    PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC  compressedTexSubImage3D  = nullptr;
    PFNGLCULLFACEPROC                 cullFace                 = nullptr;
    PFNGLCOMPILESHADERPROC            compileShader            = nullptr;
    PFNGLCOPYTEXSUBIMAGE2DPROC        copyTexSubImage2D        = nullptr;
    PFNGLDEBUGMESSAGECALLBACKPROC     debugMessageCallback     = nullptr;
    PFNGLDEBUGMESSAGECONTROLPROC      debugMessageControl      = nullptr;
    PFNGLDEBUGMESSAGEINSERTPROC       debugMessageInsert       = nullptr;
    PFNGLDELETEBUFFERSPROC            deleteBuffers            = nullptr;
    PFNGLDELETEFRAMEBUFFERSPROC       deleteFramebuffers       = nullptr;
    PFNGLDELETEPROGRAMPROC            deleteProgram            = nullptr;
    PFNGLDELETEQUERIESPROC            deleteQueries            = nullptr;
    PFNGLDELETERENDERBUFFERSPROC      deleteRenderbuffers      = nullptr;
    PFNGLDELETESAMPLERSPROC           deleteSamplers           = nullptr;
    PFNGLDELETESHADERPROC             deleteShader             = nullptr;
    PFNGLDELETETEXTURESPROC           deleteTextures           = nullptr;
    PFNGLDELETEVERTEXARRAYSPROC       deleteVertexArrays       = nullptr;
    PFNGLDEPTHFUNCPROC                depthFunc                = nullptr;
    PFNGLDEPTHMASKPROC                depthMask                = nullptr;
    PFNGLDISABLEPROC                  disable                  = nullptr;
    PFNGLDISABLEVERTEXATTRIBARRAYPROC disableVertexAttribArray = nullptr;
    PFNGLDRAWARRAYSPROC               drawArrays               = nullptr;
    PFNGLDRAWARRAYSINSTANCEDPROC      drawArraysInstanced      = nullptr;
    PFNGLDRAWBUFFERPROC               drawBuffer               = nullptr;
    PFNGLDRAWBUFFERSPROC              drawBuffers              = nullptr;
    PFNGLDRAWELEMENTSPROC             drawElements             = nullptr;
    PFNGLDRAWELEMENTSINSTANCEDPROC    drawElementsInstanced    = nullptr;
    PFNGLDRAWTEXTURENVPROC            drawTexture              = nullptr;
    PFNGLENABLEPROC                   enable                   = nullptr;
    PFNGLENABLEVERTEXATTRIBARRAYPROC  enableVertexAttribArray  = nullptr;
    PFNGLENDCONDITIONALRENDERPROC     endConditionalRender     = nullptr;
    PFNGLENDQUERYPROC                 endQuery                 = nullptr;
    PFNGLFLUSHPROC                    flush                    = nullptr;
    PFNGLFRAMEBUFFERRENDERBUFFERPROC  framebufferRenderbuffer  = nullptr;
    PFNGLFRAMEBUFFERTEXTUREPROC       framebufferTexture       = nullptr;
    PFNGLFRAMEBUFFERTEXTURE1DPROC     framebufferTexture1D     = nullptr;
    PFNGLFRAMEBUFFERTEXTURE2DPROC     framebufferTexture2D     = nullptr;
    PFNGLFRAMEBUFFERTEXTURE3DPROC     framebufferTexture3D     = nullptr;
    PFNGLFRAMEBUFFERTEXTURELAYERPROC  framebufferTextureLayer  = nullptr;
    PFNGLGENERATEMIPMAPPROC           generateMipmap           = nullptr;
    PFNGLGENBUFFERSPROC               genBuffers               = nullptr;
    PFNGLGENFRAMEBUFFERSPROC          genFramebuffers          = nullptr;
    PFNGLGENRENDERBUFFERSPROC         genRenderbuffers         = nullptr;
    PFNGLGENQUERIESPROC               genQueries               = nullptr;
    PFNGLGENSAMPLERSPROC              genSamplers              = nullptr;
    PFNGLGENTEXTURESPROC              genTextures              = nullptr;
    PFNGLGENVERTEXARRAYSPROC          genVertexArrays          = nullptr;
    PFNGLGETACTIVEUNIFORMPROC         getActiveUniform         = nullptr;
    PFNGLGETBOOLEANVPROC              getBooleanv              = nullptr;
    PFNGLGETBUFFERPARAMETERIVPROC     getBufferParameteriv     = nullptr;
    PFNGLGETDEBUGMESSAGELOGPROC       getDebugMessageLog       = nullptr;
    PFNGLGETERRORPROC                 getError                 = nullptr;
    PFNGLGETFLOATVPROC                getFloatv                = nullptr;
    PFNGLGETINTEGERI_VPROC            getIntegeri_v            = nullptr;
    PFNGLGETINTEGERVPROC              getIntegerv              = nullptr;
    PFNGLGETPROGRAMBINARYPROC         getProgramBinary         = nullptr;
    PFNGLGETPROGRAMIVPROC             getProgramiv             = nullptr;
    PFNGLGETPROGRAMINFOLOGPROC        getProgramInfoLog        = nullptr;
    PFNGLGETQUERYIVPROC               getQueryiv               = nullptr;
    PFNGLGETQUERYOBJECTIVPROC         getQueryObjectiv         = nullptr;
    PFNGLGETQUERYOBJECTUIVPROC        getQueryObjectuiv        = nullptr;
    PFNGLGETSHADERINFOLOGPROC         getShaderInfoLog         = nullptr;
    PFNGLGETSHADERIVPROC              getShaderiv              = nullptr;
    PFNGLGETSHADERSOURCEPROC          getShaderSource          = nullptr;
    PFNGLGETSTRINGPROC                getString                = nullptr;
    PFNGLGETSTRINGIPROC               getStringi               = nullptr;
    PFNGLGETTEXIMAGEPROC              getTexImage              = nullptr;
    PFNGLGETTEXLEVELPARAMETERFVPROC   getTexLevelParameterfv   = nullptr;
    PFNGLGETTEXLEVELPARAMETERIVPROC   getTexLevelParameteriv   = nullptr;
    PFNGLGETTEXPARAMETERFVPROC        getTexParameterfv        = nullptr;
    PFNGLGETTEXPARAMETERIVPROC        getTexParameteriv        = nullptr;
    PFNGLGETUNIFORMLOCATIONPROC       getUniformLocation       = nullptr;
    PFNGLINVALIDATEBUFFERDATAPROC     invalidateBufferData     = nullptr;
    PFNGLISBUFFERPROC                 isBuffer                 = nullptr;
    PFNGLISENABLEDPROC                isEnabled                = nullptr;
    PFNGLISPROGRAMPROC                isProgram                = nullptr;
    PFNGLISSHADERPROC                 isShader                 = nullptr;
    PFNGLISTEXTUREPROC                isTexture                = nullptr;
    PFNGLISVERTEXARRAYPROC            isVertexArray            = nullptr;
    PFNGLLINEWIDTHPROC                lineWidth                = nullptr;
    PFNGLLINKPROGRAMPROC              linkProgram              = nullptr;
    PFNGLMAPBUFFERPROC                mapBuffer                = nullptr;
    PFNGLMAPBUFFERRANGEPROC           mapBufferRange           = nullptr;
    PFNGLPIXELSTOREIPROC              pixelStorei              = nullptr;
    PFNGLPOINTSIZEPROC                pointSize                = nullptr;
    PFNGLPOLYGONMODEPROC              polygonMode              = nullptr;
    PFNGLPROGRAMBINARYPROC            programBinary            = nullptr;
    PFNGLPROGRAMPARAMETERIPROC        programParameteri        = nullptr;
    PFNGLPROGRAMUNIFORM1DPROC         programUniform1d         = nullptr;
    PFNGLPROGRAMUNIFORM1FPROC         programUniform1f         = nullptr;
    PFNGLPROGRAMUNIFORM1IPROC         programUniform1i         = nullptr;
    PFNGLPROGRAMUNIFORM2DPROC         programUniform2d         = nullptr;
    PFNGLPROGRAMUNIFORM2FPROC         programUniform2f         = nullptr;
    PFNGLPROGRAMUNIFORM2IPROC         programUniform2i         = nullptr;
    PFNGLPROGRAMUNIFORM3DPROC         programUniform3d         = nullptr;
    PFNGLPROGRAMUNIFORM3FPROC         programUniform3f         = nullptr;
    PFNGLPROGRAMUNIFORM3IPROC         programUniform3i         = nullptr;
    PFNGLPROGRAMUNIFORM4DPROC         programUniform4d         = nullptr;
    PFNGLPROGRAMUNIFORM4FPROC         programUniform4f         = nullptr;
    PFNGLPROGRAMUNIFORM4IPROC         programUniform4i         = nullptr;
    PFNGLPROGRAMUNIFORM1DVPROC        programUniform1dv        = nullptr;
    PFNGLPROGRAMUNIFORM1FVPROC        programUniform1fv        = nullptr;
    PFNGLPROGRAMUNIFORM1IVPROC        programUniform1iv        = nullptr;
    PFNGLPROGRAMUNIFORM2DVPROC        programUniform2dv        = nullptr;
    PFNGLPROGRAMUNIFORM2FVPROC        programUniform2fv        = nullptr;
    PFNGLPROGRAMUNIFORM2IVPROC        programUniform2iv        = nullptr;
    PFNGLPROGRAMUNIFORM3DVPROC        programUniform3dv        = nullptr;
    PFNGLPROGRAMUNIFORM3FVPROC        programUniform3fv        = nullptr;
    PFNGLPROGRAMUNIFORM3IVPROC        programUniform3iv        = nullptr;
    PFNGLPROGRAMUNIFORM4DVPROC        programUniform4dv        = nullptr;
    PFNGLPROGRAMUNIFORM4FVPROC        programUniform4fv        = nullptr;
    PFNGLPROGRAMUNIFORM4IVPROC        programUniform4iv        = nullptr;
    PFNGLPROGRAMUNIFORMMATRIX4DVPROC  programUniformMatrix4dv  = nullptr;
    PFNGLPROGRAMUNIFORMMATRIX4FVPROC  programUniformMatrix4fv  = nullptr;
    PFNGLREADPIXELSPROC               readPixels               = nullptr;
    PFNGLRENDERBUFFERSTORAGEPROC      renderbufferStorage      = nullptr;
    PFNGLSAMPLERPARAMETERFPROC        samplerParameterf        = nullptr;
    PFNGLSAMPLERPARAMETERIPROC        samplerParameteri        = nullptr;
    PFNGLSCISSORPROC                  scissor                  = nullptr;
    PFNGLSHADERSOURCEPROC             shaderSource             = nullptr;
    PFNGLSTENCILFUNCPROC              stencilFunc              = nullptr;
    PFNGLSTENCILFUNCSEPARATEPROC      stencilFuncSeparate      = nullptr;
    PFNGLSTENCILOPPROC                stencilOp                = nullptr;
    PFNGLSTENCILOPSEPARATEPROC        stencilOpSeparate        = nullptr;
    PFNGLTEXIMAGE1DPROC               texImage1D               = nullptr;
    PFNGLTEXIMAGE2DPROC               texImage2D               = nullptr;
    PFNGLTEXIMAGE3DPROC               texImage3D               = nullptr;
    PFNGLTEXPARAMETERFPROC            texParameterf            = nullptr;
    PFNGLTEXPARAMETERIPROC            texParameteri            = nullptr;
    PFNGLTEXSTORAGE1DPROC             texStorage1D             = nullptr;
    PFNGLTEXSTORAGE2DPROC             texStorage2D             = nullptr;
    PFNGLTEXSTORAGE3DPROC             texStorage3D             = nullptr;
    PFNGLTEXSUBIMAGE1DPROC            texSubImage1D            = nullptr;
    PFNGLTEXSUBIMAGE2DPROC            texSubImage2D            = nullptr;
    PFNGLTEXSUBIMAGE3DPROC            texSubImage3D            = nullptr;
    PFNGLUNIFORM1DPROC                uniform1d                = nullptr;
    PFNGLUNIFORM1FPROC                uniform1f                = nullptr;
    PFNGLUNIFORM1IPROC                uniform1i                = nullptr;
    PFNGLUNIFORM2DPROC                uniform2d                = nullptr;
    PFNGLUNIFORM2FPROC                uniform2f                = nullptr;
    PFNGLUNIFORM2IPROC                uniform2i                = nullptr;
    PFNGLUNIFORM3DPROC                uniform3d                = nullptr;
    PFNGLUNIFORM3FPROC                uniform3f                = nullptr;
    PFNGLUNIFORM3IPROC                uniform3i                = nullptr;
    PFNGLUNIFORM4DPROC                uniform4d                = nullptr;
    PFNGLUNIFORM4IPROC                uniform4i                = nullptr;
    PFNGLUNIFORM4FPROC                uniform4f                = nullptr;
    PFNGLUNIFORM1DVPROC               uniform1dv               = nullptr;
    PFNGLUNIFORM1FVPROC               uniform1fv               = nullptr;
    PFNGLUNIFORM1IVPROC               uniform1iv               = nullptr;
    PFNGLUNIFORM2DVPROC               uniform2dv               = nullptr;
    PFNGLUNIFORM2FVPROC               uniform2fv               = nullptr;
    PFNGLUNIFORM2IVPROC               uniform2iv               = nullptr;
    PFNGLUNIFORM3DVPROC               uniform3dv               = nullptr;
    PFNGLUNIFORM3FVPROC               uniform3fv               = nullptr;
    PFNGLUNIFORM3IVPROC               uniform3iv               = nullptr;
    PFNGLUNIFORM4DVPROC               uniform4dv               = nullptr;
    PFNGLUNIFORM4FVPROC               uniform4fv               = nullptr;
    PFNGLUNIFORM4IVPROC               uniform4iv               = nullptr;
    PFNGLUNIFORMMATRIX4DVPROC         uniformMatrix4dv         = nullptr;
    PFNGLUNIFORMMATRIX4FVPROC         uniformMatrix4fv         = nullptr;
    PFNGLUNMAPBUFFERPROC              unmapBuffer              = nullptr;
    PFNGLUSEPROGRAMPROC               useProgram               = nullptr;
    PFNGLVALIDATEPROGRAMPROC          validateProgram          = nullptr;
    PFNGLVERTEXATTRIB4FPROC           vertexAttrib4f           = nullptr;
    PFNGLVERTEXATTRIBDIVISORPROC      vertexAttribDivisor      = nullptr;
    PFNGLVERTEXATTRIBPOINTERPROC      vertexAttribPointer      = nullptr;
    PFNGLVERTEXATTRIBIPOINTERPROC     vertexAttribIPointer     = nullptr;
    PFNGLVERTEXATTRIBLPOINTERPROC     vertexAttribLPointer     = nullptr;
    PFNGLVIEWPORTPROC                 viewport                 = nullptr;
}

namespace Bull
{
    namespace prv
    {
        std::set<String> ExtensionsLoader::getAllExtensions(SurfaceHandler surface)
        {
            int extensionsCount;
            std::set<String> extensions;

            gl::getIntegerv(GL_NUM_EXTENSIONS, &extensionsCount);

            for(unsigned int i = 0; i < extensionsCount; i++)
            {
                extensions.insert(String(reinterpret_cast<const char*>(gl::getStringi(GL_EXTENSIONS, i))));
            }

            std::vector<String> tokens = ExtensionsLoaderType::getExtensions(surface);

            extensions.insert(tokens.begin(), tokens.end());

            return extensions;
        }

        ExtensionsLoader::ExtensionsLoader() :
            m_loadedFunctions(false),
            m_loadedExtensions(false)
        {
            /// Nothing
        }

        void ExtensionsLoader::require(Extension& extension)
        {
            Expect(!m_loadedExtensions, Throw(LogicError, "ExtensionsLoader::require", "Extensions already loaded"));

            m_extensions.emplace_back(extension);
        }

        void ExtensionsLoader::loadExtensions(SurfaceHandler surface)
        {
            Expect(!m_loadedExtensions, Throw(LogicError, "ExtensionsLoader::loadExtensions", "Extensions already loaded"));

            m_loadedExtensions = true;
            m_allExtensions = getAllExtensions(surface);

            for(const String& extension : m_allExtensions)
            {
                Log::getInstance()->info("Found extension : " + extension);
            }

            for(Extension& extension : m_extensions)
            {
                if(isSupported(extension.getName()))
                {
                    extension.load();

                    if(extension.isLoaded())
                    {
                        Log::getInstance()->info("Loaded OpenGL extension : " + extension.getName());
                    }
                    else
                    {
                        Log::getInstance()->info("Failed to load OpenGL extension : " + extension.getName());
                    }
                }
            }
        }

        void ExtensionsLoader::loadFunctions()
        {
            if(!m_loadedFunctions)
            {
                gl::activeTexture            = reinterpret_cast<PFNGLACTIVETEXTUREPROC>(GlContext::getFunction("glActiveTexture"));
                gl::attachShader             = reinterpret_cast<PFNGLATTACHSHADERPROC>(GlContext::getFunction("glAttachShader"));
                gl::beginConditionalRender   = reinterpret_cast<PFNGLBEGINCONDITIONALRENDERPROC>(GlContext::getFunction("glBeginConditionalRender"));
                gl::beginQuery               = reinterpret_cast<PFNGLBEGINQUERYPROC>(GlContext::getFunction("glBeginQuery"));
                gl::bindAttribLocation       = reinterpret_cast<PFNGLBINDATTRIBLOCATIONPROC>(GlContext::getFunction("glBindAttribLocation"));
                gl::bindBuffer               = reinterpret_cast<PFNGLBINDBUFFERPROC>(GlContext::getFunction("glBindBuffer"));
                gl::bindFragDataLocation     = reinterpret_cast<PFNGLBINDFRAGDATALOCATIONPROC>(GlContext::getFunction("glBindFragDataLocation"));
                gl::bindFramebuffer          = reinterpret_cast<PFNGLBINDFRAMEBUFFERPROC>(GlContext::getFunction("glBindFramebuffer"));
                gl::bindRenderbuffer         = reinterpret_cast<PFNGLBINDRENDERBUFFERPROC>(GlContext::getFunction("glBindRenderbuffer"));
                gl::bindSampler              = reinterpret_cast<PFNGLBINDSAMPLERPROC>(GlContext::getFunction("glBindSampler"));
                gl::bindTexture              = reinterpret_cast<PFNGLBINDTEXTUREPROC>(GlContext::getFunction("glBindTexture"));
                gl::bindVertexArray          = reinterpret_cast<PFNGLBINDVERTEXARRAYPROC>(GlContext::getFunction("glBindVertexArray"));
                gl::blendFunc                = reinterpret_cast<PFNGLBLENDFUNCPROC>(GlContext::getFunction("glBlendFunc"));
                gl::blendFuncSeparate        = reinterpret_cast<PFNGLBLENDFUNCSEPARATEPROC>(GlContext::getFunction("glBlendFuncSeparate"));
                gl::blitFramebuffer          = reinterpret_cast<PFNGLBLITFRAMEBUFFERPROC>(GlContext::getFunction("glBlitFramebuffer"));
                gl::bufferData               = reinterpret_cast<PFNGLBUFFERDATAPROC>(GlContext::getFunction("glBufferData"));
                gl::bufferSubData            = reinterpret_cast<PFNGLBUFFERSUBDATAPROC>(GlContext::getFunction("glBufferSubData"));
                gl::clear                    = reinterpret_cast<PFNGLCLEARPROC>(GlContext::getFunction("glClear"));
                gl::clearColor               = reinterpret_cast<PFNGLCLEARCOLORPROC>(GlContext::getFunction("glClearColor"));
                gl::clearDepth               = reinterpret_cast<PFNGLCLEARDEPTHPROC>(GlContext::getFunction("glClearDepth"));
                gl::clearStencil             = reinterpret_cast<PFNGLCLEARSTENCILPROC>(GlContext::getFunction("glClearStencil"));
                gl::checkFramebufferStatus   = reinterpret_cast<PFNGLCHECKFRAMEBUFFERSTATUSPROC>(GlContext::getFunction("glCheckFramebufferStatus"));
                gl::createProgram            = reinterpret_cast<PFNGLCREATEPROGRAMPROC>(GlContext::getFunction("glCreateProgram"));
                gl::createShader             = reinterpret_cast<PFNGLCREATESHADERPROC>(GlContext::getFunction("glCreateShader"));
                gl::colorMask                = reinterpret_cast<PFNGLCOLORMASKPROC>(GlContext::getFunction("glColorMask"));
                gl::compressedTexSubImage1D  = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC>(GlContext::getFunction("glCompressedTexSubImage1D"));
                gl::compressedTexSubImage2D  = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC>(GlContext::getFunction("glCompressedTexSubImage2D"));
                gl::compressedTexSubImage3D  = reinterpret_cast<PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC>(GlContext::getFunction("glCompressedTexSubImage3D"));
                gl::cullFace                 = reinterpret_cast<PFNGLCULLFACEPROC>(GlContext::getFunction("glCullFace"));
                gl::compileShader            = reinterpret_cast<PFNGLCOMPILESHADERPROC>(GlContext::getFunction("glCompileShader"));
                gl::copyTexSubImage2D        = reinterpret_cast<PFNGLCOPYTEXSUBIMAGE2DPROC>(GlContext::getFunction("glCopyTexSubImage2D"));
                gl::debugMessageCallback     = reinterpret_cast<PFNGLDEBUGMESSAGECALLBACKPROC>(GlContext::getFunction("glDebugMessageCallback"));
                gl::deleteBuffers            = reinterpret_cast<PFNGLDELETEBUFFERSPROC>(GlContext::getFunction("glDeleteBuffers"));
                gl::deleteFramebuffers       = reinterpret_cast<PFNGLDELETEFRAMEBUFFERSPROC>(GlContext::getFunction("glDeleteFramebuffers"));
                gl::deleteQueries            = reinterpret_cast<PFNGLDELETEQUERIESPROC>(GlContext::getFunction("glDeleteQueries"));
                gl::deleteProgram            = reinterpret_cast<PFNGLDELETEPROGRAMPROC>(GlContext::getFunction("glDeleteProgram"));
                gl::deleteRenderbuffers      = reinterpret_cast<PFNGLDELETERENDERBUFFERSPROC>(GlContext::getFunction("glDeleteRenderbuffers"));
                gl::deleteSamplers           = reinterpret_cast<PFNGLDELETESAMPLERSPROC>(GlContext::getFunction("glDeleteSamplers"));
                gl::deleteShader             = reinterpret_cast<PFNGLDELETESHADERPROC>(GlContext::getFunction("glDeleteShader"));
                gl::deleteTextures           = reinterpret_cast<PFNGLDELETETEXTURESPROC>(GlContext::getFunction("glDeleteTextures"));
                gl::deleteVertexArrays       = reinterpret_cast<PFNGLDELETEVERTEXARRAYSPROC>(GlContext::getFunction("glDeleteVertexArrays"));
                gl::depthFunc                = reinterpret_cast<PFNGLDEPTHFUNCPROC>(GlContext::getFunction("glDepthFunc"));
                gl::depthMask                = reinterpret_cast<PFNGLDEPTHMASKPROC>(GlContext::getFunction("glDepthMask"));
                gl::disable                  = reinterpret_cast<PFNGLDISABLEPROC>(GlContext::getFunction("glDisable"));
                gl::disableVertexAttribArray = reinterpret_cast<PFNGLDISABLEVERTEXATTRIBARRAYPROC>(GlContext::getFunction("glDisableVertexAttribArray"));
                gl::drawArrays               = reinterpret_cast<PFNGLDRAWARRAYSPROC>(GlContext::getFunction("glDrawArrays"));
                gl::drawArraysInstanced      = reinterpret_cast<PFNGLDRAWARRAYSINSTANCEDPROC>(GlContext::getFunction("glDrawArraysInstanced"));
                gl::drawBuffer               = reinterpret_cast<PFNGLDRAWBUFFERPROC>(GlContext::getFunction("glDrawBuffer"));
                gl::drawBuffers              = reinterpret_cast<PFNGLDRAWBUFFERSPROC>(GlContext::getFunction("glDrawBuffers"));
                gl::drawElements             = reinterpret_cast<PFNGLDRAWELEMENTSPROC>(GlContext::getFunction("glDrawElements"));
                gl::drawElementsInstanced    = reinterpret_cast<PFNGLDRAWELEMENTSINSTANCEDPROC>(GlContext::getFunction("glDrawElementsInstanced"));
                gl::enable                   = reinterpret_cast<PFNGLENABLEPROC>(GlContext::getFunction("glEnable"));
                gl::enableVertexAttribArray  = reinterpret_cast<PFNGLENABLEVERTEXATTRIBARRAYPROC>(GlContext::getFunction("glEnableVertexAttribArray"));
                gl::endConditionalRender     = reinterpret_cast<PFNGLENDCONDITIONALRENDERPROC>(GlContext::getFunction("glEndConditionalRender"));
                gl::endQuery                 = reinterpret_cast<PFNGLENDQUERYPROC>(GlContext::getFunction("glEndQuery"));
                gl::flush                    = reinterpret_cast<PFNGLFLUSHPROC>(GlContext::getFunction("glFlush"));
                gl::framebufferRenderbuffer  = reinterpret_cast<PFNGLFRAMEBUFFERRENDERBUFFERPROC>(GlContext::getFunction("glFramebufferRenderbuffer"));
                gl::framebufferTexture       = reinterpret_cast<PFNGLFRAMEBUFFERTEXTUREPROC>(GlContext::getFunction("glFramebufferTexture"));
                gl::framebufferTexture1D     = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE1DPROC>(GlContext::getFunction("glFramebufferTexture1D"));
                gl::framebufferTexture2D     = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE2DPROC>(GlContext::getFunction("glFramebufferTexture2D"));
                gl::framebufferTexture3D     = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURE3DPROC>(GlContext::getFunction("glFramebufferTexture3D"));
                gl::framebufferTextureLayer  = reinterpret_cast<PFNGLFRAMEBUFFERTEXTURELAYERPROC>(GlContext::getFunction("glFramebufferTextureLayer"));
                gl::generateMipmap           = reinterpret_cast<PFNGLGENERATEMIPMAPPROC>(GlContext::getFunction("glGenerateMipmap"));
                gl::genBuffers               = reinterpret_cast<PFNGLGENBUFFERSPROC>(GlContext::getFunction("glGenBuffers"));
                gl::genFramebuffers          = reinterpret_cast<PFNGLGENFRAMEBUFFERSPROC>(GlContext::getFunction("glGenFramebuffers"));
                gl::genQueries               = reinterpret_cast<PFNGLGENQUERIESPROC>(GlContext::getFunction("glGenQueries"));
                gl::genRenderbuffers         = reinterpret_cast<PFNGLGENRENDERBUFFERSPROC>(GlContext::getFunction("glGenRenderbuffers"));
                gl::genSamplers              = reinterpret_cast<PFNGLGENSAMPLERSPROC>(GlContext::getFunction("glGenSamplers"));
                gl::genTextures              = reinterpret_cast<PFNGLGENTEXTURESPROC>(GlContext::getFunction("glGenTextures"));
                gl::genVertexArrays          = reinterpret_cast<PFNGLGENVERTEXARRAYSPROC>(GlContext::getFunction("glGenVertexArrays"));
                gl::getActiveUniform         = reinterpret_cast<PFNGLGETACTIVEUNIFORMPROC>(GlContext::getFunction("glGetActiveUniform"));
                gl::getBooleanv              = reinterpret_cast<PFNGLGETBOOLEANVPROC>(GlContext::getFunction("glGetBooleanv"));
                gl::getBufferParameteriv     = reinterpret_cast<PFNGLGETBUFFERPARAMETERIVPROC>(GlContext::getFunction("glGetBufferParameteriv"));
                gl::getError                 = reinterpret_cast<PFNGLGETERRORPROC>(GlContext::getFunction("glGetError"));
                gl::getFloatv                = reinterpret_cast<PFNGLGETFLOATVPROC>(GlContext::getFunction("glGetFloatv"));
                gl::getIntegeri_v            = reinterpret_cast<PFNGLGETINTEGERI_VPROC>(GlContext::getFunction("glGetIntegeri_v"));
                gl::getIntegerv              = reinterpret_cast<PFNGLGETINTEGERVPROC>(GlContext::getFunction("glGetIntegerv"));
                gl::getQueryiv               = reinterpret_cast<PFNGLGETQUERYIVPROC>(GlContext::getFunction("glGetQueryiv"));
                gl::getQueryObjectiv         = reinterpret_cast<PFNGLGETQUERYOBJECTIVPROC>(GlContext::getFunction("glGetQueryObjectiv"));
                gl::getQueryObjectuiv        = reinterpret_cast<PFNGLGETQUERYOBJECTUIVPROC>(GlContext::getFunction("glGetQueryObjectuiv"));
                gl::getProgramBinary         = reinterpret_cast<PFNGLGETPROGRAMBINARYPROC>(GlContext::getFunction("glGetProgramBinary"));
                gl::getProgramiv             = reinterpret_cast<PFNGLGETPROGRAMIVPROC>(GlContext::getFunction("glGetProgramiv"));
                gl::getProgramInfoLog        = reinterpret_cast<PFNGLGETPROGRAMINFOLOGPROC>(GlContext::getFunction("glGetProgramInfoLog"));
                gl::getShaderInfoLog         = reinterpret_cast<PFNGLGETSHADERINFOLOGPROC>(GlContext::getFunction("glGetShaderInfoLog"));
                gl::getShaderiv              = reinterpret_cast<PFNGLGETSHADERIVPROC>(GlContext::getFunction("glGetShaderiv"));
                gl::getShaderSource          = reinterpret_cast<PFNGLGETSHADERSOURCEPROC>(GlContext::getFunction("glGetShaderSource"));
                gl::getStringi               = reinterpret_cast<PFNGLGETSTRINGIPROC>(GlContext::getFunction("glGetStringi"));
                gl::getTexImage              = reinterpret_cast<PFNGLGETTEXIMAGEPROC>(GlContext::getFunction("glGetTexImage"));
                gl::getTexLevelParameterfv   = reinterpret_cast<PFNGLGETTEXLEVELPARAMETERFVPROC>(GlContext::getFunction("glGetTexLevelParameterfv"));
                gl::getTexLevelParameteriv   = reinterpret_cast<PFNGLGETTEXLEVELPARAMETERIVPROC>(GlContext::getFunction("glGetTexLevelParameteriv"));
                gl::getTexParameterfv        = reinterpret_cast<PFNGLGETTEXPARAMETERFVPROC>(GlContext::getFunction("glGetTexParameterfv"));
                gl::getTexParameteriv        = reinterpret_cast<PFNGLGETTEXPARAMETERIVPROC>(GlContext::getFunction("glGetTexParameteriv"));
                gl::getUniformLocation       = reinterpret_cast<PFNGLGETUNIFORMLOCATIONPROC>(GlContext::getFunction("glGetUniformLocation"));
                gl::isBuffer                 = reinterpret_cast<PFNGLISBUFFERPROC>(GlContext::getFunction("glIsBuffer"));
                gl::isEnabled                = reinterpret_cast<PFNGLISENABLEDPROC>(GlContext::getFunction("glIsEnabled"));
                gl::isProgram                = reinterpret_cast<PFNGLISPROGRAMPROC>(GlContext::getFunction("glIsProgram"));
                gl::isShader                 = reinterpret_cast<PFNGLISSHADERPROC>(GlContext::getFunction("glIsShader"));
                gl::isTexture                = reinterpret_cast<PFNGLISTEXTUREPROC>(GlContext::getFunction("glIsTexture"));
                gl::isVertexArray            = reinterpret_cast<PFNGLISVERTEXARRAYPROC>(GlContext::getFunction("glIsVertexArray"));
                gl::lineWidth                = reinterpret_cast<PFNGLLINEWIDTHPROC>(GlContext::getFunction("glLineWidth"));
                gl::linkProgram              = reinterpret_cast<PFNGLLINKPROGRAMPROC>(GlContext::getFunction("glLinkProgram"));
                gl::mapBuffer                = reinterpret_cast<PFNGLMAPBUFFERPROC>(GlContext::getFunction("glMapBuffer"));
                gl::mapBufferRange           = reinterpret_cast<PFNGLMAPBUFFERRANGEPROC>(GlContext::getFunction("glMapBufferRange"));
                gl::pixelStorei              = reinterpret_cast<PFNGLPIXELSTOREIPROC>(GlContext::getFunction("glPixelStorei"));
                gl::pointSize                = reinterpret_cast<PFNGLPOINTSIZEPROC>(GlContext::getFunction("glPointSize"));
                gl::polygonMode              = reinterpret_cast<PFNGLPOLYGONMODEPROC>(GlContext::getFunction("glPolygonMode"));
                gl::programBinary            = reinterpret_cast<PFNGLPROGRAMBINARYPROC>(GlContext::getFunction("glProgramBinary"));
                gl::programParameteri        = reinterpret_cast<PFNGLPROGRAMPARAMETERIPROC>(GlContext::getFunction("glProgramParameteri"));
                gl::programUniform1d         = reinterpret_cast<PFNGLPROGRAMUNIFORM1DPROC>(GlContext::getFunction("glProgramUniform1d"));
                gl::programUniform1f         = reinterpret_cast<PFNGLPROGRAMUNIFORM1FPROC>(GlContext::getFunction("glProgramUniform1f"));
                gl::programUniform1i         = reinterpret_cast<PFNGLPROGRAMUNIFORM1IPROC>(GlContext::getFunction("glProgramUniform1i"));
                gl::programUniform2d         = reinterpret_cast<PFNGLPROGRAMUNIFORM2DPROC>(GlContext::getFunction("glProgramUniform2d"));
                gl::programUniform2f         = reinterpret_cast<PFNGLPROGRAMUNIFORM2FPROC>(GlContext::getFunction("glProgramUniform2f"));
                gl::programUniform2i         = reinterpret_cast<PFNGLPROGRAMUNIFORM2IPROC>(GlContext::getFunction("glProgramUniform2i"));
                gl::programUniform3d         = reinterpret_cast<PFNGLPROGRAMUNIFORM3DPROC>(GlContext::getFunction("glProgramUniform3d"));
                gl::programUniform3f         = reinterpret_cast<PFNGLPROGRAMUNIFORM3FPROC>(GlContext::getFunction("glProgramUniform3f"));
                gl::programUniform3i         = reinterpret_cast<PFNGLPROGRAMUNIFORM3IPROC>(GlContext::getFunction("glProgramUniform3i"));
                gl::programUniform4d         = reinterpret_cast<PFNGLPROGRAMUNIFORM4DPROC>(GlContext::getFunction("glProgramUniform4d"));
                gl::programUniform4f         = reinterpret_cast<PFNGLPROGRAMUNIFORM4FPROC>(GlContext::getFunction("glProgramUniform4f"));
                gl::programUniform4i         = reinterpret_cast<PFNGLPROGRAMUNIFORM4IPROC>(GlContext::getFunction("glProgramUniform4i"));
                gl::programUniform1dv        = reinterpret_cast<PFNGLPROGRAMUNIFORM1DVPROC>(GlContext::getFunction("glProgramUniform1dv"));
                gl::programUniform1fv        = reinterpret_cast<PFNGLPROGRAMUNIFORM1FVPROC>(GlContext::getFunction("glProgramUniform1fv"));
                gl::programUniform1iv        = reinterpret_cast<PFNGLPROGRAMUNIFORM1IVPROC>(GlContext::getFunction("glProgramUniform1iv"));
                gl::programUniform2dv        = reinterpret_cast<PFNGLPROGRAMUNIFORM2DVPROC>(GlContext::getFunction("glProgramUniform2dv"));
                gl::programUniform2fv        = reinterpret_cast<PFNGLPROGRAMUNIFORM2FVPROC>(GlContext::getFunction("glProgramUniform2fv"));
                gl::programUniform2iv        = reinterpret_cast<PFNGLPROGRAMUNIFORM2IVPROC>(GlContext::getFunction("glProgramUniform2iv"));
                gl::programUniform3dv        = reinterpret_cast<PFNGLPROGRAMUNIFORM3DVPROC>(GlContext::getFunction("glProgramUniform3dv"));
                gl::programUniform3fv        = reinterpret_cast<PFNGLPROGRAMUNIFORM3FVPROC>(GlContext::getFunction("glProgramUniform3fv"));
                gl::programUniform3iv        = reinterpret_cast<PFNGLPROGRAMUNIFORM3IVPROC>(GlContext::getFunction("glProgramUniform3iv"));
                gl::programUniform4dv        = reinterpret_cast<PFNGLPROGRAMUNIFORM4DVPROC>(GlContext::getFunction("glProgramUniform4dv"));
                gl::programUniform4fv        = reinterpret_cast<PFNGLPROGRAMUNIFORM4FVPROC>(GlContext::getFunction("glProgramUniform4fv"));
                gl::programUniform4iv        = reinterpret_cast<PFNGLPROGRAMUNIFORM4IVPROC>(GlContext::getFunction("glProgramUniform4iv"));
                gl::programUniformMatrix4dv  = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4DVPROC>(GlContext::getFunction("glProgramUniformMatrix4dv"));
                gl::programUniformMatrix4fv  = reinterpret_cast<PFNGLPROGRAMUNIFORMMATRIX4FVPROC>(GlContext::getFunction("glProgramUniformMatrix4fv"));
                gl::readPixels               = reinterpret_cast<PFNGLREADPIXELSPROC>(GlContext::getFunction("glReadPixels"));
                gl::renderbufferStorage      = reinterpret_cast<PFNGLRENDERBUFFERSTORAGEPROC>(GlContext::getFunction("glRenderbufferStorage"));
                gl::samplerParameterf        = reinterpret_cast<PFNGLSAMPLERPARAMETERFPROC>(GlContext::getFunction("glSamplerParameterf"));
                gl::samplerParameteri        = reinterpret_cast<PFNGLSAMPLERPARAMETERIPROC>(GlContext::getFunction("glSamplerParameteri"));
                gl::scissor                  = reinterpret_cast<PFNGLSCISSORPROC>(GlContext::getFunction("glScissor"));
                gl::shaderSource             = reinterpret_cast<PFNGLSHADERSOURCEPROC>(GlContext::getFunction("glShaderSource"));
                gl::stencilFunc              = reinterpret_cast<PFNGLSTENCILFUNCPROC>(GlContext::getFunction("glStencilFunc"));
                gl::stencilFuncSeparate      = reinterpret_cast<PFNGLSTENCILFUNCSEPARATEPROC>(GlContext::getFunction("glStencilFuncSeparate"));
                gl::stencilOp                = reinterpret_cast<PFNGLSTENCILOPPROC>(GlContext::getFunction("glStencilOp"));
                gl::stencilOpSeparate        = reinterpret_cast<PFNGLSTENCILOPSEPARATEPROC>(GlContext::getFunction("glStencilOpSeparate"));
                gl::texImage2D               = reinterpret_cast<PFNGLTEXIMAGE2DPROC>(GlContext::getFunction("glTexImage2D"));
                gl::texImage3D               = reinterpret_cast<PFNGLTEXIMAGE3DPROC>(GlContext::getFunction("glTexImage3D"));
                gl::texParameterf            = reinterpret_cast<PFNGLTEXPARAMETERFPROC>(GlContext::getFunction("glTexParameterf"));
                gl::texParameteri            = reinterpret_cast<PFNGLTEXPARAMETERIPROC>(GlContext::getFunction("glTexParameteri"));
                gl::texSubImage1D            = reinterpret_cast<PFNGLTEXSUBIMAGE1DPROC>(GlContext::getFunction("glTexSubImage1D"));
                gl::texSubImage2D            = reinterpret_cast<PFNGLTEXSUBIMAGE2DPROC>(GlContext::getFunction("glTexSubImage2D"));
                gl::texSubImage3D            = reinterpret_cast<PFNGLTEXSUBIMAGE3DPROC>(GlContext::getFunction("glTexSubImage3D"));
                gl::uniform1f                = reinterpret_cast<PFNGLUNIFORM1FPROC>(GlContext::getFunction("glUniform1f"));
                gl::uniform1i                = reinterpret_cast<PFNGLUNIFORM1IPROC>(GlContext::getFunction("glUniform1i"));
                gl::uniform2d                = reinterpret_cast<PFNGLUNIFORM2DPROC>(GlContext::getFunction("glUniform2d"));
                gl::uniform2f                = reinterpret_cast<PFNGLUNIFORM2FPROC>(GlContext::getFunction("glUniform2f"));
                gl::uniform2i                = reinterpret_cast<PFNGLUNIFORM2IPROC>(GlContext::getFunction("glUniform2i"));
                gl::uniform3d                = reinterpret_cast<PFNGLUNIFORM3DPROC>(GlContext::getFunction("glUniform3d"));
                gl::uniform3f                = reinterpret_cast<PFNGLUNIFORM3FPROC>(GlContext::getFunction("glUniform3f"));
                gl::uniform3i                = reinterpret_cast<PFNGLUNIFORM3IPROC>(GlContext::getFunction("glUniform3i"));
                gl::uniform4d                = reinterpret_cast<PFNGLUNIFORM4DPROC>(GlContext::getFunction("glUniform4d"));
                gl::uniform4f                = reinterpret_cast<PFNGLUNIFORM4FPROC>(GlContext::getFunction("glUniform4f"));
                gl::uniform4i                = reinterpret_cast<PFNGLUNIFORM4IPROC>(GlContext::getFunction("glUniform4i"));
                gl::uniform1fv               = reinterpret_cast<PFNGLUNIFORM1FVPROC>(GlContext::getFunction("glUniform1fv"));
                gl::uniform1iv               = reinterpret_cast<PFNGLUNIFORM1IVPROC>(GlContext::getFunction("glUniform1iv"));
                gl::uniform2fv               = reinterpret_cast<PFNGLUNIFORM2FVPROC>(GlContext::getFunction("glUniform2fv"));
                gl::uniform2iv               = reinterpret_cast<PFNGLUNIFORM2IVPROC>(GlContext::getFunction("glUniform2iv"));
                gl::uniform3fv               = reinterpret_cast<PFNGLUNIFORM3FVPROC>(GlContext::getFunction("glUniform3fv"));
                gl::uniform3iv               = reinterpret_cast<PFNGLUNIFORM3IVPROC>(GlContext::getFunction("glUniform3iv"));
                gl::uniform4fv               = reinterpret_cast<PFNGLUNIFORM4FVPROC>(GlContext::getFunction("glUniform4fv"));
                gl::uniform4iv               = reinterpret_cast<PFNGLUNIFORM4IVPROC>(GlContext::getFunction("glUniform4iv"));
                gl::uniformMatrix4fv         = reinterpret_cast<PFNGLUNIFORMMATRIX4FVPROC>(GlContext::getFunction("glUniformMatrix4fv"));
                gl::uniformMatrix4dv         = reinterpret_cast<PFNGLUNIFORMMATRIX4DVPROC>(GlContext::getFunction("glUniformMatrix4dv"));
                gl::unmapBuffer              = reinterpret_cast<PFNGLUNMAPBUFFERPROC>(GlContext::getFunction("glUnmapBuffer"));
                gl::useProgram               = reinterpret_cast<PFNGLUSEPROGRAMPROC>(GlContext::getFunction("glUseProgram"));
                gl::validateProgram          = reinterpret_cast<PFNGLVALIDATEPROGRAMPROC>(GlContext::getFunction("glValidateProgram"));
                gl::vertexAttrib4f           = reinterpret_cast<PFNGLVERTEXATTRIB4FPROC>(GlContext::getFunction("glVertexAttrib4f"));
                gl::vertexAttribDivisor      = reinterpret_cast<PFNGLVERTEXATTRIBDIVISORPROC>(GlContext::getFunction("glVertexAttribDivisor"));
                gl::vertexAttribPointer      = reinterpret_cast<PFNGLVERTEXATTRIBPOINTERPROC>(GlContext::getFunction("glVertexAttribPointer"));
                gl::vertexAttribIPointer     = reinterpret_cast<PFNGLVERTEXATTRIBIPOINTERPROC>(GlContext::getFunction("glVertexAttribIPointer"));
                gl::viewport                 = reinterpret_cast<PFNGLVIEWPORTPROC>(GlContext::getFunction("glViewport"));
            }

            m_loadedFunctions = true;
        }

        bool ExtensionsLoader::isSupported(const String& extension) const
        {
            if(m_loadedExtensions)
            {
                return std::find(m_allExtensions.begin(), m_allExtensions.end(), extension) != m_allExtensions.end();
            }

            return false;
        }
    }
}
