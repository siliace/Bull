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
                    "frag", "vert"
            };

            return std::find(extensionsSupported.begin(), extensionsSupported.end(), extension) != extensionsSupported.end();
        }

        bool BaseShaderStageLoader::loadFromPath(std::unique_ptr<ShaderStage>& resource, const Path& path, const ParameterBag& parameters) const
        {
            File resourceFile(path);

            if(resourceFile.isOpen())
            {
                return loadFromStream(resource, resourceFile, parameters);
            }

            return false;
        }

        bool BaseShaderStageLoader::loadFromStream(std::unique_ptr<ShaderStage>& resource, InStream& stream, const ParameterBag& parameters) const
        {
            unsigned int type;

            if(parameters.getParameter("type", type))
            {
                resource->create(ShaderStage::Type(type));
                return resource->compile(stream.readAll());
            }

            return false;
        }

        bool BaseShaderStageLoader::loadFromMemory(std::unique_ptr<ShaderStage>& resource, const void* data, Index length, const ParameterBag& parameters) const
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
