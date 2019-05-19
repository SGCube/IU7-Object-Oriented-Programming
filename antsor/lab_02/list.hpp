#ifndef LIST_HPP
#define LIST_HPP

#include "error.hpp"
#include "list.h"

ListBase::ListBase() :
    size_(0) {}

ListBase::~ListBase() {}

size_t ListBase::size() const
{
    return this->size_;
}

//////////////////////////////////////////////////////////////////////////////

template <typename T>
List<T>::List() :
    ListBase(),
    head(nullptr),
    tail(nullptr) {}

template <typename T>
List<T>::List(const List<T>& list) :
    ListBase(),
    head(nullptr),
    tail(nullptr)
{
    this->extend(list);
}

template <typename T>
List<T>::List(List<T>&& list)
{
    this->size_ = list->size_;
    this->head.reset(list->head);
    this->tail.reset(list->tail);
    list->size_ = 0;
    list->head = nullptr;
    list->tail = nullptr;
}

template <typename T>
List<T>::List(const size_t size, ...) :
    head(nullptr),
    tail(nullptr)
{
    va_list vlist;
    va_start(vlist, size);
    T tmp;
    for (size_t i = 0; i < size; i++)
    {
        tmp = va_arg(vlist, T);
        this->append(tmp);
    }
    va_end(vlist);
}

template <typename T>
List<T>::List(std::initializer_list<T>& list)
{
    for (const auto& data : list)
        this->append(data);
}

template <typename T>
List<T>::~List() {}

template <typename T>
List<T>& List<T>::operator=(const List& list)
{
    if (this != &list)
    {
        this->clear();
        this->extend(list);
    }
    return *this;
}

template <typename T>
List<T>& List<T>::operator=(List&& list)
{
    if (this != list)
    {
        clear();
        this->size_ = list->size_;
        this->head = list->head;
        this->tail = list->tail;
        
        list->size_ = 0;
        list->head = nullptr;
        list->tail = nullptr;
    }
    return *this;
}

template <typename T>
List<T>& List<T>::append(const T& data)
{
    std::shared_ptr<ListNode<T>> newNode = initNode(data);
    if (this->isEmpty())
        this->head = newNode;
    else
        this->tail->setNext(newNode);
    this->tail = newNode;
    return *this;
}

template <typename T>
List<T>& List<T>::operator+=(const T& data)
{
    this->append(data);
    return *this;
}

template <typename T>
List<T>& operator+(const List<T>& list, const T& data)
{
    List<T> newList(list);
    newList.append(data);
    return newList;
}

template <typename T>
List<T>& operator+(const T& data, const List<T>& list)
{
    List<T> newList(list);
    newList.insert(data);
    return newList;
}

template <typename T>
List<T>& List<T>::insert(const T& data, const ListIter<T>& iter)
{
    std::shared_ptr<ListNode<T>> curNode = this->head, prevNode = nullptr;
    ListIter<T> cur = this->begin();
    
    if (!this->head && cur == iter)
    {
        std::shared_ptr<ListNode<T>> newNode = initNode(data);
        this->head = newNode;
        this->tail = newNode;
        return *this;
    }
    
    while(curNode && cur != iter)
    {
        prevNode = curNode;
        curNode = curNode->getNext();
        cur.next();
    }
    
    if (!curNode)
        throw ErrorOutOfListRange(std::chrono::system_clock::now(), __FILE__,
                                  typeid(List).name(), __FUNCTION__);
    
    std::shared_ptr<ListNode<T>> newNode = initNode(data, curNode);
    
    if (curNode == this->head)
        this->head = newNode;
    else
        prevNode->setNext(newNode);
    
    return *this;
}

template <typename T>
List<T>& List<T>::extend(const List& list)
{
    if (list.isEmpty())
        return *this;
    
    if (this == &list)
    {
        List<T> listCopy;
        listCopy = List;
        addList(listCopy);
    }
    else
        addList(list);
    
    return *this;
}

template <typename T>
const T List<T>::remove(const ListIter<T>& iter)
{
    if (this->isEmpty())
        throw ErrorEmptyList(std::chrono::system_clock::now(), __FILE__,
                             typeid(List).name(), __FUNCTION__);
    
    std::shared_ptr<ListNode<T>> curNode = this->head, prevNode = nullptr;
    ListIter<T> cur = this->begin();

    while(curNode && cur != iter)
    {
        prevNode = curNode;
        curNode = curNode->getNext();
        cur.next();
    }
    
    if (!curNode)
        throw ErrorOutOfListRange(std::chrono::system_clock::now(), __FILE__,
                                  typeid(List).name(), __FUNCTION__);
    
    T data = iter.getCur();
    
    if (curNode->getNext() == nullptr)
        this->tail = prevNode;

    if (curNode == this->head)
        this->head = this->head->getNext();
    else
        tmp->setNext(curNode->getNext());

    this->size_--;
    
    return data;
}

template <typename T>
const T List<T>::pop()
{
    if (this->isEmpty())
        throw ErrorEmptyList(std::chrono::system_clock::now(), __FILE__,
                             typeid(List).name(), __FUNCTION__);
    
    ListIter<T> iter = this->end();
    return remove(iter);
}

template <typename T>
List<T>& List<T>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->size_ = 0;
    return *this;
}

template <typename T>
List<T>& List<T>::operator+=(const List& list)
{
    this->extend(list);
    return *this;
}

template <typename T>
bool List<T>::operator==(const List& list) const
{
    return isEqual(list);
}

template <typename T>
bool List<T>::operator!=(const List& list) const
{
    return !isEqual(list);
}

template <typename T>
ListIter<T> List<T>::begin()
{
    return ListIter<T>(head);
}

template <typename T>
ListIter<T> List<T>::end()
{
    return ListIter<T>(tail);
}

template <typename T>
ConstListIter<T> List<T>::begin() const
{
    return ConstListIter<T>(head);
}

template <typename T>
ConstListIter<T> List<T>::end() const
{
    return ConstListIter<T>(tail);
}

// private ///////////////////////////////////////////////////////////////////

template <typename T>
bool List<T>::isEmpty() const
{
    return this->head == nullptr;
}

template <typename T>
bool List<T>::isEqual(const List<T>& list) const
{
    std::shared_ptr<ListNode<T>> curNodeThis = this->head;
    std::shared_ptr<ListNode<T>> curNodeOther = list.head;

    while (curNodeThis && curNodeOther &&
           curNodeThis->getData() == curNodeOther == getData())
    {
        curNodeThis = curNodeThis->getNext();
        curNodeOther = curNodeOther->getNext();
    }
    
    return (!curNodeThis && !curNodeOther);
}

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::initNode(const T& data,
                                               std::shared_ptr<ListNode<T>> nodePtr)
{
    std::shared_ptr<ListNode<T>> newNode;
    newNode = std::make_shared<ListNode<T>>();
    if (!newNode)
    {
        throw ErrorMemory(std::chrono::system_clock::now(), __FILE__,
                          typeid(List).name(), __FUNCTION__);
    }
    newNode->setData(data);
    newNode->setNext(nodePtr);
    this->size_++;
    return newNode;
}

template <typename T>
void List<T>::addList(const List& ListToAdd)
{
    T data = ListToAdd.head->getData();
    std::shared_ptr<ListNode<T>> nextNode = ListToAdd.head->getNext();
    std::shared_ptr<ListNode<T>> nodeToAdd = initNode(data, nextNode);
    std::shared_ptr<ListNode<T>> cur = this->head;
    
    if (this->isEmpty())
    {
        cur = nodeToAdd;
        this->head = cur;
    }
    else
    {
        while(cur->getNext())
        {
            cur = cur->getNext());
        }
        cur->setNext(nodeToAdd);
        cur = cur->getNext();
    }
    
    for (std::shared_ptr<ListNode<T>> curToAdd = nextNode; curToAdd;
            curToAdd = curToAdd->getNext(), cur = cur->getNext())
    {
        data = curToAdd->getData();
        nextNode = curToAdd->getNext();
        nodeToAdd = initNode(data, nextNode);
        cur->setNext(nodeToAdd);
    }
    this->tail = nodeToAdd;
}

#endif // LIST_HPP