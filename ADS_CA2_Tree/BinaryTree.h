#pragma once
#include "TNode.h"
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{
	void addItemToArray(TNode<K, E>* node, int& pos, int* arr);


public:


	TNode<K, E>* root;
	BinaryTree();
	void add(K keyItem, E item);
	bool remove(K keyItem, E item);
	
	int Depth(K keyItem);

	bool search(K keyItem);

	void clear();
	int count();

	void printInOrder();
	void printInOrder(TNode<K, E>* node);


	void printPreOrder();
	void printPreOrder(TNode<K, E>* node);

	void printPostOrder();
	void printPostOrder(TNode<K, E>* node);
	E* toArray();
	~BinaryTree();

	//template <typename K, typename E>
//
//	E* search(K key)
//	{
//		TNode<K, E>* toBeFound = root;
//		bool found = false;
//
//		while (!found && toBeFound != nullptr)
//		{
//			if (toBeFound->getItem() == item)
//			{
//				found = true;
//				return toBeFound;
//			}
//			else
//			{
//				if (toBeFound->getItem() > item)
//				{
//					toBeFound = toBeFound->getLeft();
//				}
//				else
//				{
//					toBeFound = toBeFound->getRight();
//				}
//			}
//		}
//		if (!found)
//			return nullptr;
//	}
//	
//};
};

//template <typename K, typename E>
//int BinaryTree<K, E>::depth()
//{
//	if (root == NULL)
//		return 0;
//
//	// Get the depth of the left and right subtree 
//	// using recursion.
//	int leftDepth = depth(root->pLeft);
//	int rightDepth = depth(root->pRight();
//
//	// Choose the larger one and add the root to it.
//	if (leftDepth > rightDepth)
//		return leftDepth + 1;
//	else
//		return rightDepth + 1;
//}

//template <typename K, typename E>
//void BinaryTree<K, E>::findDepth(TNode<K, E>* root)
//{
//	// Base case
//		// Root being null means tree doesn't exist.
//		if (root == NULL)
//			return 0;
//
//		// Get the depth of the left and right subtree 
//		// using recursion.
//		int leftDepth = maxDepth(root->left);
//		int rightDepth = maxDepth(root->right);
//
//		// Choose the larger one and add the root to it.
//		if (leftDepth > rightDepth)
//			return leftDepth + 1;
//		else
//			return rightDepth + 1;
//}




template <typename K, typename E>
int BinaryTree<K, E>::Depth(K keyItem) {

	TNode<K, E>* toBeSearched = root;
	bool found = false;
	int DepthCounter = 0;

	while (!found && toBeSearched != nullptr) {

		DepthCounter++;

		if (toBeSearched->getKey() == keyItem) {
			found = true;
			return DepthCounter;

		}
		else {

			if (toBeSearched->getKey() > keyItem) {
				toBeSearched = toBeSearched->getLeft();
			}
			else {
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return 0;

}

template <typename K, typename E>
bool BinaryTree<K, E>::search(K keyItem)
{
	TNode<K, E>* toBeSearched = root;
	bool found = false;

	while (!found && toBeSearched != nullptr)
	{
		//This is Searching for Finding
		if (toBeSearched->getKey() == keyItem)
		{

			found = true;
		}
		else
		{
			if (toBeSearched->getKey() > keyItem)
			{
				toBeSearched = toBeSearched->getLeft();
			}
			else
			{
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return false;

		//This Defines Finding


}


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
E* BinaryTree<K,E>::toArray()
{
	E* arr = new E[root->count()];
	int pos = 0;
	addItemToArray(root, pos, arr);
	return arr;
}


template <typename K,typename E>
BinaryTree<K,E>::~BinaryTree()
{
	delete root;
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

template<typename K,typename E>
void BinaryTree<K,E>::printInOrder()
{
	this->printInOrder(root);
	cout << endl;
}

template<typename K,typename E>
void BinaryTree<K,E>::printInOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{
		printInOrder(node->getLeft());
		cout << node->getItem() << " ";
		printInOrder(node->getRight());
	}
}
template<typename K, typename E>
void BinaryTree<K,E>::printPreOrder()
{
	this->printPreOrder(root);
	cout << endl;
}

template<typename K, typename E>
void BinaryTree<K,E>::printPreOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{
		cout << node->getItem() << " ";
		printPreOrder(node->getLeft());
		printPreOrder(node->getRight());
	}
}

template<typename K, typename E>
void BinaryTree<K,E>::printPostOrder()
{
	this->printPostOrder(root);
	cout << endl;
}
template<typename K, typename E>
void BinaryTree<K,E>::printPostOrder(TNode<K,E>* node)
{

	if (node != nullptr)
	{

		printPostOrder(node->getLeft());
		printPostOrder(node->getRight());
		cout << node->getItem() << " ";
	}
}