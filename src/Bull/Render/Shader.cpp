#include <Bull/Core/Log.hpp>

#include <Bull/Render/Shader.hpp>

namespace Bull
{
    /*! \brief Bind a shader
     *
     * \param shader The shader to bind
     *
     */
    void Shader::bind(const Shader& shader)
    {
        gl::useProgram(shader.getSystemHandler());
    }

    /*! \brief Unbind any shader
     *
     */
    void Shader::unbind()
    {
        gl::useProgram(0);
    }

    /*! \brief Create a shader
     *
     * \param code The source of the shader
     * \param type The type of shader
     * \param error A string to store an error
     *
     * \return Return the handler of the created shader
     *
     */
    GLuint Shader::createShader(const String& code, Type type, String* error)
    {
        GLuint shader = 0;

        const char* source = static_cast<const char*>(code);

        shader = gl::createShader(type);
        gl::shaderSource(shader, 1, &source, nullptr);
        gl::compileShader(shader);

        return shaderHasError(shader, GL_COMPILE_STATUS, error) ? shader : 0;
    }

    /*! \brief Check whether a shader has an error
     *
     * \param shader The shader to check
     * \param type   The type of error to look for
     * \param error  A string to store an error
     *
     * \return Return true if the shader had an error, false otherwise
     *
     */
    bool Shader::shaderHasError(GLuint shader, GLenum type, String* error)
    {
        GLint success;
        gl::getShaderiv(shader, type, &success);

        if(!success)
        {
            GLchar info[512];
            gl::getShaderInfoLog(shader, 512, nullptr, info);

            if(error)
            {
                error->set(info);
            }

            Log::get()->warning(info);
        }

        return success;
    }

    /*! \brief Check whether a program has an error
     *
     * \param program The program to check
     * \param type    The type of error to look for
     * \param error   A string to store an error
     *
     * \return Return true if the program had an error, false otherwise
     *
     */
    bool Shader::programHasError(GLuint program, GLenum type, String* error)
    {
        GLint success;
        gl::getProgramiv(program, GL_LINK_STATUS, &success);

        if(!success)
        {
            GLchar info[512];
            gl::getProgramInfoLog(program, 512, nullptr, info);

            if(error)
            {
                error->set(info);
            }

            Log::get()->warning(info);
        }

        return success;
    }

    /*! \brief Default constructor
     *
     */
    Shader::Shader() :
        m_program(gl::createProgram())
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    Shader::~Shader()
    {
        if(gl::isProgram(m_program))
        {
            gl::deleteProgram(m_program);
        }
    }

    /*! \brief Load a shader from a string
     *
     * \param source The source of the shader
     * \param type   The type of shader to load
     * \param error  A string to store an error
     *
     * \return Return true if the shader was loaded successfully, false otherwise
     *
     */
    bool Shader::loadFromSource(const String& source, Type type, String* error)
    {
        GLuint shader = createShader(source, type, error);

        if(!shader)
        {
            return false;
        }

        gl::attachShader(m_program, shader);
        gl::linkProgram(m_program);

        return programHasError(m_program, GL_LINK_STATUS, error);
    }

    /*! \brief Load a shader from a file
     *
     * \param path  The path to the shader source file
     * \param type  The type of shader to load
     * \param error A string to store an error
     *
     * \return Return true if the shader was loaded successfully, false otherwise
     *
     */
    bool Shader::loadFromPath(const String& path, Type type, String* error)
    {
        File shaderFile(path);

        if(!shaderFile.isOpen())
        {
            return false;
        }

        return loadFromStream(shaderFile, type, error);
    }

    /*! \brief Load a shader from a stream
     *
     * \param path  The stream to read to get the shader source
     * \param type  The type of shader to load
     * \param error A string to store an error
     *
     * \return Return true if the shader was loaded successfully, false otherwise
     *
     */
    bool Shader::loadFromStream(InStream& stream, Type type, String* error)
    {
        String code;
        String buffer;
        Uint64 read = 0;

        buffer.reserve(256);

        do
        {
            read = stream.read(&buffer[0], buffer.getCapacity());

            code += (read == buffer.getCapacity()) ? buffer : buffer.subString(0, read);
        }while(read == buffer.getCapacity());

        return loadFromSource(code, type, error);
    }

    /*! \brief Get the native system handler
     *
     * \return Return the handler
     *
     */
    unsigned int Shader::getSystemHandler() const
    {
        return m_program;
    }
}
