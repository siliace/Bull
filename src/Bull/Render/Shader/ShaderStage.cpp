#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    ShaderStage::ShaderStage() :
        m_id(0),
        m_isCompiled(false)
    {
        /// Nothing
    }

    ShaderStage::ShaderStage(Type type) :
        m_id(0),
        m_isCompiled(false)
    {
        if(!create(type))
        {
            throw RuntimeError("Failed to create shader");
        }
    }

    ShaderStage::ShaderStage(const Path& path, Type type)
    {
        if(!create(type))
        {
            throw RuntimeError("Failed to create shader");
        }

        loadFromPath(path);
    }

    ShaderStage::ShaderStage(const String& code, Type type)
    {
        if(!create(type))
        {
            throw RuntimeError("Failed to create shader");
        }

        loadFromCode(code);
    }

    ShaderStage::ShaderStage(InStream& stream, Type type)
    {
        if(!create(type))
        {
            throw RuntimeError("Failed to create shader");
        }

        loadFromStream(stream);
    }

    ShaderStage::~ShaderStage()
    {
        destroy();
    }

    bool ShaderStage::create(Type type)
    {
        if(isValid())
        {
            destroy();
        }

        m_type = type;
        m_id   = gl::createShader(type);

        return m_id != 0;
    }

    bool ShaderStage::loadFromPath(const Path& path)
    {
        File file(path);

        if(file.isOpen())
        {
            return loadFromStream(file);
        }

        return false;
    }

    bool ShaderStage::loadFromCode(const String& code)
    {
        if(isValid())
        {
            const char* source = code.getBuffer();

            gl::shaderSource(m_id, 1, &source, nullptr);
        }

        return false;
    }

    bool ShaderStage::loadFromStream(InStream& stream)
    {
        return loadFromCode(stream.readAll());
    }

    bool ShaderStage::loadFromMemory(const void* data, Index length)
    {
        return loadFromCode(String(static_cast<const char*>(data), length));
    }

    bool ShaderStage::compile()
    {
        if(isValid())
        {
            gl::compileShader(m_id);

            if(!isCompiled())
            {
                Log::get()->write(getErrorMessage(), Log::Level::Error);

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
            gl::deleteShader(m_id);
        }
    }

    bool ShaderStage::isCompiled() const
    {
        int error = 0;
        gl::getShaderiv(m_id, GL_COMPILE_STATUS, &error);

        return error == GL_TRUE;
    }

    bool ShaderStage::isValid() const
    {
        return gl::isShader(m_id);
    }

    String ShaderStage::getSource() const
    {
        if(isValid())
        {
            String code;
            int size, capacity;

            gl::getShaderiv(m_id, GL_SHADER_SOURCE_LENGTH, &capacity);

            code.reserve(static_cast<Index>(capacity));
            gl::getShaderSource(m_id, static_cast<int>(code.getSize()), &size, &code[0]);

            return code;
        }

        return String();
    }

    ShaderStage::Type ShaderStage::getType() const
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

        gl::getShaderiv(m_id, GL_INFO_LOG_LENGTH, &capacity);

        if(capacity)
        {
            message.setSize(static_cast<Index>(capacity));
            gl::getShaderInfoLog(m_id, capacity, nullptr, &message[0]);
        }

        return message;
    }
}