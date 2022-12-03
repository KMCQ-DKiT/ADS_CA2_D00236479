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
	void add(K,E item);




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
TNode<typename K,typename E>::TNode()
{
	pLeft = nullptr;
	pRight = nullptr;
};


template <typename K, typename E>
TNode<typename K,typename E>::TNode(K key, E data)
{
	pLeft = nullptr;
	pRight = nullptr;
	this->data = data;
	this->key = key;
}

template <typename K,typename E>
void TNode<K,E>::add(K key, E data)
{
	if (data == this->data && key == this->key)
	{
		return;
	}
	else if (item < this->data && key < this-> key)
	{
		if (left == nullptr)
		{
			left = new TNode<T>();
			left->data = item;
			left->parent = this;
		}
		else
		{
			left->add(item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new BSTNode<T>();
			right->data = item;
			right->parent = this;
		}
		else
		{
			right->add(item);
		}
	}
}