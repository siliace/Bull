#include <stb_image/stb_image.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/Throw.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Utility/CleanupCallback.hpp>

namespace Bull
{
    int ImageLoader::read(void* user, char* data, int size)
    {
        return reinterpret_cast<InStream*>(user)->read(data, size);
    }

    void ImageLoader::skip(void* user, int n)
    {
        ByteArray buffer(n);
        reinterpret_cast<InStream*>(user)->read(&buffer[0], buffer.getCapacity());
    }

    int ImageLoader::eof(void* user)
    {
        return reinterpret_cast<InStream*>(user)->isAtEnd() ? 1 : 0;
    }

    void ImageLoader::getInfo(ImageInfo& info, const Path& path)
    {
        createTask([&info, path]() {
            stbi_info(path.toString().getBuffer(), &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels));
        });
    }

    void ImageLoader::getInfo(ImageInfo& info, InStream& stream)
    {
        createTask([&info, &stream]() {
            stbi_io_callbacks callbacks;

            callbacks.read = &ImageLoader::read;
            callbacks.skip = &ImageLoader::skip;
            callbacks.eof  = &ImageLoader::eof;

            stbi_info_from_callbacks(&callbacks, &stream, &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels));
        });
    }

    void ImageLoader::getInfo(ImageInfo& info, const void* data, std::size_t length)
    {
        createTask([&info, data, length]() {
            stbi_info_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels)) == 0;
        });
    }

    void ImageLoader::loadFromPath(AbstractImage& image, const Path& path)
    {
        createTask([&image, path, this]() {
            int width, height, channels;
            stbi_uc* buffer = stbi_load(path.toString().getBuffer(), &width, &height, &channels, STBI_rgb_alpha);

            createImage(image, buffer, width, height, channels);

            stbi_image_free(buffer);
        });
    }

    void ImageLoader::loadFromStream(AbstractImage& image, InStream& stream)
    {
        createTask([&image, &stream, this]() -> bool{
            stbi_io_callbacks callbacks;
            int width, height, channels;

            callbacks.read = &ImageLoader::read;
            callbacks.skip = &ImageLoader::skip;
            callbacks.eof  = &ImageLoader::eof;

            stbi_uc* buffer = stbi_load_from_callbacks(&callbacks, &stream, &width, &height, &channels, STBI_rgb_alpha);

            createImage(image, buffer, width, height, channels);

            stbi_image_free(buffer);
        });
    }

    void ImageLoader::loadFromMemory(AbstractImage& image, const void* data, std::size_t length)
    {
        createTask([&image, data, length, this]() -> bool{
            int width, height, channels;
            stbi_uc* buffer = stbi_load_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &width, &height, &channels, STBI_rgb_alpha);

            createImage(image, buffer, width, height, channels);

            stbi_image_free(buffer);
        });
    }

    String ImageLoader::getErrorMessage() const
    {
        Lock lock(m_mutex);

        return stbi_failure_reason();
    }

    void ImageLoader::createImage(AbstractImage& image, const void* buffer, int width, int height, int channels)
    {
        ByteArray pixels;

        pixels.fill(buffer, width * height * channels);

        if(!image.create(pixels, Size(width, height)))
        {
            Throw(InternalError, "ImageLoader::createImage", "Failed to create AbstractImage");
        }
    }
}