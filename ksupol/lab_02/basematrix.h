#ifndef BASEMATRIX_H
#define BASEMATRIX_H

class BaseMatrix
{
	public:
		BaseMatrix(size_t col, size_t row): col(col), row(row) {}
	size_t getCol() const
	{
		return col;
	}
	size_t getRow() const
	{
		return row;
	}
	protected:
		size_t col, row;
}
#endif // BASEMATRIX_H