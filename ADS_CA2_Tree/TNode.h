#pragma once

template <typename K, typename E>
class TNode {
private:
	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E data;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight;

public:

	TNode();
	TNode(K,E);
	void setItem(K keyItem, E item);
	TNode<K,E>* getLeft();
	TNode<K, E>* getRight();





	K getKey();



	bool insert(K key, E data) {
		return false;
	}
	void setKey(K key) {
		this->key = key;
	}
	K getKey() const {
		return this->key;
	}
	void setData(E data) {
		this->data = data; 
	}
	E getData() const {
		return this->data;
	}
};
template <typename K,typename E>
K TNode<K,E>::getKey()
{
	return this->key;
}

template <typename K, typename E>
TNode<K, E>::TNode()
{
	pLeft = nullptr;
	pRight = nullptr;
};


template <typename K, typename E>
TNode<typename K, typename E>::TNode(K key, E data)
{
	pLeft = nullptr;
	pRight = nullptr;
	this->data = data;
	this->key = key;
}



template <typename K,typename E>
void TNode<K,E>::setItem(K keyItem,E item)
{
	this->data = item;
	this->key = keyItem;
}
template <typename K,typename E>
TNode<K,E>* TNode<K,E>::getLeft()
{
	return this->pLeft;
}
template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getRight()
{
	return this->pRight;
}