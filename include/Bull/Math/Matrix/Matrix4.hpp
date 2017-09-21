#ifndef BULL_MATH_MATRIX_MATRIX4_HPP
#define BULL_MATH_MATRIX_MATRIX4_HPP

#include <array>

#include <Bull/Math/Matrix/SquareMatrix.hpp>

namespace Bull
{
    template<typename T>
    struct Matrix4 : public SquareMatrix<T, 4>
    {
        static Matrix4<T> Identity;

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

    template<typename T>
    Matrix4<T> Matrix4<T>::Identity = Matrix4<T>::makeIdentity();

    typedef Matrix4<int> Matrix4I;
    typedef Matrix4<float> Matrix4F;
    typedef Matrix4<double> Matrix4D;
    typedef Matrix4<unsigned int> Matrix4UI;
}

#include <Bull/Math/Matrix/Matrix4.inl>

#endif // BULL_MATRIX4_HPP
