#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>
using std::shared_ptr;

template <typename T>
class ListNode
{
public:
    // constructor
    ListNode();
    explicit ListNode(const T data);
    explicit ListNode(const shared_ptr<ListNode<T>> node);
    ListNode(const T data, const shared_ptr<ListNode<T>> next);

    // destructor
    virtual ~ListNode();

    // data access
    void setData(const T data);
    T getData() const;
    T& getPointer();

    // next node access
    void setNext(const shared_ptr<ListNode<T>> next);
    shared_ptr<ListNode<T>> getNext();

    // data compare operators
    bool operator==(const ListNode<T>& node) const;
    bool operator!=(const ListNode<T>& node) const;
    bool operator<(const ListNode<T>& node) const;
    bool operator>(const ListNode<T>& node) const;
    bool operator<=(const ListNode<T>& node) const;
    bool operator>=(const ListNode<T>& node) const;

private:
    T data_;
    shared_ptr<ListNode<T>> next_;
};

#endif // LISTNODE_H
