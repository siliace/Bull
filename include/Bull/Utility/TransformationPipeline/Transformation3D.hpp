#ifndef BULL_TRANSFORMATION3D_HPP
#define BULL_TRANSFORMATION3D_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>

#include <Bull/Utility/TransformationPipeline/Matrixable.hpp>

namespace Bull
{
    class BULL_UTILITY_API Transformation3D : public Matrixable
    {
    public:

        /*! \brief Create a scale Transformation3D
         *
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D makeScale(const Vector3F& scale);

        /*! \brief Create a rotation Transformation3D
         *
         * \param angles The EulerAngles to rotate
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D makeRotation(const EulerAnglesF& angles);

        /*! \brief Create a translation Transformation3D
         *
         * \param translation The translation vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D makeTranslation(const Vector3F& translation);

        /*! \brief Create a Transformation3D
         *
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const EulerAnglesF& angles, const Vector3F& scale);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3F& translation, const Vector3F& scale);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3F& translation, const EulerAnglesF& angles);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3F& translation, const EulerAnglesF& angles, const Vector3F& scale);

    public:

        /*! \brief Default constructor
         *
         */
        Transformation3D();

        /*! \brief Set the scale of the Transformation3D
         *
         * \param scale The scale vector
         *
         * \return This
         *
         */
        Transformation3D& setScale(const Vector3F& scale);

        /*! \brief Get the scale vector of this Transformation3D
         *
         * \return The scale vector
         *
         */
        Vector3F getScale() const;

        /*! \brief Set the rotation of the Transformation3D
         *
         * \param angles Angles to rotate
         *
         * \return This
         *
         */
        Transformation3D& setRotation(const EulerAnglesF& angles);

        /*! \brief Get the rotation of the Transformation3D
         *
         * \return The EulerAnglesF representing the rotation
         */
        EulerAnglesF getRotation() const;

        /*! \brief Set the translation vector of this Transformation3D
         *
         * \param translation The translation vector
         *
         * \return This
         *
         */
        Transformation3D& setTranslation(const Vector3F& translation);

        /*! \brief Get the translation vector of this Transformation3D
         *
         * \return The translation vector
         *
         */
        Vector3F getTranslation() const;

        /*! \brief Apply a scaling to the current Transformation3D
         *
         * \param scale The scale vector
         *
         * \return This
         *
         */
        Transformation3D& applyScale(const Vector3F& scale);

        /*! \brief Apply a rotation to the current Transformation3D
         *
         * \param angles The EulerAnglesF to rotate
         *
         * \return This
         *
         */
        Transformation3D& applyRotation(const EulerAnglesF& angles);

        /*! \brief Apply a translation to the current Transformation3D
         *
         * \param translation The translation vector
         *
         * \return This
         *
         */
        Transformation3D& applyTranslation(const Vector3F& translation);

        /*! \brief Convert the Transformation3D to a Matrix4F
         *
         * \return The Matrix4F
         *
         */
        Matrix4F toMatrix() const override;

    private:

        Matrix4F m_matrix; /*!< The Transformation3D matrix */
    };
}

#endif //BULL_TRANSFORMATION3D_HPP
