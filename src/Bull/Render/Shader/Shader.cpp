#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/LogicError.hpp>
#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Shader/Shader.hpp>
#include <Bull/Render/Shader/ShaderStageLoader.hpp>

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
        Expect(gl::isProgram(m_program), Throw(InternalError, "Failed to create shader"));
    }
    
    Shader::Shader(Shader&& right) noexcept
    {
        std::swap(m_program, right.m_program);
    }

    Shader::~Shader()
    {
        gl::deleteProgram(m_program);
    }

    Shader& Shader::operator=(Shader&& right) noexcept
    {
        std::swap(m_program, right.m_program);

        return *this;
    }

    void Shader::create(const ShaderBinary& shaderBinary) const
    {
        Expect(shaderBinary.isValid(), Throw(InvalidParameter, "Invalid shader binary"));

        gl::programBinary(m_program, shaderBinary.format, shaderBinary.content.getBuffer(), shaderBinary.content.getCapacity());
    }

    void Shader::attach(const ShaderStage& stage) const
    {
        Expect(stage.isValid(), Throw(InvalidParameter, "Can't attach invalid ShaderStage"));
        Expect(stage.isCompiled(), Throw(InvalidParameter, "Can't attach non compiled ShaderStage"));

        gl::attachShader(m_program, stage.getSystemHandler());
    }

    void Shader::link() const
    {
        gl::linkProgram(m_program);

        Expect(isLinked(), Throw(InternalError, "Failed to link shader"));
    }

    void Shader::bind() const
    {
        gl::useProgram(m_program);
    }

    bool Shader::isLinked() const
    {
        int status = 0;
        gl::getProgramiv(m_program, GL_LINK_STATUS, &status);

        return status == GL_TRUE;
    }

    void Shader::setUniform(const String& name, int uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform1i)
        {
            gl::programUniform1i(m_program, location, uniform);
        }
        else
        {
            bind();

            gl::uniform1i(location, uniform);
        }
    }

    void Shader::setUniform(const String& name, unsigned int uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform1i)
        {
            gl::programUniform1i(m_program, location, uniform);
        }
        else
        {
            bind();

            gl::uniform1i(location, uniform);
        }
    }

    void Shader::setUniform(const String& name, float uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform1i)
        {
            gl::programUniform1f(m_program, location, uniform);
        }
        else
        {
            bind();

            gl::uniform1f(location, uniform);
        }
    }

    void Shader::setUniformColor(const String& name, const Color& uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

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
    }

    void Shader::setUniformVector(const String& name, const Vector<float, 2>& uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform2f)
        {
            gl::programUniform2f(m_program, location, uniform.at(0), uniform.at(1));
        }
        else
        {
            bind();

            gl::uniform2f(location, uniform.at(0), uniform.at(1));
        }
    }

    void Shader::setUniformVector(const String& name, const Vector<float, 3>& uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform3f)
        {
            gl::programUniform3f(m_program, location, uniform.at(0), uniform.at(1), uniform.at(2));
        }
        else
        {
            bind();

            gl::uniform3f(location, uniform.at(0), uniform.at(1), uniform.at(2));
        }
    }

    void Shader::setUniformVector(const String& name, const Vector<float, 4>& uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniform4f)
        {
            gl::programUniform4f(m_program, location, uniform.at(0), uniform.at(1), uniform.at(2), uniform.at(3));
        }
        else
        {
            bind();

            gl::uniform4f(location, uniform.at(0), uniform.at(1), uniform.at(2), uniform.at(3));
        }
    }

    void Shader::setUniformMatrix(const String& name, const Matrix4F& uniform) const
    {
        int location = getUniformLocation(name);

        #if defined BULL_SHADER_UNIFORM_STRICT
        Expect(location != -1, Throw(UniformVariableNotFound, "Uniform " + name + " not found"));
        #else
        if(location == -1)
        {
            return;
        }
        #endif

        if(gl::programUniformMatrix4fv)
        {
            gl::programUniformMatrix4fv(m_program, location, 1, true, uniform.getPtr());
        }
        else
        {
            bind();

            gl::uniformMatrix4fv(location, 1, true, uniform.getPtr());
        }
    }

    ShaderBinary Shader::getBinary() const
    {
        int length;
        ShaderBinary shaderBinary;

        Expect(isLinked(), Throw(LogicError, "Cannot get binary from a non linked shader"));

        gl::getProgramiv(m_program, GL_PROGRAM_BINARY_LENGTH, &length);

        shaderBinary.content.resize(length);

        gl::getProgramBinary(getSystemHandler(), length, nullptr, &shaderBinary.format, &shaderBinary.content[0]);

        Expect(shaderBinary.isValid(), Throw(InternalError, "Failed to download program binary"));

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

        message.setSize(static_cast<std::size_t>(capacity));
        gl::getProgramInfoLog(m_program, capacity, nullptr, &message[0]);

        return message;
    }

    int Shader::getUniformLocation(const String& name) const
    {
        return gl::getUniformLocation(m_program, name.getBuffer());
    }
}
