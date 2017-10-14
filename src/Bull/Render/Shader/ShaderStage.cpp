#include <Bull/Core/Exception/RuntimeError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Log/Log.hpp>

#include <Bull/Render/OpenGL.hpp>
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

    bool ShaderStage::create(ShaderStageType::ShaderStageType type)
    {
        if(isValid())
        {
            destroy();
        }

        m_type = type;
        m_id   = gl::createShader(shaderType[type]);

        return gl::isShader(m_id);
    }

    bool ShaderStage::loadFromPath(const Path& path, const ShaderStageParameters& parameters)
    {
        return Loader::get()->loadFromPath(this, path, parameters);
    }

    bool ShaderStage::loadFromStream(InStream& stream, const ShaderStageParameters& parameters)
    {
        return Loader::get()->loadFromStream(this, stream, parameters);
    }

    bool ShaderStage::loadFromMemory(const void* data, Index length, const ShaderStageParameters& parameters)
    {
        return Loader::get()->loadFromMemory(this, data, length, parameters);
    }

    bool ShaderStage::saveToPath(const Path& path, const ShaderStageParameters& parameters) const
    {
        return Saver::get()->saveToPath(this, path, parameters);
    }

    bool ShaderStage::saveToStream(OutStream& stream, const ShaderStageParameters& parameters) const
    {
        return Saver::get()->saveToStream(this, stream, parameters);
    }

    bool ShaderStage::saveToMemory(void* data, Index length, const ShaderStageParameters& parameters) const
    {
        return Saver::get()->saveToMemory(this, data, length, parameters);
    }

    bool ShaderStage::compile(const String& code)
    {
        if(isValid())
        {
            const char* source = code.getBuffer();

            gl::shaderSource(m_id, 1, &source, nullptr);
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

    ShaderStageType::ShaderStageType ShaderStage::getType() const
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