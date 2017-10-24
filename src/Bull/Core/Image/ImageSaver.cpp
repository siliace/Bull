#include <algorithm>

#include <stb_image/stb_image_write.h>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/ImageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageSaver::saveToPath(const Image* image, const Path& path, const ImageParameters& parameters) const
        {
            Vector2I size = image->getSize();
            const char* file = path.toString().getBuffer();
            const Uint8* pixels = image->getPixels().getBuffer();

            switch(parameters.format)
            {
                case ImageFormat::Bmp: return stbi_write_bmp(file, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat::Tga: return stbi_write_tga(file, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat::Png: return stbi_write_png(file, size.x(), size.y(), parameters.channels, pixels, parameters.stride) != 0;
                case ImageFormat::Jpg: return stbi_write_jpg(file, size.x(), size.y(), parameters.channels, pixels, parameters.quality) != 0;
            }

            return false;
        }

        bool ImageSaver::saveToStream(const Image* image, OutStream& stream, const ImageParameters& parameters) const
        {
            return false;
        }

        bool ImageSaver::saveToMemory(const Image* image, void* data, Index length, const ImageParameters& parameters) const
        {
            return false;
        }

        bool ImageSaver::isFormatSupported(const String& extension) const
        {
            static std::vector<String> extensions = {
                    "jpg", "jpeg", "png", "bmp", "tga"
            };

            return std::find(extensions.begin(), extensions.end(), extension) != extensions.end();
        }

        bool ImageSaver::isParametersSupported(const ImageParameters& parameters) const
        {
            switch(parameters.format)
            {
                case ImageFormat::Jpg: return true;
                case ImageFormat::Png: return true;
                case ImageFormat::Bmp: return true;
                case ImageFormat::Tga: return true;
            }

            return false;
        }
    }
}