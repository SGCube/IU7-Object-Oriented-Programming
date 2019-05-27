#ifndef MATRIX_H
#define MATRIX_H
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "exception.h"
#include "basematrix.h"
#include "miterator.h"
template<typename T>
class MIterator;

template<typename T>
class cMIterator;

template <typename T>
class Matrix: public BaseMatrix
{
    class Roww;
public:
    Matrix(size_t row, size_t col, T** mat = nullptr);
    Matrix(size_t row, size_t col, const T& init);
    Matrix(std::initializer_list<std::initializer_list<T>> list);
    explicit Matrix(const Matrix<T> &mtr);
    Matrix(Matrix<T> &&mtr);
    ~Matrix();

    // =
    Matrix<T> operator =(const Matrix<T> &mtr);
    Matrix<T> operator =(Matrix<T> &&mtr) noexcept;
    Matrix<T> operator =(std::initializer_list<std::initializer_list<T>> list);

    void fill(const T& init) noexcept;
    void swap(size_t roww1, size_t col1, size_t roww2, size_t col2);

    // Операторы получения элемента
    const T &operator() (size_t i, size_t j) const;
    T &operator()(size_t i, size_t j);
    Roww operator[] (size_t roww);
    const Roww operator[] (size_t roww) const;
    // функциональное получение элемента
    const T &at(size_t i, size_t j) const;


    // + -
    Matrix<T> operator +(const Matrix<T> &mtr) const;
    Matrix<T> operator -(const Matrix<T> &mtr) const;
    // + - функциональные
    Matrix<T> add(const Matrix<T> &mtr) const;
    Matrix<T> sub(const Matrix<T> &mtr) const;

    // += -=
    const Matrix<T> & operator +=(const Matrix<T> &mtr);
    const Matrix<T> & operator -=(const Matrix<T> &mtr);
    // += -= функциональные
    const Matrix<T> & selfAdd(const Matrix<T> &mtr);
    const Matrix<T> & selfSub(const Matrix<T> &mtr);


    // * el
    Matrix<T> operator * (const T &el) const;
    const Matrix<T> &operator *= (const T &el) noexcept;
    // * num функциональные
    Matrix<T> mult(const T &num);
    const Matrix<T> & selfMult(const T &el) noexcept;


    // * mtr
    Matrix<T> operator * (const Matrix<T> &mtr);
    const Matrix<T> &operator *=(const Matrix<T> &mtr);
    // * mtr функциональные
    Matrix<T> mult (const Matrix<T> &mtr);
    const Matrix<T> selfMult(const Matrix<T> &mtr);

    // ==
    bool operator ==(Matrix<T> &mtr);
    bool operator !=(Matrix<T> &mtr);

    // Обратная матрица
    Matrix<T> operator ~();
    // Обратная матрица функцией
    Matrix<T> revert();

    double det() const;
    Matrix<T> addMinor(size_t row, size_t col) const;

    // Транспонирование
    Matrix<T> transpose() const;
    const Matrix<T> &self_transpese();


    // Итераторы
    MIterator<T>   begin();
    MIterator<T>   end();

    /* const */
    cMIterator<T>  cbegin() const;
    cMIterator<T>  cend() const;


private:
    std::shared_ptr<T> data;

    size_t // Возвращает ранг мартрицы при инициалзизации списком
    init_list_matrix_rate(std::initializer_list<std::initializer_list<T>> &list);

    class Roww
    {
    private:
        T *data = nullptr;
        size_t curRoww, rowwNum, colNum;

        size_t getCurRoww() { return curRoww; }
        size_t getRowwNum() { return rowwNum; }
        size_t getColNum() { return colNum; }

    public:
        Roww() = delete;
        Roww(Roww &) = delete;
        Roww(Roww &&);
        Roww(T *data, size_t curRoww, size_t rowwNum, size_t colNum);

        T &operator[](size_t index);
        const T &operator[](size_t index) const
            { return (*this)[index]; }
    };

};
#endif //MATRIX_H
