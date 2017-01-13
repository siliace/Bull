set (INC_ROOT ${PROJECT_SOURCE_DIR}/include/Bull/Render)
set (SRC_ROOT ${PROJECT_SOURCE_DIR}/src/Bull/Render)

########################################################################################################################
# Render files                                                                                                         #
########################################################################################################################

set(SRC ${SRC_ROOT}/Color.cpp
        ${INC_ROOT}/Color.hpp
        ${SRC_ROOT}/GlLoader.cpp
        ${SRC_ROOT}/GlLoader.hpp
        ${SRC_ROOT}/HardwareBuffer.cpp
        ${INC_ROOT}/HardwareBuffer.hpp
        ${SRC_ROOT}/OpenGL.hpp
        ${SRC_ROOT}/RenderTarget.cpp
        ${INC_ROOT}/RenderTarget.hpp
        ${SRC_ROOT}/RenderTexture.cpp
        ${INC_ROOT}/RenderTexture.hpp
        ${SRC_ROOT}/RenderTextureImpl.hpp
        ${SRC_ROOT}/RenderTextureImplDefault.cpp
        ${SRC_ROOT}/RenderTextureImplDefault.hpp
        ${SRC_ROOT}/RenderWindow.cpp
        ${INC_ROOT}/RenderWindow.hpp
        ${SRC_ROOT}/Shader.cpp
        ${INC_ROOT}/Shader.hpp
        ${SRC_ROOT}/Texture.cpp
        ${INC_ROOT}/Texture.hpp
        ${SRC_ROOT}/Viewport.cpp
        ${INC_ROOT}/Viewport.hpp)

source_group("" FILES ${SRC})

########################################################################################################################
# Render/Context files                                                                                                 #
########################################################################################################################

set(SRC_CONTEXT ${SRC_ROOT}/Context/Context.cpp
                ${INC_ROOT}/Context/Context.hpp
                ${SRC_ROOT}/Context/ContextResource.cpp
                ${INC_ROOT}/Context/ContextResource.hpp
                ${SRC_ROOT}/Context/ContextSettings.cpp
                ${INC_ROOT}/Context/ContextSettings.hpp
                ${SRC_ROOT}/Context/ExtensionsLoader.cpp
                ${SRC_ROOT}/Context/ExtensionsLoader.hpp
                ${SRC_ROOT}/Context/GlContext.cpp
                ${SRC_ROOT}/Context/GlContext.hpp
                ${SRC_ROOT}/Context/ShaderStateSaver.cpp
                ${INC_ROOT}/Context/ShaderStateSaver.hpp
                ${SRC_ROOT}/Context/SurfaceHandler.hpp
                ${SRC_ROOT}/Context/TextureStateSaver.cpp
                ${INC_ROOT}/Context/TextureStateSaver.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglContext.cpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglContext.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglCreateContextARB.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglExtensionsLoader.cpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglExtensionsLoader.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglMultisampleARB.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglPbufferARB.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglPixelFormatARB.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Wgl/WglSwapControlEXT.hpp)
else()
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxContext.cpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxContext.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxCreateContextARB.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxExtensionsLoader.cpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxExtensionsLoader.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxSwapControlEXT.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxSwapControlMESA.hpp)
    list(APPEND SRC_CONTEXT ${SRC_ROOT}/Context/Glx/GlxSwapControlSGI.hpp)
endif()

source_group("context" FILES ${SRC_CONTEXT})

set(EXTERNAL_LIBS)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})

list(APPEND EXTERNAL_LIBS ${OPENGL_gl_LIB})

bull_add_library(bull-render SOURCES ${SRC} ${SRC_CONTEXT}
                             DEPENDS bull-core bull-utility
                             EXTERNALS ${EXTERNAL_LIBS})

