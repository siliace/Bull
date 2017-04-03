#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader.hpp>

namespace Bull
{
    unsigned int Shader::getMaxVertexAttribs()
    {
        int count;

        ensureContext();

        gl::getIntegerv(GL_MAX_VERTEX_ATTRIBS, &count);

        return static_cast<unsigned int>(count);
    }

    Shader::Shader() :
        m_program(gl::createProgram())
    {
        if(m_program == 0)
        {
            throw std::runtime_error("Failed to create program");
        }
    }

    Shader::~Shader()
    {
        gl::deleteProgram(m_program);
    }

    bool Shader::attach(const ShaderStage& stage)
    {
        if(stage.isValid() && stage.isCompiled())
        {
            gl::attachShader(m_program, stage.getSystemHandler());

            return true;
        }

        return false;
    }

    bool Shader::link()
    {
        gl::linkProgram(m_program);

        if(hasError())
        {
            StringStream ss;

            ss << String::number(getErrorCode()) << getErrorMessage();

            Log::get()->write(ss.toString(), Log::Level::Error);

            return false;
        }

        return true;
    }

    void Shader::bind() const
    {
        gl::useProgram(m_program);
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
            bind();
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
            bind();
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
            bind();
            gl::uniformMatrix4fv(location, 1, true, uniform);
        }

        return true;
    }

    unsigned int Shader::getSystemHandler() const
    {
        return m_program;
    }

    bool Shader::hasError() const
    {
        return getErrorCode() == 0;
    }

    unsigned int Shader::getErrorCode() const
    {
        int code = 0;
        gl::getProgramiv(m_program, GL_LINK_STATUS, &code);

        return static_cast<unsigned int>(code);
    }

    String Shader::getErrorMessage() const
    {
        if(hasError())
        {
            int capacity;
            String message;

            gl::getProgramiv(m_program, GL_INFO_LOG_LENGTH, &capacity);

            message.reserve(capacity);

            gl::getProgramInfoLog(m_program, capacity, nullptr, &message[0]);

            return message;
        }

        return String();
    }

    int Shader::getUniformLocation(const String& name)
    {
        return gl::getUniformLocation(m_program, name);
    }
}
