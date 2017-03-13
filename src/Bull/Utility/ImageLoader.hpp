#ifndef Bull_ImageLoader_hpp
#define Bull_ImageLoader_hpp

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/Integer.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Image.hpp>

namespace Bull
{
    namespace prv
    {
        class ImageLoader
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
            static bool load(const Path& path, std::vector<Uint8>& pixels, Vector2UI& size);

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
            static bool save(const Path& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size);

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
            static bool saveBmp(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);

            /*! \brief Save an image as .png file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            static bool savePng(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);

            /*! \brief Save an image as .tga file
             *
             * \param path   The path of the file to create to save the image
             * \param pixels Pixels of the image to save
             * \param size   The size of the image to save
             *
             * \return True if the image was saved successfully
             *
             */
            static bool saveTga(const String& path, const std::vector<Uint8>& pixels, const Vector2UI& size);
        };
    }
}

#endif // Bull_ImageLoader_hpp
