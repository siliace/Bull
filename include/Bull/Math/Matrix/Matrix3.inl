namespace Bull
{
    template <typename T>
    Matrix3<T>::Matrix3(T value) :
        SquareMatrix<T, 3>(value)
    {
        /// Nothing
    }

    template <typename T>
    template <typename U, Index WU, Index HU>
    Matrix3<T>::Matrix3(const Matrix<U, WU, HU>& copy) :
        SquareMatrix<T, 3>(copy)
    {
        /// Nothing
    }
}