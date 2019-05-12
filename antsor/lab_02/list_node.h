#ifndef LISTNODE_H
#define LISTNODE_H

#include <memory>
using std::shared_ptr;

template <typename DataType>
class ListNode
{
public:
    ListNode();
    explicit ListNode(const DataType data);
    explicit ListNode(const shared_ptr<ListNode<DataType>> node);
    ListNode(const DataType data, const shared_ptr<ListNode<DataType>> next);

    virtual ~ListNode();

    void setData(const DataType data);
    DataType getData() const;
    DataType& getPointer();

    void setNextNode(const shared_ptr<ListNode<DataType>> next);
    shared_ptr<ListNode<DataType>> getNextNode();

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
