#ifndef BULL_RENDER_SHADER_SHADERSTAGESAVER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGESAVER_HPP

#include <Bull/Core/Resource/AbstractResourceSaver.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    namespace prv
    {
        struct ShaderStageSaver : public AbstractResourceSaver<ShaderStage, ShaderStageParameters>
        {
            /*! \brief Save a ShaderStage to path
             *
             * \param resource
             * \param path
             * \param parameters
             *
             * \return
             *
             */
            bool saveToPath(const ShaderStage* resource, const Path& path, const ShaderStageParameters& parameters) const override;

            /*! \brief Save a ShaderStage to stream
             *
             * \param resource
             * \param stream
             * \param parameters
             *
             * \return
             *
             */
            bool saveToStream(const ShaderStage* resource, OutStream& stream, const ShaderStageParameters& parameters) const override;

            /*! \brief Save a ShaderStage to a memory area
             *
             * \param resource
             * \param data
             * \param length
             * \param parameters
             *
             * \return
             *
             */
            bool saveToMemory(const ShaderStage* resource, void* data, Index length, const ShaderStageParameters& parameters) const override;

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

#endif // BULL_RENDER_SHADER_SHADERSTAGESAVER_HPP
