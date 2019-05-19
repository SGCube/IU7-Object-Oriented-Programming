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
    // constructors
    List();
    explicit List(const List<T>& list);
    List(List<T>&& list);
    List(const size_t size, ...);
    List(std::initializer_list<T>& list);
    // destructor
    virtual ~List();

    // equation operators
    List<T>& operator=(const List<T>& list);
    List<T>& operator=(List<T>&& list);

    // compare operators
    bool operator==(const List<T>& list) const;
    bool operator!=(const List<T>& list) const;

    // append / list + data
    List<T>& append(const T& data);
    List<T>& operator+=(const T& data);
    List<T> operator+(const T& data) const;

    // insert / data + list
    List<T>& insert(const T& data, const ListIter<T>& iter);
    friend List<T> operator+(const T& data, const List<T>& list);

    // extend / list + list
    List<T>& extend(const List<T>& list);
    List<T>& operator+=(const List<T>& list);
    List<T> operator+(const List<T>& list) const;

    // element remove / clear
	const T remove(const ListIter<T>& iter);
    const T pop();
    List<T>& clear();

    // iterator set
    ListIter<T> begin();
    ListIter<T> end();
    ConstListIter<T> begin() const;
    ConstListIter<T> end() const;

private:
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

    bool List<T>::isEmpty() const;
    bool List<T>::isEqual(const List<T>& list) const;
    std::shared_ptr<ListNode<T>> initNode(const T& data, std::shared_ptr<ListNode<T>> nodePtr);
    void List<T>::addList(const List& ListToAdd);
};

#endif // LIST_H
