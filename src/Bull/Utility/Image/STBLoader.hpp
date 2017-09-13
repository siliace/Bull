#ifndef BULL_UTILITY_IMAGE_STBLOADER_HPP
#define BULL_UTILITY_IMAGE_STBLOADER_HPP

#include <Bull/Utility/Image/AbstractImageLoader.hpp>

namespace Bull
{
    namespace prv
    {
        class STBLoader : public AbstractImageLoader
        {
        private:

            /*! \brief Read data from an user stream
             *
             * \param user The user stream
             * \param data The memory to fill
             * \param size How many bytes should be read from the stream
             *
             * \return The number of byte actually read
             *
             */
            static int read(void* user, char* data, int size);

            /*! \brief Skip byte from an user stream
             *
             * \param user The user stream
             * \param n    How many bytes should be skipped
             *
             */
            static void skip(void* user, int n);

            /*! \brief Tell whether an user stream is at the end
             *
             * \param user The user stream
             *
             * \return Nonzero if the stream if at the end
             *
             */
            static int eof(void* user);

        public:

            /*! \brief Tell whether an ImageFormat is support
             *
             * \param format The format to test
             *
             * \return True if the format is supported by the loader
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

            /*! \brief Load a Resource from a Path
             *
             * \param resource The Resource to load
             * \param path     The path
             *
             * \return True if the Resource was loaded successfully
             *
             */
            bool loadFromPath(std::unique_ptr<Image>& resource, const Path& path, const ParameterBag& parameters) const override;

            /*! \brief Load a Resource from a Path
             *
             * \param resource The Resource to load
             * \param stream   The stream to read to load
             *
             * \return True if the Resource was loaded successfully
             *
             */
            bool loadFromStream(std::unique_ptr<Image>& resource, InStream& stream, const ParameterBag& parameters) const override;

            /*! \brief Load a Resource from a memory area
             *
             * \param resource The Resource to load
             * \param data     The memory
             * \param length   The length of data
             *
             * \return True if the Resource was loaded successfully
             *
             */
            bool loadFromMemory(std::unique_ptr<Image>& resource, const void* data, Index length, const ParameterBag& parameters) const override;

            /*! \brief Load an Image from pixels
             *
             * \param resource The Resource to load
             * \param pixels   Pixels of the Image
             * \param size     The size of the Image
             *
             * \return True if the Resource was loaded successfully
             *
             */
            bool loadFromPixels(std::unique_ptr<Image>& resource, const ByteArray& pixels, const Vector2UI& size, const ParameterBag& parameters) const override;
        };
    }
}

#endif // BULL_UTILITY_IMAGE_STBLOADER_HPP
