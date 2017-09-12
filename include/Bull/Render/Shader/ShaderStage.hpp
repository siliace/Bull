#ifndef BULL_RENDER_SHADER_SHADERSTAGE_HPP
#define BULL_RENDER_SHADER_SHADERSTAGE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/NonCopyable.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Context/ContextResource.hpp>

namespace Bull
{
    class BULL_RENDER_API ShaderStage : public NonCopyable, public ContextResource
    {
    public:

        enum Type : unsigned int
        {
            Vertex   = GL_VERTEX_SHADER,
            Fragment = GL_FRAGMENT_SHADER,
            Geometry = GL_GEOMETRY_SHADER,
        };

    public:

        /*! \brief Default constructor
         *
         */
        ShaderStage();

        /*! \brief Constructor
         *
         * \param type The type of shader to create
         *
         */
        explicit ShaderStage(Type type);

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
        bool create(Type type);

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
        Type getType() const;

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

        unsigned int m_id;         /*!< The OpenGL shader handler */
        Type         m_type;       /*!< The shader type */
        bool         m_isCompiled; /*!< Does the shader is compiled? */
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGE_HPP
