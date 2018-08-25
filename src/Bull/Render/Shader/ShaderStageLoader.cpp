#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/Memory/MemoryStream.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    ShaderStage ShaderStageLoader::loadFromPath(const Path& path, ShaderStageType type) const
    {
        File file(path, FileOpeningMode_Read);

        return loadFromStream(file, type);
    }

    ShaderStage ShaderStageLoader::loadFromStream(InStream& stream, ShaderStageType type) const
    {
        ShaderStage stage;

        stage.create(type);
        stage.compile(TextReader(stream).readAll());

        return stage;
    }

    ShaderStage ShaderStageLoader::loadFromMemory(const void* data, std::size_t length, ShaderStageType type) const
    {
        MemoryStream memoryStream(data, length);

        return loadFromStream(memoryStream, type);
    }
}