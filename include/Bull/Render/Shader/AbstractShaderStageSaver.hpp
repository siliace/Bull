#ifndef BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP

#include <Bull/Core/Loader/AbstractResourceSaver.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    struct BULL_RENDER_API AbstractShaderStageSaver : public AbstractResourceSaver<ShaderStage>
    {
        /*! \brief Tell whether a file extension is supported
         *
         * \param extension The extension
         *
         * \return True if the extension is supported
         *
         */
        virtual bool isSupportedExtension(const String& extension) const = 0;

        /*! \brief Save a ShaderStage to a file
         *
         * \param resource The ShaderStage to save
         * \param path     The Path to save the Resource
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        virtual bool saveToPath(const ShaderStage& resource, const Path& path) const = 0;

        /*! \brief Save a ShaderStage to a stream
         *
         * \param resource The ShaderStage to save
         * \param stream
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        virtual bool saveToStream(const ShaderStage& resource, OutStream& stream) const = 0;

        /*! \brief Save a ShaderStage to a memory area
         *
         * \param resource The ShaderStage to save
         * \param data
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        virtual bool saveToMemory(const ShaderStage& resource, void* data, Index length) const = 0;
    };
}

#endif // BULL_RENDER_SHADER_ABSTRACTSHADERSTAGESAVER_HPP
