#ifndef BULL_RENDER_SHADER_SHADERSTAGEPARAMETERS_HPP
#define BULL_RENDER_SHADER_SHADERSTAGEPARAMETERS_HPP

#include <Bull/Core/Loader/ParameterBag.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    struct BULL_RENDER_API ShaderStageParameters : ParameterBag
    {
        /*! \brief Constructor
         *
         * \param type The type of the shader to load
         *
         */
        explicit ShaderStageParameters(ShaderStage::Type type);

        /*! \brief Set the type of the ShaderStage
         *
         * \param type The type
         *
         * \return This
         *
         */
        ShaderStageParameters& setType(ShaderStage::Type type);

        /*! \brief Get the type of the ShaderStage to load
         *
         * \return The type
         *
         */
        ShaderStage::Type getType() const;
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGEPARAMETERS_HPP
