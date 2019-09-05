#include <algorithm>

#include <Bull/Render/Context/Context.hpp>
#include <Bull/Render/Context/GlFunctions.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>

namespace Bull
{
    std::vector<int> ShaderBinary::getSupportedFormats()
    {
        int length;
        std::vector<int> formats;

        Context::ensureContext();

        gl::getIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &length);

        formats.resize(length, 0);

        gl::getIntegerv(GL_PROGRAM_BINARY_FORMATS, &formats[0]);

        return formats;
    }

    ShaderBinary::ShaderBinary() :
            format(0)
    {
        /// Nothing
    }

    bool ShaderBinary::isValid() const
    {
        if(!content.isEmpty() && format)
        {
            std::vector<int> formats = getSupportedFormats();

            return std::find(formats.begin(), formats.end(), format) != formats.end();
        }

        return false;
    }
}