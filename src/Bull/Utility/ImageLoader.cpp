#include <cstring>

#include <stb_image.h>
#include <stb_image_write.h>

#include <Bull/Utility/ImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageLoader::load(const String& path, std::vector<Uint8>& pixels, Vector2UI& size)
        {
            int width, height, channels;
            unsigned char* buffer = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);

            pixels.clear();

            if(buffer)
            {
                size.x = width;
                size.y = height;

                if(size.x && size.y)
                {
                    pixels.resize(size.x * size.y * 4);
                    std::memcpy(&pixels[0], buffer, pixels.size());

                    return true;
                }
            }

            return false;
        }
    }
}
