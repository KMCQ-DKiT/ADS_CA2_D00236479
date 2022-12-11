#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BinaryTreeTest
{
	TEST_CLASS(BinaryTreeTest)
	{
	public:
		
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int,int> tree;
			tree.add(1,2);
			Assert::IsNotNull(tree.root);

			Assert::AreEqual(2, tree.root->getItem());
		}

		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int,int> tree;
			tree.add(3,5);
			tree.add(1,2);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(5, tree.root->getItem());
			TNode<int,int>* pLeft = tree.root->getLeft();
			Assert::IsNotNull(pLeft);
			Assert::AreEqual(2, pLeft->getItem());
		}
		TEST_METHOD(TestAddToRootRight)
		{
			BinaryTree<int,int> tree;
			tree.add(2,2);
			tree.add(3,3);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			TNode<int,int>* pRight = tree.root->getRight();
			Assert::IsNotNull(pRight);
			Assert::AreEqual(3, pRight->getItem());
		}
		TEST_METHOD(TestCountOnFullTree)
		{
			BinaryTree<int,int> tree;
			tree.add(4,6);
			tree.add(2,1);
			tree.add(6,8);
			tree.add(1,5);
			tree.add(3,9);
			tree.add(5,10);
			tree.add(7,20);

			Assert::AreEqual(7, tree.count());
		}

		TEST_METHOD(TestRemoveItemNotPresent)
		{
			BinaryTree<int,int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			Assert::AreEqual(7, tree.count());
			tree.remove(8,8);
			Assert::AreEqual(7, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int,int>* left = tree.root->getLeft();
			TNode<int,int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		TEST_METHOD(TestRemoveLeafNode)
		{
			BinaryTree<int,int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			Assert::AreEqual(7, tree.count());
			tree.remove(5,5);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int,int>* left = tree.root->getLeft();
			TNode<int,int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			BinaryTree<int,int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			Assert::AreEqual(7, tree.count());
			tree.remove(7,7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int,int>* left = tree.root->getLeft();
			TNode<int,int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());
		}

		TEST_METHOD(TestRemoveNodeWithTwoChildren)
		{
			BinaryTree<int,int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			Assert::AreEqual(7, tree.count());
			tree.remove(2,2);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int,int>* left = tree.root->getLeft();
			TNode<int,int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			BinaryTree<int,int> tree;
			tree.add(8,8);
			tree.add(4,4);
			tree.add(12,12);
			tree.add(2,2);
			tree.add(6,6);
			tree.add(1,1);
			tree.add(3,3);
			tree.add(5,5);
			tree.add(7,7);
			tree.add(10,10);
			tree.add(14,14);
			tree.add(9,9);
			tree.add(11,11);
			tree.add(13,13);
			tree.add(15,15);
			Assert::AreEqual(15, tree.count());

			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
			tree.remove(12,12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getItem());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
		}

		TEST_METHOD(SearchIsTrue)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			tree.search(7);
			Assert::IsTrue(tree.search(7));
		}

		TEST_METHOD(SearchIsFalse)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
		
			Assert::IsFalse(tree.search(90));
		}

		TEST_METHOD(TestGetSubTree)
		{

		

			BinaryTree<int, int> tree;
			TNode<int, int>* root = new TNode<int, int>(10, 10);
			root->setLeft(new TNode<int, int>(4, 4));
			root->setRight(new TNode<int, int>(15, 15));
			root->getLeft()->setLeft(new TNode<int, int>(3, 3));
			root->getLeft()->setRight(new TNode<int, int>(14, 14));
			root->getLeft()->getLeft()->setLeft(new TNode<int, int>(2, 2));
			root->getLeft()->getRight()->setRight(new TNode<int, int>(17, 17));
			TNode<int, int>* new_root = tree.SubTree(root, 15);

		}
		TEST_METHOD(SearchDepth)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 6);
			tree.add(2, 1);
			tree.add(6, 8);
			tree.add(1, 5);
			tree.add(3, 9);
			tree.add(5, 10);
			tree.add(7, 20);
			Assert::AreEqual(2, tree.Depth(3));

		}


		TEST_METHOD(SearchHeight)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(8, 8);
			Assert::AreEqual(4, tree.Height(tree.root));
		}
		TEST_METHOD(TestfindBalance)
		{
			BinaryTree<int, int> tree;
			TNode<int, int>* root = tree.root;
			tree.add(8, 8);
			tree.add(3, 3);
			tree.add(10, 10);
			tree.add(3, 3);
			tree.add(2, 2);
			tree.add(15, 15);
			tree.add(13, 13);
			tree.add(12, 12);

			Assert::AreEqual(1, tree.Balance(root));

		};

	};
}
