#ifndef BULL_CORE_IMAGE_STBLOADER_HPP
#define BULL_CORE_IMAGE_STBLOADER_HPP

#include <Bull/Core/Image/AbstractImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        struct STBLoader : public AbstractImageLoader
        {
            static int read(void *user, char *data, int size);

            static void skip(void *user, int n);

            static int eof(void *user);

            /*! \brief Tell whether an ImageFormat is supported
             *
             * \param format The ImageFormat to test
             *
             * \return True if the ImageFormat is supported
             *
             */
            bool isSupportedFormat(ImageFormat format) const override;

            /*! \brief Load a Image from a Path
             *
             * \param image      The Image to load
             * \param path       The path
             * \param parameters Parameters to create the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromPath(Image* image, const Path& path, const ImageParameterBag& parameters) const override;

            /*! \brief Load a Image from a Path
             *
             * \param image      The Image to load
             * \param stream     The stream to read to load
             * \param parameters Parameters to create the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromStream(Image* image, InStream& stream, const ImageParameterBag& parameters) const override;

            /*! \brief Load a Image from a memory area
             *
             * \param image      The Image to load
             * \param data       The memory
             * \param length     The length of data
             * \param parameters Parameters to create the Image
             *
             * \return True if the Image was loaded successfully
             *
             */
            bool loadFromMemory(Image* image, const void* data, Index length, const ImageParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_CORE_IMAGE_STBLOADER_HPP
