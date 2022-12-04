#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTesting
{
	TEST_CLASS(NodeTesting)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			TNode<int, int> node(1, 2);
			Assert::AreEqual(1, node.getKey());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
		}

		TEST_METHOD(TestAddLessThan)
		{
			TNode<int,int> node(4,5);
			Assert::AreEqual(4, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(2,4);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(2, node.getLeft()->getItem());
		}

	};
}
