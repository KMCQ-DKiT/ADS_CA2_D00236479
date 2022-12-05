#pragma once
#include "TNode.h"
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{
	void addItemToArray(TNode<K,E>* node, int& pos, int* arr);


public:


	TNode<K,E> *root;
	BinaryTree();
    void add(K keyItem, E item);
    bool remove(K keyItem, E item);

	void clear();

	int count();



	E* search(K key) {
		return nullptr;
	}
	
};
template <typename K, typename E>
BinaryTree<K,E>::BinaryTree()
{
	root = nullptr;
}
template <typename K, typename E>
void BinaryTree<K,E>::add(K keyItem,E item)
{
    if (root == nullptr)
    {
        root = new TNode<K,E>();
		root->setKeyItem(keyItem);
        root->setItem(item);
		
    }
    else
    {	
		root->add(keyItem,item);
        
		
    }
}

template <typename K, typename E>
bool BinaryTree<K,E>::remove(K keyItem, E item)
{
	TNode<K,E>* toBeRemoved = root;
	TNode<K,E>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getItem() == item && toBeRemoved->getKey()== keyItem)
		{

			found = true;
		}
		else
		{
			parent = toBeRemoved;
			if (toBeRemoved->getItem() > item && toBeRemoved->getKey() > keyItem)
			{
				toBeRemoved = toBeRemoved->getLeft();
			}
			else
			{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
	{
		TNode<K,E>* newChild;
		if (toBeRemoved->getLeft() == nullptr)
		{
			newChild = toBeRemoved->getRight();
		}
		else
		{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr)
		{
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved)
		{
			parent->setLeft(newChild);
		}
		else
		{
			parent->setRight(newChild);
		}
		return true;
	}

	TNode<K,E>* smallestParent = toBeRemoved;
	TNode<K,E>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr)
	{
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	toBeRemoved->setItem(smallest->getItem());
	if (smallestParent == toBeRemoved)
	{
		smallestParent->setRight(smallest->getRight());
	}
	else
	{
		smallestParent->setLeft(smallest->getRight());
	}

}

template <typename K,typename E>
void BinaryTree<K,E>::clear()
{
	delete root;
	root = nullptr;
}

template <typename K,typename E>
int BinaryTree<K,E>::count()
{
	if (root == nullptr)
		return 0;
	return root->count();
}