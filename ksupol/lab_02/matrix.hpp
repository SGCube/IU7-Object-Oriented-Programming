 #ifndef MATRIX_HPP
#define MATRIX_HPP
#include <time.h>
#include "miterator.h"
#include "matrix.h"

template<typename T>
size_t Matrix<T>::init_list_matrix_rate(std::initializer_list<std::initializer_list<T> > &list)
{
    size_t rate = list.size();

    for (auto &el: list)
    {
        rate = (el.size() > rate) ? el.size() : rate;
    }

    return rate;
}

template<typename T>
Matrix<T>::~Matrix()
{}

template<typename T>
Matrix<T>::Matrix(size_t row, size_t col, T **mat):
    BaseMatrix (row, col), data(new T[row * col])
{
    if (data.get() == nullptr)
    {
        throw exceptAllocationError(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    if (mat)
    {
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                (*this)[i][j] = (*mat)[i * col + j];
            }
        }
    }
}

template<typename T>
Matrix<T>::Matrix(size_t row, size_t col, const T &init):
    Matrix(row, col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            (*this)[i][j] = init;
        }
    }
}

template<typename T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> list)
{
    size_t rate = init_list_matrix_rate(list);
    row = rate;
    col = rate;
    data.reset(new T[row * col]);

    if (data.get() == nullptr)
    {
        throw exceptAllocationError(time(nullptr), typeid (*this).name(), __FUNCTION__);
    }


    size_t i = 0;
    size_t j = 0;
    for (auto &roww : list)
    {
        j = 0;
        for (auto &el : roww)
        {
            (*this)[i][j] = el;
            j++;
        }
        i++;
    }
}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &mtr):
    Matrix(mtr.getLen(), mtr.getCol())
{
    for (size_t i = 0; i < mtr.getLen(); i++)
    {
        for (size_t j = 0; j < mtr.getCol(); j++)
        {
            (*this)[i][j] = mtr[i][j];
        }
    }
}

template<typename T>
Matrix<T>::Matrix(Matrix<T> &&mtr):
    BaseMatrix (row, col)
{
    data.reset(mtr.data.get());
    mtr.data.reset();
}

template<typename T>
void Matrix<T>::fill(const T &init) noexcept
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*this)[i][j] = init;
        }
    }
}

template<typename T>
void Matrix<T>::swap(size_t roww1, size_t col1, size_t roww2, size_t col2)
{
    if (roww1 < row || roww2 < row ||
        col1 < col || col2 < col)
    {
        throw exceptOutOfRange(__func__,__FILE__,__LINE__);
    }
    T tmp = (*this)[roww1][col1];
    (*this)[roww1][col1] = (*this)[roww2][col2];
    (*this)[roww2][col2] = tmp;
}


template<typename T>
const T &Matrix<T>::operator()(size_t i, size_t j) const
{
    return (data.get() + i)[j];
}

template<typename T>
T &Matrix<T>::operator()(size_t i, size_t j)
{
    return (data.get() + i)[j];
}

template<typename T>
typename Matrix<T>::Roww Matrix<T>::operator[](size_t roww)
{
    return Roww(data.get(), roww, row, col);
}

template<typename T>
const typename Matrix<T>::Roww Matrix<T>::operator[](size_t roww) const
{
    return Roww(data.get(), roww, row, col);
}


template<typename T>
Matrix<T> Matrix<T>::operator +(const Matrix<T> &mtr) const
{
    if (this->getLen() != mtr.getLen() ||
        this->getCol() != mtr.getCol())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    Matrix<T> result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = (*this)[i][j] + mtr[i][j];
        }
    }

    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator -(const Matrix<T> &mtr) const
{
    if (this->getLen() != mtr.getLen() ||
        this->getCol() != mtr.getCol())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    Matrix<T> result(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            result[i][j] = (*this)[i][j] - mtr[i][j];
        }
    }

    return result;
}

template<typename T>
const Matrix<T> & Matrix<T>::operator +=(const Matrix<T> &mtr)
{
    if (this->getLen() != mtr.getLen() ||
        this->getCol() != mtr.getCol())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*this)[i][j] += mtr[i][j];
        }
    }

    return *this;
}

template<typename T>
const Matrix<T> & Matrix<T>::operator -=(const Matrix<T> &mtr)
{
    if (this->getLen() != mtr.getLen() ||
        this->getCol() != mtr.getCol())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            (*this)[i][j] -= mtr[i][j];
        }
    }
}



template<typename T>
Matrix<T> Matrix<T>::operator =(const Matrix<T> &mtr)
{
    Matrix<T> result(mtr);
    return result;
}

template<typename T>
Matrix<T> operator *(const T &el, const Matrix<T> &mtr)
{
    Matrix<T> answer(mtr);
    for (int i = 0; i < mtr.getLen(); i++)
    {
        for (int j = 0; j < mtr.getCol(); j++)
        {
            answer[i][j] *= el;
        }
    }
    return answer;
}

template<typename T>
Matrix<T> Matrix<T>::operator =(Matrix<T> &&mtr) noexcept
{
    Matrix<T> result(mtr);
    return result;
}

template<typename T>
Matrix<T> Matrix<T>::operator *(const T &el) const
{
    Matrix<T> result(*this);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            result[i][j] *= el;
        }
    }

    return result;
}


template<typename T>
const Matrix<T> &Matrix<T>::operator *=(const T &el) noexcept
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            (*this)[i][j] *= el;
        }
    }

    return (*this);
}

template<typename T>
Matrix<T> Matrix<T>::operator *(const Matrix<T> &mtr)
{
    if (col != mtr.getLen())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    Matrix<double> result(row, mtr.getCol(), 0);

    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < mtr.getCol(); j++)
        {
            for (size_t k = 0; k < col; k++)
            {
                result[i][j] += (*this)[i][j] * mtr[i][j];
            }
        }
    }

    return result;
}

template<typename T>
const Matrix<T> &Matrix<T>::operator *=(const Matrix<T> &mtr)
{
    if (col != mtr.getLen() ||
        col != mtr.getCol())
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    (*this) = (*this) * mtr;
    return *this;
}



template<typename T>
Matrix<T> Matrix<T>::addMinor(size_t roww, size_t col) const
{
    if (row != col || row == 1 || col == 1)
    {
        throw  exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    Matrix<double> result(row - 1, col - 1);
    for (size_t i = 0; i < roww - 1; i++)
    {
        for (size_t j = 0; j < col - 1; j++)
        {
            result[i][j] = (*this)[i][j];
        }
    }

    for (size_t i = roww + 1; i < row; i++)
    {
        for (size_t j = col + 1; j < col; j++)
        {
            result[i - 1][j - 1] = (*this)[i][j];
        }
    }

    return result;
}


template<typename T>
double Matrix<T>::det() const
{
    if (row != col)
    {
        throw exceptWrongSizes(__func__,__FILE__,__LINE__);
    }

    if (row == 1)
    {
        return (*this)[0][0];
    }

    int sig = 1;
    double result = 0;

    for (size_t j = 0; j < col; j++)
    {
        Matrix<double> M = addMinor(0, j);
        result += sig * (*this)[0][j] * M.det();
        sig *= -1;
    }

    return result;
}


template<typename T>
Matrix<T> Matrix<T>::operator ~()
{
    Matrix<double> result = this->transpose();
    double reverse_det = 1.0 / this->det();

    result *= reverse_det;
    return result;
}



template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
    Matrix<T> result(col, row);

    for (size_t i = 0; i < col; i++)
    {
        for (size_t j = 0; j < row; j++)
        {
            result[i][j] = (*this)[j][i];
        }
    }

    return result;
}

template<typename T>
const Matrix<T> & Matrix<T>::self_transpese()
{
    Matrix<T> result(*this);
    delete this;
    this = result.transpose();

    return *this;
}


template<typename T>
MIterator<T> Matrix<T>::begin()
{
    MIterator<T> iter(data, 0, row * col);
    return iter;
}

template<typename T>
MIterator<T> Matrix<T>::end()
{
    size_t size = row * col;

    MIterator<T> iter(data, size, size);
    return iter;
}

template<typename T>
cMIterator<T> Matrix<T>::cbegin() const
{
    cMIterator<T> iter((std::shared_ptr<double> &)data, 0, row * col);
    return iter;
}

template<typename T>
cMIterator<T> Matrix<T>::cend() const
{
    size_t size = row * col;

    cMIterator<T> iter((std::shared_ptr<double> &)data, size, size);
    return iter;
}



template<typename T>
T &Matrix<T>::Roww::operator[](size_t index)
{
    if ( !(0 <= index && index < colNum) )
    {
        throw exceptOutOfRange(time(nullptr), typeid (*this).name(),
                           __FUNCTION__,
                           "bad index");
    }
    if (curRoww >= rowwNum)
    {
        throw exceptOutOfRange(time(nullptr), typeid (*this).name(),
                           __FUNCTION__,
                           "bad roww");
    }
    return *(data + curRoww * colNum + index);
}

template<typename T>
Matrix<T>::Roww::Roww(Roww &&tmp): data(tmp.data), curRoww(tmp.curRoww),
    rowwNum(tmp.rowwNum), colNum(tmp.colNum)
{
    tmp.data = nullptr;
    tmp.rowwNum = -1;
    tmp.colNum = -1;
    tmp.curRoww = -1;
}


template<typename T>
Matrix<T>::Roww::Roww(T *data, size_t curRoww, size_t rowwNum, size_t colNum):
    data(data), curRoww(curRoww), rowwNum(rowwNum), colNum(colNum)
{
    if (data == nullptr)
    {
        throw exceptBadPointer(time(nullptr), typeid (*this).name(), __FUNCTION__);
    }
}


template<typename T>
bool Matrix<T>::operator ==(Matrix<T> &mtr)
{
    if (row != mtr.getRow() || col != mtr.getCol())
    {
        return false;
    }

    for (auto i = cbegin(), j = mtr.cbegin(); i != cend(); i++, j++)
    {
        if (*i != *j)
        {
            return false;
        }
    }

    return true;
}

template <typename T>
bool Matrix<T>::operator !=(Matrix<T> &mtr)
{
    return ! (this->operator==(mtr));
}


template<typename T>
const T &Matrix<T>::at(size_t i, size_t j) const
{
    return (*this)[i][j];
}



template<typename T>
Matrix<T> Matrix<T>::add(const Matrix<T> &mtr) const
{
    return (*this) + mtr;
}

template<typename T>
Matrix<T> Matrix<T>::sub(const Matrix<T> &mtr) const
{
    return (*this) - mtr;
}

template<typename T>
const Matrix<T> & Matrix<T>::selfAdd(const Matrix<T> &mtr)
{
    return (*this) += mtr;
}

template<typename T>
const Matrix<T> & Matrix<T>::selfSub(const Matrix<T> &mtr)
{
    return (*this) -= mtr;
}

template<typename T>
Matrix<T> Matrix<T>::mult(const T &el)
{
    return (*this) * el;
}

template<typename T>
const Matrix<T> &Matrix<T>::selfMult(const T &el) noexcept
{
    return (*this) *= el;
}


template <typename T>
Matrix<T> Matrix<T>::mult(const Matrix<T> &mtr)
{
    return (*this) * mtr;
}

template <typename T>
const Matrix<T> Matrix<T>::selfMult(const Matrix<T> &mtr)
{
    return (*this) *= mtr;
}


template <typename T>
Matrix<T> Matrix<T>::revert()
{
    return ~(*this);
}
#endif //MATRIX_HPP
