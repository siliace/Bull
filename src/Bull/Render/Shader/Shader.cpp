#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>

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

    bool Shader::create(const ShaderBinary& shaderBinary)
    {
        if(shaderBinary.isValid())
        {
            gl::programBinary(m_program, shaderBinary.format, shaderBinary.binary.getBuffer(), shaderBinary.binary.getCapacity());

            return true;
        }

        return false;
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
        if(isValid())
        {
            gl::linkProgram(m_program);

            if(!isLinked())
            {
                Log::get()->write(getErrorMessage(), LogLevel::LogLevel_Error);

                return false;
            }

            return true;
        }

        return false;
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

    bool  Shader::setUniform(const String& name, unsigned int uniform)
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

    bool Shader::setUniform(const String& name, float uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform1i)
        {
            gl::programUniform1f(m_program, location, uniform);
        }
        else
        {
            bind();

            gl::uniform1f(location, uniform);
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

    bool Shader::setUniformVector(const String& name, const Vector<float, 2>& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform2f)
        {
            gl::programUniform2f(m_program, location, uniform.at(0), uniform.at(1));
        }
        else
        {
            bind();

            gl::uniform2f(location, uniform.at(0), uniform.at(1));
        }

        return true;
    }

    bool Shader::setUniformVector(const String& name, const Vector<float, 3>& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform3f)
        {
            gl::programUniform3f(m_program, location, uniform.at(0), uniform.at(1), uniform.at(2));
        }
        else
        {
            bind();

            gl::uniform3f(location, uniform.at(0), uniform.at(1), uniform.at(2));
        }

        return true;
    }

    bool Shader::setUniformVector(const String& name, const Vector<float, 4>& uniform)
    {
        int location = getUniformLocation(name);

        if(location == -1)
        {
            return false;
        }

        if(gl::programUniform4f)
        {
            gl::programUniform4f(m_program, location, uniform.at(0), uniform.at(1), uniform.at(2), uniform.at(3));
        }
        else
        {
            bind();

            gl::uniform4f(location, uniform.at(0), uniform.at(1), uniform.at(2), uniform.at(3));
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
            gl::programUniformMatrix4fv(m_program, location, 1, true, uniform.getPtr());
        }
        else
        {
            bind();

            gl::uniformMatrix4fv(location, 1, true, uniform.getPtr());
        }

        return true;
    }

    ShaderBinary Shader::getBinary() const
    {
        ShaderBinary shaderBinary;

        if(isValid() && isLinked())
        {
            int length;

            gl::getProgramiv(m_program,  GL_PROGRAM_BINARY_LENGTH, &length);

            if(length)
            {
                shaderBinary.binary.create(length);

                gl::getProgramBinary(getSystemHandler(), length, nullptr, &shaderBinary.format, &shaderBinary.binary[0]);

                if(!shaderBinary.isValid())
                {
                    throw RuntimeError("Failed to download program binary");
                }
            }
        }

        return shaderBinary;
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
            message.setSize(static_cast<std::size_t>(capacity));
            gl::getProgramInfoLog(m_program, capacity, nullptr, &message[0]);
        }

        return message;
    }

    int Shader::getUniformLocation(const String& name)
    {
        return gl::getUniformLocation(m_program, name.getBuffer());
    }
}
