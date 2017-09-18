#include <Bull/Core/Loader/ParameterNotFound.hpp>

#include <Bull/Render/Shader/ShaderStageParameterBag.hpp>

namespace Bull
{
    ShaderStageParameterBag::ShaderStageParameterBag(ShaderStageType::ShaderStageType type)
    {
        setShaderStageType(type);
    }

    ShaderStageParameterBag& ShaderStageParameterBag::setShaderStageType(ShaderStageType::ShaderStageType type)
    {
        setParameter("shader_type", type);

        return (*this);
    }

    ShaderStageType::ShaderStageType ShaderStageParameterBag::getShaderStageType() const
    {
        unsigned int type;

        if(getParameter("shader_type", type))
        {
            return ShaderStageType::ShaderStageType(type);
        }

        throw ParameterNotFound("shader_type");
    }
}