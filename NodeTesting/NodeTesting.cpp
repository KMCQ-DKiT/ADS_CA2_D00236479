#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTesting
{
	TEST_CLASS(NodeTesting)
	{
	public:
		/*
			Test to ensure the data is set in the
			TNode constructor and left, right, parent are nullptr
		*/
		TEST_METHOD(TestConstructor)
		{
			TNode<int, int> node(1, 2);
			Assert::AreEqual(1, node.getKey());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
		}
		/*
			Test Add to add a node as a child. As this is
			A Binary Search Tree, all items add should remain in order.
			By Adding 2 to a node wiht a value of 4, the new node
			should be on the left.
		*/
		TEST_METHOD(TestAddLessThan)
		{
			TNode<int,int> node(4,4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(2,2);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(2, node.getLeft()->getItem());
		}
		/*
		
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 6 to a node wiht a value of 4, the new node
		should be on the right.

		*/
		TEST_METHOD(TestAddGreaterThan)
		{
			TNode<int,int> node(4,4);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getRight());
			node.add(6,6);
			Assert::IsNotNull(node.getRight());
			Assert::AreEqual(6, node.getRight()->getItem());
		}
		/*
		Test Add to add a node as a child. As this is
		A Binary Search Tree, all items add should remain in order.
		By Adding 6 to a node wiht a value of 4, the new node
		should be on the right. If we then add two children 5 and 7
		They should appear as follows
					4
				   / \
					  6
					 / \
					5   7
		*/
		TEST_METHOD(TestAddGreaterThanChildren)
		{
			TNode<int,int> node(4,4);
			node.add(6,6);
			TNode<int,int> *pRight = node.getRight();
			node.add(5,5);
			node.add(7,7);
			Assert::IsNotNull(pRight->getLeft());
			Assert::AreEqual(5, pRight->getLeft()->getItem());
			Assert::IsNotNull(pRight->getRight());
			Assert::AreEqual(7, pRight->getRight()->getItem());

		}
	};
}
