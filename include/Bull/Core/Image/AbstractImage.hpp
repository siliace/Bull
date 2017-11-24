#ifndef BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP
#define BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP

#include <Bull/Core/Image/ImageParameters.hpp>
#include <Bull/Core/Resource/Resource.hpp>
#include <Bull/Core/Resource/ResourceLoader.hpp>
#include <Bull/Core/Resource/ResourceSaver.hpp>
#include <Bull/Core/Memory/ByteVector.hpp>

#include <Bull/Math/Vector/Vector2.hpp>

namespace Bull
{
    struct BULL_CORE_API AbstractImage : public Resource<ImageParameters>
    {
        /*! \brief Create the AbstractImage
         *
         * \param size The size of the AbstractImage
         *
         * \return True if the AbstractImage was created successfully
         *
         */
        virtual bool create(const Vector2UI& size) = 0;

        /*! \brief Create the AbstractImage
         *
         * \param pixels Pixels of the Image
         * \param size   The size of the Image
         *
         * \return True if the AbstractImage was created successfully
         *
         */
        virtual bool create(const ByteVector& pixels, const Vector2UI& size) = 0;

        /*! \brief Get the size of the AbstractImage
         *
         * \return The size
         *
         */
        virtual const Vector2UI& getSize() const = 0;
    };
}

#endif // BULL_CORE_IMAGE_ABSTRACTIMAGE_HPP
