#ifndef BULL_IMAGELOADER_HPP
#define BULL_IMAGELOADER_HPP

#include <Bull/Utility/AbstractImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        class ImageLoader : public AbstractImageLoader
        {
        public:

            /*! \brief Load an image
             *
             * \param path   The path of the image to load
             * \param pixels Pixels of the loaded image
             * \param size   The size of the loaded image
             *
             * \return True if the image was loaded successfully
             *
             */
            bool loadFromPath(const Path& path, std::vector<Uint8>& pixels, Vector2UI& size) const override;

            /*! \brief Save an image
             *
             * \param path   The path of the file to create to save the image
             * \param format The format to use to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveToPath(const Path& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size) const override;

        private:

            /*! \brief Save an image as .bmp file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveBmpToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .png file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool savePngToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const;

            /*! \brief Save an image as .tga file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            bool saveTgaToPath(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size) const;
        };
    }
}

#endif // BULL_IMAGELOADER_HPP
