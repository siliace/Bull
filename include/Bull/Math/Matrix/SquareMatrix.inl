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

    template <typename T, Index S>
    SquareMatrix<T, S> operator*(const SquareMatrix<T, S>& left, const SquareMatrix<T, S>& right)
    {
        SquareMatrix<T, S> product;

        for(Index j = 0; j < S; j++)
        {
            for(Index i = 0; i < S; i++)
            {
                T sum = 0;
                Vector<T, S> row = left.getRow(j);
                Vector<T, S> column = right.getColumn(i);

                for(Index k = 0; k < S; k++)
                {
                    sum += row.at(k) * column.at(k);
                }

                product.at(i, j) = sum;
            }
        }

        return product;
    }
}