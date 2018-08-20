#include <stb_image/stb_image.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/FileSystem/FileImpl.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/Memory/MemoryStream.hpp>

namespace Bull
{
    int ImageLoader::read(void* user, char* data, int size)
    {
        ByteArray bytes = reinterpret_cast<InStream*>(user)->read(size);

        std::memcpy(data, bytes.getBuffer(), bytes.getCapacity());

        return bytes.getCapacity();
    }

    void ImageLoader::skip(void* user, int n)
    {
        reinterpret_cast<InStream*>(user)->skip(n);
    }

    int ImageLoader::eof(void* user)
    {
        return reinterpret_cast<InStream*>(user)->isAtEnd() ? 1 : 0;
    }

    ImageLoader::ImageInfo ImageLoader::getInfo(const Path& path) const
    {
        File file = path.toFile(FileOpeningMode_Read);

        return getInfo(file);
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
        MemoryStream memoryStream(data, length);

        return getInfo(memoryStream);
    }

    Image ImageLoader::loadFromPath(const Path& path) const
    {
        File file = path.toFile(FileOpeningMode_Read);

        return loadFromStream(file);
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
        MemoryStream memoryStream(data, length);

        return loadFromStream(memoryStream);
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
