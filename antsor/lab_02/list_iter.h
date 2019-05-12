#ifndef LISTITER_H
#define LISTITER_H

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

#include "list_node.h"

template <typename DataType>
class ListIteratorBase
{
public:
    // constuctor
    ListIteratorBase();
    ListIteratorBase(const shared_ptr<ListNode<DataType>> node);
    ListIteratorBase(const ListIteratorBase<DataType>& listIterator);

    // destructor
    virtual ~ListIteratorBase();
    
    // pointer compare
    bool checkRange() const;
    bool operator==(const ListIteratorBase<DataType>& listIterator) const;
    bool operator!=(const ListIteratorBase<DataType>& listIterator) const;

    // equation operator
    ListIteratorBase<DataType>& operator=(const ListIteratorBase<DataType>& listIterator);
    
    // iteration
    ListIteratorBase<DataType>& next();
    ListIteratorBase<DataType>& operator++();
    ListIteratorBase<DataType> operator++(int);
    
    
protected:
    weak_ptr<ListNode<DataType>> cur_;
};

template <typename DataType>
class ListIterator : public ListIteratorBase<DataType>
{
public:
    // constuctor
    ListIterator(const ListIterator<DataType>& listIterator);

    // equation operator
    ListIterator<DataType>& operator=(const ListIterator<DataType>& listIterator);
    
    // access operators/functions
    DataType& getCur();
    const DataType& getCur() const;
    
    DataType& operator*();
    const DataType& operator*() const;
    
    DataType* operator->();
    const DataType* operator->() const;
};

template <typename DataType>
class ConstListIterator : public ListIteratorBase<DataType>
{
public:
    // constuctor
    ConstListIterator(const ConstListIterator<DataType>& listIterator);

    // equation operator
    ConstListIterator<DataType>& operator=(const ConstListIterator<DataType>& listIterator);
    
    // access operators/functions
    const DataType& getCur() const;
    const DataType& operator*() const;
    const DataType* operator->() const;
};

#endif // LISTITER_H
