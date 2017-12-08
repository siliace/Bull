#ifndef BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP

#include <Bull/Core/Assets/AssetLoader.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    class BULL_RENDER_API ShaderStageLoader : public Singleton<ShaderStageLoader>, public AssetLoader<ShaderStage>
    {
    public:

        /*! \brief Load an ShaderStage from a File
         *
         * \param stage The ShaderStage to load
         * \param path  The Path of the File to read
         * \param type  The type of ShaderStage to load
         *
         * \return True if the ShaderStage started to be loaded
         *
         */
        bool loadFromPath(ShaderStage& stage, const Path& path, ShaderStageType type);

        /*! \brief Load an ShaderStage from an InStream
         *
         * \param stage  The ShaderStage to load
         * \param stream The InStream to read
         * \param type   The type of ShaderStage to load
         *
         * \return True if the ShaderStage started to be loaded
         *
         */
        bool loadFromStream(ShaderStage& stage, InStream& stream, ShaderStageType type);
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
