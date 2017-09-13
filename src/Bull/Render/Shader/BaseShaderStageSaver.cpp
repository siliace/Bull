#include <algorithm>
#include <cstring>

#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/BaseShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool BaseShaderStageSaver::isSupportedExtension(const String& extension) const
        {
            static std::vector<String> extensionsSupported = {
                    "vert", "frag",
            };

            return std::find(extensionsSupported.begin(), extensionsSupported.end(), extension) != extensionsSupported.end();
        }

        bool BaseShaderStageSaver::saveToPath(const ShaderStage& resource, const Path& path, const ShaderStageParameters& parameters) const
        {
            File file(path);

            if(file.isOpen())
            {
                return saveToStream(resource, file, parameters);
            }

            return false;
        }

        bool BaseShaderStageSaver::saveToStream(const ShaderStage& resource, OutStream& stream, const ShaderStageParameters& parameters) const
        {
            String code = resource.getSource();

            return stream.write(code.getBuffer(), code.getSize()) == code.getSize();
        }

        bool BaseShaderStageSaver::saveToMemory(const ShaderStage& resource, void* data, Index length, const ShaderStageParameters& parameters) const
        {
            String code = resource.getSource();

            if(data && length >= code.getSize())
            {
                std::memcpy(data, code.getBuffer(), code.getSize());

                return true;
            }

            return false;
        }
    }
}