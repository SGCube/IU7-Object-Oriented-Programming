#ifndef LISTITER_HPP
#define LISTITER_HPP

#include "list_iter.h"

// BaseIter     //////////////////////////////////////////////////////

template <typename T>
BaseIter<T>::BaseIter()
{
    this->cur_.lock() = nullptr;
}

template <typename T>
BaseIter<T>::BaseIter(const std::shared_ptr<ListNode<T>> node) :
    cur_(node) {}

template <typename T>
BaseIter<T>::BaseIter(const BaseIter <T>& iter) :
	cur_(iter.cur_) {}

template <typename T>
BaseIter<T>::~BaseIter() {}

template <typename T>
bool BaseIter<T>::checkRange() const
{
    return this->cur_.lock() != nullptr;
}

template <typename T>
bool BaseIter<T>::operator==(const BaseIter<T>& iter) const
{
    return this->cur_.lock() == iter.cur_.lock();
}

template <typename T>
bool BaseIter<T>::operator!=(const BaseIter<T>& iter) const
{
    return this->cur_.lock() != iter.cur_.lock();
}

template <typename T>
BaseIter<T>& BaseIter<T>::operator=(const BaseIter<T>& iter)
{
    if (this != &iter)
        this->cur__ = iter.cur__;
    return *this;
}

template <typename T>
BaseIter<T>& BaseIter<T>::next()
{
    this->cur_ = this->cur_.lock()->getNext();
    return *this;
}

template <typename T>
BaseIter<T>& BaseIter<T>::operator++()
{
    this->next();
    return *this;
}

template <typename T>
BaseIter<T> BaseIter<T>::operator++(int)
{
    BaseIter<T> tmpIterator(*this);
    this->operator++();
    return tmpIterator;
}

// ListIter      /////////////////////////////////////////////////////////

template <typename T>
ListIter<T>::ListIter(const std::shared_ptr<ListNode<T>> node)
{
	this->cur_ = node;
}

template <typename T>
ListIter<T>::ListIter(const ListIter<T>& listIter)
{
	this->cur_ = listIter.cur_;
}

template <typename T>
ListIter<T>& ListIter<T>::operator=(const ListIter<T>& listIter)
{
    if (this != &listIter)
        this->cur__ = listIter.cur__;
    return *this;
}

template <typename T>
T& ListIter<T>::operator*()
{
    return this->cur_.lock()->getPointer();
}

template <typename T>
const T& ListIter<T>::operator*() const
{
    return this->cur_.lock()->getPointer();
}

template <typename T>
T* ListIter<T>::operator->()
{
    return &this->cur_.lock()->getPointer();
}

template <typename T>
const T* ListIter<T>::operator->() const
{
    return &this->cur_.lock()->getPointer();
}

// ConstListIter /////////////////////////////////////////////////////////

template <typename T>
ConstListIter<T>::ConstListIter(const std::shared_ptr<ListNode<T>> node)
{
	this->cur_ = node;
}

template <typename T>
ConstListIter<T>::ConstListIter(const ConstListIter<T>& listIter)
{
	this->cur_ = listIter.cur_;
}

template <typename T>
ConstListIter<T>& ConstListIter<T>::operator=(const ConstListIter<T>& listIter)
{
    if (this != &listIter)
        this->cur__ = listIter.cur__;
    return *this;
}

template <typename T>
const T& ConstListIter<T>::getCur() const
{
    return this->cur_.lock()->getPointer();
}
template <typename T>
const T& ConstListIter<T>::operator*() const
{
    return this->cur_.lock()->getPointer();
}

template <typename T>
const T* ConstListIter<T>::operator->() const
{
    return &this->cur_.lock()->getPointer();
}

#endif // LISTITER_HPP
