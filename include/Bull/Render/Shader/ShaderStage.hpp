#ifndef BULL_RENDER_SHADER_SHADERSTAGE_HPP
#define BULL_RENDER_SHADER_SHADERSTAGE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Loader/Resource.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Shader/ShaderStageParameterBag.hpp>
#include <Bull/Render/Shader/ShaderStageType.hpp>

namespace Bull
{
    namespace prv
    {
        class BaseShaderStageSaver;
        class BaseShaderStageLoader;
    }

    class BULL_RENDER_API ShaderStage : public NonCopyable, public ContextResource, public Resource<ShaderStage, prv::BaseShaderStageSaver, prv::BaseShaderStageLoader, ShaderStageParameterBag>
    {
    public:

        /*! \brief Default constructor
         *
         */
        ShaderStage();

        /*! \brief Destructor
         *
         */
        ~ShaderStage();

        /*! \brief Create the shader
         *
         * \param type The type of shader to create
         *
         * \return True if the ShaderStage was created successfully
         *
         */
        bool create(ShaderStageType::ShaderStageType type);

        /*! \brief Load a ShaderStage from a Path
         *
         * \param path       The path
         * \param parameters Parameters to create the ShaderStage
         *
         * \return True if the ShaderStage was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) override;

        /*! \brief Load a ShaderStage from a Path
         *
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the ShaderStage
         *
         * \return True if the ShaderStage was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) override;

        /*! \brief Load a ShaderStage from a memory area
         *
         * \param data       The memory
         * \param length     The length of data
         * \param parameters Parameters to create the ShaderStage
         *
         * \return True if the ShaderStage was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) override;

        /*! \brief Save a ShaderStage to a file
         *
         * \param path       The Path to save the ShaderStage
         * \param parameters Parameters to save the ShaderStage
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        bool saveToPath(const Path& path, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) const override;

        /*! \brief Save a ShaderStage to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the ShaderStage
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        bool saveToStream(OutStream& stream, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) const override;

        /*! \brief Save a ShaderStage to a memory area
         *
         * \param data       Memory to write to save the ShaderStage
         * \param length     The length of the memory
         * \param parameters Parameters to save the ShaderStage
         *
         * \return True if the ShaderStage was saved successfully
         *
         */
        bool saveToMemory(void* data, Index length, const ShaderStageParameterBag& parameters = ShaderStageParameterBag()) const override;

        /*! \brief Compile the ShaderStage
         *
         * \param code The code of the ShaderStage
         *
         * \return True if the shader was compiled successfully
         *
         */
        bool compile(const String& code);

        /*! \brief Destroy the shader
         *
         */
        void destroy();

        /*! \brief Check whether a shader is compiled
         *
         * \return True if the shader is compiled
         *
         */
        bool isCompiled() const;

        /*! \brief Check if the shader is valid (e.g exists in the GPU's memory)
         *
         * \return True if the shader is valid
         *
         */
        bool isValid() const;

        /*! \brief Get the source code of the shader
         *
         * \return The source code
         *
         */
        String getSource() const;

        /*! \brief Get the type of the shader
         *
         * \return The type
         *
         */
        ShaderStageType::ShaderStageType getType() const;

        /*! \brief Get the ShaderStage system handler
         *
         * \return The native ShaderStage system handler
         *
         */
        unsigned int getSystemHandler() const;

    protected:

        /*! \brief Get the current error message of the shader
         *
         * \return The error message
         *
         */
        String getErrorMessage() const;

    private:

        unsigned int                     m_id;         /*!< The OpenGL shader handler */
        ShaderStageType::ShaderStageType m_type;       /*!< The shader type */
        bool                             m_isCompiled; /*!< Does the shader is compiled? */
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGE_HPP
