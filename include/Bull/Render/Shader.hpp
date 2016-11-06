#ifndef Bull_Shader_hpp
#define Bull_Shader_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/OpenGL.hpp>

namespace Bull
{
    class Shader : public NonCopyable, ContextResource
    {
    public:

        enum Type
        {
            Vertex   = GL_VERTEX_SHADER,
            Fragment = GL_FRAGMENT_SHADER
        };

        /*! \brief Bind a shader
         *
         * \param shader The shader to bind
         *
         */
        static void bind(const Shader& shader);

        /*! \brief Unbind any shader
         *
         */
        static void unbind();

    private:

        /*! \brief Create a shader
         *
         * \param code  The source of the shader
         * \param type  The type of shader
         * \param error A string to store an error
         *
         * \return Return the handler of the created shader
         *
         */
        static GLuint createShader(const String& code, Type type, String* error = nullptr);

        /*! \brief Check whether a shader has an error
         *
         * \param shader The shader to check
         * \param type   The type of error to look for
         * \param error  A string to store an error
         *
         * \return Return true if the shader had an error, false otherwise
         *
         */
        static bool shaderHasError(GLuint shader, GLenum type, String* error = nullptr);

        /*! \brief Check whether a program has an error
         *
         * \param program The program to check
         * \param type    The type of error to look for
         * \param error   A string to store an error
         *
         * \return Return true if the program had an error, false otherwise
         *
         */
        static bool programHasError(GLuint program, GLenum type, String* error = nullptr);

    public:

        /*! \brief Default constructor
         *
         */
        Shader();

        /*! \brief Destructor
         *
         */
        ~Shader();

        /*! \brief Load a shader from a string
         *
         * \param source The source of the shader
         * \param type   The type of shader to load
         * \param error  A string to store an error
         *
         * \return Return true if the shader was loaded successfully, false otherwise
         *
         */
        bool loadFromSource(const String& source, Type type, String* error = nullptr);

        /*! \brief Load a shader from a file
         *
         * \param path  The path to the shader source file
         * \param type  The type of shader to load
         * \param error A string to store an error
         *
         * \return Return true if the shader was loaded successfully, false otherwise
         *
         */
        bool loadFromPath(const String& path, Type type, String* error = nullptr);

        /*! \brief Load a shader from a stream
         *
         * \param path  The stream to read to get the shader source
         * \param type  The type of shader to load
         * \param error A string to store an error
         *
         * \return Return true if the shader was loaded successfully, false otherwise
         *
         */
        bool loadFromStream(InStream& stream, Type type, String* error = nullptr);

        /*! \brief Get the native system handler
         *
         * \return Return the handler
         *
         */
        unsigned int getSystemHandler() const;

    private:

        GLuint m_program;
    };
}

#endif // Bull_Shader_hpp
