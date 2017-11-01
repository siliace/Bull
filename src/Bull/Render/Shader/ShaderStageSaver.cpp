#include <cstring>

#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool ShaderStageSaver::saveToPath(const ShaderStage* shaderStage, const Path& path, const ShaderStageParameters& parameters) const
        {
            File file(path);

            if(file.isOpen())
            {
                file.write(shaderStage->getSource());

                return true;
            }

            return false;
        }

        bool ShaderStageSaver::saveToStream(const ShaderStage* shaderStage, OutStream& stream, const ShaderStageParameters& parameters) const
        {
            String code = shaderStage->getSource();

            stream.write(code.getBuffer(), code.getCapacity());

            return true;
        }

        bool ShaderStageSaver::saveToMemory(const ShaderStage* shaderStage, void* data, std::size_t length, const ShaderStageParameters& parameters) const
        {
            String code = shaderStage->getSource();

            if(length >= code.getCapacity())
            {
                std::memcpy(data, code.getBuffer(), length);

                return true;
            }

            return false;
        }

        bool ShaderStageSaver::isFormatSupported(const String& extension) const
        {
            return true;
        }
        
        bool ShaderStageSaver::isParametersSupported(const ShaderStageParameters& parameters) const
        {
            return true;
        }
    }
}