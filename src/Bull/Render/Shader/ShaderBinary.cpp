#include <algorithm>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>

namespace Bull
{
    std::vector<int> ShaderBinary::getSupportedFormats()
    {
        int count;
        std::vector<int> formats;

        ensureContext();

        gl::getIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &count);

        formats.resize(count);

        gl::getIntegeri_v(GL_PROGRAM_BINARY_FORMATS, 1, &formats[0]);

        return formats;
    }

    ShaderBinary::ShaderBinary() :
        format(0)
    {
        /// Nothing
    }

    bool ShaderBinary::isValid() const
    {
        std::vector<int> formats = getSupportedFormats();

        return std::find(formats.begin(), formats.end(), format) != formats.end();
    }
}