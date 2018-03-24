#include <stb_image/stb_image.h>

#include <Bull/Core/Image/ImageLoader.hpp>
#include <Bull/Core/IO/OutStringStream.hpp>
#include <Bull/Core/Log/Log.hpp>
#include <Bull/Core/Utility/CleanupCallback.hpp>

namespace Bull
{
    int ImageLoader::read(void* user, char* data, int size)
    {
        InStream* stream = reinterpret_cast<InStream*>(user);

        return stream->read(data, size);
    }

    void ImageLoader::skip(void* user, int n)
    {
        ByteArray buffer(n);
        InStream* stream = reinterpret_cast<InStream*>(user);

        stream->read(&buffer[0], buffer.getCapacity());
    }

    int ImageLoader::eof(void* user)
    {
        InStream* stream = reinterpret_cast<InStream*>(user);

        return stream->isAtEnd() ? 1 : 0;
    }

    bool ImageLoader::getInfo(ImageInfo& info, const Path& path)
    {
        return createTask([&info, path]() -> bool{
            return stbi_info(path.toString().getBuffer(),
                             reinterpret_cast<int*>(&info.size.width),
                             reinterpret_cast<int*>(&info.size.height),
                             reinterpret_cast<int*>(&info.channels)) == 0;
        });
    }

    bool ImageLoader::getInfo(ImageInfo& info, InStream& stream)
    {
        return createTask([&info, &stream]() -> bool{
            stbi_io_callbacks callbacks;

            callbacks.read = &ImageLoader::read;
            callbacks.skip = &ImageLoader::skip;
            callbacks.eof  = &ImageLoader::eof;

            return stbi_info_from_callbacks(&callbacks, &stream,
                                            reinterpret_cast<int*>(&info.size.width),
                                            reinterpret_cast<int*>(&info.size.height),
                                            reinterpret_cast<int*>(&info.channels)) == 0;
        });
    }

    bool ImageLoader::getInfo(ImageInfo& info, const void* data, std::size_t length)
    {
        return createTask([&info, data, length]() -> bool{
            return stbi_info_from_memory(reinterpret_cast<const stbi_uc*>(data), length,
                                         reinterpret_cast<int*>(&info.size.width),
                                         reinterpret_cast<int*>(&info.size.height),
                                         reinterpret_cast<int*>(&info.channels)) == 0;
        });
    }

    bool ImageLoader::loadFromPath(AbstractImage& image, const Path& path)
    {
        return createTask([&image, path, this]() -> bool{
            int width, height, channels;
            stbi_uc* buffer = stbi_load(path.toString().getBuffer(), &width, &height, &channels, STBI_rgb_alpha);

            CleanupCallback cleanupCallback([buffer](){
                stbi_image_free(buffer);
            });

            if(!createImage(image, buffer, width, height, channels))
            {
                OutStringStream oss;
                oss << "Failed to load image from path " << path.toString() << " : " << getErrorMessage();

                Log::getInstance()->error(oss.toString());

                return false;
            }

            return true;
        });
    }

    bool ImageLoader::loadFromStream(AbstractImage& image, InStream& stream)
    {
        return createTask([&image, &stream, this]() -> bool{
            stbi_io_callbacks callbacks;
            int width, height, channels;

            callbacks.read = &ImageLoader::read;
            callbacks.skip = &ImageLoader::skip;
            callbacks.eof  = &ImageLoader::eof;

            stbi_uc* buffer = stbi_load_from_callbacks(&callbacks, &stream, &width, &height, &channels, STBI_rgb_alpha);

            CleanupCallback cleanupCallback([buffer](){
                stbi_image_free(buffer);
            });

            if(!createImage(image, buffer, width, height, channels))
            {
                OutStringStream oss;
                oss << "Failed to load image from stream : " << getErrorMessage();

                Log::getInstance()->error(oss.toString());

                return false;
            }

            return true;
        });
    }

    bool ImageLoader::loadFromMemory(AbstractImage& image, const void* data, std::size_t length)
    {
        return createTask([&image, data, length, this]() -> bool{
            int width, height, channels;
            stbi_uc* buffer = stbi_load_from_memory(reinterpret_cast<const stbi_uc*>(data), length, &width, &height, &channels, STBI_rgb_alpha);

            CleanupCallback cleanupCallback([buffer](){
                stbi_image_free(buffer);
            });

            if(!createImage(image, buffer, width, height, channels))
            {
                OutStringStream oss;
                oss << "Failed to load image from memory : " << getErrorMessage();

                Log::getInstance()->error(oss.toString());

                return false;
            }

            return true;
        });
    }

    String ImageLoader::getErrorMessage() const
    {
        m_mutex.lock();
        String message(stbi_failure_reason());
        m_mutex.unlock();

        return message;
    }

    bool ImageLoader::createImage(AbstractImage& image, const void* buffer, int width, int height, int channels)
    {
        if(buffer && width && height)
        {
            ByteArray pixels;

            if(pixels.fill(buffer, width * height * channels))
            {
                Size size(width, height);

                return image.create(pixels, size);
            }
        }

        return false;
    }
}