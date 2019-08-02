#ifndef BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP

#include <Bull/Core/Assets/AssetLoader.hpp>
#include <Bull/Core/Memory/String.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    struct BULL_RENDER_API ShaderStageLoader : public AssetLoader<ShaderStage, ShaderStageType>
    {
        /*! \brief Load an ShaderStage from a File
         *
         * \param path The Path of the File to read
         * \param type The type of ShaderStage to load
         *
         */
        std::shared_ptr<ShaderStage> loadFromPath(const Path& path, ShaderStageType type) const override;

        /*! \brief Load an ShaderStage from an InStream
         *
         * \param stream The InStream to read
         * \param type   The type of ShaderStage to load
         *
         */
        std::shared_ptr<ShaderStage> loadFromStream(InStream& stream, ShaderStageType type) const override;

        /*! \brief Load an ShaderStage from a memory area
         *
         * \param data   Data to read
         * \param length The length of data
         * \param type   The type of ShaderStage to load
         *
         */
        std::shared_ptr<ShaderStage> loadFromMemory(const void* data, std::size_t length, ShaderStageType type) const override;
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
