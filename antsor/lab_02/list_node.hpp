#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include "list_node.h"

template <typename T>
ListNode<T>::ListNode() : data_(NULL), next_(nullptr) {}

template <typename T>
ListNode<T>::ListNode(const T data) :
	data_(data),
	next_(nullptr) {}

template <typename T>
ListNode<T>::ListNode(const T data, const shared_ptr<ListNode<T>> next) :
    data_(data),
    next_(next) {}

template <typename T>
ListNode<T>::~ListNode()
{
    this->data_ = NULL;
    this->next_ = nullptr;
}

template <typename T>
void ListNode<T>::setData(const T data)
{
    this->data_ = data;
}

template <typename T>
T ListNode<T>::getData() const
{
    return this->data_;
}

template <typename T>
T& ListNode<T>::getPointer()
{
    return this->data_;
}

template <typename T>
void ListNode<T>::setNext(const shared_ptr<ListNode<T>> next)
{
    this->next_ = next;
}

template <typename T>
shared_ptr<ListNode<T>> ListNode<T>::getNext()
{
    return this->next_;
}

template <typename T>
bool ListNode<T>::operator==(const ListNode<T>& node) const
{
    return this->data_ == node->data;
}

template <typename T>
bool ListNode<T>::operator!=(const ListNode<T>& node) const
{
    return this->data_ != node->data;
}

template <typename T>
bool ListNode<T>::operator<(const ListNode<T>& node) const
{
    return this->data_ < node->data;
}

template <typename T>
bool ListNode<T>::operator>(const ListNode<T>& node) const
{
    return this->data_ > node->data;
}

template <typename T>
bool ListNode<T>::operator<=(const ListNode<T>& node) const
{
    return this->data_ <= node->data;
}

template <typename T>
bool ListNode<T>::operator>=(const ListNode<T>& node) const
{
    return this->data_ >= node->data;
}

#endif // LISTNODE_HPP
