#ifndef BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP

#include <Bull/Render/Shader/AbstractShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        struct BaseShaderStageLoader : public AbstractShaderStageLoader
        {
            /*! \brief Load a ShaderStage from a Path
             *
             * \param shaderStage The ShaderStage to load
             * \param path        The path
             * \param parameters  Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromPath(ShaderStage* shaderStage, const Path& path, const ShaderStageParameterBag& parameters) const override;

            /*! \brief Load a ShaderStage from a Path
             *
             * \param shaderStage The ShaderStage to load
             * \param stream      The stream to read to load
             * \param parameters  Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromStream(ShaderStage* ShaderStage, InStream& stream, const ShaderStageParameterBag& parameters) const override;

            /*! \brief Load a ShaderStage from a memory area
             *
             * \param shaderStage The ShaderStage to load
             * \param data        The memory
             * \param length      The length of data
             * \param parameters  Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromMemory(ShaderStage* shaderStage, const void* data, Index length, const ShaderStageParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP
