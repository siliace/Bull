#include <Bull/Core/Image/ImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        bool ImageLoader::loadFromPath(Image* resource, const Path& path, const ImageParameters& parameters) const
        {
            return false;
        }

        bool ImageLoader::loadFromStream(Image* resource, InStream& stream, const ImageParameters& parameters) const
        {
            return false;
        }

        bool ImageLoader::loadFromMemory(Image* resource, const void* data, Index length, const ImageParameters& parameters) const
        {
            return false;
        }

        bool ImageLoader::isFormatSupported(const String& extension) const
        {
            return false;
        }

        bool ImageLoader::isParametersSupported(const ImageParameters& parameters) const
        {
            return false;
        }
    }
}