namespace Bull
{
    template <typename T, std::size_t S>
    SquareMatrix<T, S> SquareMatrix<T, S>::makeIdentity()
    {
        SquareMatrix<T, S> identity;

        for(std::size_t i = 0; i < S; i++)
        {
            identity.at(i, i) = 1;
        }

        return identity;
    }

    template <typename T, std::size_t S>
    SquareMatrix<T, S>::SquareMatrix(T value) :
        Matrix<T, S, S>(value)
    {
        /// Nothing
    }

    template <typename T, std::size_t S>
    template <typename U, std::size_t WU, std::size_t HU>
    SquareMatrix<T, S>::SquareMatrix(const Matrix<U, WU, HU>& copy) :
        Matrix<T, S, S>(copy)
    {
        /// Nothing
    }

    template <typename T, std::size_t S>
    SquareMatrix<T, S> operator*(const SquareMatrix<T, S>& left, const SquareMatrix<T, S>& right)
    {
        SquareMatrix<T, S> product;

        for(std::size_t j = 0; j < S; j++)
        {
            for(std::size_t i = 0; i < S; i++)
            {
                T sum = 0;
                Vector<T, S> row = left.getRow(j);
                Vector<T, S> column = right.getColumn(i);

                for(std::size_t k = 0; k < S; k++)
                {
                    sum += row.at(k) * column.at(k);
                }

                product.at(i, j) = sum;
            }
        }

        return product;
    }
}