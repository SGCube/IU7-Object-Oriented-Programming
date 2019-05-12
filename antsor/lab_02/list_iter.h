#ifndef LISTITER_H
#define LISTITER_H

#include <memory>
using std::shared_ptr;
using std::weak_ptr;

#include "list_node.h"

template <typename DataType>
class ListIterator
{
public:
    // constuctor
    ListIterator();
    ListIterator(const shared_ptr<ListNode<DataType>> node);
    ListIterator(const ListIterator<DataType>& listIterator);

    // destructor
    virtual ~ListIterator();
    
    // pointer compare
    bool checkRange() const;
    bool operator==(const ListIterator<DataType>& listIterator) const;
    bool operator!=(const ListIterator<DataType>& listIterator) const;

    // equation operator
    ListIterator<DataType>& operator=(const ListIterator<DataType>& listIterator);
    
    // iteration
    ListIterator<DataType>& next();
    ListIterator<DataType>& operator++();
    ListIterator<DataType> operator++(int);
    
    
protected:
    weak_ptr<ListNode<DataType>> cur_;
};

#endif // LISTITER_H
