#ifndef LISTNODE_CPP
#define LISTNODE_CPP

#include "list_node.h"

template <typename DataType>
ListNode<DataType>::ListNode() : data_(NULL), next_(nullptr) {}

template <typename DataType>
ListNode<DataType>::ListNode(const DataType data) : data_(data), next_(nullptr) {}

template <typename DataType>
ListNode<DataType>::ListNode(const shared_ptr<ListNode<DataType>> node) :
    data_(node->data),
    next_(node) {}

template <typename DataType>
ListNode<DataType>::ListNode(const DataType data,
                             const shared_ptr<ListNode<DataType>> next) :
    data_(data),
    next_(next) {}

template <typename DataType>
ListNode<DataType>::~ListNode()
{
    data_ = NULL;
    next_ = nullptr;
}

template <typename DataType>
void ListNode<DataType>::setData(const DataType data)
{
    data_ = data;
}

template <typename DataType>
DataType ListNode<DataType>::getData() const
{
    return data_;
}

template <typename DataType>
DataType& ListNode<DataType>::getPointer()
{
    return data_;
}

template <typename DataType>
void ListNode<DataType>::setNextNode(const shared_ptr<ListNode<DataType>> next)
{
    next_ = next;
}

template <typename DataType>
shared_ptr<ListNode<DataType>> ListNode<DataType>::getNextNode()
{
    return next_;
}

template <typename DataType>
bool ListNode<DataType>::operator==(const ListNode<DataType>& node) const
{
    return data_ == node->data;
}

template <typename DataType>
bool ListNode<DataType>::operator!=(const ListNode<DataType>& node) const
{
    return data_ != node->data;
}

template <typename DataType>
bool ListNode<DataType>::operator<(const ListNode<DataType>& node) const
{
    return data_ < node->data;
}

template <typename DataType>
bool ListNode<DataType>::operator>(const ListNode<DataType>& node) const
{
    return data_ > node->data;
}

template <typename DataType>
bool ListNode<DataType>::operator<=(const ListNode<DataType>& node) const
{
    return data_ <= node->data;
}

template <typename DataType>
bool ListNode<DataType>::operator>=(const ListNode<DataType>& node) const
{
    return data_ >= node->data;
}

#endif // LISTNODE_CPP
