#ifndef ITERATORS_H
#define ITERATORS_H
#include <memory>
#include "matrix.h"

template <typename T>
class Iterator
{
public:
    ~Iterator();
    Iterator(std::shared_ptr<T> &data, size_t cur_num, size_t max_num);
    Iterator(const Iterator<T> &iter);
    Iterator(Iterator<T> &&iter);

    operator bool() const;
    bool operator != (const Iterator<T> &iter) const;
    bool operator == (const Iterator<T> &iter) const;

    Iterator<T> operator +(int step);
    const Iterator<T> &operator +=(int step);
    const Iterator<T> &operator ++();
    Iterator<T> operator ++(int);

    Iterator<T> operator -(int step);
    const Iterator<T> &operator -=(int step);
    Iterator<T> operator --();
    Iterator<T> operator --(int);

protected:
    std::weak_ptr<T> data;
    size_t cur_num;
    size_t max_num;
};
#endif //ITERATORS_H
