//#include <catch2/catch_test_macros.hpp>
//#include "AVLTree.h"
//#include <iostream>
//
//using namespace std;
//
//
////
////// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
//TEST_CASE("Incorrect Commands", "[Made]"){
//	// instantiate any class members that you need to test here
//    AVLTree* tree = new AVLTree();
//
//    SECTION("Name Invalid") {
//        tree->insert("My8 Ra0sey","30981303");
//        vector <string> inOrder;
//
//        tree->printInOrder(tree->root,inOrder);
//        REQUIRE(inOrder.size() == 0);
//    };
//    SECTION("ID Length Invalid"){
//        tree->insert("Mya Ramsey","3098130");
//        vector <string> inOrder;
//
//        tree->printInOrder(tree->root,inOrder);
//        REQUIRE(inOrder.size() == 0);
//    }
//    SECTION("Name Valid & ID Valid"){
//        tree->insert("Mya Ramsey","30981303");
//        vector <string> inOrder;
//
//        tree->printInOrder(tree->root,inOrder);
//        REQUIRE(inOrder.size() == 1);
//    }
//    SECTION("Adding Multiple Valid"){
//        tree->insert("Mya Ramsey","30981303");
//        tree->insert("Zach Tyson", "74715154");
//        vector <string> inOrder;
//
//        tree->printInOrder(tree->root,inOrder);
//        cout << inOrder.size() << endl;
//
//        REQUIRE(inOrder.size() == 2);
//    }
//    SECTION("Adding Invalid and Valid"){
//        tree->insert("Mya Ramsey","30981303");
//        tree->insert("sj92h","3091303");
//        vector <string> inOrder;
//        tree->printInOrder(tree->root,inOrder);
//        REQUIRE(inOrder.size() == 1);
//    }
//
//}
//
//TEST_CASE("Test 2", "[flag]"){
//	// you can also use "sections" to share setup code between tests, for example:
//	int one = 1;
//
//	SECTION("num is 2") {
//		int num = one + 1;
//		REQUIRE(num == 2);
//	};
//
//	SECTION("num is 3") {
//		int num = one + 2;
//		REQUIRE(num == 3);
//	};
//
//	// each section runs the setup code independently to ensure that they don't affect each other
//}
//
//// you must write 5 unique, meaningful tests for credit on the testing portion of this project!
//
//// the provided test from the template is below.
//
////TEST_CASE("Example BST Insert", "[flag]"){
////	/*
////		MyAVLTree tree;   // Create a Tree object
////		tree.insert(3);
////		tree.insert(2);
////		tree.insert(1);
////		std::vector<int> actualOutput = tree.inorder();
////		std::vector<int> expectedOutput = {1, 2, 3};
////		REQUIRE(expectedOutput.size() == actualOutput.size());
////		REQUIRE(actualOutput == expectedOutput);
////	*/
////}
