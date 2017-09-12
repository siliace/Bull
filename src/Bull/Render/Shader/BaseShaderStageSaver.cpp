#include <Bull/Render/Shader/BaseShaderStageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool BaseShaderStageSaver::isSupportedExtension(const String& extension) const
        {
            return false;
        }

        bool BaseShaderStageSaver::saveToPath(const ShaderStage& resource, const Path& path) const
        {
            return false;
        }

        bool BaseShaderStageSaver::saveToStream(const ShaderStage& resource, OutStream& stream) const
        {
            return false;
        }

        bool BaseShaderStageSaver::saveToMemory(const ShaderStage& resource, void* data, Index length) const
        {
            return false;
        }
    }
}