#ifndef BASEMATRIX_H
#define BASEMATRIX_H

#include <stdlib.h>

class BaseMatrix
{
public:
    BaseMatrix(){}
    BaseMatrix(size_t row, size_t col): row(row), col(col) {}
    size_t getRow() const
    {
        return row;
    }
    size_t getCol() const
    {
        return col;
    }
    size_t Size() const
    {
        return row * col;
    }

protected:
    size_t row;
    size_t col;
};

#endif // BASEMATRIX_H
