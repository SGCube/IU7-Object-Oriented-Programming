#include "matrix.h"

template<typename Type>
Matrix<Type>::~Matrix()
{}

template<typename Type>
Matrix<Type>::Matrix(size_t colNum, size_t rowNum, Type** matrix):
    BaseMatrix (colNum, rowNum), data(new Type[colNum * rowNum])
{
    if (data.get() == nullptr)
        throw alloc_err(time(nullptr), typeid(*this).name(), __FUNCTION__);
    if (matrix)
    {
        for (size_t i = 0; i < colNum; i++)
        {
            for (size_t j = 0; j < rowNum; j++)
                (*this)[i][j] = (*matrix)[i * rowNum + j];
        }
    }
}

template<typename Type>
bool Matrix<Type>::operator ==(Matrix<Type> &matrix)
{
    if (col != matrix.getCol() || row != matrix.getRow())
    {
        return false;
    }
    for (auto i = cbegin(), j = mtr.cbegin(); i != cend(); i++, j++)
    {
        if (*i != *j)
            return false;
    }
    return true;
}

template <typename Type>
bool Matrix<Type>::operator !=(Matrix<Type> &matrix)
{
    return !(this->operator ==(matrix));
}

/*
template<typename Type>
Matrix<Type>::Matrix(std::initializer_list<std::initializer_list<T>> array)
{
    size_t i = 0;
    size_t j = 0;
    for (auto &row : list)
    {
       j = 0;
        for (auto &el : raw)
        {
            (*this)[i][j] = el;
            j++;
        }
        i++;
    }
}
template<typename Type>
double Matrix<Type>::determinant() const
{
    if (col != row)
        throw wrong_sizes(__func__,__FILE__,__LINE__);
    if (col == 1)
        return (*this)[0][0];
    int sig = 1;
    double result = 0;
    for (size_t j = 0; j < row; j++)
    {
        Matrix<double> M = addMinor(0, j);
        result += sig * (*this)[0][j] * M.det();
        sig *= -1;
    }
    return result;
}
*/
template <typename Type>
Matrix<Type> Matrix<Type>::reverse()
{
    return ~(*this);
}

template<typename Type>
Matrix<Type> Matrix<Type>::operator ~()
{
    Matrix<double> result = this->transpose();
    double reverse_det = 1.0 / this->det();
    result *= reverse_det;
    return result;
}

template<typename Type>
Matrix<Type> Matrix<Type>::transpose() const
{
    Matrix<Type> result(row, col);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
            result[i][j] = (*this)[j][i];
    }
    return result;
}

template<typename Type>
const Matrix<Type> & Matrix<Type>::self_transpose()
{
    Matrix<Type> result(*this);
    delete this;
    this = result.transpose();
    return *this;
}

template<typename Type>
iterator<Type> Matrix<Type>::begin()
{
	size_t size = col * row;
	iterator<Type> iter(data, 0, size);
	return iter;
}

template<typename Type>
iterator<Type> Matrix<Type>::end()
{
	size_t size = col * row;
	iterator<Type> iter(data, size, size);
	return iter;
}

template<typename Type>
cIterator<Type> Matrix<Type>::cbegin() const
{
	size_t size = col * row;
	cIterator<Type> iter((std::shared_ptr<double> &)data, 0, size);
	return iter;
}

template<typename Type>
cIterator<Type> Matrix<Type>::cend() const
{
    size_t size = col * row;
	cIterator<Type> iter((std::shared_ptr<double> &)data, size, size);
	return iter;
}