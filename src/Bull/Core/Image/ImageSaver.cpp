#include <algorithm>

#include <stb_image/stb_image_write.h>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/ImageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        void ImageSaver::writeToStream(void* context, void* data, int size)
        {
            OutStream* stream = reinterpret_cast<OutStream*>(context);

            stream->write(data, static_cast<std::size_t>(size));
        }

        void ImageSaver::writeToMemory(void* context, void* data, int size)
        {
            PixelBuffer* buffer = reinterpret_cast<PixelBuffer*>(context);

            std::memset(buffer->data, 0, buffer->length);
            std::memcpy(buffer->data, data, std::min(buffer->length, static_cast<std::size_t>(size)));
        }

        bool ImageSaver::saveToPath(const Image* image, const Path& path, const ImageParameters& parameters) const
        {
            Vector2UI size = image->getSize();
            const char* file = path.toString().getBuffer();
            const Uint8* pixels = image->getPixels().getBuffer();

            switch(parameters.format)
            {
                case ImageFormat_Bmp: return stbi_write_bmp(file, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Tga: return stbi_write_tga(file, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Png: return stbi_write_png(file, size.x(), size.y(), parameters.channels, pixels, parameters.stride) != 0;
                case ImageFormat_Jpg: return stbi_write_jpg(file, size.x(), size.y(), parameters.channels, pixels, parameters.quality) != 0;
            }

            return false;
        }

        bool ImageSaver::saveToStream(const Image* image, OutStream& stream, const ImageParameters& parameters) const
        {
            Vector2UI size = image->getSize();
            const Uint8* pixels = image->getPixels().getBuffer();

            switch(parameters.format)
            {
                case ImageFormat_Bmp: return stbi_write_bmp_to_func(&ImageSaver::writeToStream, &stream, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Tga: return stbi_write_tga_to_func(&ImageSaver::writeToStream, &stream, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Png: return stbi_write_png_to_func(&ImageSaver::writeToStream, &stream, size.x(), size.y(), parameters.channels, pixels, parameters.stride) != 0;
                case ImageFormat_Jpg: return stbi_write_jpg_to_func(&ImageSaver::writeToStream, &stream, size.x(), size.y(), parameters.channels, pixels, parameters.quality) != 0;
            }

            return false;
        }

        bool ImageSaver::saveToMemory(const Image* image, void* data, std::size_t length, const ImageParameters& parameters) const
        {
            PixelBuffer buffer;
            Vector2UI size = image->getSize();
            const Uint8* pixels = image->getPixels().getBuffer();

            buffer.data   = data;
            buffer.length = length;

            switch(parameters.format)
            {
                case ImageFormat_Bmp: return stbi_write_bmp_to_func(&ImageSaver::writeToMemory, &buffer, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Tga: return stbi_write_tga_to_func(&ImageSaver::writeToMemory, &buffer, size.x(), size.y(), parameters.channels, pixels) != 0;
                case ImageFormat_Png: return stbi_write_png_to_func(&ImageSaver::writeToMemory, &buffer, size.x(), size.y(), parameters.channels, pixels, parameters.stride)  != 0;
                case ImageFormat_Jpg: return stbi_write_jpg_to_func(&ImageSaver::writeToMemory, &buffer, size.x(), size.y(), parameters.channels, pixels, parameters.quality) != 0;
            }

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
                case ImageFormat_Jpg: return true;
                case ImageFormat_Png: return true;
                case ImageFormat_Bmp: return true;
                case ImageFormat_Tga: return true;
            }

            return false;
        }
    }
}