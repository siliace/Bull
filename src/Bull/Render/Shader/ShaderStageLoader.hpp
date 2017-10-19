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
            /*! \brief Save a Resource to path
             *
             * \param resource
             * \param path
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromPath(ShaderStage* resource, const Path& path, const ShaderStageParameters& parameters) const override;

            /*! \brief Save a Resource to stream
             *
             * \param resource
             * \param stream
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromStream(ShaderStage* resource, InStream& stream, const ShaderStageParameters& parameters) const override;

            /*! \brief Save a Resource to a memory area
             *
             * \param resource
             * \param data
             * \param length
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromMemory(ShaderStage* resource, const void* data, Index length, const ShaderStageParameters& parameters) const override;

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
