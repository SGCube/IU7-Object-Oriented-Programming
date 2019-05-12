#ifndef LISTITER_CPP
#define LISTITER_CPP

#include "list_iter.h"

template <typename DataType>
ListIterator<DataType>::ListIterator()
{
    cur_.lock() = nullptr;
}

template <typename DataType>
ListIterator<DataType>::ListIterator(const ListIterator <DataType>& listIterator) :
    cur_(listIterator.cur_) {}

template <typename DataType>
ListIterator<DataType>::ListIterator(const shared_ptr<ListNode<DataType>> node) :
    cur_(node) {}

template <typename DataType>
ListIterator<DataType>::~ListIterator() {}

template <typename DataType>
bool ListIterator<DataType>::checkRange() const
{
    return cur_.lock() != nullptr;
}

template <typename DataType>
bool ListIterator<DataType>::operator==(const ListIterator<DataType>& listIterator) const
{
    return cur_.lock() == listIterator.cur_.lock();
}

template <typename DataType>
bool ListIterator<DataType>::operator!=(const ListIterator<DataType>& listIterator) const
{
    return cur_.lock() != listIterator.cur_.lock();
}

template <typename DataType>
ListIterator<DataType>& ListIterator<DataType>::operator=(const ListIterator<DataType>& listIterator)
{
    if (this != listIterator)
        cur__ = listIterator.cur__;

    return *this;
}

template <typename DataType>
ListIterator<DataType>& ListIterator<DataType>::next()
{
    cur_ = cur_.lock()->getNextNode();
    return *this;
}

template <typename DataType>
ListIterator<DataType>& ListIterator<DataType>::operator++()
{
    next();
    return *this;
}

template <typename DataType>
ListIterator<DataType> ListIterator<DataType>::operator++(int)
{
    ListIterator<DataType> tmpIterator(*this);
    this->operator++;
    return tmpIterator;
}

#endif // LISTITER_CPP
