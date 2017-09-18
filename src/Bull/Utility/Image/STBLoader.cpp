#include <stb_image/stb_image.h>

#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Utility/CallOnExit.hpp>
#include <Bull/Utility/Image/Image.hpp>
#include <Bull/Utility/Image/STBLoader.hpp>

namespace Bull
{
    namespace prv
    {
        int STBLoader::read(void *user, char *data, int size)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            return stream->read(data, size);
        }

        void STBLoader::skip(void *user, int n)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            stream->setCursor(stream->getCursor() + n);
        }

        int STBLoader::eof(void *user)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            stream->getCursor() == stream->getSize();
        }

        bool STBLoader::isSupportedFormat(ImageFormat format) const
        {
            switch(format)
            {
                case ImageFormat::Png: return true;
                case ImageFormat::Jpg: return true;
                case ImageFormat::Bmp: return true;
                case ImageFormat::Tga: return true;
            }

            return false;
        }

        bool STBLoader::loadFromPath(Image* image, const Path& path, const ImageParameterBag& parameters) const
        {
            int w, h, channels;

            unsigned char* buffer = stbi_load(path.toString().getBuffer(), &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels(w * h * 4);

                if(pixels.fill(buffer, w * h * 4))
                {
                    return image->create(pixels, Vector2UI(w, h));
                }
            }

            return false;
        }

        bool STBLoader::loadFromStream(Image* image, InStream& stream, const ImageParameterBag& parameters) const
        {
            int w, h, channels;
            stbi_io_callbacks callbacks;
            callbacks.read = read;
            callbacks.skip = skip;
            callbacks.eof  = eof;

            unsigned char* buffer = stbi_load_from_callbacks(&callbacks, &stream, &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels(w * h * 4);

                if(pixels.fill(buffer, w * h * 4))
                {
                    return image->create(pixels, Vector2UI(w, h));
                }
            }

            return false;
        }

        bool STBLoader::loadFromMemory(Image* image, const void* data, Index length, const ImageParameterBag& parameters) const
        {
            int w, h, channels;

            unsigned char* buffer = stbi_load_from_memory(reinterpret_cast<const unsigned char*>(data), length, &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels(w * h * 4);

                if(pixels.fill(buffer, w * h * 4))
                {
                    return image->create(pixels, Vector2UI(w, h));
                }
            }

            return false;
        }
    }
}