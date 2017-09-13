#include <algorithm>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Memory/MemoryStream.hpp>

#include <Bull/Render/Shader/BaseShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool BaseShaderStageLoader::isSupportedExtension(const String& extension) const
        {
            static std::vector<String> extensionsSupported = {
                    "vert", "frag",
            };

            return std::find(extensionsSupported.begin(), extensionsSupported.end(), extension) != extensionsSupported.end();
        }

        bool BaseShaderStageLoader::loadFromPath(std::unique_ptr<ShaderStage>& resource, const Path& path, const ShaderStageParameters& parameters) const
        {
            File resourceFile(path);

            if(resourceFile.isOpen())
            {
                return loadFromStream(resource, resourceFile, parameters);
            }

            return false;
        }

        bool BaseShaderStageLoader::loadFromStream(std::unique_ptr<ShaderStage>& resource, InStream& stream, const ShaderStageParameters& parameters) const
        {
            resource->create(ShaderStage::Type(parameters.getType()));

            return resource->compile(stream.readAll());
        }

        bool BaseShaderStageLoader::loadFromMemory(std::unique_ptr<ShaderStage>& resource, const void* data, Index length, const ShaderStageParameters& parameters) const
        {
            MemoryStream stream(data, length);

            if(stream.isOpen())
            {
                return loadFromStream(resource, stream, parameters);
            }

            return false;
        }
    }
}
