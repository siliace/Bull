#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ShaderStageLoader::loadFromPath(ShaderStage* resource, const Path& path, const ShaderStageParameters& parameters) const
        {
            File file(path);

            if(file.isOpen())
            {
                return loadFromStream(resource, file, parameters);
            }

            return false;
        }

        bool ShaderStageLoader::loadFromStream(ShaderStage* resource, InStream& stream, const ShaderStageParameters& parameters) const
        {
            if(resource->create(parameters.type))
            {
                return resource->compile(stream.readAll());
            }

            return false;
        }

        bool ShaderStageLoader::loadFromMemory(ShaderStage* resource, const void* data, Index length, const ShaderStageParameters& parameters) const
        {
            String code(static_cast<const char*>(data), length);

            if(resource->create(parameters.type))
            {
                return resource->compile(code);
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