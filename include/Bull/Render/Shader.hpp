#ifndef Bull_Shader_hpp
#define Bull_Shader_hpp

#include <Bull/Core/Pattern/NonCopyable.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/String.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Render/Context/ContextResource.hpp>
#include <Bull/Render/Color.hpp>
#include <Bull/Render/Texture.hpp>

namespace Bull
{
    class Shader : public NonCopyable, ContextResource
    {
    public:

        enum Type
        {
            Vertex   = 0x8B31,
            Fragment = 0x8B30
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

        /*! \brief Get the maximum vertex attributes available
         *
         * \return Return the max
         *
         */
        static unsigned int getMaxVertexAttribs();

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
        static unsigned int createShader(const String& code, Type type, String* error = nullptr);

        /*! \brief Check whether a shader has an error
         *
         * \param shader The shader to check
         * \param type   The type of error to look for
         * \param error  A string to store an error
         *
         * \return Return true if the shader had an error, false otherwise
         *
         */
        static bool shaderHasError(unsigned int shader, unsigned int type, String* error = nullptr);

        /*! \brief Check whether a program has an error
         *
         * \param program The program to check
         * \param type    The type of error to look for
         * \param error   A string to store an error
         *
         * \return Return true if the program had an error, false otherwise
         *
         */
        static bool programHasError(unsigned int program, unsigned int type, String* error = nullptr);

    public:

        /*! \brief Default constructor
         *
         */
        Shader();

        /*! \brief Constructor
         *
         * \param pathVertex   The path to the vertex shader source
         * \param pathFragment The path to the vertex fragment source
         *
         */
        Shader(const String& pathVertex, const String& pathFragment);

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

        bool setUniform(const String& name, int uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, const Color& uniform);

        /*! \brief Set an uniform variable
         *
         * \param name    The name of the uniform variable in the shader
         * \param uniform The value to set to the uniform variable
         *
         * \return Return true if the uniform variable was found, false otherwise
         *
         */
        bool setUniform(const String& name, const Matrix4F& uniform);

        /*! \brief Get the native system handler
         *
         * \return Return the handler
         *
         */
        unsigned int getSystemHandler() const;

    private:

        /*! \brief Get the location of an uniform variable
         *
         * \param name The name of the uniform variable in the shader
         *
         * \return Return the location of the uniform
         *
         */
        int getUniformLocation(const String& name);

        unsigned int m_program;
    };
}

#endif // Bull_Shader_hpp
