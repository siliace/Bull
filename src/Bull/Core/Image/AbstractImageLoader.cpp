#define STB_IMAGE_IMPLEMENTATION

#include <stb_image/stb_image.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Image/AbstractImageLoader.hpp>
#include <Bull/Core/Image/PixelFormatUtils.hpp>

namespace Bull
{
    namespace stbi
    {
        int channels(PixelFormat pixelFormat)
        {
            switch(pixelFormat)
            {
                case PixelFormat_Luma8:
                    return STBI_grey;
                case PixelFormat_Luma8Alpha8:
                    return STBI_grey_alpha;
                case PixelFormat_Rgb8:
                    return STBI_rgb;
                case PixelFormat_Rgb8Alpha8:
                    return STBI_rgb_alpha;
            }

            return 0;
        }
    }

    std::string AbstractImageLoader::getErrorMessage() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);

        return stbi_failure_reason();
    }

    AbstractImageLoader::RawImage AbstractImageLoader::loadPixelsFromStream(InStream& stream, PixelFormat pixelFormat) const
    {
        int channels;
        int width, height;
        stbi_io_callbacks callbacks;

        callbacks.read = [](void* user, char* data, int size) -> int
        {
            ByteArray bytes = reinterpret_cast<InStream*>(user)->read(size);

            std::memcpy(data, bytes.getBuffer(), bytes.getCapacity());

            return bytes.getCapacity();
        };

        callbacks.skip = [](void* user, int n)
        {
            reinterpret_cast<InStream*>(user)->skip(n);
        };

        callbacks.eof = [](void* user) -> int
        {
            return reinterpret_cast<InStream*>(user)->isAtEnd() ? 1 : 0;
        };

        stbi_uc* buffer = stbi_load_from_callbacks(&callbacks, &stream, &width, &height, &channels, stbi::channels(pixelFormat));

        Expect(buffer, Throw(InternalError, "Failed to load image: " + getErrorMessage()));

        Size<std::size_t> size(width, height);
        ByteArray pixels = ByteArray::memoryCopy(buffer, PixelFormatUtils::getImageByteCount(size, pixelFormat));

        stbi_image_free(buffer);

        return {pixels, size, channels};
    }
}
