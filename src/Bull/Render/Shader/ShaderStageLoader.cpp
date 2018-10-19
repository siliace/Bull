#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/IO/TextReader.hpp>
#include <Bull/Core/IO/MemoryStream.hpp>

#include <Bull/Render/Shader/ShaderStageLoader.hpp>

namespace Bull
{
    std::shared_ptr<ShaderStage> ShaderStageLoader::loadFromPath(const Path& path, ShaderStageType type) const
    {
        File file(path, FileOpeningMode_Read);

        return loadFromStream(file, type);
    }

    std::shared_ptr<ShaderStage> ShaderStageLoader::loadFromStream(InStream& stream, ShaderStageType type) const
    {
        std::shared_ptr<ShaderStage> stage = std::make_shared<ShaderStage>();

        stage->create(type);
        stage->compile(TextReader(stream).readAll());

        return stage;
    }

    std::shared_ptr<ShaderStage> ShaderStageLoader::loadFromMemory(const void* data, std::size_t length, ShaderStageType type) const
    {
        MemoryStream memoryStream(data, length);

        return loadFromStream(memoryStream, type);
    }
}