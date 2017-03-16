#include <cstring>

#include <stb_image.h>
#include <stb_image_write.h>

#include <Bull/Utility/ImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageLoader::loadFromPath(const Path& path, std::vector<Uint8>& pixels, Vector2UI& size) const
        {
            int width, height, channels;
            unsigned char* buffer = stbi_load(path, &width, &height, &channels, STBI_rgb_alpha);

            pixels.clear();

            if(buffer)
            {
                size.x = static_cast<unsigned int>(width);
                size.y = static_cast<unsigned int>(height);

                if(size.x && size.y)
                {
                    pixels.resize(size.x * size.y * 4);
                    std::memcpy(&pixels[0], buffer, pixels.size());

                    return true;
                }
            }

            return false;
        }

        bool ImageLoader::saveToPath(const Path& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size) const
        {
            if(!path.isValid())
            {
                switch(format)
                {
                    case Image::Bmp: return saveBmpToPath(path, pixels, size);
                    case Image::Tga: return saveTgaToPath(path, pixels, size);
                    case Image::Png: return savePngToPath(path, pixels, size);
                    case Image::Jpg:
                    case Image::Jpeg: return false;
                }
            }

            return false;
        }

        bool ImageLoader::saveBmpToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".bmp"))
            {
                fullPath += ".bmp";
            }

            return stbi_write_bmp(fullPath, size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::savePngToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".png"))
            {
                fullPath += ".png";
            }

            return stbi_write_png(fullPath, size.x, size.y, 4, &pixels[0], 0) != 0;
        }

        bool ImageLoader::saveTgaToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".tga"))
            {
                fullPath += ".tga";
            }

            return stbi_write_tga(fullPath, size.x, size.y, 4, &pixels[0]) != 0;
        }
    }
}
