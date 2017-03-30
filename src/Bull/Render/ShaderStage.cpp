#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/StringStream.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/ShaderStage.hpp>

namespace Bull
{
    ShaderStage::ShaderStage(Type type) :
        m_handler(0),
        m_isCompiled(false)
    {
        create(type);
    }

    ShaderStage::ShaderStage(ShaderStage&& stage) :
        m_type(stage.m_type),
        m_handler(stage.m_handler),
        m_isCompiled(stage.m_isCompiled)
    {
        stage.m_handler = 0;
        stage.m_isCompiled = false;
    }

    ShaderStage::~ShaderStage()
    {
        destroy();
    }

    ShaderStage& ShaderStage::operator=(ShaderStage&& stage)
    {
        m_type     = stage.m_type;
        m_handler  = stage.m_handler;
        m_isCompiled = stage.m_isCompiled;

        stage.m_handler = 0;
        stage.m_isCompiled = false;

        return (*this);
    }

    bool ShaderStage::create(Type type)
    {
        if(isValid())
        {
            destroy();
        }

        m_type    = type;
        m_handler = gl::createShader(type);

        return m_handler != 0;
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
            const char* source = static_cast<const char*>(code);

            gl::shaderSource(m_handler, 1, &source, nullptr);
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
            gl::compileShader(m_handler);

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
            gl::deleteShader(m_handler);
        }
    }

    bool ShaderStage::isCompiled() const
    {
        return m_isCompiled;
    }

    bool ShaderStage::isValid() const
    {
        return m_handler != 0;
    }

    ShaderStage::Type ShaderStage::getType() const
    {
        return m_type;
    }

    bool ShaderStage::hasError() const
    {
        return getErrorCode() == 0;
    }

    unsigned int ShaderStage::getErrorCode() const
    {
        int error = 0;
        gl::getShaderiv(m_handler, GL_COMPILE_STATUS, &error);

        return static_cast<unsigned int>(error);
    }

    String ShaderStage::getErrorMessage() const
    {
        if(hasError())
        {
            int capacity;
            String message;

            gl::getShaderiv(m_handler, GL_INFO_LOG_LENGTH, &capacity);

            message.reserve(capacity);

            gl::getShaderInfoLog(m_handler, capacity, nullptr, &message[0]);

            return message;
        }

        return String();
    }

    unsigned int ShaderStage::getHandler() const
    {
        return m_handler;
    }
}