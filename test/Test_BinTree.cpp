#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/bin_tree.h"

using namespace ads;

/* Assert that a Default BinTree Constructs without error. */
TEST(BinTreeTest, DefaultConstruction) {
  bin_tree<int> tree;

	ASSERT_FALSE(tree.find(1));
}

TEST(BinTreeTest, VectorConstructor) {
	bin_tree<int> tree({2, 1, 3});

	ASSERT_FALSE(tree.find(0));
	ASSERT_TRUE(tree.find(1));
	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree.find(3));

	std::vector<int> expected 	= { 1, 2, 3 };
	std::vector<int> actual			= tree.in_order();

	ASSERT_EQ(actual, expected);
}

TEST(BinTreeTest, InitializerListConstructor) {
	bin_tree<int> tree = {2, 1, 3};

	ASSERT_FALSE(tree.find(0));
	ASSERT_TRUE(tree.find(1));
	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree.find(3));

	std::vector<int> expected 	= { 1, 2, 3 };
	std::vector<int> actual			= tree.in_order();

	ASSERT_EQ(actual, expected);
}

TEST(BinTreeTest, CopyConstructor) {
	bin_tree<int> tree({1, 2, 3});

	ASSERT_TRUE(tree.find(2));

	bin_tree<int> tree_copy(tree);

	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree_copy.find(2));
}

TEST(BinTreeTest, AssignmentCopy) {
	bin_tree<int> tree({1, 2, 3});

	ASSERT_TRUE(tree.find(2));

	bin_tree<int> tree_copy = tree;

	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree_copy.find(2));

	tree_copy = tree_copy;

	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree_copy.find(2));
}

TEST(BinTreeTest, InOrderTraversal) {
	bin_tree<int> tree({10, 5, 2, 3, 4, 1, 8, 9, 7, 6});

	std::vector<int> expected 	= { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	std::vector<int> actual			= tree.in_order();

	ASSERT_EQ(actual, expected);
}

TEST(BinTreeTest, ClearBinaryTree) {
	bin_tree<int> tree({2, 1, 3});

	ASSERT_FALSE(tree.find(0));
	ASSERT_TRUE(tree.find(1));
	ASSERT_TRUE(tree.find(2));
	ASSERT_TRUE(tree.find(3));

	tree.clear();

	ASSERT_FALSE(tree.find(0));
	ASSERT_FALSE(tree.find(1));
	ASSERT_FALSE(tree.find(2));
	ASSERT_FALSE(tree.find(3));
}

TEST(BinTreeTest, InsertElement) {
	bin_tree<int> tree;

	ASSERT_FALSE(tree.find(0));

	tree.insert(0);

	ASSERT_TRUE(tree.find(0));
}

TEST(BinTreeTest, PreOrderTraversal) {
	bin_tree<int> tree({1, 2, 3, 4, 5, 6, 7});

	std::vector<int> rightPreOrder 	= { 4, 2, 1, 3, 6, 5, 7 };
	std::vector<int> actual					= tree.pre_order();

	ASSERT_EQ(actual, rightPreOrder);
}

TEST(BinTreeTest, PostOrderTraversal) {
	bin_tree<int> tree({1, 2, 3, 4, 5, 6, 7});

	std::vector<int> rightPostOrder  { 1, 3, 2, 5, 7, 6, 4 };
	std::vector<int> actual					= tree.post_order();

	ASSERT_EQ(actual, rightPostOrder);
}

// The fixture for testing class Project1. From google test primer.
class Test_BinTree : public ::testing::Test {
	protected:

		Test_BinTree() {
			// You can do set-up work for each test here.
		}

		// If the constructor and destructor are not enough for setting up
		// and cleaning up each test, you can define the following methods:
		virtual void SetUp() {
			// Code here will be called immediately after the constructor (right
			// before each test).
		}

		virtual void TearDown() {
			// Code here will be called immediately after each test (right
			// before the destructor).
		}

};