#ifndef BULL_MATH_MATRIX_MATRIX3_HPP
#define BULL_MATH_MATRIX_MATRIX3_HPP

#include <array>

#include <Bull/Math/Matrix/SquareMatrix.hpp>

namespace Bull
{
    template<typename T>
    struct Matrix3 : public SquareMatrix<T, 3>
    {
        static Matrix3<T> Identity;

        /*! \brief Default constructor
         *
         */
        Matrix3() = default;

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        Matrix3(T value);

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, Index WU, Index HU>
        Matrix3(const Matrix<U, WU, HU>& copy);
    };

    template<typename T>
    Matrix3<T> Matrix3<T>::Identity = Matrix3<T>::makeIdentity();

    typedef Matrix3<int> Matrix3I;
    typedef Matrix3<float> Matrix3F;
    typedef Matrix3<double> Matrix3D;
    typedef Matrix3<unsigned int> Matrix3UI;
}

#include <Bull/Math/Matrix/Matrix3.inl>

#endif // BULL_MATRIX3_HPP
