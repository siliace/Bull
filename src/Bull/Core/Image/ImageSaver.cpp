#include <stb_image/stb_image_write.h>

#include <Bull/Core/Image/ImageSaver.hpp>

namespace Bull
{
    bool ImageSaver::isSupportedFormat(ImageFormat format)
    {
        switch(format)
        {
            case ImageFormat_Bmp: return true;
            case ImageFormat_Png: return true;
            case ImageFormat_Jpg: return true;
            case ImageFormat_Tga: return true;
        }

        return false;
    }

    bool ImageSaver::saveToPath(const Image& image, const Path& path, const ImageSavingParameters& parameters)
    {
        return isSupportedFormat(parameters.format) && createTask([image, path, parameters]() -> bool{
            switch(parameters.format)
            {
                case ImageFormat_Bmp: return stbi_write_bmp(path.toString().getBuffer(), image.getSize().x(), image.getSize().y(), 4, image.getPixels().getBuffer()) == 0;
                case ImageFormat_Png: return stbi_write_png(path.toString().getBuffer(), image.getSize().x(), image.getSize().y(), 4, image.getPixels().getBuffer(), parameters.stride) == 0;
                case ImageFormat_Jpg: return stbi_write_jpg(path.toString().getBuffer(), image.getSize().x(), image.getSize().y(), 4, image.getPixels().getBuffer(), parameters.quality) == 0;
                case ImageFormat_Tga: return stbi_write_tga(path.toString().getBuffer(), image.getSize().x(), image.getSize().y(), 4, image.getPixels().getBuffer()) == 0;
            }

            return false;
        });
    }
}