#include <stb_image/stb_image_write.h>

#include <Bull/Utility/Image/Image.hpp>
#include <Bull/Utility/Image/STBSaver.hpp>

namespace Bull
{
    namespace prv
    {
        bool STBSaver::isSupportedFormat(ImageFormat format) const
        {
            return false;
        }

        bool STBSaver::saveToPath(const Image* image, const Path& path, const ImageParameterBag& parameters) const
        {
            switch(parameters.getImageFormat())
            {
                case ImageFormat::Png: return stbi_write_png(path.toString().getBuffer(), image->getSize().x(), image->getSize().y(), 4, image->getPixels().getBuffer(), 0) != 0;
                case ImageFormat::Bmp: return stbi_write_bmp(path.toString().getBuffer(), image->getSize().x(), image->getSize().y(), 4, image->getPixels().getBuffer()) != 0;
                case ImageFormat::Tga: return stbi_write_tga(path.toString().getBuffer(), image->getSize().x(), image->getSize().y(), 4, image->getPixels().getBuffer()) != 0;
            }

            return false;
        }

        bool STBSaver::saveToStream(const Image* image, OutStream& stream, const ImageParameterBag& parameters) const
        {
            return false;
        }

        bool STBSaver::saveToMemory(const Image* image, void* data, Index length, const ImageParameterBag& parameters) const
        {
            return false;
        }
    }
}