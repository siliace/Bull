#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader/Shader.hpp>

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
        /// Nothing
    }

    Shader::~Shader()
    {
        if(isValid())
        {
            gl::deleteProgram(m_program);
        }
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

    bool Shader::attachFromPath(const Path& path, ShaderStage::Type type)
    {
        ShaderStage stage(path, type);

        if(stage.compile())
        {
            return attach(stage);
        }

        return false;

    }

    bool Shader::attachFromCode(const String& code, ShaderStage::Type type)
    {
        ShaderStage stage(code, type);

        if(stage.compile())
        {
            return attach(stage);
        }

        return false;
    }

    bool Shader::attachFromStream(InStream& stream, ShaderStage::Type type)
    {
        ShaderStage stage(stream, type);

        if(stage.compile())
        {
            return attach(stage);
        }

        return false;
    }

    bool Shader::link()
    {
        gl::linkProgram(m_program);

        if(!isLinked())
        {
            Log::get()->write(getErrorMessage(), Log::Level::Error);

            return false;
        }

        return true;
    }

    void Shader::bind() const
    {
        if(isValid())
        {
            gl::useProgram(m_program);
        }
    }

    bool Shader::isValid() const
    {
        return gl::isProgram(m_program) == GL_TRUE;
    }

    bool Shader::isLinked() const
    {
        int status = 0;
        gl::getProgramiv(m_program, GL_LINK_STATUS, &status);

        return status == GL_TRUE;
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

    bool Shader::setUniformColor(const String& name, const Color& uniform)
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

    bool Shader::setUniformVector(const String& name, const Vector2F& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform2fv)
        {
            gl::programUniform2fv(m_program, location, 2, &uniform.x);
        }
        else
        {
            bind();

            gl::uniform2fv(location, 1, &uniform.x);
        }

        return true;
    }

    bool Shader::setUniformVector(const String& name, const Vector3F& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform3fv)
        {
            gl::programUniform3fv(m_program, location, 3, &uniform.x);
        }
        else
        {
            bind();

            gl::uniform3fv(location, 1, &uniform.x);
        }

        return true;
    }

    bool Shader::setUniformVector(const String& name, const Vector4F& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform4fv)
        {
            gl::programUniform4fv(m_program, location, 4, &uniform.x);
        }
        else
        {
            bind();

            gl::uniform4fv(location, 1, &uniform.x);
        }

        return true;
    }

    bool Shader::setUniformMatrix(const String& name, const Matrix4F& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniformMatrix4fv)
        {
            gl::programUniformMatrix4fv(m_program, location, 1, GL_FALSE, uniform);
        }
        else
        {
            bind();

            gl::uniformMatrix4fv(location, 1, GL_FALSE, uniform);
        }

        return true;
    }

    unsigned int Shader::getSystemHandler() const
    {
        return m_program;
    }

    String Shader::getErrorMessage() const
    {
        int capacity;
        String message;

        gl::getProgramiv(m_program, GL_INFO_LOG_LENGTH, &capacity);

        if(capacity)
        {
            message.setSize(static_cast<Index>(capacity));
            gl::getProgramInfoLog(m_program, capacity, nullptr, &message[0]);
        }

        return message;
    }

    int Shader::getUniformLocation(const String& name)
    {
        return gl::getUniformLocation(m_program, name.getBuffer());
    }
}
