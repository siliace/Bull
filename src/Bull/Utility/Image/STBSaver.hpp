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
             * \param format The ImageFormat to test
             *
             * \return True if the ImageFormat is supported
             *
             */
            bool isSupportedFormat(ImageFormat format) const override;

            /*! \brief Save a Resource to a file
             *
             * \param resource   The Resource to save
             * \param path       The Path to save the Resource
             * \param parameters Parameters to save the Resource
             *
             * \return True if the Resource was saved successfully
             *
             */
            bool saveToPath(const Image* resource, const Path& path, const ImageParameterBag& parameters) const override;

            /*! \brief Save a Resource to a stream
             *
             * \param resource   The Resource to save
             * \param stream     The stream to write
             * \param parameters Parameters to save the Resource
             *
             * \return True if the Resource was saved successfully
             *
             */
            bool saveToStream(const Image* resource, OutStream& stream, const ImageParameterBag& parameters) const override;

            /*! \brief Save a Resource to a memory area
             *
             * \param resource   The Resource to save
             * \param data       Memory to write to save the Resource
             * \param length     The length of the memory
             * \param parameters Parameters to save the Resource
             *
             * \return True if the Resource was saved successfully
             *
             */
            bool saveToMemory(const Image* resource, void* data, Index length, const ImageParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_UTILITY_IMAGE_STBSAVER_HPP
