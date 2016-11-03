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
        GLint  success;
        const char* source = static_cast<const char*>(code);

        shader = gl::createShader(type);
        gl::shaderSource(shader, 1, &source, nullptr);
        gl::compileShader(shader);

        gl::getShaderiv(shader, GL_COMPILE_STATUS, &success);

        if(!success)
        {
            GLchar info[512];
            gl::getShaderInfoLog(shader, 512, nullptr, info);

            if(error)
            {
                (*error) = info;
            }
            else
            {
                Log::get()->warning(info);
            }
        }

        return shader;
    }

    /*! \brief Default constructor
     *
     */
    Shader::Shader() :
        m_program(0)
    {
        /// Nothing
    }

    /*! \brief Destructor
     *
     */
    Shader::~Shader()
    {
        if(m_program)
        {
            gl::deleteProgram(m_program);
        }
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
