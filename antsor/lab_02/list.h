#ifndef LIST_H
#define LIST_H

#include "list_iter.h"
#include "list_node.h"

#include <stdarg.h>

class ListBase
{
public:
    ListBase();
    virtual ~ListBase();

    size_t size() const;
protected:
    size_t size_;
};

template <typename DataType>
class List : public ListBase
{
public:
    List();
    explicit List(const List<DataType>& list);
    List(List<DataType>&& list);
    List(const size_t size, ...);
    List(std::initializer_list<DataType>& list);
    virtual ~List();

    List<DataType>& operator=(const List<DataType>& list);
    List<DataType>& operator=(List<DataType>&& list);

    bool operator==(const List<DataType>& someList) const;
    bool operator!=(const List<DataType>& someList) const;

    List<DataType>& append(const DataType& data);
    List<DataType>& operator+=(const DataType& data);
    List<DataType> operator+(const DataType& data) const;

    List<DataType& insert(const DataType& data, const ListIterator<DataType>& iter);
    friend List<DataType> operator+(const DataType& data, const List<DataType>& list);

    List<DataType>& extend(const List<DataType>& list);
    List<DataType>& operator+=(const List<DataType>& list);
    List<DataType> operator+(const List<DataType>& list) const;

    const DataType pop();
    const DataType remove(const ListIterator<DataType>& iter);
    List<DataType>& clear();

    ListIter<DataType> begin();
    ListIter<DataType> end();

    ConstListIter<DataType> begin() const;
    ConstListIter<DataType> end() const;

private:
    std::shared_ptr<ListNode<DataType>> head;
    std::shared_ptr<ListNode<DataType>> tail;
};

#endif // LIST_H
