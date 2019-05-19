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

template <typename T>
class List : public ListBase
{
    friend class ListIter<T>;
public:
    List();
    explicit List(const List<T>& list);
    List(List<T>&& list);
    List(const size_t size, ...);
    List(std::initializer_list<T>& list);
    virtual ~List();

    List<T>& operator=(const List<T>& list);
    List<T>& operator=(List<T>&& list);

    bool operator==(const List<T>& someList) const;
    bool operator!=(const List<T>& someList) const;

    List<T>& append(const T& data);
    List<T>& operator+=(const T& data);
    List<T> operator+(const T& data) const;

    List<T& insert(const T& data, const ListIterator<T>& iter);
    friend List<T> operator+(const T& data, const List<T>& list);

    List<T>& extend(const List<T>& list);
    List<T>& operator+=(const List<T>& list);
    List<T> operator+(const List<T>& list) const;

    const T pop();
    const T remove(const ListIterator<T>& iter);
    List<T>& clear();

    ListIter<T> begin();
    ListIter<T> end();

    ConstListIter<T> begin() const;
    ConstListIter<T> end() const;

private:
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;
};

#endif // LIST_H
