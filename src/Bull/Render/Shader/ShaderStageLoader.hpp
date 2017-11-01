#ifndef BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP

#include <Bull/Core/Resource/AbstractResourceLoader.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    namespace prv
    {
        struct ShaderStageLoader : public AbstractResourceLoader<ShaderStage, ShaderStageParameters>
        {
            /*! \brief Load an ShaderStageLoader from a Path
             *
             * \param shaderStage The ShaderStageLoader to load
             * \param path        The Path of the File to read
             * \param parameters  Parameters to use to load the ShaderStageLoader
             *
             * \return True if the ShaderStageLoader was loaded successfully
             *
             */
            bool loadFromPath(ShaderStage* shaderStage, const Path& path, const ShaderStageParameters& parameters) const override;

            /*! \brief Load an ShaderStage from a stream
             *
             * \param shaderStage The ShaderStage to load
             * \param stream      The stream to read
             * \param parameters  Parameters to use to load the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromStream(ShaderStage* shaderStage, InStream& stream, const ShaderStageParameters& parameters) const override;

            /*! \brief Load an ShaderStage from a memory area
             *
             * \param shaderStage The ShaderStage to load
             * \param data        Data to read
             * \param length      The length of data
             * \param parameters  Parameters to use to load the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromMemory(ShaderStage* shaderStage, const void* data, std::size_t length, const ShaderStageParameters& parameters) const override;

            /*! \brief Tell whether the extension is supported
             *
             * \param extension The extension to check
             *
             * \return True if the extension is supported
             *
             */
            bool isFormatSupported(const String& extension) const override;

            /*! \brief Tell whether parameters are supported
             *
             * \param parameters Parameters to check
             *
             * \return True if the parameters are supported
             *
             */
            bool isParametersSupported(const ShaderStageParameters& parameters) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
