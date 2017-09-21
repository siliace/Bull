#include <Bull/Core/Memory/RangeCheck.hpp>

namespace Bull
{
    template <typename T, Index W, Index H>
    Matrix<T, W, H>::Matrix() :
        Matrix<T, W, H>(0)
    {
        /// Nothing
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H>::Matrix(T value)
    {
        set(value);
    }

    template <typename T, Index W, Index H>
    template <typename U, Index WU, Index HU>
    Matrix<T, W, H>::Matrix(const Matrix<U, WU, HU>& copy) :
        Matrix<T, W, H>(0)
    {
        for(Index j = 0; j < std::min(H, HU); j++)
        {
            for(Index i = 0; i < std::min(W, WU); i++)
            {
                at(i, j) = static_cast<T>(copy.at(i, j));
            }
        }
    }

    template <typename T, Index W, Index H>
    template <typename U, Index WU, Index HU>
    Matrix<T, W, H>& Matrix<T, W, H>::operator=(const Matrix<U, WU, HU>& copy)
    {
        set(0);

        for(Index j = 0; j < std::min(H, HU); j++)
        {
            for(Index i = 0; i < std::min(W, WU); i++)
            {
                at(i, j) = static_cast<T>(copy.at(i, j));
            }
        }

        return (*this);
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H>& Matrix<T, W, H>::set(T value)
    {
        m_matrix.fill(value);
    }

    template <typename T, Index W, Index H>
    bool Matrix<T, W, H>::operator==(const Matrix<T, W, H>& right) const
    {
        return m_matrix == right.m_matrix;
    }

    template <typename T, Index W, Index H>
    bool Matrix<T, W, H>::operator!=(const Matrix<T, W, H>& right) const
    {
        return m_matrix != right.m_matrix;
    }

    template <typename T, Index W, Index H>
    T& Matrix<T, W, H>::at(Index x, Index y)
    {
        RangeCheck(x, W);
        RangeCheck(y, H);

        return m_matrix.at(y * W + x);
    }

    template <typename T, Index W, Index H>
    const T& Matrix<T, W, H>::at(Index x, Index y) const
    {
        RangeCheck(x, W);
        RangeCheck(y, H);

        return m_matrix.at(y * W + x);
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H>& Matrix<T, W, H>::setRow(const Vector<T, H>& row, Index index)
    {
        for(Index i = 0; i < W; i++)
        {
            at(index, i) = row.at(i);
        }

        return (*this);
    }

    template <typename T, Index W, Index H>
    Vector<T, W> Matrix<T, W, H>::getRow(Index row) const
    {
        Vector<T, W> rowVec;

        for(Index i = 0; i < W; i++)
        {
            rowVec.at(i) = at(row, i);
        }

        return rowVec;
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H>& Matrix<T, W, H>::setColumn(const Vector<T, H>& column, Index index)
    {
        for(Index i = 0; i < W; i++)
        {
            at(i, index) = column.at(i);
        }

        return (*this);
    }

    template <typename T, Index W, Index H>
    Vector<T, H> Matrix<T, W, H>::getColumn(Index column) const
    {
        Vector<T, W> columnVec;

        for(Index i = 0; i < W; i++)
        {
            columnVec.at(i) = at(i, column);
        }

        return columnVec;
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H> Matrix<T, W, H>::operator-() const
    {
        Matrix<T, W, H> negation;

        for(Index i = 0; i < W * H; i++)
        {
            negation.at(i) = -at(i);
        }

        return negation;
    }

    template <typename T, Index W, Index H>
    const T* Matrix<T, W, H>::getPtr() const
    {
        return m_matrix.data();
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H> operator+(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right)
    {
        Matrix<T, W, H> sum;

        for(Index j = 0; j < H; j++)
        {
            for(Index i = 0; i < W; i++)
            {
                sum.at(i, j) = left.at(i, j) + right(i, j);
            }
        }

        return sum;
    }

    template <typename T, Index W, Index H>
    Matrix<T, W, H> operator-(const Matrix<T, W, H>& left, const Matrix<T, W, H>& right)
    {
        return left + -right;
    }
}