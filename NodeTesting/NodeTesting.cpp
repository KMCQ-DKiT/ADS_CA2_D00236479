#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NodeTesting
{
	TEST_CLASS(NodeTesting)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			TNode<int,int> node(1,1);
			Assert::AreEqual(1, node.getKey());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
		}
	};
}
