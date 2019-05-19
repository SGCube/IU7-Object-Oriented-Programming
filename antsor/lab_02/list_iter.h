#ifndef LISTITER_H
#define LISTITER_H

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

#include "list_node.h"

template <typename DataType>
class BaseIter
{
public:
    // constuctor
    BaseIter();
    BaseIter(const shared_ptr<ListNode<DataType>> node);
    BaseIter(const BaseIter<DataType>& iter);

    // destructor
    virtual ~BaseIter();
    
    // pointer compare
    bool checkRange() const;
    bool operator==(const BaseIter<DataType>& iter) const;
    bool operator!=(const BaseIter<DataType>& iter) const;

    // equation operator
    BaseIter<DataType>& operator=(const BaseIter<DataType>& iter);
    
    // iteration
    BaseIter<DataType>& next();
    BaseIter<DataType>& operator++();
    BaseIter<DataType> operator++(int);
    
    
protected:
    weak_ptr<ListNode<DataType>> cur_;
};

template <typename DataType>
class ListIter : public BaseIter<DataType>
{
public:
    // constuctor
    ListIter(const ListIter<DataType>& listIter);

    // equation operator
    ListIter<DataType>& operator=(const ListIter<DataType>& listIter);
    
    // access operators/functions
    DataType& getCur();
    const DataType& getCur() const;
    
    DataType& operator*();
    const DataType& operator*() const;
    
    DataType* operator->();
    const DataType* operator->() const;
};

template <typename DataType>
class ConstListIter : public BaseIter<DataType>
{
public:
    // constuctor
    ConstListIter(const ConstListIter<DataType>& listIter);

    // equation operator
    ConstListIter<DataType>& operator=(const ConstListIter<DataType>& listIter);
    
    // access operators/functions
    const DataType& getCur() const;
    const DataType& operator*() const;
    const DataType* operator->() const;
};

#endif // LISTITER_H
