#include <memory>

template <class ItemType>
class DoubleNode
{
public:
	DoubleNode();
	DoubleNode(const ItemType& anItem);
	DoubleNode(const ItemType& anItem, std::shared_ptr<DoubleNode<ItemType>> next, std::shared_ptr<DoubleNode<ItemType>> previous);
private:
	ItemType item;
	std::shared_ptr<DoubleNode<ItemType>> next;
	std::weak_ptr<DoubleNode<ItemType>> previous;
};