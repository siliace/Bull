namespace Bull
{
    template <typename T, Index S>
    SquareMatrix<T, S> SquareMatrix<T, S>::makeIdentity()
    {
        SquareMatrix<T, S> identity;

        for(Index i = 0; i < S; i++)
        {
            identity.at(i, i) = 1;
        }

        return identity;
    }

    template <typename T, Index S>
    SquareMatrix<T, S>::SquareMatrix(T value) :
        Matrix<T, S, S>(value)
    {
        /// Nothing
    }

    template <typename T, Index S>
    template <typename U, Index WU, Index HU>
    SquareMatrix<T, S>::SquareMatrix(const Matrix<U, WU, HU>& copy) :
        Matrix<T, S, S>(copy)
    {
        /// Nothing
    }
}