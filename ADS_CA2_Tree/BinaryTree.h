#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{
public:
    void add(K,E item);

	E* search(K key) {
		return nullptr;
	}
};
template <typename K,typename E>
void BinaryTree<typename K,E>::add(K,E item)
{
    if (root == nullptr)
    {
        root = new TNode<K,E>();
        root->setItem(item);
    }
    else
    {
        root->add(item);
    }
}