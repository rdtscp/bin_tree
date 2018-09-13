#include <string>
#include <vector>
#include <iostream>

#include "gtest/gtest.h"

#include "../include/bin_tree.h"

using namespace ads;

/* Assert that a Default BinTree Constructs without error. */
TEST(BinTreeTest, DefaultConstruction) {
  bin_tree<int> tree({2, 1, 3});

	std::vector<int> expected 	= { 1, 2, 3 };
	std::vector<int> actual		 	= tree.in_order();

	bool result = true;
	for (int i = 0; i < actual.size(); i++) {
		if (expected[i] != actual[i]) {
			result = false;
			break;
		}
		std::cout << actual[i] << ", ";
	}

	ASSERT_TRUE(result);
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