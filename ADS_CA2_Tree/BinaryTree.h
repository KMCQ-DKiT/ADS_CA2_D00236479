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
