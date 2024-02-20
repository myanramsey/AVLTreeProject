#include <catch2/catch_test_macros.hpp>
#include "AVLTree.h"
#include <iostream>

using namespace std;


//
//// the syntax for defining a test is below. It is important for the name to be unique, but you can group multiple tests with [tags]. A test can have [multiple][tags] using that syntax.
TEST_CASE("Incorrect Commands", "[Made]"){
	// instantiate any class members that you need to test here
    AVLTree* tree = new AVLTree();
    bool idCheck;
    bool nameCheck;

    SECTION("Name Invalid") {
        nameCheck = tree->isValidName("My8 Ramsey");
        REQUIRE(nameCheck == false);
    };
    SECTION("ID Length Invalid"){
        idCheck = tree->isValidID("3098130A");
        REQUIRE(idCheck == false);
    }
    SECTION("Name Valid & ID Valid"){
        nameCheck = tree->isValidName("Mya Ramsey");
        idCheck = tree->isValidID("30981303");
        REQUIRE(nameCheck == true);
        REQUIRE(idCheck == true);

    }
    SECTION("Adding Multiple Valid"){
        tree->insert("Mya Ramsey","30981303");
        tree->insert("Zach Tyson", "74715154");
        vector <string> inOrder;

        tree->printInOrder(tree->root,inOrder);
        REQUIRE(inOrder.size() == 2);
    }
    SECTION("Adding Invalid and Valid"){
        string names[4] = {"Mya Ramsey","skljad!","Amy","Money3"};
        string id[4] = {"30981303", "2ajduoi", "12345678", "00000000"};

        for(int i = 0; i < 4; i++){
            if(tree->isValidName(names[i]) && tree->isValidID(id[i])){
                tree->insert(names[i],id[i]);
            }
        }

        vector <string> inOrder;
        tree->printInOrder(tree->root,inOrder);
        REQUIRE(inOrder.size() == 2);
    }

}

TEST_CASE("Edge Cases", "[Made]"){
	// you can also use "sections" to share setup code between tests, for example:
    AVLTree* tree = new AVLTree();

    SECTION("Removing A Node That DNE") {
		tree->insert("Mya","30981303");
        tree->remove(tree->root,"1234890");
        vector <string> inOrder;
        tree->printInOrder(tree->root,inOrder);
        REQUIRE(inOrder.size() == 1);
	};

	SECTION("Multiple Names Search") {
		tree->insert("Mya","30981303");
        tree->insert("Mya","12345678");
        vector<string> namesFound;
        tree->searchNames(tree->root,"Mya",namesFound);
		REQUIRE(namesFound.size() == 2);
	};
    SECTION("Names Not Found"){
        tree->insert("Megan","30981303");
        tree->insert("Mya","12345678");
        vector<string> namesFound;
        tree->searchNames(tree->root,"Zach",namesFound);
        REQUIRE(namesFound.size() == 0);
    }

	// each section runs the setup code independently to ensure that they don't affect each other
}

TEST_CASE("Rotations","[Made]"){
    AVLTree* tree = new AVLTree();
    vector<string> preOrder;

    SECTION("Right Left Rotation"){
        tree->insert("22","22");
        tree->insert("4","4");
        tree->insert("25","25");
        tree->insert("1","1");
        tree->insert("2","2");

        tree->printPreOrder(tree->root,preOrder);
        vector<string> expectedOutput = {"22","2","1","4","25"};

        REQUIRE(preOrder == expectedOutput);
    }
    SECTION("Left Right Case"){
        tree->insert("10","10");
        tree->insert("8","8");
        tree->insert("9","9");

        tree->printPreOrder(tree->root,preOrder);
        vector<string> expectedOutput = {"9","8","10"};

        REQUIRE(preOrder == expectedOutput);
    }
    SECTION("Right Right Case"){
        tree->insert("1","1");
        tree->insert("2","2");
        tree->insert("3","3");

        tree->printPreOrder(tree->root,preOrder);
        vector<string> expectedOutput = {"2","1","3"};

        REQUIRE(preOrder == expectedOutput);
    }
    SECTION("Left Left Case"){
        tree->insert("3","3");
        tree->insert("2","2");
        tree->insert("1","1");

        tree->printPreOrder(tree->root,preOrder);
        vector<string> expectedOutput = {"2","1","3"};

        REQUIRE(preOrder == expectedOutput);
    }

}

TEST_CASE("Deletion", "[Made]"){
    x
}

// you must write 5 unique, meaningful tests for credit on the testing portion of this project!

// the provided test from the template is below.

//TEST_CASE("Example BST Insert", "[flag]"){
//	/*
//		MyAVLTree tree;   // Create a Tree object
//		tree.insert(3);
//		tree.insert(2);
//		tree.insert(1);
//		std::vector<int> actualOutput = tree.inorder();
//		std::vector<int> expectedOutput = {1, 2, 3};
//		REQUIRE(expectedOutput.size() == actualOutput.size());
//		REQUIRE(actualOutput == expectedOutput);
//	*/
//}
