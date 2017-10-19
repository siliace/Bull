#ifndef BULL_SHADERSTAGEPARAMETERS_HPP
#define BULL_SHADERSTAGEPARAMETERS_HPP

#include <Bull/Core/Resource/ParameterBag.hpp>

#include <Bull/Render/Shader/ShaderStageType.hpp>

namespace Bull
{
    struct BULL_CORE_API ShaderStageParameters : public ParameterBag
    {
        ShaderStageType::ShaderStageType type = ShaderStageType::Vertex;
    };
}

#endif //BULL_SHADERSTAGEPARAMETERS_HPP
