#include <algorithm>

#include <Bull/Render/OpenGL.hpp>
#include <Bull/Render/Shader/ShaderBinary.hpp>

namespace Bull
{
    std::vector<int> ShaderBinary::getSupportedFormats()
    {
        int lenght;
        std::vector<int> formats;

        ensureContext();

        gl::getIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &lenght);

        formats.resize(lenght, 0);

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
        if(!isEmpty() && format)
        {
            std::vector<int> formats = getSupportedFormats();

            return std::find(formats.begin(), formats.end(), format) != formats.end();
        }

        return false;
    }
}