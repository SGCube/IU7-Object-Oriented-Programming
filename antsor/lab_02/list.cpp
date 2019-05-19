#ifndef LIST_CPP
#define LIST_CPP

#include "error.hpp"
#include "list.h"

ListBase::ListBase() :
    size_(0) {}

ListBase::~ListBase() {}

size_t ListBase::size() const
{
    return this->size_;
}

////////////////////////////////////////////////////////////////////////////////

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

// protected

template <typename T>
std::shared_ptr<ListNode<T>> List<T>::initNode(const T& data, std::shared_ptr<ListNode<T>> nodePtr)
{
    std::shared_ptr<ListNode<typeData>> newNode;
    newNode = std::make_shared<ListNode<typeData>>();
    if (!newNode)
    {
        throw MemoryError(": method - initNode()");
    }
    newNode->setData(data);
    newNode->setNext(ptrNode);
    this->sizeList += 1;
    
    return newNode;
}

#endif // LIST_CPP