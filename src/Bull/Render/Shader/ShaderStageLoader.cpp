#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/FileSystem/File.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    void ShaderStageLoader::loadFromPath(ShaderStage& stage, const Path& path, ShaderStageType type)
    {
        createTask([&stage, path, type]() {
            File file(path);

            Expect(file, Throw(InternalError, "ShaderStageLoader::loadFromPath", "Failed to open " + path.toString()));

            stage.create(type);
            stage.compile(file.readAll());
        });
    }

    void ShaderStageLoader::loadFromStream(ShaderStage& stage, InStream& stream, ShaderStageType type)
    {
        createTask([&stage, &stream, type]() {
            stage.create(type);
            stage.compile(stream.readAll());
        });
    }

    void ShaderStageLoader::loadFromMemory(ShaderStage& stage, const void* data, std::size_t length, ShaderStageType type)
    {
        createTask([&stage, data, length, type]() {
            String code(reinterpret_cast<const char*>(data), length);

            stage.create(type);
            stage.compile(code);
        });
    }
}