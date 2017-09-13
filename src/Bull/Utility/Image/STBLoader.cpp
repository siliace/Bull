#include <algorithm>

#ifndef STBI_NO_STDIO
    #define STBI_NO_STDIO
#endif

#include <stb_image/stb_image.h>

#include <Bull/Utility/CallOnExit.hpp>
#include <Bull/Utility/Image/STBLoader.hpp>

namespace Bull
{
    namespace prv
    {
        int STBLoader::read(void* user, char* data, int size)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            return static_cast<int>(stream->read(data, size));
        }

        void STBLoader::skip(void *user, int n)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            stream->setCursor(stream->getCursor() + n);
        }

        int STBLoader::eof(void* user)
        {
            InStream* stream = reinterpret_cast<InStream*>(user);
            return stream->getCursor() == stream->getSize();
        }

        bool STBLoader::isSupportedFormat(ImageFormat format) const
        {
            switch(format)
            {
                case ImageFormat::Bmp: return true;
                case ImageFormat::Png: return true;
                case ImageFormat::Tga: return true;
                case ImageFormat::Jpg: return true;
                default:               return false;
            }
        }

        bool STBLoader::isSupportedExtension(const String& extension) const
        {
            static std::vector<String> supportedExtensions = {
                    "bmp", "png", "tga", "jpg", "jpeg"
            };

            return std::find(supportedExtensions.begin(), supportedExtensions.end(), extension) != supportedExtensions.end();
        }

        bool STBLoader::loadFromPath(std::unique_ptr<Image>& resource, const Path& path, const ParameterBag& parameters) const
        {
            int w, h;
            int channels;

            unsigned char* buffer = stbi_load(path.toString().getBuffer(), &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels;

                if(pixels.fill(buffer, w * h * 4))
                {
                    return loadFromPixels(resource, pixels, Vector2UI(w, h), parameters);
                }
            }

            return false;
        }

        bool STBLoader::loadFromStream(std::unique_ptr<Image>& resource, InStream& stream, const ParameterBag& parameters) const
        {
            int w, h;
            int channels;
            stbi_io_callbacks callbacks;

            callbacks.read = &read;
            callbacks.skip = &skip;
            callbacks.eof  = &eof;

            unsigned char* buffer = stbi_load_from_callbacks(&callbacks, &stream, &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels;

                if(pixels.fill(buffer, w * h * 4))
                {
                    return loadFromPixels(resource, pixels, Vector2UI(w, h), parameters);
                }
            }

            return false;
        }

        bool STBLoader::loadFromMemory(std::unique_ptr<Image>& resource, const void* data, Index length, const ParameterBag& parameters) const
        {
            int w, h;
            int channels;

            unsigned char* buffer = stbi_load_from_memory(reinterpret_cast<const unsigned char*>(data), length, &w, &h, &channels, STBI_rgb_alpha);

            if(buffer && w && h)
            {
                CallOnExit atExit([buffer](){
                    stbi_image_free(buffer);
                });

                ByteArray pixels;

                if(pixels.fill(buffer, w * h * 4))
                {
                    return loadFromPixels(resource, pixels, Vector2UI(w, h), parameters);
                }
            }

            return false;
        }

        bool STBLoader::loadFromPixels(std::unique_ptr<Image>& resource, const ByteArray& pixels, const Vector2UI& size, const ParameterBag& parameters) const
        {
            return resource->create(pixels, size);
        }
    }
}