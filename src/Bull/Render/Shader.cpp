#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log.hpp>

#include <Bull/Render/Context/ShaderStateSaver.hpp>
#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader.hpp>

namespace Bull
{
    void Shader::bind(const Shader* shader)
    {
        gl::useProgram(shader->getSystemHandler());
    }

    void Shader::unbind()
    {
        gl::useProgram(0);
    }

    unsigned int Shader::getMaxVertexAttribs()
    {
        int count;

        gl::getIntegerv(GL_MAX_VERTEX_ATTRIBS, &count);

        return static_cast<unsigned int>(count);
    }

    GLuint Shader::createShader(const String& code, Type type, String* error)
    {
        GLuint shader = 0;

        const char* source = static_cast<const char*>(code);

        shader = gl::createShader(type);
        gl::shaderSource(shader, 1, &source, nullptr);
        gl::compileShader(shader);

        return shaderHasError(shader, GL_COMPILE_STATUS, error) ? shader : 0;
    }

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

            Log::get()->write(info, Log::Level::Warning);
        }

        return success;
    }

    bool Shader::programHasError(GLuint program, GLenum type, String* error)
    {
        GLint success;
        gl::getProgramiv(program, type, &success);

        if(!success)
        {
            GLchar info[512];
            gl::getProgramInfoLog(program, 512, nullptr, info);

            if(error)
            {
                error->set(info);
            }

            Log::get()->write(info, Log::Level::Warning);
        }

        return success;
    }

    Shader::Shader() :
        m_program(gl::createProgram())
    {
        /// Nothing
    }

    Shader::Shader(const String& vertex, const String& fragment, const String& geometry) :
        Shader()
    {
        loadFromSource(vertex, Shader::Vertex);
        loadFromSource(fragment, Shader::Fragment);
        loadFromSource(geometry, Shader::Geometry);
    }

    Shader::Shader(const Path& pathVertex, const Path& pathFragment, const Path& pathGeometry) :
        Shader()
    {
        loadFromPath(pathVertex,   Shader::Vertex);
        loadFromPath(pathFragment, Shader::Fragment);
        loadFromPath(pathGeometry, Shader::Geometry);
    }

    Shader::~Shader()
    {
        if(gl::isProgram(m_program))
        {
            gl::deleteProgram(m_program);
        }
    }

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

    bool Shader::loadFromPath(const Path& path, Type type, String* error)
    {
        File shaderFile(path, File::Read);

        if(shaderFile)
        {
            return loadFromStream(shaderFile, type, error);
        }

        return false;
    }

    bool Shader::loadFromStream(InStream& stream, Type type, String* error)
    {
        return loadFromSource(stream.readAll(), type, error);
    }

    bool Shader::setUniform(const String& name, int uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform1i)
        {
            gl::programUniform1i(m_program, location, uniform);
        }
        else
        {
            ShaderStateSaver saver;
            gl::useProgram(m_program);
            gl::uniform1i(location, uniform);
        }

        return true;
    }

    bool Shader::setUniform(const String& name, const Color& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform4f)
        {
            gl::programUniform4f(m_program, location,
                                 static_cast<float>(uniform.red)   / 255.f,
                                 static_cast<float>(uniform.green) / 255.f,
                                 static_cast<float>(uniform.blue)  / 255.f,
                                 static_cast<float>(uniform.alpha) / 255.f);
        }
        else
        {
            ShaderStateSaver saver;
            gl::useProgram(m_program);
            gl::uniform4f(location,
                          static_cast<float>(uniform.red)   / 255.f,
                          static_cast<float>(uniform.green) / 255.f,
                          static_cast<float>(uniform.blue)  / 255.f,
                          static_cast<float>(uniform.alpha) / 255.f);
        }

        return true;
    }

    bool Shader::setUniform(const String& name, const Matrix4F& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform4f)
        {
            gl::programUniformMatrix4fv(m_program, location, 1, true, uniform);
        }
        else
        {
            ShaderStateSaver saver;
            gl::useProgram(m_program);
            gl::uniformMatrix4fv(location, 1, true, uniform);
        }

        return true;
    }

    unsigned int Shader::getSystemHandler() const
    {
        return m_program;
    }

    int Shader::getUniformLocation(const String& name)
    {
        return gl::getUniformLocation(m_program, name);
    }
}
