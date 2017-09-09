#ifndef BULL_UTILITY_IMAGE_IMAGE_HPP
#define BULL_UTILITY_IMAGE_IMAGE_HPP

#include <vector>

#include <Bull/Core/FileSystem/Path.hpp>
#include <Bull/Core/IO/InStream.hpp>
#include <Bull/Core/IO/OutStream.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/System/Integer.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Color.hpp>
#include <Bull/Utility/Image/AbstractImageLoader.hpp>
#include <Bull/Utility/Image/ImageFormat.hpp>

namespace Bull
{
    class BULL_UTILITY_API Image
    {
    public:

        /*! \brief Default constructor
         *
         */
        Image();

        /*! \brief Constructor
         *
         * \param size  The size of the Image
         * \param color The color to fill the Image
         *
         */
        explicit Image(const Vector2UI& size, const Color& color = Color::Black);

        /*! \brief Constructor
         *
         * \param width  The width of the Image to create
         * \param height The height of the Image to create
         * \param color  The color to fill the Image
         *
         */
        Image(unsigned int width, unsigned int height, const Color& color = Color::Black);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        Image(const ByteArray& pixels, const Vector2UI& size);

        /*! \brief Constructor
         *
         * \param pixels Pixels of the Image
         * \param width  The width of the Image to create
         * \param height The height of the Image to create
         *
         */
        Image(const ByteArray& pixels, unsigned int width, unsigned int height);

        /*! \brief Load an Image from a file
         *
         * \param path The path to the Image to load
         *
         * \return True if the Image was loaded successfully
         *
         */
        bool loadFromPath(const Path& path);

        /*! \brief Load an Image from a stream
         *
         * \param stream The stream to read to load the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool loadFromStream(InStream& stream);

        /*! \brief Load an Image from memory
         *
         * \param data     Buffer which contains row data
         * \param dataSize The size of data
         *
         * \return True if the Image was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, std::size_t dataSize);

        /*! \brief Load an Image from pixels
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was loaded successfully
         *
         */
        bool loadFromPixels(const ByteArray& pixels, const Vector2UI& size);

        /*! \brief Load an Image from pixels
         *
         * \param pixels Pixels of the Image
         * \param width  The width of the Image
         * \param height The height of the Image
         *
         * \return True if the Image was loaded successfully
         *
         */
        bool loadFromPixels(const ByteArray& pixels, unsigned int width, unsigned int height);

        /*! \brief Set the color of a pixel
         *
         * \param x
         * \param y
         * \param color
         *
         */
        void set(unsigned int x, unsigned int y, const Color& color);

        /*! \brief Get the color of a pixel
         *
         * \param x
         * \param y
         *
         * \return The color
         *
         */
        Color get(unsigned int x, unsigned int y) const;

        /*! \brief Get the size of the Image
         *
         * \return Return the size
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Get pixels of the Image
         *
         * \return Return pixels
         *
         */
        const ByteArray& getPixels() const;

        /*! \brief Save the Image
         *
         * \param path
         * \param format
         *
         * \return Return
         *
         */
        bool saveToPath(const Path& path, ImageFormat format) const;

        /*! \brief
         *
         * \param stream
         * \param format
         *
         * \return
         *
         */
        bool saveToMemory(OutStream& stream, ImageFormat format) const;

        /*! \brief
         *
         * \param data
         * \param size
         * \param format
         *
         * \return
         *
         */
        bool saveToSteam(void* data, std::size_t size, ImageFormat format) const;

    private:

        Vector2UI m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_UTILITY_IMAGE_IMAGE_HPP
