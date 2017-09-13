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

            /*! \brief Load a ShaderStage from a Path
             *
             * \param resource   The ShaderStage to load
             * \param path       The path
             * \param parameters Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool saveToPath(const ShaderStage& resource, const Path& path, const ShaderStageParameters& parameters) const override;

            /*! \brief Load a ShaderStage from a Path
             *
             * \param resource   The ShaderStage to load
             * \param stream     The stream to read to load
             * \param parameters Parameters to create the ShaderStage
             *
             * \return True if the ShaderStage was loaded successfully
             *
             */
            bool saveToStream(const ShaderStage& resource, OutStream& stream, const ShaderStageParameters& parameters) const override;

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
            bool saveToMemory(const ShaderStage& resource, void* data, Index length, const ShaderStageParameters& parameters) const override;
        };
    }
}

#endif // BULL_RENDER_SHADER_BASESHADERSTAGESAVER_HPP
