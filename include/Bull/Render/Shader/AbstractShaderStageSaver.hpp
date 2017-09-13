#ifndef BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>
#include <Bull/Render/Shader/ShaderStageParameters.hpp>

namespace Bull
{
    struct BULL_RENDER_API AbstractShaderStageSaver : public AbstractResourceSaver<ShaderStage, ShaderStageParameters>
    {
        /*! \brief Tell whether a file extension is supported
         *
         * \param extension The extension
         *
         * \return True if the extension is supported
         *
         */
        virtual bool isSupportedExtension(const String& extension) const = 0;

        /*! \brief Load a ShaderStage from a Path
         *
         * \param resource   The ShaderStage to load
         * \param path       The path
         * \param parameters Parameters to create the ShaderStage
         *
         * \return True if the ShaderStage was loaded successfully
         *
         */
        virtual bool saveToPath(const ShaderStage& resource, const Path& path, const ShaderStageParameters& parameters) const = 0;

        /*! \brief Load a ShaderStage from a Path
         *
         * \param resource   The ShaderStage to load
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the ShaderStage
         *
         * \return True if the ShaderStage was loaded successfully
         *
         */
        virtual bool saveToStream(const ShaderStage& resource, OutStream& stream, const ShaderStageParameters& parameters) const = 0;

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
        virtual bool saveToMemory(const ShaderStage& resource, void* data, Index length, const ShaderStageParameters& parameters) const = 0;
    };
}

#endif // BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
