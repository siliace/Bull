namespace Bull
{
    template <typename T>
    Matrix2<T>::Matrix2(T value) :
        SquareMatrix<T, 2>(value)
    {
        /// Nothing
    }

    template <typename T>
    template <typename U, Index WU, Index HU>
    Matrix2<T>::Matrix2(const Matrix<U, WU, HU>& copy) :
        SquareMatrix<T, 2>(copy)
    {
        /// Nothing
    }
}
