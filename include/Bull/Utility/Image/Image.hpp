#ifndef BULL_UTILITY_IMAGE_IMAGE_HPP
#define BULL_UTILITY_IMAGE_IMAGE_HPP

#include <Bull/Core/Loader/Resource.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

#include <Bull/Utility/Export.hpp>
#include <Bull/Utility/Image/AbstractImageSaver.hpp>
#include <Bull/Utility/Image/AbstractImageLoader.hpp>
#include <Bull/Utility/Image/ImageParameterBag.hpp>

namespace Bull
{
    namespace prv
    {
        class STBSaver;
        class STBLoader;
    }

    class BULL_UTILITY_API Image : public Resource<Image, prv::STBSaver, prv::STBLoader, ImageParameterBag>
    {
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
        bool create(const Vector2UI& size);

        /*! \brief Create the Image
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the Image was created successfully
         *
         */
        bool create(const ByteArray& pixels, const Vector2UI& size);

        /*! \brief Load a Resource from a Path
         *
         * \param path       The path
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromPath(const Path& path, const ImageParameterBag& parameters = ImageParameterBag()) override;

        /*! \brief Load a Resource from a Path
         *
         * \param stream     The stream to read to load
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromStream(InStream& stream, const ImageParameterBag& parameters = ImageParameterBag()) override;

        /*! \brief Load a Resource from a memory area
         *
         * \param data       The memory
         * \param length     The length of data
         * \param parameters Parameters to create the resource
         *
         * \return True if the Resource was loaded successfully
         *
         */
        bool loadFromMemory(const void* data, Index length, const ImageParameterBag& parameters = ImageParameterBag()) override;

        /*! \brief Save a Resource to a file
         *
         * \param path       The Path to save the Resource
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToPath(const Path& path, const ImageParameterBag& parameters = ImageParameterBag()) const override;

        /*! \brief Save a Resource to a stream
         *
         * \param stream     The stream to write
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToStream(OutStream& stream, const ImageParameterBag& parameters = ImageParameterBag()) const override;

        /*! \brief Save a Resource to a memory area
         *
         * \param data       Memory to write to save the Resource
         * \param length     The length of the memory
         * \param parameters Parameters to save the Resource
         *
         * \return True if the Resource was saved successfully
         *
         */
        bool saveToMemory(void* data, Index length, const ImageParameterBag& parameters = ImageParameterBag()) const override;

        /*! \brief Get the size of the Image
         *
         * \return The size
         *
         */
        const Vector2UI& getSize() const;

        /*! \brief Get pixels of the Image
         *
         * \return The pixels
         *
         */
        const ByteArray& getPixels() const;

    private:

        Vector2UI m_size;
        ByteArray m_pixels;
    };
}

#endif // BULL_UTILITY_IMAGE_IMAGE_HPP
