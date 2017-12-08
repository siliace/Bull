#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/Log.hpp>

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

    bool ShaderStage::create(ShaderStageType type)
    {
        if(isValid())
        {
            destroy();
        }

        ensureContext();

        m_type = type;
        m_id   = gl::createShader(shaderType[type]);

        return gl::isShader(m_id);
    }

    bool ShaderStage::compile(const String& code)
    {
        if(isValid())
        {
            const char* source = code.getBuffer();

            ensureContext();

            gl::shaderSource(m_id, 1, &source, nullptr);
            gl::compileShader(m_id);

            if(!isCompiled())
            {
                Log::get()->write(getErrorMessage(), LogLevel::LogLevel_Error);

                return false;
            }

            m_isCompiled = true;

            return true;
        }

        return false;
    }

    void ShaderStage::destroy()
    {
        if(isValid())
        {
            ensureContext();

            gl::deleteShader(m_id);
        }
    }

    bool ShaderStage::isCompiled() const
    {
        int error = 0;

        ensureContext();

        gl::getShaderiv(m_id, GL_COMPILE_STATUS, &error);

        return error == GL_TRUE;
    }

    bool ShaderStage::isValid() const
    {
        ensureContext();

        return gl::isShader(m_id);
    }

    String ShaderStage::getSource() const
    {
        if(isValid())
        {
            String code;
            int size, capacity;

            ensureContext();

            gl::getShaderiv(m_id, GL_SHADER_SOURCE_LENGTH, &capacity);

            code.create(capacity);
            gl::getShaderSource(m_id, code.getSize(), &size, &code[0]);

            return code;
        }

        return String();
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
