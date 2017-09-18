#ifndef BULL_RENDER_SHADER_SHADERSTAGEPARAMETERBAG_HPP
#define BULL_RENDER_SHADER_SHADERSTAGEPARAMETERBAG_HPP

#include <Bull/Core/Loader/ParameterBag.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Shader/ShaderStageType.hpp>

namespace Bull
{
    struct BULL_RENDER_API ShaderStageParameterBag : public ParameterBag
    {
        /*! \brief Default constructor
         *
         */
        ShaderStageParameterBag() = default;

        /*! \brief Constructor
         *
         * \param type The type of the shader
         *
         */
        ShaderStageParameterBag(ShaderStageType::ShaderStageType type);

        /*! \brief Set the type og the shader
         *
         * \param type The type of the shader
         *
         * \return This
         *
         */
        ShaderStageParameterBag& setShaderStageType(ShaderStageType::ShaderStageType type);

        /*! \brief Get the type og the shader
         *
         * \return The type of the shader
         *
         */
        ShaderStageType::ShaderStageType getShaderStageType() const;
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGEPARAMETERBAG_HPP
