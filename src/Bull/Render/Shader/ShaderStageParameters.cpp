#include <Bull/Render/Shader/ShaderStageParameters.hpp>

namespace Bull
{
    ShaderStageParameters::ShaderStageParameters(ShaderStage::Type type)
    {
        setType(type);
    }

    ShaderStageParameters& ShaderStageParameters::setType(ShaderStage::Type type)
    {
        setParameter("type", type);

        return (*this);
    }

    ShaderStage::Type ShaderStageParameters::getType() const
    {
        unsigned int type = 0;

        getParameter("type", type);

        return static_cast<ShaderStage::Type>(type);
    }
}