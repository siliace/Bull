#ifndef BULL_MATH_MATRIX_MATRIX4_HPP
#define BULL_MATH_MATRIX_MATRIX4_HPP

#include <array>

#include <Bull/Math/Angle.hpp>
#include <Bull/Math/Matrix/SquareMatrix.hpp>
#include <Bull/Math/Polygon/Rectangle.hpp>
#include <Bull/Math/Quaternion.hpp>

namespace Bull
{
    template<typename T>
    struct Matrix4 : public SquareMatrix<T, 4>
    {
        static Matrix4<T> Identity;

        /*! \brief Create a scaling transformation matrix
         *
         * \param scale The scaling factor
         *
         * \return The transformation matrix
         *
         */
        static Matrix4<T> makeScale(const Vector3<T>& scale);

        /*! \brief Create a rotation transformation matrix
         *
         * \param rotation The rotation
         *
         * \return The transformation matrix
         *
         */
        static Matrix4<T> makeRotation(const Quaternion<T>& rotation);

        /*! \brief Create a translation transformation matrix
         *
         * \param translation The translation
         *
         * \return The translation matrix
         *
         */
        static Matrix4<T> makeTranslation(const Vector3<T>& translation);

        /*! \brief Create an orthographic projection matrix
         *
         * \param plan
         * \param zBounds
         *
         * \return The projection matrix
         *
         */
        static Matrix4<T> makeOrthographic(const Rectangle<T>& plan, const Vector2<T>& zBounds);

        /*! \brief Create a perspective projection matrix
         *
         * \param angle
         * \param ratio
         * \param zBounds
         *
         * \return The projection matrix
         *
         */
        static Matrix4<T> makePerspective(const Angle<T>& angle, float ratio, const Vector2<T>& zBounds);

        /*! \brief Create a look at matrix
         *
         * \param eye    The position of the camera
         * \param center The target to look at
         * \param up     The up vector of the camera
         *
         * \return The view matrix
         *
         */
        static Matrix4<T> makeLookAt(const Vector3<T>& eye, const Vector3<T>& center, const Vector3<T>& up = Vector3<T>::Up);

        /*! \brief Default constructor
         *
         */
        Matrix4() = default;

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        Matrix4(T value);

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, Index WU, Index HU>
        Matrix4(const Matrix<U, WU, HU>& copy);
    };

    template <typename T>
    Matrix4<T> Matrix4<T>::Identity = Matrix4<T>::makeIdentity();

    typedef Matrix4<int> Matrix4I;
    typedef Matrix4<float> Matrix4F;
    typedef Matrix4<double> Matrix4D;
    typedef Matrix4<unsigned int> Matrix4UI;
}

#include <Bull/Math/Matrix/Matrix4.inl>

#endif // BULL_MATRIX4_HPP
