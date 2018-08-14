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

        /*! \brief Scale the Transformable
         *
         * \param scale The scaling factor
         *
         * \return This
         *
         */
        Transformable& scale(const Vector3F& scale);

        /*! \brief Set the scale of the Transformable
         *
         * \param scale The scale
         *
         */
        inline void setScale(const Vector3F& scale)
        {
            m_scale = scale;
        }

        /*! \brief Get the scale of the Transformable
         *
         * \return The scale
         *
         */
        inline const Vector3F& getScale() const
        {
            return m_scale;
        }

        /*! \brief Rotate the Transformable
         *
         * \param rotation The rotation
         *
         * \return This
         *
         */
        Transformable& rotate(const EulerAnglesF& rotation);

        /*! \brief Set the rotation of the Transformable
         *
         * \param rotation The rotation
         *
         */
        inline void setRotation(const EulerAnglesF& rotation)
        {
            m_rotation = rotation;
        }

        /*! \brief Get the rotation of the Transformable
         *
         * \return The rotation
         *
         */
        inline const EulerAnglesF& getRotation() const
        {
            return m_rotation;
        }

        /*! \brief Move the Transformable
         *
         * \param translation The translation
         *
         * \return This
         *
         */
        Transformable& move(const Vector3F& translation);

        /*! \brief Set the translation of the Transformable
         *
         * \param translation The translation
         *
         */
        inline void setTranslation(const Vector3F& translation)
        {
            m_translation = translation;
        }

        /*! \brief Get the translation of the Transformable
         *
         * \return The translation
         *
         */
        inline const Vector3F& getTranslation() const
        {
            return m_translation;
        }

        /*! \brief Get the model Matrix of the Transformable
         *
         * \return The model Matrix
         *
         */
        Matrix4F getModelMatrix() const;

    private:

        Vector3F     m_scale; /*!< The scale of the Transformable */
        EulerAnglesF m_rotation; /*!< The rotation of the Transformable */
        Vector3F     m_translation; /*!< The translation of the Transformable */
    };
}

#endif // BULL_GRAPHICS_TRANSFORMABLE_HPP
