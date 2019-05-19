#ifndef LISTITER_H
#define LISTITER_H

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

#include "list_node.h"

template <typename T>
class BaseIter
{
public:
    // constuctor
    BaseIter();
    BaseIter(const shared_ptr<ListNode<T>> node);
    BaseIter(const BaseIter<T>& iter);

    // destructor
    virtual ~BaseIter();
    
    // pointer compare
    bool checkRange() const;
    bool operator==(const BaseIter<T>& iter) const;
    bool operator!=(const BaseIter<T>& iter) const;

    // equation operator
    BaseIter<T>& operator=(const BaseIter<T>& iter);
    
    // iteration
    BaseIter<T>& next();
    BaseIter<T>& operator++();
    BaseIter<T> operator++(int);
    
    
protected:
    weak_ptr<ListNode<T>> cur_;
};

template <typename T>
class ListIter : public BaseIter<T>
{
public:
    // constuctor
    ListIter(const ListIter<T>& listIter);

    // equation operator
    ListIter<T>& operator=(const ListIter<T>& listIter);
    
    // access operators/functions
    T& getCur();
    const T& getCur() const;
    
    T& operator*();
    const T& operator*() const;
    
    T* operator->();
    const T* operator->() const;
};

template <typename T>
class ConstListIter : public BaseIter<T>
{
public:
    // constuctor
    ConstListIter(const ConstListIter<T>& listIter);

    // equation operator
    ConstListIter<T>& operator=(const ConstListIter<T>& listIter);
    
    // access operators/functions
    const T& getCur() const;
    const T& operator*() const;
    const T* operator->() const;
};

#endif // LISTITER_H
