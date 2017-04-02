#ifndef BULL_ABSTRACTIMAGELOADER_HPP
#define BULL_ABSTRACTIMAGELOADER_HPP

#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Image.hpp>

namespace Bull
{
    struct BULL_API AbstractImageLoader
    {
        /*! @brief Load an image
         *
         * @param path   The path of the image to load
         * @param pixels Pixels of the loaded image
         * @param size   The size of the loaded image
         *
         * @return True if the image was loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path, std::vector<Uint8>& pixels, Vector2UI& size) const = 0;

        /*! @brief Save an image
         *
         * @param path   The path of the file to create to save the image
         * @param format The format to use to save the image
         * @param pixels Pixels of the image to save
         * @param size   The size of the image to save
         *
         * @return True if the image was saved successfully
         *
         */
        virtual bool saveToPath(const Path& path, Image::Format format, const std::vector<Uint8>& pixels, const Vector2UI& size) const = 0;
    };
}

#endif // BULL_ABSTRACTIMAGELOADER_HPP
