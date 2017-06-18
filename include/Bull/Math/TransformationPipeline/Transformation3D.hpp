#ifndef BULL_TRANSFORMATION3D_HPP
#define BULL_TRANSFORMATION3D_HPP

#include <Bull/Math/Matrix/Matrix4.hpp>

namespace Bull
{
    template <typename T>
    class Transformation3D
    {
    public:

        /*! \brief Create a scale Transformation3D
         *
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D makeScale(const Vector3<T>& scale);

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
        static Transformation3D makeTranslation(const Vector3<T>& translation);

        /*! \brief Create a Transformation3D
         *
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const EulerAnglesF& angles, const Vector3<T>& scale);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3<T>& translation, const Vector3<T>& scale);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3<T>& translation, const EulerAnglesF& angles);

        /*! \brief Create a Transformation3D
         *
         * \param translation The translation vector
         * \param angles The EulerAngles to rotate
         * \param scale The scale vector
         *
         * \return The Transformation3D
         *
         */
        static Transformation3D make(const Vector3<T>& translation, const EulerAnglesF& angles, const Vector3<T>& scale);

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
        Transformation3D& setScale(const Vector3<T>& scale);

        /*! \brief Get the scale vector of this Transformation3D
         *
         * \return The scale vector
         *
         */
        Vector3<T> getScale() const;

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
        Transformation3D& setTranslation(const Vector3<T>& translation);

        /*! \brief Get the translation vector of this Transformation3D
         *
         * \return The translation vector
         *
         */
        Vector3<T> getTranslation() const;

        /*! \brief Apply a scaling to the current Transformation3D
         *
         * \param scale The scale vector
         *
         * \return This
         *
         */
        Transformation3D& applyScale(const Vector3<T>& scale);

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
        Transformation3D& applyTranslation(const Vector3<T>& translation);

        /*! \brief Convert the Transformation3D to a Matrix4F
         *
         * \return The Matrix
         *
         */
        const Matrix4F& getMatrix() const;

    private:

        Matrix4<T> m_matrix; /*!< The Transformation3D matrix */
    };

    typedef Transformation3D<int>          Transformation3DI;
    typedef Transformation3D<float>        Transformation3DF;
    typedef Transformation3D<double>       Transformation3DD;
    typedef Transformation3D<unsigned int> Transformation3DUI;
}

#include <Bull/Math/TransformationPipeline/Transformation3D.inl>

#endif //BULL_TRANSFORMATION3D_HPP
