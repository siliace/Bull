set (INCROOT ${PROJECT_SOURCE_DIR}/include/Bull/Render)
set (SRCROOT ${PROJECT_SOURCE_DIR}/src/Bull/Render)

set(SRC ${SRCROOT}/Color.cpp
        ${INCROOT}/Color.hpp
        ${SRCROOT}/GlLoader.cpp
        ${SRCROOT}/GlLoader.hpp
        ${SRCROOT}/HardwareBuffer.cpp
        ${INCROOT}/HardwareBuffer.hpp
        ${SRCROOT}/OpenGL.hpp
        ${SRCROOT}/RenderTarget.cpp
        ${INCROOT}/RenderTarget.hpp
        ${SRCROOT}/RenderTexture.cpp
        ${INCROOT}/RenderTexture.hpp
        ${SRCROOT}/RenderTextureImpl.hpp
        ${SRCROOT}/RenderTextureImplDefault.cpp
        ${SRCROOT}/RenderTextureImplDefault.hpp
        ${SRCROOT}/RenderWindow.cpp
        ${INCROOT}/RenderWindow.hpp
        ${SRCROOT}/Shader.cpp
        ${INCROOT}/Shader.hpp
        ${SRCROOT}/Texture.cpp
        ${INCROOT}/Texture.hpp
        ${SRCROOT}/Viewport.cpp
        ${INCROOT}/Viewport.hpp)

set(SRC_CONTEXT ${SRCROOT}/Context/Context.cpp
                ${INCROOT}/Context/Context.hpp
                ${SRCROOT}/Context/ContextResource.cpp
                ${INCROOT}/Context/ContextResource.hpp
                ${SRCROOT}/Context/ContextSettings.cpp
                ${INCROOT}/Context/ContextSettings.hpp
                ${SRCROOT}/Context/ExtensionsLoader.cpp
                ${SRCROOT}/Context/ExtensionsLoader.hpp
                ${SRCROOT}/Context/GlContext.cpp
                ${SRCROOT}/Context/GlContext.hpp
                ${SRCROOT}/Context/ShaderStateSaver.cpp
                ${INCROOT}/Context/ShaderStateSaver.hpp
                ${SRCROOT}/Context/SurfaceHandler.hpp
                ${SRCROOT}/Context/TextureStateSaver.cpp
                ${INCROOT}/Context/TextureStateSaver.hpp)

if(BULL_OS_WINDOWS)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglContext.cpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglContext.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglCreateContextARB.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglExtensionsLoader.cpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglExtensionsLoader.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglMultisampleARB.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglPbufferARB.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglPixelFormatARB.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Wgl/WglSwapControlARB.hpp)
else()
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxContext.cpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxContext.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxCreateContextARB.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxExtensionsLoader.cpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxExtensionsLoader.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxSwapControlEXT.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxSwapControlMESA.hpp)
    list(APPEND SRC_CONTEXT ${SRCROOT}/Context/Glx/GlxSwapControlSGI.hpp)
endif()

add_library(bull-render ${LIB_TYPE} ${SRC} ${SRC_CONTEXT})

if(BULL_OS_WINDOWS)
    target_link_libraries(bull-render opengl32 gdi32)
else()
    target_link_libraries(bull-render GL)
endif()

target_link_libraries(bull-render bull-core bull-utility)