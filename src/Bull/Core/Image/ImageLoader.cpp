#include <stb_image/stb_image.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Utility/Finally.hpp>

namespace Bull
{
    int ImageLoader::read(void* user, char* data, int size)
    {
        return reinterpret_cast<InStream*>(user)->read(data, size);
    }

    void ImageLoader::skip(void* user, int n)
    {
        std::vector<Uint8> buffer(n);
        reinterpret_cast<InStream*>(user)->read(buffer.data(), buffer.capacity());
    }

    int ImageLoader::eof(void* user)
    {
        return reinterpret_cast<InStream*>(user)->isAtEnd() ? 1 : 0;
    }

    ImageLoader::ImageInfo ImageLoader::getInfo(const Path& path) const
    {
        ImageInfo info;

        stbi_info(path.toString().getBuffer(), &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels));

        return info;
    }

    ImageLoader::ImageInfo ImageLoader::getInfo(InStream& stream) const
    {
        ImageInfo info;
        stbi_io_callbacks callbacks;

        callbacks.read = &ImageLoader::read;
        callbacks.skip = &ImageLoader::skip;
        callbacks.eof  = &ImageLoader::eof;

        stbi_info_from_callbacks(&callbacks, &stream, &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels));

        return info;
    }

    ImageLoader::ImageInfo ImageLoader::getInfo(const void* data, std::size_t length) const
    {
        ImageInfo info;

        stbi_info_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &info.size.width, &info.size.height, reinterpret_cast<int*>(&info.channels));

        return info;
    }

    Image ImageLoader::loadFromPath(const Path& path) const
    {
        Image image;
        int width, height, channels;
        stbi_uc* buffer = stbi_load(path.toString().getBuffer(), &width, &height, &channels, STBI_rgb_alpha);

        Expect(buffer, Throw(InternalError, "ImageLoader::loadFromPath", "Failed to load image: " + getErrorMessage()));

        image = createImage(buffer, width, height, channels);

        stbi_image_free(buffer);

        return image;
    }

    Image ImageLoader::loadFromStream(InStream& stream) const
    {
        Image image;
        stbi_io_callbacks callbacks;
        int width, height, channels;

        callbacks.read = &ImageLoader::read;
        callbacks.skip = &ImageLoader::skip;
        callbacks.eof  = &ImageLoader::eof;

        stbi_uc* buffer = stbi_load_from_callbacks(&callbacks, &stream, &width, &height, &channels, STBI_rgb_alpha);

        Expect(buffer, Throw(InternalError, "ImageLoader::loadFromStream", "Failed to load image: " + getErrorMessage()));

        image = createImage(buffer, width, height, channels);

        stbi_image_free(buffer);

        return image;
    }

    Image ImageLoader::loadFromMemory(const void* data, std::size_t length) const
    {
        Image image;
        int width, height, channels;
        stbi_uc* buffer = stbi_load_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &width, &height, &channels, STBI_rgb_alpha);

        Expect(buffer, Throw(InternalError, "ImageLoader::loadFromMemory", "Failed to load image: " + getErrorMessage()));

        image = createImage(buffer, width, height, channels);

        stbi_image_free(buffer);

        return image;
    }

    String ImageLoader::getErrorMessage() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        return stbi_failure_reason();
    }

    Image ImageLoader::createImage(const unsigned char* buffer, int width, int height, int channels) const
    {
        Image image;
        std::vector<Uint8> pixels;

        pixels.resize(width * height * channels, 0);

        std::memcpy(&pixels[0], buffer, pixels.capacity());

        image.create(pixels, Size(width, height));

        return image;
    }
}
