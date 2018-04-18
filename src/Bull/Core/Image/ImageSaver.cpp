#include <algorithm>

#include <stb_image/stb_image_write.h>

#include <Bull/Core/Image/ImageSaver.hpp>

namespace Bull
{
    void ImageSaver::writeToStream(void* context, void* data, int size)
    {
        reinterpret_cast<OutStream*>(context)->write(data, size);
    }

    void ImageSaver::writeToMemory(void* context, void* data, int size)
    {
        Buffer* buffer = reinterpret_cast<Buffer*>(context);
        std::memcpy(buffer->target, data, std::min(buffer->length, static_cast<std::size_t>(size)));
    }

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
                case ImageFormat_Bmp: return stbi_write_bmp(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
                case ImageFormat_Png: return stbi_write_png(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.stride) == 0;
                case ImageFormat_Jpg: return stbi_write_jpg(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.quality) == 0;
                case ImageFormat_Tga: return stbi_write_tga(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
            }

            return false;
        });
    }

    bool ImageSaver::saveToStream(const Image& image, OutStream& stream, const ImageSavingParameters& parameters)
    {
        return isSupportedFormat(parameters.format) && createTask([&image, &stream, parameters]() -> bool{
            switch(parameters.format)
            {
                case ImageFormat_Bmp: return stbi_write_bmp_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
                case ImageFormat_Png: return stbi_write_png_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.stride) == 0;
                case ImageFormat_Jpg: return stbi_write_jpg_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.quality) == 0;
                case ImageFormat_Tga: return stbi_write_tga_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
            }

            return false;
        });
    }

    bool ImageSaver::saveToMemory(const Image& image, void* data, std::size_t length, const ImageSavingParameters& parameters)
    {
        if(data && length)
        {
            return isSupportedFormat(parameters.format) && createTask([&image, data, length, parameters]() -> bool{
                Buffer buffer = {data, length};

                switch(parameters.format)
                {
                    case ImageFormat_Bmp: return stbi_write_bmp_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
                    case ImageFormat_Png: return stbi_write_png_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.stride) == 0;
                    case ImageFormat_Jpg: return stbi_write_jpg_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer(), parameters.quality) == 0;
                    case ImageFormat_Tga: return stbi_write_tga_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().getBuffer()) == 0;
                }

                return false;
            });
        }

        return false;
    }
}