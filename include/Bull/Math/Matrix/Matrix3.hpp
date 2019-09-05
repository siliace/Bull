#ifndef BULL_MATH_MATRIX_MATRIX3_HPP
#define BULL_MATH_MATRIX_MATRIX3_HPP

#include <array>

#include <Bull/Math/Matrix/SquareMatrix.hpp>

namespace Bull
{
    template <typename T>
    class Matrix3 : public SquareMatrix<T, 3>
    {
    public:

        static Matrix3<T> Identity;

    public:

        /** \brief Default constructor
         *
         */
        Matrix3() = default;

        /** \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit Matrix3(T value) :
                SquareMatrix<T, 3>(value)
        {
            /// Nothing
        }

        /** \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        Matrix3(const Matrix<U, WU, HU>& copy) :
                SquareMatrix<T, 3>(copy)
        {
            /// Nothing
        }
    };

    template <typename T>
    Matrix3<T> Matrix3<T>::Identity = Matrix3<T>::makeIdentity();

    typedef Matrix3<int> Matrix3I;
    typedef Matrix3<float> Matrix3F;
    typedef Matrix3<double> Matrix3D;
    typedef Matrix3<unsigned int> Matrix3UI;
}

#endif // BULL_MATRIX3_HPP
