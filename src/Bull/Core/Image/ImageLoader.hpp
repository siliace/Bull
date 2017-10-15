#ifndef BULL_CORE_IMAGE_IMAGELOADER_HPP
#define BULL_CORE_IMAGE_IMAGELOADER_HPP

#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Resource/AbstractResourceLoader.hpp>

namespace Bull
{
    namespace prv
    {
        struct ImageLoader : public AbstractResourceLoader<Image, ImageParameters>
        {
            /*! \brief Save a Resource to path
             *
             * \param resource
             * \param path
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromPath(Image* resource, const Path& path, const ImageParameters& parameters) const override;

            /*! \brief Save a Resource to stream
             *
             * \param resource
             * \param stream
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromStream(Image* resource, InStream& stream, const ImageParameters& parameters) const override;

            /*! \brief Save a Resource to a memory area
             *
             * \param resource
             * \param data
             * \param length
             * \param parameters
             *
             * \return
             *
             */
            bool loadFromMemory(Image* resource, const void* data, Index length, const ImageParameters& parameters) const override;

            /*! \brief Tell whether the extension is supported
             *
             * \param extension The extension to check
             *
             * \return True if the extension is supported
             *
             */
            bool isFormatSupported(const String& extension) const override;

            /*! \brief Tell whether parameters are supported
             *
             * \param parameters Parameters to check
             *
             * \return True if the parameters are supported
             *
             */
            bool isParametersSupported(const ImageParameters& parameters) const override;
        };
    }
}

#endif // BULL_CORE_IMAGE_IMAGELOADER_HPP
