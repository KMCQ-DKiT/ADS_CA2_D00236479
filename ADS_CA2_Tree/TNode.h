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
	TNode(K, E);

	void setItem(K keyItem, E item);

	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();

	void add(K keyItem, E item);

	void setLeft(TNode<K, E>* l);
	void setRight(TNode<K, E>* r);


	int count();

	E getItem();

	K getKey();


	~TNode();


};
//template <typename K, typename E>
//	bool insert(K key, E data) {
//		return false;
//	}
//	template <typename K, typename E>
//
//	void setData(E data) {
//		this->data = data; 
//	}
//	template <typename K, typename E>
//	E getData() const {
//		return this->data;
//	}

template <typename K,typename E>
E TNode<K,E>::getItem()
{
	return this->data;

}

template <typename K, typename E>
K TNode<K, E>::getKey()
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

template <typename K,typename E>
void TNode<K, E>::add(K keyItem, E item)
{
	//Checks for Duplicates
	if (item == this->data && keyItem == this->key)
	{
		return;
	}
	// Checking if the data is the same but key is less than
	else if (item == this->data && keyItem < this->key) {

		if (pLeft == nullptr)
		{
			pLeft = new TNode<K, E>();
			pLeft->data = item;
			pLeft->key = keyItem;
		

		}
		else
		{
			pLeft->add(item,keyItem);

		}

	}
	// Checking if the data is the same and key is greater than
	else if (item == this->data && keyItem > this->key) {

		if (pRight == nullptr)
		{
			pRight = new TNode<K, E>();
			pRight->data = item;
			pRight->key = keyItem;

		}
		else
		{
			pRight->add(item,keyItem);
		}
	}
	//Checking if data is Lower than and key is the same
	else if (item < this->data && keyItem == this->key) {
		if (pLeft == nullptr)
		{
			pLeft = new TNode<K, E>();
			pLeft->data = item;
			pLeft->key = keyItem;


		}
		else
		{
			pLeft->add(item,keyItem);
		}

	}
	// Checking if data is higher than and key is the same
	else if (item > this->data && keyItem == this->key) {
		if (pRight == nullptr)
		{
			pRight = new TNode<K, E>();
			pRight->data = item;
			pRight->key = keyItem;

		}
		else
		{
			pRight->add(item,keyItem);
		}
	}
	//Checks if data and key is larger than
	else if (item > this->data && keyItem > this->key) {
		if (pRight == nullptr)
		{
			pRight = new TNode<K, E>();
			pRight->data = item;
			pRight->key = keyItem;

		}
		else
		{
			pRight->add(item,keyItem);
		}

	}
	//Checks if data and key is less than
	else if (item < this->data && keyItem < this->key) {
		if (pLeft == nullptr)
		{
			pLeft = new TNode<K, E>();
			pLeft->data = item;
			pLeft->key = keyItem;


		}
		else
		{
			pLeft->add(item,keyItem);
		}
	}
			
	

}
template <typename K,typename E>
void TNode<K,E>::setLeft(TNode<K,E>* l)
{
	this->pLeft = l;
}
template <typename K,typename E>
void TNode<K,E>::setRight(TNode<K,E>* r)
{
	this->pRight = r;
}
template <typename K,typename E>
int TNode<K,E>::count()
{
	int c = 1;
	if (pLeft != nullptr)
	{
		c += pLeft->count();
	}
	if (pRight != nullptr)
	{
		c += pRight->count();
	}
	return c;
}

template <typename K,typename E>
TNode<K,E>::~TNode()
{
	delete pLeft;
	delete pRight;
}