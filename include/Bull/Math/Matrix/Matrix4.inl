namespace Bull
{
    template <typename T>
    Matrix4<T>::Matrix4(T value) :
        SquareMatrix<T, 4>(value)
    {
        /// Nothing
    }

    template <typename T>
    template <typename U, Index WU, Index HU>
    Matrix4<T>::Matrix4(const Matrix<U, WU, HU>& copy) :
        SquareMatrix<T, 4>(copy)
    {
        /// Nothing
    }
}
