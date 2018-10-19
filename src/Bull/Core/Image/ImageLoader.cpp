#include <stb_image/stb_image.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/IO/MemoryStream.hpp>

namespace Bull
{
    namespace stbi
    {
        int channels(PixelFormat pixelFormat)
        {
            switch(pixelFormat)
            {
                case PixelFormat_Luma8: return STBI_grey;
                case PixelFormat_Luma8Alpha8: return STBI_grey_alpha;
                case PixelFormat_Rgb8: return STBI_rgb;
                case PixelFormat_Rgb8Alpha8: return STBI_rgb_alpha;
            }
        }
    }

    std::shared_ptr<Image> ImageLoader::loadFromPath(const Path& path, PixelFormat pixelFormat) const
    {
        File file(path, FileOpeningMode_Read);

        return loadFromStream(file, pixelFormat);
    }

    std::shared_ptr<Image> ImageLoader::loadFromStream(InStream& stream, PixelFormat pixelFormat) const
    {
        Size size;
        int channels;
        stbi_io_callbacks callbacks;
        std::shared_ptr<Image> image;

        callbacks.read = [](void* user, char* data, int size) -> int {
            ByteArray bytes = reinterpret_cast<InStream*>(user)->read(size);

            std::memcpy(data, bytes.getBuffer(), bytes.getCapacity());

            return bytes.getCapacity();
        };

        callbacks.skip = [](void* user, int n) {
            reinterpret_cast<InStream*>(user)->skip(n);
        };

        callbacks.eof  = [](void* user) -> int {
            return reinterpret_cast<InStream*>(user)->isAtEnd() ? 1 : 0;
        };

        stbi_uc* buffer = stbi_load_from_callbacks(&callbacks, &stream, &size.width, &size.height, &channels, stbi::channels(pixelFormat));

        Expect(buffer, Throw(InternalError, "ImageLoader::loadFromStream", "Failed to load image: " + getErrorMessage()));

        std::size_t bytesCount = PixelFormatUtils::getImageByteCount(size, pixelFormat);

        image = std::make_shared<Image>(ByteArray::memoryCopy(buffer, bytesCount), size, pixelFormat);

        stbi_image_free(buffer);

        return std::shared_ptr<Image>(image);
    }

    std::shared_ptr<Image> ImageLoader::loadFromMemory(const void* data, std::size_t length, PixelFormat pixelFormat) const
    {
        MemoryStream memoryStream(data, length);

        return loadFromStream(memoryStream, pixelFormat);
    }

    String ImageLoader::getErrorMessage() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        return stbi_failure_reason();
    }
}
