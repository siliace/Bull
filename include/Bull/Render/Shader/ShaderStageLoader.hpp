#ifndef BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
#define BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP

#include <Bull/Core/Assets/AssetIOScheduler.hpp>
#include <Bull/Core/Memory/String.hpp>
#include <Bull/Core/Pattern/Singleton.hpp>

#include <Bull/Render/Shader/ShaderStage.hpp>

namespace Bull
{
    class BULL_RENDER_API ShaderStageLoader : public Singleton<ShaderStageLoader>, public AssetIOScheduler<ShaderStage>
    {
    public:

        /*! \brief Load an ShaderStage from a File
         *
         * \param stage The ShaderStage to load
         * \param path  The Path of the File to read
         * \param type  The type of ShaderStage to load
         *
         */
        void loadFromPath(ShaderStage& stage, const Path& path, ShaderStageType type);

        /*! \brief Load an ShaderStage from an InStream
         *
         * \param stage  The ShaderStage to load
         * \param stream The InStream to read
         * \param type   The type of ShaderStage to load
         *
         */
        void loadFromStream(ShaderStage& stage, InStream& stream, ShaderStageType type);

        /*! \brief Load an ShaderStage from a memory area
         *
         * \param stage  The ShaderStage to load
         * \param data   Data to read
         * \param length The length of data
         * \param type   The type of ShaderStage to load
         *
         */
        void loadFromMemory(ShaderStage& stage, const void* data, std::size_t length, ShaderStageType type);

    private:

        friend class Singleton<ShaderStageLoader>;

        /*! \brief Default constructor
         *
         */
        ShaderStageLoader() = default;
    };
}

#endif // BULL_RENDER_SHADER_SHADERSTAGELOADER_HPP
