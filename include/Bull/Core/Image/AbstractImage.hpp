#ifndef BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP
#define BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP

#include <Bull/Core/Assets/Asset.hpp>
#include <Bull/Core/Memory/ByteArray.hpp>
#include <Bull/Core/Utility/Size.hpp>

namespace Bull
{
    struct BULL_CORE_API AbstractImage : public Asset
    {
        /*! \brief Create the AbstractImage
         *
         * \param size The size of the AbstractImage
         *
         */
        virtual void create(const Size& size) = 0;

        /*! \brief Create the AbstractImage
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         */
        virtual void create(const ByteArray& pixels, const Size& size) = 0;

        /*! \brief Get the size of the AbstractImage
         *
         * \return The size
         *
         */
        virtual const Size& getSize() const = 0;
    };
}

#endif // BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP
