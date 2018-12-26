#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image_write.h>

#include <Bull/Core/Exception/InternalError.hpp>
#include <Bull/Core/Exception/InvalidParameter.hpp>
#include <Bull/Core/FileSystem/File.hpp>
#include <Bull/Core/Image/AbstractImageSaver.hpp>
#include <Bull/Core/Image/PixelFormatUtils.hpp>
#include <Bull/Core/Memory/MemoryAccumulator.hpp>

namespace Bull
{
    void AbstractImageSaver::write(void* context, void* data, int size)
    {
        /// stb_image_write sometimes send data with size == 0
        if(size)
        {
            static_cast<OutStream*>(context)->write(ByteArray::memoryCopy(data, size));
        }
    }

    File AbstractImageSaver::saveToPath(const Path& path, const AbstractImage& image, const AbstractImageSaver::Parameters& parameters) const
    {
        File file(path, FileOpeningMode_Write | FileOpeningMode_Truncate);
        saveToStream(file, image, parameters);

        return file;
    }

    OutStream& AbstractImageSaver::saveToStream(OutStream& stream, const AbstractImage& image, const AbstractImageSaver::Parameters& parameters) const
    {
        AbstractImage::Size size(image.getSize());
        int channels = PixelFormatUtils::getPixelFormatSize(image.getPixelFormat());

        switch(parameters.format)
        {
            case ImageFormat::Bmp:
                saveToBmp(stream, size, channels, image.getPixels());
                break;
            case ImageFormat::Tga:
                saveToTga(stream, size, channels, image.getPixels());
                break;
            case ImageFormat::Png:
                saveToPng(stream, size, channels, image.getPixels(), parameters.stride);
                break;
            case ImageFormat::Jpg:
                saveToJpg(stream, size, channels, image.getPixels(), parameters.quality);
                break;
            default:
                Throw(InvalidParameter, "Requested ImageFormat not supported");
                break;
        }

        return stream;
    }

    ByteArray AbstractImageSaver::saveToMemory(const AbstractImage& image, const AbstractImageSaver::Parameters& parameters) const
    {
        MemoryAccumulator accumulator;
        saveToStream(accumulator, image, parameters);

        return accumulator.getBytes();
    }

    void AbstractImageSaver::saveToBmp(OutStream& stream, const AbstractImage::Size& size, int channels, const ByteArray& pixels) const
    {
        int success = stbi_write_bmp_to_func(&AbstractImageSaver::write, &stream,
                                             size.width, size.height,
                                             channels,
                                             pixels.getBuffer());

        Expect(success != 0, Throw(InternalError, "Failed to write image in a stream"));
    }

    void AbstractImageSaver::saveToTga(OutStream& stream, const AbstractImage::Size& size, int channels, const ByteArray& pixels) const
    {
        int success = stbi_write_tga_to_func(&AbstractImageSaver::write, &stream,
                                             size.width, size.height,
                                             channels,
                                             pixels.getBuffer());

        Expect(success != 0, Throw(InternalError, "Failed to write image in a stream"));
    }

    void AbstractImageSaver::saveToPng(OutStream& stream, const AbstractImage::Size& size, int channels, const ByteArray& pixels, int stride) const
    {
        int success = stbi_write_png_to_func(&AbstractImageSaver::write, &stream,
                                             size.width, size.height,
                                             channels,
                                             pixels.getBuffer(),
                                             stride);

        Expect(success != 0, Throw(InternalError, "Failed to write image in a stream"));
    }

    void AbstractImageSaver::saveToJpg(OutStream& stream, const AbstractImage::Size& size, int channels, const ByteArray& pixels, int quality) const
    {
        quality = ((quality > 100) ? 100 : (quality < 0) ? 0 : quality);

        int success = stbi_write_jpg_to_func(&AbstractImageSaver::write, &stream,
                                             size.width, size.height,
                                             channels,
                                             pixels.getBuffer(),
                                             quality);

        Expect(success != 0, Throw(InternalError, "Failed to write image in a stream"));
    }
}