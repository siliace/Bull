#ifndef BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP

#include <Bull/Render/Shader/AbstractShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        struct BaseShaderStageLoader : public AbstractShaderStageLoader
        {
            /*! \brief Tell whether a file extension is supported
             *
             * \param extension The extension
             *
             * \return True if the extension is supported
             *
             */
            bool isSupportedExtension(const String& extension) const override;

            /*! \brief Load a ShaderStage from a Path
             *
             * \param resource   The ShaderStage to load
             * \param path       The path
             * \param parameters Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromPath(std::unique_ptr<ShaderStage>& resource, const Path& path, const ParameterBag& parameters) const override;

            /*! \brief Load a ShaderStage from a Path
             *
             * \param resource   The ShaderStage to load
             * \param stream     The stream to read to load
             * \param parameters Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromStream(std::unique_ptr<ShaderStage>& resource, InStream& stream, const ParameterBag& parameters) const override;

            /*! \brief Load a ShaderStage from a memory area
             *
             * \param resource   The ShaderStage to load
             * \param data       The memory
             * \param length     The length of data
             * \param parameters Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool loadFromMemory(std::unique_ptr<ShaderStage>& resource, const void* data, Index length, const ParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_BASESHADERSTAGELOADER_HPP
