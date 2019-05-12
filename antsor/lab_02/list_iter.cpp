#ifndef LISTITER_CPP
#define LISTITER_CPP

#include "list_iter.h"

// ListIteratorBase     //////////////////////////////////////////////////////

template <typename DataType>
ListIteratorBase<DataType>::ListIteratorBase()
{
    cur_.lock() = nullptr;
}

template <typename DataType>
ListIteratorBase<DataType>::ListIteratorBase(const ListIteratorBase <DataType>& listIterator) :
    cur_(listIterator.cur_) {}

template <typename DataType>
ListIteratorBase<DataType>::ListIteratorBase(const shared_ptr<ListNode<DataType>> node) :
    cur_(node) {}

template <typename DataType>
ListIteratorBase<DataType>::~ListIteratorBase() {}

template <typename DataType>
bool ListIteratorBase<DataType>::checkRange() const
{
    return cur_.lock() != nullptr;
}

template <typename DataType>
bool ListIteratorBase<DataType>::operator==(const ListIteratorBase<DataType>& listIterator) const
{
    return cur_.lock() == listIterator.cur_.lock();
}

template <typename DataType>
bool ListIteratorBase<DataType>::operator!=(const ListIteratorBase<DataType>& listIterator) const
{
    return cur_.lock() != listIterator.cur_.lock();
}

template <typename DataType>
ListIteratorBase<DataType>& ListIteratorBase<DataType>::operator=(const ListIteratorBase<DataType>& listIterator)
{
    if (this != &listIterator)
        cur__ = listIterator.cur__;
    return *this;
}

template <typename DataType>
ListIteratorBase<DataType>& ListIteratorBase<DataType>::next()
{
    cur_ = cur_.lock()->getNextNode();
    return *this;
}

template <typename DataType>
ListIteratorBase<DataType>& ListIteratorBase<DataType>::operator++()
{
    next();
    return *this;
}

template <typename DataType>
ListIteratorBase<DataType> ListIteratorBase<DataType>::operator++(int)
{
    ListIteratorBase<DataType> tmpIterator(*this);
    this->operator++;
    return tmpIterator;
}

// ListIterator      /////////////////////////////////////////////////////////

template <typename DataType>
ListIterator<DataType>::ListIterator(const ListIterator<DataType>& listIterator) : 
    cur_(listIterator.cur_) {}

template <typename DataType>
ListIterator<DataType>& ListIterator<DataType>::operator=(const ListIterator<DataType>& listIterator)
{
    if (this != &listIterator)
        cur__ = listIterator.cur__;
    return *this;
}

template <typename DataType>
DataType& ListIterator<DataType>::getCur()
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType& ListIterator<DataType>::getCur() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
DataType& ListIterator<DataType>::operator*()
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType& ListIterator<DataType>::operator*() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
DataType* ListIterator<DataType>::operator->()
{
    return &cur_.lock()->getPointer();
}

template <typename DataType>
const DataType* ListIterator<DataType>::operator->() const
{
    return &cur_.lock()->getPointer();
}

// ConstListIterator /////////////////////////////////////////////////////////

template <typename DataType>
ConstListIterator<DataType>::ConstListIterator(const ConstListIterator<DataType>& listIterator) : 
    cur_(listIterator.cur_) {}

template <typename DataType>
ConstListIterator<DataType>& ConstListIterator<DataType>::operator=(const ConstListIterator<DataType>& listIterator)
{
    if (this != &listIterator)
        cur__ = listIterator.cur__;
    return *this;
}

template <typename DataType>
const DataType& ConstListIterator<DataType>::getCur() const
{
    return cur_.lock()->getPointer();
}
template <typename DataType>
const DataType& ConstListIterator<DataType>::operator*() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType* ConstListIterator<DataType>::operator->() const
{
    return &cur_.lock()->getPointer();
}

#endif // LISTITER_CPP
