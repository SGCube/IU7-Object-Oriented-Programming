#ifndef __MATRIX__H__
#define __MATRIX__H__

#include <iostream>
#include <cmath>
#include "matrix_error.h"


template<typename Type>
class iterator;

template<typename Type>
class cIterator;


template <typename Type>
class Matrix: public BaseMatrix
{
	public:
		Matrix(const size_t colNum, const size rowNum, Type** matrix = null_ptr);
		virtual ~Matrix(); // деструктор
		Matrix(std::initializer_list<std::initializer_list<Type>> array); // {}
		explicit Matrix(const Matrix& matrix); // копирование
		Matrix(Matrix&& matrix); //перенос
		
		Matrix<Type>& operator=(const Matrix<Type>& matrix); // перенос
		Matrix<Type>& operator=(Matrix<Type>&& matrix) noexcept; // копирование
		Matrix<Type>& operator=(std::initializer_list<std::initializer_list<T>> array); // {}
		
		const Type& at(size_t col, size_t row) const; // достать элемент матрицы по номеру столбца и строки
		Type& at(size_t col, size_t row); // изменение элемента матрицы по номеру столбца и строки
		
		// сложение матриц
		Matrix<Type> operator+(const Matrix<Type>& matrix) const;
		Matrix<Type> add(const Matrix<Type>& matrix) const;
		
		// вычитание матриц
		Matrix<Type> operator-(const Matrix<Type>& matrix) const;
		Matrix<Type> sub(const Matrix<Type>& matrix) const;
		
		// умножение матриц
		Matrix<Type> operator*(const Matrix<Type>& matrix) const;
		Matrix<Type> multiply(const Matrix<Type>& matrix) const;
		
		// += 
		Matrix<Type>& operator+=(const Matrix<Type>& matrix);
		Matrix<Type>& addself(const Matrix<Type>& matrix);
		
		// -= 
		Matrix<Type>& operator-=(const Matrix<Type>& matrix);
		Matrix<Type>& subself(const Matrix<Type>& matrix);
		
		// нахождение детерминанта !!!!!!!!!!!
		Matrix<Type> determinant(const Matrix<Type>& matrix) const;
		
		// проверка на равенство
		bool operator ==(Matrix<Type>& matrix);
		bool operator !=(Matrix<Type>& matrix);

		// обратная матрица
		Matrix<Type> reverse() const;	//!
		Matrix<Type> operator ~();	//!

		// транспонирование
		Matrix<Type> transpose() const;	//!
		const Matrix<Type> &self_transpose();	//!
		
		// итераторы
		iterator<Type>   begin();	//!
		iterator<Type>   end();	//!

		// константные итераторы
		cIterator<Type>  cbegin() const; //!
		cIterator<Type>  cend() const;	//!
	private:
		std::shared_ptr<Type> data;
		size_t colNum_; // кол-во столбцов
		size_t rowNum_; //кол-во строк
};