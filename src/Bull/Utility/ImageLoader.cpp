#include <cstring>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <Bull/Utility/ImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageLoader::load(const Path& path, std::vector<Uint8>& pixels, Vector2UI& size)
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

        bool ImageLoader::save(const Path& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size)
        {
            if(!path.isValid())
            {
                switch(format)
                {
                    case Image::Bmp: return saveBmp(path, pixels, size);
                    case Image::Tga: return saveTga(path, pixels, size);
                    case Image::Png: return savePng(path, pixels, size);
                    case Image::Jpg:
                    case Image::Jpeg: return false;
                }
            }

            return false;
        }

        bool ImageLoader::saveBmp(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size)
        {
            String fullPath = path;

            if(!fullPath.endsWith(".bmp"))
            {
                fullPath += ".bmp";
            }

            return stbi_write_bmp(fullPath, size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::savePng(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size)
        {
            String fullPath = path;

            if(!fullPath.endsWith(".png"))
            {
                fullPath += ".png";
            }

            return stbi_write_png(fullPath, size.x, size.y, 4, &pixels[0], 0) != 0;
        }

        bool ImageLoader::saveTga(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size)
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
