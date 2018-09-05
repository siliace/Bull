#ifndef BULL_CORE_IMAGE_PIXELFORMAT_HPP
#define BULL_CORE_IMAGE_PIXELFORMAT_HPP

#include <Bull/Core/Export.hpp>

namespace Bull
{
    class BULL_CORE_API PixelFormat
    {
    public:

        static PixelFormat Luma8;
        static PixelFormat LumaAlpha8;
        static PixelFormat RGB8;
        static PixelFormat RGBA8;
        static PixelFormat DepthStencil;

        enum class Type
        {
            None,
            Luma,        /*!< A pixel format with 1 light channel */
            LumaAlpha,   /*!< A pixel format with 1 light channel and 1 alpha channel */
            Rgb,         /*!< A pixel format with 3 color channels */
            RgbAlpha,    /*!< A pixel format with 3 color channels and 1 alpha channel */
            DepthStencil /*!< A pixel format that store depth and stencil info */
        };

        enum class Data
        {
            None,
            UnsignedByte,   /*!< A pixel format that use 1 byte per channel */
            UnsignedInt24_8 /*!< A pixel format that use 3 bytes for the first channel and 1 for the second */
        };


    public:

        /*! \brief Default constructor
         *
         */
        PixelFormat();

        /*! \brief Tell whether the PixelFormat is valid
         *
         * \return True if valid
         *
         */
        bool isValid() const;

        /*! \brief Get the type of the PixelFormat
         *
         * \return The PixelFormatType
         *
         */
        inline PixelFormat::Type getType() const
        {
            return m_type;
        }

        /*! \brief The type of data of the PixelFormat
         *
         * \return The PixelFormatData
         *
         */
        inline PixelFormat::Data getData() const
        {
            return m_data;
        }

    private:

        /*! \brief Constructor
         *
         * \param type The type of the PixelFormat
         * \param data The data type of the PixelFormat
         *
         */
        PixelFormat(PixelFormat::Type type, PixelFormat::Data data);

    private:

        Type m_type;
        Data m_data;
    };
}

#endif // BULL_CORE_IMAGE_PIXELFORMAT_HPP
