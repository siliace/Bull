#ifndef BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderStageParameterBag.hpp>

namespace Bull
{
    struct BULL_RENDER_API AbstractShaderStageSaver : public AbstractResourceSaver<ShaderStage, ShaderStageParameterBag>
    {

    };
}

#endif // BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
