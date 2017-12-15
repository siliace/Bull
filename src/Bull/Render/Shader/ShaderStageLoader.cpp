#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    bool ShaderStageLoader::loadFromPath(ShaderStage& stage, const Path& path, ShaderStageType type)
    {
        return createTask([&stage, path, type]() -> bool{
            File file(path);

            if(file && stage.create(type))
            {
                return stage.compile(file.readAll());
            }

            return false;
        });
    }

    bool ShaderStageLoader::loadFromStream(ShaderStage& stage, InStream& stream, ShaderStageType type)
    {
        return createTask([&stage, &stream, type]() -> bool{
            if(stage.create(type))
            {
                return stage.compile(stream.readAll());
            }

            return false;
        });
    }

    bool ShaderStageLoader::loadFromMemory(ShaderStage& stage, const void* data, std::size_t length, ShaderStageType type)
    {
        return createTask([&stage, data, length, type]() -> bool{
            String code(reinterpret_cast<const char*>(data), length);

            if(stage.create(type))
            {
                return stage.compile(code);
            }

            return false;
        });
    }
}