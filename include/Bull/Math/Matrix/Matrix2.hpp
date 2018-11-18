#ifndef BULL_MATH_MATRIX_MATRIX2_HPP
#define BULL_MATH_MATRIX_MATRIX2_HPP

#include <array>

#include <Bull/Math/Matrix/SquareMatrix.hpp>

namespace Bull
{
    template<typename T>
    class Matrix2 : public SquareMatrix<T, 2>
    {
    public:

        static Matrix2<T> Identity;

    public:

        /*! \brief Default constructor
         *
         */
        Matrix2() = default;

        /*! \brief Constructor
         *
         * \param value The value to use to fill the Matrix
         *
         */
        explicit Matrix2(T value) :
            SquareMatrix<T, 2>(value)
        {
            /// Nothing
        }

        /*! \brief Copy constructor
         *
         * \param copy The Matrix to copy
         *
         */
        template <typename U, std::size_t WU, std::size_t HU>
        Matrix2(const Matrix<U, WU, HU>& copy) :
            SquareMatrix<T, 2>(copy)
        {
            /// Nothing
        }
    };

    template<typename T>
    Matrix2<T> Matrix2<T>::Identity = Matrix2<T>::makeIdentity();

    typedef Matrix2<int> Matrix2I;
    typedef Matrix2<float> Matrix2F;
    typedef Matrix2<double> Matrix2D;
    typedef Matrix2<unsigned int> Matrix2UI;
}

#endif // BULL_MATRIX2_HPP
