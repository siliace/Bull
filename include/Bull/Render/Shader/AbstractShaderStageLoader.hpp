#ifndef BULL_RENDER_SHADER_ABSTRACTSHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_ABSTRACTSHADERSTAGELOADER_HPP

#include <Bull/Core/Loader/AbstractResourceLoader.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderStageParameterBag.hpp>

namespace Bull
{
    struct BULL_RENDER_API AbstractShaderStageLoader : public AbstractResourceLoader<ShaderStage, ShaderStageParameterBag>
    {

    };
}

#endif // BULL_RENDER_SHADER_ABSTRACTSHADERSTAGELOADER_HPP
