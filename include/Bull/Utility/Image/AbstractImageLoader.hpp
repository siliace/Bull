#ifndef BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP
#define BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP

#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Export.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    struct BULL_UTILITY_API AbstractImageLoader
    {
        /*! \brief Load an image
         *
         * \param path   The path of the image to load
         * \param pixels Pixels of the loaded image
         * \param size   The size of the loaded image
         *
         * \return True if the image was loaded successfully
         *
         */
        virtual bool loadFromPath(const Path& path, ByteArray& pixels, Vector2UI& size) const = 0;

        /*! \brief Load an image
         *
         * \param stream The stream to read to load the image
         * \param pixels Pixels of the loaded image
         * \param size   The size of the loaded image
         *
         * \return True if the image was loaded successfully
         *
         */
        virtual bool loadFromStream(InStream& stream, ByteArray& pixels, Vector2UI& size) const = 0;

        /*! \brief Load an image
         *
         * \param data     Data to read to load the image
         * \param dataSize Size of data
         * \param pixels   Pixels of the loaded image
         * \param size     The size of the loaded image
         *
         * \return True if the image was loaded successfully
         *
         */
        virtual bool loadFromMemory(const void* data, std::size_t dataSize, ByteArray& pixels, Vector2UI& size) const = 0;

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
        virtual bool saveToPath(const Path& path, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const = 0;

        /*! \brief Save an image
         *
         * \param outStream The stream to fill
         * \param format    The format to use to save the image
         * \param pixels    Pixels of the image to save
         * \param size      The size of the image to save
         *
         * \return True if the image was saved successfully
         *
         */
        virtual bool saveToStream(OutStream& outStream, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const = 0;

        /*! \brief Save an image
         *
         * \param data     Data to fill
         * \param dataSize The size of data
         * \param format   The format to use to save the image
         * \param pixels   Pixels of the image to save
         * \param size     The size of the image to save
         *
         * \return True if the image was saved successfully
         *
         */
        virtual bool saveToMemory(void* data, std::size_t dataSize, ImageFormat format, const ByteArray& pixels, const Vector2UI& size) const = 0;
    };
}

#endif // BULL_UTILITY_IMAGE_ABSTRACTIMAGELOADER_HPP
