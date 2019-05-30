﻿#ifndef MITERATOR_HPP
#define MITERATOR_HPP
#include "miterator.h"

template<typename T>
T &MIterator<T>::operator *()
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return *(ptr.get() + this->cur_num);
}

template<typename T>
const T &MIterator<T>::operator *() const
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return *(ptr.get() + this->cur_num);
}

template<typename T>
T *MIterator<T>::operator ->()
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return ptr.get();
}

template<typename T>
const T *MIterator<T>::operator ->() const
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return ptr.get();
}

template<typename T>
const T &cMIterator<T>::operator *()
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return *(ptr.get() + this->cur_num);
}

template<typename T>
const T *cMIterator<T>::operator ->()
{
    if (this->data.expired() == true)
    {
        throw exceptDamagedIterator(time(nullptr), typeid(*this).name(), __FUNCTION__);
    }

    std::shared_ptr<T> ptr = this->data.lock();
    return ptr.get();
}
#endif //MITERATOR_HPP
