#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/StringStream.hpp>
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
        create(type);
    }

    ShaderStage::ShaderStage(const Path& path, Type type)
    {
        create(type);
        loadFromPath(path);
    }

    ShaderStage::ShaderStage(const String& code, Type type)
    {
        create(type);
        loadFromCode(code);
    }

    ShaderStage::ShaderStage(InStream& stream, Type type)
    {
        create(type);
        loadFromStream(stream);
    }

    ShaderStage::ShaderStage(ShaderStage&& stage) :
        m_id(stage.m_id),
        m_type(stage.m_type),
        m_isCompiled(stage.m_isCompiled)
    {
        stage.m_id         = 0;
        stage.m_isCompiled = false;
    }

    ShaderStage::~ShaderStage()
    {
        destroy();
    }

    ShaderStage& ShaderStage::operator=(ShaderStage&& stage)
    {
        m_id         = stage.m_id;
        m_type       = stage.m_type;
        m_isCompiled = stage.m_isCompiled;

        stage.m_id         = 0;
        stage.m_isCompiled = false;

        return (*this);
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

    bool ShaderStage::compile()
    {
        if(isValid())
        {
            gl::compileShader(m_id);

            if(hasError())
            {
                StringStream ss;

                ss << String::number(getErrorCode()) << getErrorMessage();

                Log::get()->write(ss.toString(), Log::Level::Error);

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
        return m_isCompiled;
    }

    bool ShaderStage::isValid() const
    {
        return m_id != 0;
    }

    String ShaderStage::getSource() const
    {
        if(isValid())
        {
            String code;
            int size, capacity;

            gl::getShaderiv(m_id, GL_SHADER_SOURCE_LENGTH, &capacity);

            code.reserve(static_cast<std::size_t>(capacity));
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

    bool ShaderStage::hasError() const
    {
        return getErrorCode() == 0;
    }

    unsigned int ShaderStage::getErrorCode() const
    {
        int error = 0;
        gl::getShaderiv(m_id, GL_COMPILE_STATUS, &error);

        return static_cast<unsigned int>(error);
    }

    String ShaderStage::getErrorMessage() const
    {
        if(hasError())
        {
            int capacity;
            String message;

            gl::getShaderiv(m_id, GL_INFO_LOG_LENGTH, &capacity);

            message.reserve(capacity);

            gl::getShaderInfoLog(m_id, capacity, nullptr, &message[0]);

            return message;
        }

        return String();
    }
}