#include <algorithm>
#include <cstring>

#include <stb_image/stb_image_write.h>

#include <Bull/Core/Exception/Expect.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/Exception/Throw.hpp>
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

    void ImageSaver::saveToPath(const Image& image, const Path& path, const ImageSavingParameters& parameters)
    {
        Expect(isSupportedFormat(parameters.format), Throw(InvalidParameter, "ImageSaver::saveToPath", "Unsupported image format"));

        switch(parameters.format)
        {
            case ImageFormat_Bmp: stbi_write_bmp(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().data());
            case ImageFormat_Png: stbi_write_png(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.stride);
            case ImageFormat_Jpg: stbi_write_jpg(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.quality);
            case ImageFormat_Tga: stbi_write_tga(path.toString().getBuffer(), image.getSize().width, image.getSize().height, 4, image.getPixels().data());
        }
    }

    void ImageSaver::saveToStream(const Image& image, OutStream& stream, const ImageSavingParameters& parameters)
    {
        Expect(isSupportedFormat(parameters.format), Throw(InvalidParameter, "ImageSaver::saveToStream", "Unsupported image format"));

        switch(parameters.format)
        {
            case ImageFormat_Bmp: stbi_write_bmp_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().data());
            case ImageFormat_Png: stbi_write_png_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.stride);
            case ImageFormat_Jpg: stbi_write_jpg_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.quality);
            case ImageFormat_Tga: stbi_write_tga_to_func(&ImageSaver::writeToStream, &stream, image.getSize().width, image.getSize().height, 4, image.getPixels().data());
        }
    }

    void ImageSaver::saveToMemory(const Image& image, void* data, std::size_t length, const ImageSavingParameters& parameters)
    {
        if(data && length)
        {
            Expect(isSupportedFormat(parameters.format), Throw(InvalidParameter, "ImageSaver::saveToMemory", "Unsupported image format"));

            Buffer buffer = {data, length};

            switch(parameters.format)
            {
                case ImageFormat_Bmp: stbi_write_bmp_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().data());
                case ImageFormat_Png: stbi_write_png_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.stride);
                case ImageFormat_Jpg: stbi_write_jpg_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().data(), parameters.quality);
                case ImageFormat_Tga: stbi_write_tga_to_func(&ImageSaver::writeToMemory, &buffer, image.getSize().width, image.getSize().height, 4, image.getPixels().data());
            }
        }
    }
}