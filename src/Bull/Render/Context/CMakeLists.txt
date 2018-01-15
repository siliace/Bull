set(BULL_INC_RENDER_CONTEXT ${BULL_INC_RENDER}/Context)
set(BULL_SRC_RENDER_CONTEXT ${BULL_SRC_RENDER}/Context)

target_sources(bull-render
        PUBLIC
            ${BULL_INC_RENDER_CONTEXT}/Context.hpp
            ${BULL_SRC_RENDER_CONTEXT}/Context.cpp
            ${BULL_INC_RENDER_CONTEXT}/ContextResource.hpp
            ${BULL_SRC_RENDER_CONTEXT}/ContextResource.cpp
            ${BULL_INC_RENDER_CONTEXT}/ContextSettings.hpp
            ${BULL_SRC_RENDER_CONTEXT}/ContextSettings.cpp
            ${BULL_INC_RENDER_CONTEXT}/ContextSettingsProfile.hpp
            ${BULL_INC_RENDER_CONTEXT}/ContextSettingsType.hpp
        PRIVATE
            ${BULL_SRC_RENDER_CONTEXT}/Extension.hpp
            ${BULL_SRC_RENDER_CONTEXT}/Extension.cpp
            ${BULL_SRC_RENDER_CONTEXT}/ExtensionsLoader.hpp
            ${BULL_SRC_RENDER_CONTEXT}/ExtensionsLoader.cpp
            ${BULL_SRC_RENDER_CONTEXT}/GlContext.hpp
            ${BULL_SRC_RENDER_CONTEXT}/GlContext.cpp
            ${BULL_SRC_RENDER_CONTEXT}/GlFunctions.hpp
            ${BULL_SRC_RENDER_CONTEXT}/GlKhrNoError.hpp
            ${BULL_SRC_RENDER_CONTEXT}/SurfaceHandler.hpp
        )

if(BULL_OS_WINDOWS)
    add_subdirectory(Wgl)
else()
    add_subdirectory(Glx)
endif()