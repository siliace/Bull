#ifndef BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP

#include <Bull/Render/Shader/AbstractShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        struct BaseShaderStageSaver : public AbstractShaderStageSaver
        {
            /*! \brief Tell whether a file extension is supported
             *
             * \param extension The extension
             *
             * \return True if the extension is supported
             *
             */
            bool isSupportedExtension(const String& extension) const override;

            /*! \brief Save a ShaderStage to a file
             *
             * \param resource The ShaderStage to save
             * \param path     The Path to save the Resource
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToPath(const ShaderStage& resource, const Path& path) const override;

            /*! \brief Save a ShaderStage to a stream
             *
             * \param resource The ShaderStage to save
             * \param stream
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToStream(const ShaderStage& resource, OutStream& stream) const override;

            /*! \brief Save a ShaderStage to a memory area
             *
             * \param resource The ShaderStage to save
             * \param data
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToMemory(const ShaderStage& resource, void* data, Index length) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP
