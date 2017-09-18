#include <cstring>

#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/BaseShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool BaseShaderStageSaver::saveToPath(const ShaderStage* shaderStage, const Path& path, const ShaderStageParameterBag& parameters) const
        {
            File file;

            return file.open(path, File::Write) && saveToStream(shaderStage, file, parameters);
        }

        bool BaseShaderStageSaver::saveToStream(const ShaderStage* shaderStage, OutStream& stream, const ShaderStageParameterBag& parameters) const
        {
            String code = shaderStage->getSource();

            stream.write(code.getBuffer(), code.getCapacity());

            return true;
        }

        bool BaseShaderStageSaver::saveToMemory(const ShaderStage* shaderStage, void* data, Index length, const ShaderStageParameterBag& parameters) const
        {
            if(data && length)
            {
                std::memcpy(data, shaderStage->getSource().getBuffer(), length);

                return true;
            }

            return false;
        }
    }
}