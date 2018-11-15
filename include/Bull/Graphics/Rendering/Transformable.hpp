#ifndef BULL_GRAPHICS_TRANSFORMABLE_HPP
#define BULL_GRAPHICS_TRANSFORMABLE_HPP

#include <Bull/Graphics/Export.hpp>

#include <Bull/Math/EulerAngles.hpp>
#include <Bull/Math/Matrix/Matrix4.hpp>
#include <Bull/Math/Vector/Vector3.hpp>

namespace Bull
{
    class BULL_GRAPHICS_API Transformable
    {
    public:

        /*! \brief Default constructor
         *
         */
        Transformable();

        /*! \brief Constructor by movement
         *
         * \param right The Transformable to move
         *
         */
        Transformable(Transformable&& right) = default;

        /*! \brief Basic assignment operator by movement
         *
         * \param right The Transformable to move
         *
         * \return This
         *
         */
        Transformable& operator=(Transformable&& right) = default;

        /*! \brief Scale the Transformable
         *
         * \param scale The scaling factor
         *
         */
        void scale(const Vector3F& scale);

        /*! \brief Rotate the Transformable
         *
         * \param rotation The rotation
         *
         */
        void rotate(const EulerAnglesF& rotation);

        /*! \brief Move the Transformable
         *
         * \param translation The translation
         *
         */
        void move(const Vector3F& translation);

        /*! \brief Get the model Matrix of the Transformable
         *
         * \return The model Matrix
         *
         */
        Matrix4F getModelMatrix() const;

        /*! \brief Set the scale of the Transformable
         *
         * \param scale The scale
         *
         */
        void setScale(const Vector3F& scale);

        /*! \brief Get the scale of the Transformable
         *
         * \return The scale
         *
         */
        const Vector3F& getScale() const;

        /*! \brief Set the rotation of the Transformable
         *
         * \param rotation The rotation
         *
         */
        void setRotation(const EulerAnglesF& rotation);

        /*! \brief Get the rotation of the Transformable
         *
         * \return The rotation
         *
         */
        const EulerAnglesF& getRotation() const;

        /*! \brief Set the translation of the Transformable
         *
         * \param translation The translation
         *
         */
        void setTranslation(const Vector3F& translation);

        /*! \brief Get the translation of the Transformable
         *
         * \return The translation
         *
         */
        const Vector3F& getTranslation() const;

    private:

        Vector3F     m_scale; /*!< The scale of the Transformable */
        EulerAnglesF m_rotation; /*!< The rotation of the Transformable */
        Vector3F     m_translation; /*!< The translation of the Transformable */
    };
}

#endif // BULL_GRAPHICS_TRANSFORMABLE_HPP
