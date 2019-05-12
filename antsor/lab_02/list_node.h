#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>
using std::shared_ptr;

template <typename DataType>
class ListNode
{
public:
    // constructor
    ListNode();
    explicit ListNode(const DataType data);
    explicit ListNode(const shared_ptr<ListNode<DataType>> node);
    ListNode(const DataType data, const shared_ptr<ListNode<DataType>> next);

    // destructor
    virtual ~ListNode();

    // data access
    void setData(const DataType data);
    DataType getData() const;
    DataType& getPointer();

    // next node access
    void setNextNode(const shared_ptr<ListNode<DataType>> next);
    shared_ptr<ListNode<DataType>> getNextNode();

    // data compare operators
    bool operator==(const ListNode<DataType>& node) const;
    bool operator!=(const ListNode<DataType>& node) const;
    bool operator<(const ListNode<DataType>& node) const;
    bool operator>(const ListNode<DataType>& node) const;
    bool operator<=(const ListNode<DataType>& node) const;
    bool operator>=(const ListNode<DataType>& node) const;

private:
    DataType data_;
    shared_ptr<ListNode<DataType>> next_;
};

#endif // LISTNODE_H
