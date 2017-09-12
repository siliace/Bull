#ifndef BULL_UTILITY_IMAGE_STBSAVER_HPP
#define BULL_UTILITY_IMAGE_STBSAVER_HPP

#include <Bull/Utility/Image/AbstractImageSaver.hpp>

namespace Bull
{
    namespace prv
    {
        struct STBSaver : public AbstractImageSaver
        {
            /*! \brief Tell whether an ImageFormat is supported
             *
             * \param format The format to test
             *
             * \return True if the format is supported
             *
             */
            bool isSupportedFormat(ImageFormat format) const override;

            /*! \brief Tell whether a file extension is supported
             *
             * \param extension The extension
             *
             * \return True if the extension is supported
             *
             */
            bool isSupportedExtension(const String& extension) const override;

            /*! \brief Save a Image to a file
             *
             * \param resource The Image to save
             * \param path     The Path to save the Image
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToPath(const Image& resource, const Path& path) const override;

            /*! \brief Save a Image to a stream
             *
             * \param resource The Image to save
             * \param stream   The stream to write
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToStream(const Image& resource, OutStream& stream) const override;

            /*! \brief Save a Image to a memory area
             *
             * \param resource The Image to save
             * \param data     Data to save the Image
             * \param length   The length of data
             *
             * \return True if the Image was saved successfully
             *
             */
            bool saveToMemory(const Image& resource, void* data, Index length) const override;
        };
    }
}

#endif // BULL_UTILITY_IMAGE_STBSAVER_HPP
