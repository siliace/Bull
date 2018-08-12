#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    ShaderStage ShaderStageLoader::loadFromPath(const Path& path, ShaderStageType type) const
    {
        File file(path);
        ShaderStage stage;

        Expect(file, Throw(InternalError, "ShaderStageLoader::loadFromPath", "Failed to open " + path.toString()));

        stage.create(type);
        stage.compile(file.readAll());

        return stage;
    }

    ShaderStage ShaderStageLoader::loadFromStream(InStream& stream, ShaderStageType type) const
    {
        ShaderStage stage;

        stage.create(type);
        stage.compile(stream.readAll());

        return stage;
    }

    ShaderStage ShaderStageLoader::loadFromMemory(const void* data, std::size_t length, ShaderStageType type) const
    {
        ShaderStage stage;
        String code(reinterpret_cast<const char*>(data), length);

        stage.create(type);
        stage.compile(code);

        return stage;
    }
}