#ifndef BULL_TRANSFORMATION_HPP
#define BULL_TRANSFORMATION_HPP

#include <Bull/Core/System/Export.hpp>

#include <Bull/Math/Matrix/Matrix4.hpp>

namespace Bull
{
    class BULL_API Transformation
    {
    public:

        /*! \brief Create a scale Transformation
         *
         * \param scale The scale vector
         *
         * \return The Transformation
         *
         */
        static Transformation makeScale(const Vector3F& scale);

        /*! \brief Create a rotation Transformation
         *
         * \param angles The EulerAngles to rotate
         *
         * \return The Transformation
         *
         */
        static Transformation makeRotation(const EulerAnglesF& angles);

        /*! \brief Create a translation Transformation
         *
         * \param translation The translation vector
         *
         * \return The Transformation
         *
         */
        static Transformation makeTranslation(const Vector3F& translation);

        /*! \brief Create a Transformation
         *
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation
         *
         */
        static Transformation make(const EulerAnglesF& angles, const Vector3F& scale);

        /*! \brief Create a Transformation
         *
         * \param translation The translation vector
         * \param scale The scale vector
         *
         * \return The Transformation
         *
         */
        static Transformation make(const Vector3F& translation, const Vector3F& scale);

        /*! \brief Create a Transformation
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         *
         * \return The Transformation
         *
         */
        static Transformation make(const Vector3F& translation, const EulerAnglesF& angles);

        /*! \brief Create a Transformation
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation
         *
         */
        static Transformation make(const Vector3F& translation, const EulerAnglesF& angles, const Vector3F& scale);

    public:

        /*! \brief Default constructor
         *
         */
        Transformation();

        /*! \brief Set the scale of the Transformation
         *
         * \param scale The scale vector
         *
         * \return This
         *
         */
        Transformation& setScale(const Vector3F& scale);

        /*! \brief Get the scale vector of this Transformation
         *
         * \return The scale vector
         *
         */
        Vector3F getScale() const;

        /*! \brief Set the rotation of the Transformation
         *
         * \param angles Angles to rotate
         *
         * \return This
         *
         */
        Transformation& setRotation(const EulerAnglesF& angles);

        /*! \brief Get the rotation of the Transformation
         *
         * \return The EulerAnglesF representing the rotation
         */
        EulerAnglesF getRotation() const;

        /*! \brief Set the translation vector of this Transformation
         *
         * \param translation The translation vector
         *
         * \return This
         *
         */
        Transformation& setTranslation(const Vector3F& translation);

        /*! \brief Get the translation vector of this Transformation
         *
         * \return The translation vector
         *
         */
        Vector3F getTranslation() const;

        /*! \brief Apply a scaling to the current Transformation
         *
         * \param scale The scale vector
         *
         * \return This
         *
         */
        Transformation& applyScale(const Vector3F& scale);

        /*! \brief Apply a rotation to the current Transformation
         *
         * \param angles The EulerAnglesF to rotate
         *
         * \return This
         *
         */
        Transformation& applyRotation(const EulerAnglesF& angles);

        /*! \brief Apply a translation to the current Transformation
         *
         * \param translation The translation vector
         *
         * \return This
         *
         */
        Transformation& applyTranslation(const Vector3F& translation);

        /*! \brief Convert the Transformation to a Matrix4F
         *
         * \return The Matrix4F
         *
         */
        const Matrix4F& toMatrix() const;

    private:

        Matrix4F m_matrix; /*!< The Transformation matrix */
    };
}

#endif //BULL_TRANSFORMATION_HPP
