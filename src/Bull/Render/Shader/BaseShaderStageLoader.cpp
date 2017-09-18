#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/BaseShaderStageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool BaseShaderStageLoader::loadFromPath(ShaderStage* shaderStage, const Path& path, const ShaderStageParameterBag& parameters) const
        {
            File file;

            return file.open(path, File::Read) && loadFromStream(shaderStage, file, parameters);
        }

        bool BaseShaderStageLoader::loadFromStream(ShaderStage* shaderStage, InStream& stream, const ShaderStageParameterBag& parameters) const
        {
            return shaderStage->create(parameters.getShaderStageType()) && shaderStage->compile(stream.readAll());
        }

        bool BaseShaderStageLoader::loadFromMemory(ShaderStage* shaderStage, const void* data, Index length, const ShaderStageParameterBag& parameters) const
        {
            return shaderStage->create(parameters.getShaderStageType()) && shaderStage->compile(String(reinterpret_cast<const char*>(data), length));
        }
    }
}