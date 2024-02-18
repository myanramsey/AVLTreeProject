#include <iostream>

#include "AVLTree.h"


using namespace std;

int main(){
	cout << "Hello AVL!\n";
    AVLTree* tree = new AVLTree();

    //right-right case
//    tree->insert("5","5");
//    tree->insert("8","8");
//    tree->insert("2","2");
//    tree->insert("3","3");
//    tree->insert("9","9");
//    tree->insert("10","10");

//    //right-left case
//    tree->insert("22","22");
//    tree->insert("4","4");
//    tree->insert("25","25");
//    tree->insert("1","1");
//    tree->insert("2","2");

    //Right Right
//    tree->insert("1","1");
//    tree->insert("2","2");
//    tree->insert("3","3");

    //Left Left
    tree->insert("3","3");
    tree->insert("2","2");
    tree->insert("1","1");






    cout << "In Order: ";
    tree->printInOrder(tree->root);
    cout << endl;

    cout << "PreOrder: ";
    tree->printPreOrder(tree->root);
    cout << endl;

    cout << "PostOrder: ";
    tree->printPostOrder(tree->root);
    cout << endl;

	return 0;
}
