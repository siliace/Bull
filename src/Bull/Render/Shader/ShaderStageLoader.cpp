#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    void ShaderStageLoader::loadFromPath(ShaderStage& stage, const Path& path, ShaderStageType type)
    {
        createTask([&stage, path, type]() -> bool{
            File file(path);

            if(file && stage.create(type))
            {
                return stage.compile(file.readAll());
            }

            return false;
        });
    }

    void ShaderStageLoader::loadFromStream(ShaderStage& stage, InStream& stream, ShaderStageType type)
    {
        createTask([&stage, &stream, type]() -> bool{
            if(stage.create(type))
            {
                return stage.compile(stream.readAll());
            }

            return false;
        });
    }

    void ShaderStageLoader::loadFromMemory(ShaderStage& stage, const void* data, std::size_t length, ShaderStageType type)
    {
        createTask([&stage, data, length, type]() -> bool{
            String code(reinterpret_cast<const char*>(data), length);

            if(stage.create(type))
            {
                return stage.compile(code);
            }

            return false;
        });
    }
}