#ifndef BULL_CORE_IMAGE_IMAGE_HPP
#define BULL_CORE_IMAGE_IMAGE_HPP

#include <Bull/Core/Image/AbstractImage.hpp>
#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Resource/Resource.hpp>

namespace Bull
{
    class BULL_CORE_API Image : public AbstractImage
    {
    public:

        using Saver  = ResourceSaver<Image, ImageParameters>;
        using Loader = ResourceLoader<Image, ImageParameters>;

    public:

        /*! \brief Default constructor
         *
         */
        Image() = default;

        /*! \brief Create the Image
         *
         * \param size The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const Vector2UI& size) override;

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const ByteArray& pixels, const Vector2UI& size) override;

        /*! \brief Load a Resource from a Path
         *
         * \param path       The Path of the file to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Load a Resource from an InStream
         *
         * \param stream     The stream to read
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory area to read
         * \param length     The length of the memory area
         * \param parameters Parameters to load the Resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ImageParameters& parameters = ImageParameters()) override;

        /*! \brief Save the Resource to a Path
         *
         * \param path       The path of the
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToPath(const Path& path, const ImageParameters& parameters = ImageParameters()) const override;

        /*! \brief Save the Resource to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToStream(OutStream& stream, const ImageParameters& parameters = ImageParameters()) const override;

        /*! \brief Save the Resource to a Path
         *
         * \param data       The memory to write
         * \param length     The length of the memory area
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToMemory(void* data, Index length, const ImageParameters& parameters = ImageParameters()) const override;
        
        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        const ByteArray& getPixels() const;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Vector2UI& getSize() const override;

    private:

        Vector2UI m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_CORE_IMAGE_IMAGE_HPP
