#include <cstring>

#include <stb_image/stb_image.h>
#include <stb_image/stb_image_write.h>

#include <Bull/Utility/Image/ImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        int ImageLoader::read(void* user, char* data, int size)
        {
            InStream* stream = static_cast<InStream*>(user);
            return static_cast<int>(stream->read(data, size));
        }

        void ImageLoader::skip(void* user, int size)
        {
            InStream* stream = static_cast<InStream*>(user);
            stream->setCursor(stream->getCursor() + size);
        }

        int ImageLoader::eof(void* user)
        {
            InStream* stream = static_cast<InStream*>(user);
            return stream->getCursor() >= stream->getSize();
        }

        void ImageLoader::writeToStream(void* context, void* data, int size)
        {
            OutStream* stream = static_cast<OutStream*>(context);
            stream->write(data, size);
        }

        void ImageLoader::writeToMemory(void* context, void* data, int size)
        {
            Buffer* buffer = static_cast<Buffer*>(context);
            std::memcpy(data, buffer->data, buffer->size);
        }

        bool ImageLoader::loadFromPath(const Path& path, ByteArray& pixels, Vector2UI& size) const
        {
            int width, height, channels;
            unsigned char* buffer = stbi_load(path.toString().getBuffer(), &width, &height, &channels, STBI_rgb_alpha);

            pixels.destroy();

            if(buffer)
            {
                size.x = static_cast<unsigned int>(width);
                size.y = static_cast<unsigned int>(height);

                if(size.x && size.y)
                {
                    pixels.resize(size.x * size.y * 4);
                    std::memcpy(&pixels[0], buffer, pixels.getCapacity());
                }

                stbi_image_free(buffer);

                return true;
            }

            return false;
        }

        bool ImageLoader::loadFromStream(InStream& stream, ByteArray& pixels, Vector2UI& size) const
        {
            int width, height, channels;
            stbi_io_callbacks callbacks;
            callbacks.read = &ImageLoader::read;
            callbacks.skip = &ImageLoader::skip;
            callbacks.eof  = &ImageLoader::eof;

            pixels.destroy();

            stream.setCursor(0);

            unsigned char* buffer = stbi_load_from_callbacks(&callbacks, &stream, &width, &height, &channels, STBI_rgb_alpha);

            if(buffer)
            {
                size.x = static_cast<unsigned int>(width);
                size.y = static_cast<unsigned int>(height);

                if(size.x && size.y)
                {
                    pixels.resize(size.x * size.y * 4);
                    std::memcpy(&pixels[0], buffer, pixels.getCapacity());
                }

                stbi_image_free(buffer);

                return true;
            }

            return false;
        }

        bool ImageLoader::loadFromMemory(const void* data, Index dataSize, ByteArray& pixels, Vector2UI& size) const
        {
            if(data && dataSize)
            {
                int width, height, channels;
                unsigned char* buffer = stbi_load_from_memory(static_cast<const unsigned char*>(data), dataSize, &width, &height, &channels, STBI_rgb_alpha);

                pixels.destroy();

                if(buffer)
                {
                    size.x = static_cast<unsigned int>(width);
                    size.y = static_cast<unsigned int>(height);

                    if(size.x && size.y)
                    {
                        pixels.resize(size.x * size.y * 4);
                        std::memcpy(&pixels[0], buffer, pixels.getCapacity());
                    }

                    stbi_image_free(buffer);

                    return true;
                }

                return false;
            }

            return false;
        }

        bool ImageLoader::saveToPath(const Path& path, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const
        {
            switch(format)
            {
                case ImageFormat::Bmp: return saveBmpToPath(path.toString(), pixels, size);
                case ImageFormat::Tga: return saveTgaToPath(path.toString(), pixels, size);
                case ImageFormat::Png: return savePngToPath(path.toString(), pixels, size);
                case ImageFormat::Jpg:
                case ImageFormat::Jpeg: return false;
            }

            return false;
        }

        bool ImageLoader::saveToStream(OutStream& outStream, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const
        {
            switch(format)
            {
                case ImageFormat::Bmp: return saveBmpToStream(outStream, pixels, size);
                case ImageFormat::Tga: return saveTgaToStream(outStream, pixels, size);
                case ImageFormat::Png: return savePngToStream(outStream, pixels, size);
                case ImageFormat::Jpg:
                case ImageFormat::Jpeg: return false;
            }

            return false;
        }

        bool ImageLoader::saveToMemory(void* data, Index dataSize, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const
        {
            switch(format)
            {
                case ImageFormat::Bmp: return saveBmpToMemory(data, dataSize, pixels, size);
                case ImageFormat::Tga: return saveTgaToMemory(data, dataSize, pixels, size);
                case ImageFormat::Png: return savePngToMemory(data, dataSize, pixels, size);
                case ImageFormat::Jpg:
                case ImageFormat::Jpeg: return false;
            }

            return false;
        }

        bool ImageLoader::saveBmpToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".bmp"))
            {
                fullPath += ".bmp";
            }

            return stbi_write_bmp(fullPath.getBuffer(), size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::saveBmpToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const
        {
            return stbi_write_bmp_to_func(&ImageLoader::writeToStream, &stream, size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::saveBmpToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const
        {
            Buffer buffer;
            buffer.data = data;
            buffer.size = dataSize;

            return stbi_write_bmp_to_func(&ImageLoader::writeToMemory, &buffer, size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::savePngToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".png"))
            {
                fullPath += ".png";
            }

            return stbi_write_png(fullPath.getBuffer(), size.x, size.y, 4, &pixels[0], 0) != 0;
        }

        bool ImageLoader::savePngToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const
        {
            return stbi_write_png_to_func(&ImageLoader::writeToStream, &stream, size.x, size.y, 4, &pixels[0], 0) != 0;
        }

        bool ImageLoader::savePngToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const
        {
            Buffer buffer;
            buffer.data = data;
            buffer.size = dataSize;

            return stbi_write_png_to_func(&ImageLoader::writeToMemory, &buffer, size.x, size.y, 4, &pixels[0], 0) != 0;
        }

        bool ImageLoader::saveTgaToPath(const String& path, const ByteArray& pixels, const Vector2UI& size) const
        {
            String fullPath = path;

            if(!fullPath.endsWith(".tga"))
            {
                fullPath += ".tga";
            }

            return stbi_write_tga(fullPath.getBuffer(), size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::saveTgaToStream(OutStream& stream, const ByteArray& pixels, const Vector2UI& size) const
        {
            return stbi_write_tga_to_func(&ImageLoader::writeToStream, &stream, size.x, size.y, 4, &pixels[0]) != 0;
        }

        bool ImageLoader::saveTgaToMemory(void* data, Index dataSize, const ByteArray& pixels, const Vector2UI& size) const
        {
            Buffer buffer;
            buffer.data = data;
            buffer.size = dataSize;

            return stbi_write_tga_to_func(&ImageLoader::writeToMemory, &buffer, size.x, size.y, 4, &pixels[0]) != 0;
        }
    }
}
