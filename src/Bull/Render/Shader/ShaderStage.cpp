#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    namespace
    {
        unsigned int shaderType[] = {GL_VERTEX_SHADER, GL_FRAGMENT_SHADER, GL_GEOMETRY_SHADER};
    }

    ShaderStage::ShaderStage() :
        m_id(0),
        m_isCompiled(false)
    {
        /// Nothing
    }

    ShaderStage::~ShaderStage()
    {
        destroy();
    }

    void ShaderStage::create(ShaderStageType type)
    {
        if(isValid())
        {
            destroy();
        }

        ensureContext();

        m_type = type;
        m_id   = gl::createShader(shaderType[type]);

        if(!isValid())
        {
            Throw(InternalError, "ShaderStage::create", "Failed to create ShaderStage");
        }
    }

    void ShaderStage::compile(const String& code)
    {
        const char* source = code.getBuffer();

        ensureContext();

        gl::shaderSource(m_id, 1, &source, nullptr);
        gl::compileShader(m_id);

        if(!isCompiled())
        {
            Throw(InternalError, "ShaderStage::compile", "Failed to compile ShaderStage");
        }

        m_isCompiled = true;
    }

    void ShaderStage::destroy()
    {
        ensureContext();

        gl::deleteShader(m_id);
    }

    bool ShaderStage::isCompiled() const
    {
        if(isValid())
        {
            int error = 0;

            ensureContext();

            gl::getShaderiv(m_id, GL_COMPILE_STATUS, &error);

            return error == GL_TRUE;
        }

        return false;
    }

    bool ShaderStage::isValid() const
    {
        ensureContext();

        return gl::isShader(m_id);
    }

    bool ShaderStage::isLoaded() const
    {
        return isCompiled();
    }

    String ShaderStage::getSource() const
    {
        String code;
        int size, capacity;

        ensureContext();

        gl::getShaderiv(m_id, GL_SHADER_SOURCE_LENGTH, &capacity);

        code.create(capacity);
        gl::getShaderSource(m_id, code.getSize(), &size, &code[0]);

        return code;
    }

    ShaderStageType ShaderStage::getType() const
    {
        return m_type;
    }

    unsigned int ShaderStage::getSystemHandler() const
    {
        return m_id;
    }

    String ShaderStage::getErrorMessage() const
    {
        int capacity;
        String message;

        ensureContext();

        gl::getShaderiv(m_id, GL_INFO_LOG_LENGTH, &capacity);

        if(capacity)
        {
            message.setSize(static_cast<std::size_t>(capacity));
            gl::getShaderInfoLog(m_id, capacity, nullptr, &message[0]);
        }

        return message;
    }
}
