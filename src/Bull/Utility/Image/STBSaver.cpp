#include <algorithm>
#include <cstring>

#include <stb_image/stb_image_write.h>

#include <Bull/Utility/Image/STBSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool STBSaver::isSupportedFormat(ImageFormat format) const
        {
            switch(format)
            {
                case ImageFormat::Png: return true;
                case ImageFormat::Bmp: return true;
                case ImageFormat::Tga: return true;
                default:               return false;
            }
        }

        bool STBSaver::isSupportedExtension(const String& extension) const
        {
            static std::vector<String> supportedExtensions = {
                    "png", "bmp", "tga"
            };

            return std::find(supportedExtensions.begin(), supportedExtensions.end(), extension) != supportedExtensions.end();
        }

        bool STBSaver::saveToPath(const Image& resource, const Path& path, const ImageParameters& parameters) const
        {
            ImageFormat format = parameters.getFormat();

            switch(format)
            {
                case ImageFormat::Png: return stbi_write_png(path.toString().getBuffer(), resource.getSize().x, resource.getSize().y, 4, resource.getPixels().getBuffer(), 0);
                case ImageFormat::Bmp: return stbi_write_bmp(path.toString().getBuffer(), resource.getSize().x, resource.getSize().y, 4, resource.getPixels().getBuffer());
                case ImageFormat::Tga: return stbi_write_tga(path.toString().getBuffer(), resource.getSize().x, resource.getSize().y, 4, resource.getPixels().getBuffer());
                default:               return false;
            }
        }

        bool STBSaver::saveToStream(const Image& resource, OutStream& stream, const ImageParameters& parameters) const
        {
            return false;
        }

        bool STBSaver::saveToMemory(const Image& resource, void* data, Index length, const ImageParameters& parameters) const
        {
            std::memcpy(data, resource.getPixels().getBuffer(), length);

            return true;
        }
    }
}