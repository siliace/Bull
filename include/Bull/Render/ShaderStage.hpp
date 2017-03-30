#ifndef BULL_SHADERSTAGE_HPP
#define BULL_SHADERSTAGE_HPP

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/Memory/MemoryBuffer.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/OpenGL.hpp>

#include <Bull/Window/ContextResource.hpp>

namespace Bull
{
    class BULL_API ShaderStage : public NonCopyable, public ContextResource
    {
    public:

        enum Type
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
         * @param type The type of shader to create
         *
         */
        ShaderStage(Type type);

        /*! \brief Constructor
         *
         * @param stage
         *
         */
        ShaderStage(ShaderStage&& stage);

        /*! \brief Destructor
         *
         */
        ~ShaderStage();

        /*! \brief Basic assignment operator
         *
         * @param stage
         *
         * @return This
         *
         */
        ShaderStage& operator=(ShaderStage&& stage);

        /*! \brief Create the shader
         *
         * @param type The type of shader to create
         *
         * @return True if the shader was created successfully
         *
         */
        bool create(Type type);

        /*! \brief Load a shader from a file
         *
         * @param path The path to the file
         *
         * @return True if the shader was loaded successfully
         *
         */
        bool loadFromPath(const Path& path);

        /*! \brief Load a shader from a String
         *
         * @param code The code of the shader
         *
         * @return True if the shader was loaded successfully
         *
         */
        bool loadFromCode(const String& code);

        /*! \brief Load a shader from an InStream
         *
         * @param code The InStream which contains the code
         *
         * @return True if the shader was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream);

        /*! \brief Compile the shader
         *
         * @return True if the shader was compiled successfully
         *
         */
        bool compile();

        /*! \brief Destroy the shader
         *
         */
        void destroy();

        /*! \brief Check whether a shader is compiled
         *
         * @return True if the shader is compiled
         *
         */
        bool isCompiled() const;

        /*! \brief Check if the shader is valid (e.g exists in the GPU's memory)
         *
         * @return True if the shader is valid
         *
         */
        bool isValid() const;

        /*! \brief Get the type of the shader
         *
         * @return The type
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

        /*! \brief Check if the shader as an error
         *
         * @return True if the shader has an error
         *
         */
        bool hasError() const;

        /*! \brief Get the current error code of the shader
         *
         * @return The error code
         *
         */
        unsigned int getErrorCode() const;

        /*! \brief Get the current error message of the shader
         *
         * @return The error message
         *
         */
        String getErrorMessage() const;

    private:

        unsigned int m_id;         /*!< The OpenGL shader handler */
        Type         m_type;       /*!< The shader type */
        bool         m_isCompiled; /*!< Does the shader is compiled? */
    };
}

#endif //BULL_SHADERSTAGE_HPP
