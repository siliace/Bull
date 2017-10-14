#ifndef BULL_RENDER_SHADER_SHADERSTAGE_HPP
#define BULL_RENDER_SHADER_SHADERSTAGE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Resource/ResourceLoader.hpp>
#include <Bull/Core/Resource/ResourceSaver.hpp>
#include <Bull/Core/Resource/Resource.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/Export.hpp>
#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Shader/ShaderStageParameters.hpp>

namespace Bull
{
    class BULL_RENDER_API ShaderStage : public NonCopyable, public ContextResource, public Resource<ShaderStageParameters>
    {
    public:

        using Saver = ResourceSaver<ShaderStage, ShaderStageParameters>;
        using Loader = ResourceLoader<ShaderStage, ShaderStageParameters>;

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
        
        /*! \brief Load a Resource from a Path
         *
         * \param path       The Path of the file to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ShaderStageParameters& parameters) override;

        /*! \brief Load a Resource from an InStream
         *
         * \param stream     The stream to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ShaderStageParameters& parameters) override;

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory area to read
         * \param length     The length of the memory area
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ShaderStageParameters& parameters) override;

        /*! \brief Save the Resource to a Path
         *
         * \param path       The path of the
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToPath(const Path& path, const ShaderStageParameters& parameters) const override;

        /*! \brief Save the Resource to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToStream(OutStream& stream, const ShaderStageParameters& parameters) const override;

        /*! \brief Save the Resource to a Path
         *
         * \param data       The memory to write
         * \param length     The length of the memory area
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToMemory(void* data, Index length, const ShaderStageParameters& parameters) const override;
        
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
