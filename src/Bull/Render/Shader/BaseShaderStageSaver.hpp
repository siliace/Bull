#ifndef BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP

#include <Bull/Render/Shader/AbstractShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        struct BaseShaderStageSaver : public AbstractShaderStageSaver
        {
            /*! \brief Save a ShaderStage to a file
             *
             * \param shaderStage The ShaderStage to save
             * \param path        The Path to save the Resource
             * \param parameters  Parameters to save the Resource
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToPath(const ShaderStage* shaderStage, const Path& path, const ShaderStageParameterBag& parameters) const override;

            /*! \brief Save a ShaderStage to a stream
             *
             * \param shaderStage The ShaderStage to save
             * \param stream      The stream to write
             * \param parameters  Parameters to save the Resource
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToStream(const ShaderStage* resource, OutStream& stream, const ShaderStageParameterBag& parameters) const override;

            /*! \brief Save a ShaderStage to a memory area
             *
             * \param shaderStage The ShaderStage to save
             * \param data        Memory to write to save the Resource
             * \param length      The length of the memory
             * \param parameters  Parameters to save the Resource
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToMemory(const ShaderStage* resource, void* data, Index length, const ShaderStageParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP
