#pragma once
#include "TNode.h"
#include<iostream>
#include <math.h>
#include <algorithm>
using namespace std;
template <typename K, typename E>
class BinaryTree
{
public:
	TNode<K, E>* root;
	BinaryTree();
	void add(K keyItem, E item);
	bool remove(K keyItem, E item);
	int Depth(K keyItem);
	int search(K keyItem);
	int Balance(TNode<K, E>* root);
	int Height(TNode<K, E>* root);	
	void clear();
	int count();
	TNode<K, E>* SubTree(TNode<K, E>* root, K keyItem);
	void printInOrder();
	void printInOrder(TNode<K, E>* node);
	void printPreOrder();
	void printPreOrder(TNode<K, E>* node);
	void printPostOrder();
	void printPostOrder(TNode<K, E>* node);
	~BinaryTree();


};


template <typename K, typename E>
int BinaryTree<K, E>::Height(TNode<K, E>* root)
{
	try
	{
		if (root == nullptr)
			return 0;
		return 1 + max(Height(root->getLeft()), Height(root->getRight()));
	}
	catch (...)
	{
		throw runtime_error("Something went wrong!");
	}
}


template <typename K, typename E>
int BinaryTree<K, E>::Depth(K keyItem) {

	TNode<K, E>* toBeSearched = root;
	bool found = false;
	int DepthCounter = -1;

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
int BinaryTree<K, E>::Balance(TNode<K, E>* root)
{
	try
	{
		if (root == nullptr)
			return true;
		int lh = Height(root->getLeft());
		int rh = Height(root->getRight());

		return (abs(lh - rh) <= 1 & Balance(root->getLeft()) & Balance(root->getRight()));
	}
	catch (...)
	{
		throw runtime_error("Something went wrong!");
	}
}
template <typename K, typename E>
int BinaryTree<K, E>::search(K keyItem)
{
	TNode<K, E>* node = root;
	try
	{
		while (node != nullptr)
		{
			if (node->getKey() == keyItem)
			{
				break;
			}
			else if (keyItem < node->getKey())
			{
				node = node->getLeft();
			}
			else
			{
				node = node->getRight();
			}
		}
		if (node != nullptr)
		{
			return node->getItem();
		}
	}
	catch (K keyItem)
	{
		throw runtime_error(keyItem + "No Key");
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}
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


template<typename K, typename E>
void BinaryTree<K, E>::printInOrder()
{

	try
	{
		this->printInOrder(root);
		cout << endl;
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}
template<typename K, typename E>
void BinaryTree<K, E>::printInOrder(TNode<K, E>* node)
{

	try
	{
		if (node != nullptr)
		{
			printInOrder(node->getLeft());
			cout << node->getItem() << " ";
			printInOrder(node->getRight());
		}
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}
template<typename K, typename E>
void BinaryTree<K, E>::printPreOrder()
{

	try
	{
		this->printPreOrder(root);
		cout << endl;
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}

template<typename K, typename E>
void BinaryTree<K, E>::printPreOrder(TNode<K, E>* node)
{

	try
	{
		if (node != nullptr)
		{
			cout << node->getItem() << " ";
			printPreOrder(node->getLeft());
			printPreOrder(node->getRight());
		}
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}
template<typename K, typename E>
void BinaryTree<K, E>::printPostOrder()
{
	try
	{
		this->printPostOrder(root);
		cout << endl;
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}
template<typename K, typename E>
void BinaryTree<K, E>::printPostOrder(TNode<K, E>* node)
{
	try
	{
		if (node != nullptr)
		{

			printPostOrder(node->getLeft());
			printPostOrder(node->getRight());
			cout << node->getItem() << " ";
		}
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}

}

template <typename K, typename E>
TNode<K, E>* BinaryTree<K, E>::SubTree(TNode<K, E> *root, K keyItem) {
    try
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		if (root->getKey() == keyItem)
		{
			return root;
		}

		TNode<K, E>* leftSubtree = SubTree(root->getLeft(), keyItem);
		TNode<K, E>* rightSubtree = SubTree(root->getRight(), keyItem);

		if (leftSubtree != nullptr)
		{
			return leftSubtree;
		}
		else if (rightSubtree != nullptr)
		{
			return rightSubtree;
		}
		else
		{
			return nullptr;
		}
	}
	catch (K keyItem)
	{
		throw runtime_error(keyItem + "No Key");
	}
	catch (...)
	{
		throw runtime_error("ERROR!");
	}
}