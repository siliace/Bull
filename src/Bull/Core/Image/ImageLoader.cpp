#include <algorithm>

#include <stb_image/stb_image.h>

#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Utility/CleanupCallback.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageLoader::loadFromPath(Image* image, const Path& path, const ImageParameters& parameters) const
        {
            File file(path);

            if(file.isOpen())
            {
                return loadFromStream(image, file, parameters);
            }

            return false;
        }

        bool ImageLoader::loadFromStream(Image* image, InStream& stream, const ImageParameters& parameters) const
        {
            String content = stream.readAll();

            return loadFromMemory(image, content.getBuffer(), content.getSize(), parameters);
        }

        bool ImageLoader::loadFromMemory(Image* image, const void* data, std::size_t length, const ImageParameters& parameters) const
        {
            int w, h, channels;

            stbi_uc* buffer = stbi_load_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &w, &h, &channels, parameters.channels);

            if(buffer && w && h)
            {
                ByteVector pixels;
                CleanupCallback cleanup([buffer](){
                    stbi_image_free(buffer);
                });

                if(pixels.fill(buffer, w * h * parameters.channels))
                {
                    return image->create(pixels, Vector2I(w, h));
                }
            }

            return false;
        }

        bool ImageLoader::isFormatSupported(const String& extension) const
        {
            static std::vector<String> extensions = {
                "jpg", "jpeg", "png", "bmp", "psd", "tga", "gif", "hdr", "pic", "pnm"
            };

            return std::find(extensions.begin(), extensions.end(), extension) != extensions.end();
        }

        bool ImageLoader::isParametersSupported(const ImageParameters& parameters) const
        {
            return true;
        }
    }
}