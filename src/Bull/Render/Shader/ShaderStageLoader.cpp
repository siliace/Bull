#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ShaderStageLoader::loadFromPath(ShaderStage* shaderStage, const Path& path, const ShaderStageParameters& parameters) const
        {
            File file(path);

            if(file.isOpen())
            {
                return loadFromStream(shaderStage, file, parameters);
            }

            return false;
        }

        bool ShaderStageLoader::loadFromStream(ShaderStage* shaderStage, InStream& stream, const ShaderStageParameters& parameters) const
        {
            if(shaderStage->create(parameters.type))
            {
                return shaderStage->compile(stream.readAll());
            }

            return false;
        }

        bool ShaderStageLoader::loadFromMemory(ShaderStage* shaderStage, const void* data, std::size_t length, const ShaderStageParameters& parameters) const
        {
            String code(static_cast<const char*>(data), length);

            if(shaderStage->create(parameters.type))
            {
                return shaderStage->compile(code);
            }

            return false;
        }

        bool ShaderStageLoader::isFormatSupported(const String& extension) const
        {
            return true;
        }

        bool ShaderStageLoader::isParametersSupported(const ShaderStageParameters& parameters) const
        {
            return true;
        }
    }
}