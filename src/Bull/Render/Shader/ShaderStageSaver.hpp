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
             * \param image      The ShaderStage to save
             * \param path       The Path of the File to write
             * \param parameters Parameters to use to save the ShaderStage
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToPath(const ShaderStage* shaderStage, const Path& path, const ShaderStageParameters& parameters) const override;

            /*! \brief Save a ShaderStage to stream
             *
             * \param image      The ShaderStage to save
             * \param stream     The stream to write
             * \param parameters Parameters to use to save the ShaderStage
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToStream(const ShaderStage* shaderStage, OutStream& stream, const ShaderStageParameters& parameters) const override;
            
            /*! \brief Save a ShaderStage to a memory area
             *
             * \param image      The ShaderStage to save
             * \param data       Data to write
             * \param length     The length of data
             * \param parameters Parameters to use to save the ShaderStage
             *
             * \return True if the ShaderStage was saved successfully
             *
             */
            bool saveToMemory(const ShaderStage* shaderStage, void* data, std::size_t length, const ShaderStageParameters& parameters) const override;

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
