#ifndef Bull_OpenGL_hpp
#define Bull_OpenGL_hpp

#include <GL/glcorearb.h>
#include <GL/glext.h>

#include <Bull/Core/System/Export.hpp>

namespace gl
{
    BULL_API extern PFNGLACTIVETEXTUREPROC            activeTexture;
    BULL_API extern PFNGLATTACHSHADERPROC             attachShader;
    BULL_API extern PFNGLBEGINCONDITIONALRENDERPROC   beginConditionalRender;
    BULL_API extern PFNGLBEGINQUERYPROC               beginQuery;
    BULL_API extern PFNGLBINDATTRIBLOCATIONPROC       bindAttribLocation;
    BULL_API extern PFNGLBINDBUFFERPROC               bindBuffer;
    BULL_API extern PFNGLBINDFRAMEBUFFERPROC          bindFramebuffer;
    BULL_API extern PFNGLBINDFRAGDATALOCATIONPROC     bindFragDataLocation;
    BULL_API extern PFNGLBINDRENDERBUFFERPROC         bindRenderbuffer;
    BULL_API extern PFNGLBINDSAMPLERPROC              bindSampler;
    BULL_API extern PFNGLBINDTEXTUREPROC              bindTexture;
    BULL_API extern PFNGLBINDVERTEXARRAYPROC          bindVertexArray;
    BULL_API extern PFNGLBLENDFUNCPROC                blendFunc;
    BULL_API extern PFNGLBLENDFUNCSEPARATEPROC        blendFuncSeparate;
    BULL_API extern PFNGLBLITFRAMEBUFFERPROC          blitFramebuffer;
    BULL_API extern PFNGLBUFFERDATAPROC               bufferData;
    BULL_API extern PFNGLBUFFERSUBDATAPROC            bufferSubData;
    BULL_API extern PFNGLCLEARPROC                    clear;
    BULL_API extern PFNGLCLEARCOLORPROC               clearColor;
    BULL_API extern PFNGLCLEARDEPTHPROC               clearDepth;
    BULL_API extern PFNGLCLEARSTENCILPROC             clearStencil;
    BULL_API extern PFNGLCREATEPROGRAMPROC            createProgram;
    BULL_API extern PFNGLCREATESHADERPROC             createShader;
    BULL_API extern PFNGLCHECKFRAMEBUFFERSTATUSPROC   checkFramebufferStatus;
    BULL_API extern PFNGLCOLORMASKPROC                colorMask;
    BULL_API extern PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC  compressedTexSubImage1D;
    BULL_API extern PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC  compressedTexSubImage2D;
    BULL_API extern PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC  compressedTexSubImage3D;
    BULL_API extern PFNGLCULLFACEPROC                 cullFace;
    BULL_API extern PFNGLCOMPILESHADERPROC            compileShader;
    BULL_API extern PFNGLCOPYTEXSUBIMAGE2DPROC        copyTexSubImage2D;
    BULL_API extern PFNGLDEBUGMESSAGECALLBACKPROC     debugMessageCallback;
    BULL_API extern PFNGLDEBUGMESSAGECONTROLPROC      debugMessageControl;
    BULL_API extern PFNGLDEBUGMESSAGEINSERTPROC       debugMessageInsert;
    BULL_API extern PFNGLDELETEBUFFERSPROC            deleteBuffers;
    BULL_API extern PFNGLDELETEFRAMEBUFFERSPROC       deleteFramebuffers;
    BULL_API extern PFNGLDELETEPROGRAMPROC            deleteProgram;
    BULL_API extern PFNGLDELETEQUERIESPROC            deleteQueries;
    BULL_API extern PFNGLDELETERENDERBUFFERSPROC      deleteRenderbuffers;
    BULL_API extern PFNGLDELETESAMPLERSPROC           deleteSamplers;
    BULL_API extern PFNGLDELETESHADERPROC             deleteShader;
    BULL_API extern PFNGLDELETETEXTURESPROC           deleteTextures;
    BULL_API extern PFNGLDELETEVERTEXARRAYSPROC       deleteVertexArrays;
    BULL_API extern PFNGLDEPTHFUNCPROC                depthFunc;
    BULL_API extern PFNGLDEPTHMASKPROC                depthMask;
    BULL_API extern PFNGLDISABLEPROC                  disable;
    BULL_API extern PFNGLDISABLEVERTEXATTRIBARRAYPROC disableVertexAttribArray;
    BULL_API extern PFNGLDRAWARRAYSPROC               drawArrays;
    BULL_API extern PFNGLDRAWARRAYSINSTANCEDPROC      drawArraysInstanced;
    BULL_API extern PFNGLDRAWBUFFERPROC               drawBuffer;
    BULL_API extern PFNGLDRAWBUFFERSPROC              drawBuffers;
    BULL_API extern PFNGLDRAWELEMENTSPROC             drawElements;
    BULL_API extern PFNGLDRAWELEMENTSINSTANCEDPROC    drawElementsInstanced;
    BULL_API extern PFNGLDRAWTEXTURENVPROC            drawTexture;
    BULL_API extern PFNGLENABLEPROC                   enable;
    BULL_API extern PFNGLENABLEVERTEXATTRIBARRAYPROC  enableVertexAttribArray;
    BULL_API extern PFNGLENDCONDITIONALRENDERPROC     endConditionalRender;
    BULL_API extern PFNGLENDQUERYPROC                 endQuery;
    BULL_API extern PFNGLFLUSHPROC                    flush;
    BULL_API extern PFNGLFRAMEBUFFERRENDERBUFFERPROC  framebufferRenderbuffer;
    BULL_API extern PFNGLFRAMEBUFFERTEXTUREPROC       framebufferTexture;
    BULL_API extern PFNGLFRAMEBUFFERTEXTURE1DPROC     framebufferTexture1D;
    BULL_API extern PFNGLFRAMEBUFFERTEXTURE2DPROC     framebufferTexture2D;
    BULL_API extern PFNGLFRAMEBUFFERTEXTURE3DPROC     framebufferTexture3D;
    BULL_API extern PFNGLFRAMEBUFFERTEXTURELAYERPROC  framebufferTextureLayer;
    BULL_API extern PFNGLGENERATEMIPMAPPROC           generateMipmap;
    BULL_API extern PFNGLGENBUFFERSPROC               genBuffers;
    BULL_API extern PFNGLGENFRAMEBUFFERSPROC          genFramebuffers;
    BULL_API extern PFNGLGENRENDERBUFFERSPROC         genRenderbuffers;
    BULL_API extern PFNGLGENQUERIESPROC               genQueries;
    BULL_API extern PFNGLGENSAMPLERSPROC              genSamplers;
    BULL_API extern PFNGLGENTEXTURESPROC              genTextures;
    BULL_API extern PFNGLGENVERTEXARRAYSPROC          genVertexArrays;
    BULL_API extern PFNGLGETACTIVEUNIFORMPROC         getActiveUniform;
    BULL_API extern PFNGLGETBOOLEANVPROC              getBooleanv;
    BULL_API extern PFNGLGETBUFFERPARAMETERIVPROC     getBufferParameteriv;
    BULL_API extern PFNGLGETDEBUGMESSAGELOGPROC       getDebugMessageLog;
    BULL_API extern PFNGLGETERRORPROC                 getError;
    BULL_API extern PFNGLGETFLOATVPROC                getFloatv;
    BULL_API extern PFNGLGETINTEGERVPROC              getIntegerv;
    BULL_API extern PFNGLGETPROGRAMBINARYPROC         getProgramBinary;
    BULL_API extern PFNGLGETPROGRAMIVPROC             getProgramiv;
    BULL_API extern PFNGLGETPROGRAMINFOLOGPROC        getProgramInfoLog;
    BULL_API extern PFNGLGETQUERYIVPROC               getQueryiv;
    BULL_API extern PFNGLGETQUERYOBJECTIVPROC         getQueryObjectiv;
    BULL_API extern PFNGLGETQUERYOBJECTUIVPROC        getQueryObjectuiv;
    BULL_API extern PFNGLGETSHADERINFOLOGPROC         getShaderInfoLog;
    BULL_API extern PFNGLGETSHADERIVPROC              getShaderiv;
    BULL_API extern PFNGLGETSHADERSOURCEPROC          getShaderSource;
    BULL_API extern PFNGLGETSTRINGPROC                getString;
    BULL_API extern PFNGLGETSTRINGIPROC               getStringi;
    BULL_API extern PFNGLGETTEXIMAGEPROC              getTexImage;
    BULL_API extern PFNGLGETTEXLEVELPARAMETERFVPROC   getTexLevelParameterfv;
    BULL_API extern PFNGLGETTEXLEVELPARAMETERIVPROC   getTexLevelParameteriv;
    BULL_API extern PFNGLGETTEXPARAMETERFVPROC        getTexParameterfv;
    BULL_API extern PFNGLGETTEXPARAMETERIVPROC        getTexParameteriv;
    BULL_API extern PFNGLGETUNIFORMLOCATIONPROC       getUniformLocation;
    BULL_API extern PFNGLINVALIDATEBUFFERDATAPROC     invalidateBufferData;
    BULL_API extern PFNGLISENABLEDPROC                isEnabled;
    BULL_API extern PFNGLISPROGRAMPROC                isProgram;
    BULL_API extern PFNGLLINEWIDTHPROC                lineWidth;
    BULL_API extern PFNGLLINKPROGRAMPROC              linkProgram;
    BULL_API extern PFNGLMAPBUFFERPROC                mapBuffer;
    BULL_API extern PFNGLMAPBUFFERRANGEPROC           mapBufferRange;
    BULL_API extern PFNGLPIXELSTOREIPROC              pixelStorei;
    BULL_API extern PFNGLPOINTSIZEPROC                pointSize;
    BULL_API extern PFNGLPOLYGONMODEPROC              polygonMode;
    BULL_API extern PFNGLPROGRAMBINARYPROC            programBinary;
    BULL_API extern PFNGLPROGRAMPARAMETERIPROC        programParameteri;
    BULL_API extern PFNGLPROGRAMUNIFORM1DPROC         programUniform1d;
    BULL_API extern PFNGLPROGRAMUNIFORM1FPROC         programUniform1f;
    BULL_API extern PFNGLPROGRAMUNIFORM1IPROC         programUniform1i;
    BULL_API extern PFNGLPROGRAMUNIFORM2DPROC         programUniform2d;
    BULL_API extern PFNGLPROGRAMUNIFORM2FPROC         programUniform2f;
    BULL_API extern PFNGLPROGRAMUNIFORM2IPROC         programUniform2i;
    BULL_API extern PFNGLPROGRAMUNIFORM3DPROC         programUniform3d;
    BULL_API extern PFNGLPROGRAMUNIFORM3FPROC         programUniform3f;
    BULL_API extern PFNGLPROGRAMUNIFORM3IPROC         programUniform3i;
    BULL_API extern PFNGLPROGRAMUNIFORM4DPROC         programUniform4d;
    BULL_API extern PFNGLPROGRAMUNIFORM4FPROC         programUniform4f;
    BULL_API extern PFNGLPROGRAMUNIFORM4IPROC         programUniform4i;
    BULL_API extern PFNGLPROGRAMUNIFORM1DVPROC        programUniform1dv;
    BULL_API extern PFNGLPROGRAMUNIFORM1FVPROC        programUniform1fv;
    BULL_API extern PFNGLPROGRAMUNIFORM1IVPROC        programUniform1iv;
    BULL_API extern PFNGLPROGRAMUNIFORM2DVPROC        programUniform2dv;
    BULL_API extern PFNGLPROGRAMUNIFORM2FVPROC        programUniform2fv;
    BULL_API extern PFNGLPROGRAMUNIFORM2IVPROC        programUniform2iv;
    BULL_API extern PFNGLPROGRAMUNIFORM3DVPROC        programUniform3dv;
    BULL_API extern PFNGLPROGRAMUNIFORM3FVPROC        programUniform3fv;
    BULL_API extern PFNGLPROGRAMUNIFORM3IVPROC        programUniform3iv;
    BULL_API extern PFNGLPROGRAMUNIFORM4DVPROC        programUniform4dv;
    BULL_API extern PFNGLPROGRAMUNIFORM4FVPROC        programUniform4fv;
    BULL_API extern PFNGLPROGRAMUNIFORM4IVPROC        programUniform4iv;
    BULL_API extern PFNGLPROGRAMUNIFORMMATRIX4DVPROC  programUniformMatrix4dv;
    BULL_API extern PFNGLPROGRAMUNIFORMMATRIX4FVPROC  programUniformMatrix4fv;
    BULL_API extern PFNGLREADPIXELSPROC               readPixels;
    BULL_API extern PFNGLRENDERBUFFERSTORAGEPROC      renderbufferStorage;
    BULL_API extern PFNGLSAMPLERPARAMETERFPROC        samplerParameterf;
    BULL_API extern PFNGLSAMPLERPARAMETERIPROC        samplerParameteri;
    BULL_API extern PFNGLSCISSORPROC                  scissor;
    BULL_API extern PFNGLSHADERSOURCEPROC             shaderSource;
    BULL_API extern PFNGLSTENCILFUNCPROC              stencilFunc;
    BULL_API extern PFNGLSTENCILFUNCSEPARATEPROC      stencilFuncSeparate;
    BULL_API extern PFNGLSTENCILOPPROC                stencilOp;
    BULL_API extern PFNGLSTENCILOPSEPARATEPROC        stencilOpSeparate;
    BULL_API extern PFNGLTEXIMAGE1DPROC               texImage1D;
    BULL_API extern PFNGLTEXIMAGE2DPROC               texImage2D;
    BULL_API extern PFNGLTEXIMAGE3DPROC               texImage3D;
    BULL_API extern PFNGLTEXPARAMETERFPROC            texParameterf;
    BULL_API extern PFNGLTEXPARAMETERIPROC            texParameteri;
    BULL_API extern PFNGLTEXSTORAGE1DPROC             texStorage1D;
    BULL_API extern PFNGLTEXSTORAGE2DPROC             texStorage2D;
    BULL_API extern PFNGLTEXSTORAGE3DPROC             texStorage3D;
    BULL_API extern PFNGLTEXSUBIMAGE1DPROC            texSubImage1D;
    BULL_API extern PFNGLTEXSUBIMAGE2DPROC            texSubImage2D;
    BULL_API extern PFNGLTEXSUBIMAGE3DPROC            texSubImage3D;
    BULL_API extern PFNGLUNIFORM1DPROC                uniform1d;
    BULL_API extern PFNGLUNIFORM1FPROC                uniform1f;
    BULL_API extern PFNGLUNIFORM1IPROC                uniform1i;
    BULL_API extern PFNGLUNIFORM2DPROC                uniform2d;
    BULL_API extern PFNGLUNIFORM2FPROC                uniform2f;
    BULL_API extern PFNGLUNIFORM2IPROC                uniform2i;
    BULL_API extern PFNGLUNIFORM3DPROC                uniform3d;
    BULL_API extern PFNGLUNIFORM3FPROC                uniform3f;
    BULL_API extern PFNGLUNIFORM3IPROC                uniform3i;
    BULL_API extern PFNGLUNIFORM4DPROC                uniform4d;
    BULL_API extern PFNGLUNIFORM4FPROC                uniform4f;
    BULL_API extern PFNGLUNIFORM4IPROC                uniform4i;
    BULL_API extern PFNGLUNIFORM1DVPROC               uniform1dv;
    BULL_API extern PFNGLUNIFORM1FVPROC               uniform1fv;
    BULL_API extern PFNGLUNIFORM1IVPROC               uniform1iv;
    BULL_API extern PFNGLUNIFORM2DVPROC               uniform2dv;
    BULL_API extern PFNGLUNIFORM2FVPROC               uniform2fv;
    BULL_API extern PFNGLUNIFORM2IVPROC               uniform2iv;
    BULL_API extern PFNGLUNIFORM3DVPROC               uniform3dv;
    BULL_API extern PFNGLUNIFORM3FVPROC               uniform3fv;
    BULL_API extern PFNGLUNIFORM3IVPROC               uniform3iv;
    BULL_API extern PFNGLUNIFORM4DVPROC               uniform4dv;
    BULL_API extern PFNGLUNIFORM4FVPROC               uniform4fv;
    BULL_API extern PFNGLUNIFORM4IVPROC               uniform4iv;
    BULL_API extern PFNGLUNIFORMMATRIX4DVPROC         uniformMatrix4dv;
    BULL_API extern PFNGLUNIFORMMATRIX4FVPROC         uniformMatrix4fv;
    BULL_API extern PFNGLUNMAPBUFFERPROC              unmapBuffer;
    BULL_API extern PFNGLUSEPROGRAMPROC               useProgram;
    BULL_API extern PFNGLVALIDATEPROGRAMPROC          validateProgram;
    BULL_API extern PFNGLVERTEXATTRIB4FPROC           vertexAttrib4f;
    BULL_API extern PFNGLVERTEXATTRIBDIVISORPROC      vertexAttribDivisor;
    BULL_API extern PFNGLVERTEXATTRIBPOINTERPROC      vertexAttribPointer;
    BULL_API extern PFNGLVERTEXATTRIBIPOINTERPROC     vertexAttribIPointer;
    BULL_API extern PFNGLVERTEXATTRIBLPOINTERPROC     vertexAttribLPointer;
    BULL_API extern PFNGLVIEWPORTPROC                 viewport;
}

#endif // Bull_OpenGL_hpp