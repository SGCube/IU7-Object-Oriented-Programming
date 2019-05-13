#ifndef LIST_CPP
#define LIST_CPP

#include "list.h"

ListBase::ListBase() :
    size_(0) {}

ListBase::~ListBase() {}

size_t ListBase::size() const
{
    return size_;
}

template <typename DataType>
List<DataType>::List() :
    head(nullptr),
    tail(nullptr) {}

template <typename DataType>
List<DataType>::List(const List<DataType>& list) :
    head(nullptr),
    tail(nullptr)
{
    extend(list);
}

template <typename DataType>
List<DataType>::List(List<DataType>&& list)
{
    size_ = list->size_;
    head.reset(list->head);
    tail.reset(list->tail);
    list->size_ = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename DataType>
List<DataType>::List(const size_t size, ...) :
    head(nullptr),
    tail(nullptr)
{
    va_list vlist;
    va_start(vlist, size);
    DataType tmp;
    for (size_t i = 0; i < size; i++)
    {
        tmp = va_arg(vlist, DataType);
        append(tmp);
    }
    va_end(vlist);
}

template <typename DataType>
List<DataType>::List(std::initializer_list<DataType>& list)
{
    for (const auto& data : list)
        append(data);
}

template <typename DataType>
List<DataType>::~List() {}

#endif