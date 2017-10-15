#include <Bull/Core/Image/ImageSaver.hpp>

namespace Bull
{
    bool ImageSaver::saveToPath(const Image* resource, const Path& path, const ImageParameters& parameters) const
    {
        return false;
    }

    bool ImageSaver::saveToStream(const Image* resource, OutStream& stream, const ImageParameters& parameters) const
    {
        return false;
    }

    bool ImageSaver::saveToMemory(const Image* resource, void* data, Index length, const ImageParameters& parameters) const
    {
        return false;
    }

    bool ImageSaver::isFormatSupported(const String& extension) const
    {
        return false;
    }

    bool ImageSaver::isParametersSupported(const ImageParameters& parameters) const
    {
        return false;
    }
}