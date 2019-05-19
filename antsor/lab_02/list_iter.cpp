#ifndef LISTITER_CPP
#define LISTITER_CPP

#include "list_iter.h"

// BaseIter     //////////////////////////////////////////////////////

template <typename DataType>
BaseIter<DataType>::BaseIter()
{
    cur_.lock() = nullptr;
}

template <typename DataType>
BaseIter<DataType>::BaseIter(const BaseIter <DataType>& iter) :
    cur_(iter.cur_) {}

template <typename DataType>
BaseIter<DataType>::BaseIter(const shared_ptr<ListNode<DataType>> node) :
    cur_(node) {}

template <typename DataType>
BaseIter<DataType>::~BaseIter() {}

template <typename DataType>
bool BaseIter<DataType>::checkRange() const
{
    return cur_.lock() != nullptr;
}

template <typename DataType>
bool BaseIter<DataType>::operator==(const BaseIter<DataType>& iter) const
{
    return cur_.lock() == iter.cur_.lock();
}

template <typename DataType>
bool BaseIter<DataType>::operator!=(const BaseIter<DataType>& iter) const
{
    return cur_.lock() != iter.cur_.lock();
}

template <typename DataType>
BaseIter<DataType>& BaseIter<DataType>::operator=(const BaseIter<DataType>& iter)
{
    if (this != &iter)
        cur__ = iter.cur__;
    return *this;
}

template <typename DataType>
BaseIter<DataType>& BaseIter<DataType>::next()
{
    cur_ = cur_.lock()->getNextNode();
    return *this;
}

template <typename DataType>
BaseIter<DataType>& BaseIter<DataType>::operator++()
{
    next();
    return *this;
}

template <typename DataType>
BaseIter<DataType> BaseIter<DataType>::operator++(int)
{
    BaseIter<DataType> tmpIterator(*this);
    this->operator++;
    return tmpIterator;
}

// ListIter      /////////////////////////////////////////////////////////

template <typename DataType>
ListIter<DataType>::ListIter(const ListIter<DataType>& listIter) : 
    cur_(listIter.cur_) {}

template <typename DataType>
ListIter<DataType>& ListIter<DataType>::operator=(const ListIter<DataType>& listIter)
{
    if (this != &listIter)
        cur__ = listIter.cur__;
    return *this;
}

template <typename DataType>
DataType& ListIter<DataType>::getCur()
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType& ListIter<DataType>::getCur() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
DataType& ListIter<DataType>::operator*()
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType& ListIter<DataType>::operator*() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
DataType* ListIter<DataType>::operator->()
{
    return &cur_.lock()->getPointer();
}

template <typename DataType>
const DataType* ListIter<DataType>::operator->() const
{
    return &cur_.lock()->getPointer();
}

// ConstListIter /////////////////////////////////////////////////////////

template <typename DataType>
ConstListIter<DataType>::ConstListIter(const ConstListIter<DataType>& listIter) : 
    cur_(listIter.cur_) {}

template <typename DataType>
ConstListIter<DataType>& ConstListIter<DataType>::operator=(const ConstListIter<DataType>& listIter)
{
    if (this != &listIter)
        cur__ = listIter.cur__;
    return *this;
}

template <typename DataType>
const DataType& ConstListIter<DataType>::getCur() const
{
    return cur_.lock()->getPointer();
}
template <typename DataType>
const DataType& ConstListIter<DataType>::operator*() const
{
    return cur_.lock()->getPointer();
}

template <typename DataType>
const DataType* ConstListIter<DataType>::operator->() const
{
    return &cur_.lock()->getPointer();
}

#endif // LISTITER_CPP
