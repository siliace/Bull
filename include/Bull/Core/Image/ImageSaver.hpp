#ifndef BULL_CORE_IMAGE_IMAGESAVER_HPP
#define BULL_CORE_IMAGE_IMAGESAVER_HPP

#include <Bull/Core/Assets/AssetIOScheduler.hpp>
#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Image/ImageFormat.hpp>
#include <Bull/Core/Image/Image.hpp>
#include <Bull/Core/IO/OutStream.hpp>

namespace Bull
{
    struct ImageSavingParameters
    {
        int stride         = 0;
        int quality        = 100;
        ImageFormat format = ImageFormat_Png;
    };

    struct BULL_CORE_API ImageSaver : public AssetIOScheduler<Image>
    {
        /*! \brief Tell whether an ImageFormat is supported
         *
         * \param format The ImageFormat to test
         *
         * \return True if the ImageFormat is supported
         *
         */
        bool isSupportedFormat(ImageFormat format);

        /*! \brief Save an Image to a File
         *
         * \param image      The Image to save
         * \param path       The Path of the File to write
         * \param parameters Parameters to use to save the Image
         *
         * \return True if the Image started to be saved
         *
         */
        bool saveToPath(const Image& image, const Path& path, const ImageSavingParameters& parameters = ImageSavingParameters());
    };
}

#endif // BULL_CORE_IMAGE_IMAGESAVER_HPP
