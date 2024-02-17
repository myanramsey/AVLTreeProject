#include <iostream>

#include "AVLTree.h"


using namespace std;

int main(){
	cout << "Hello AVL!\n";
    AVLTree* tree = new AVLTree();
    tree->insert("5","5");
    tree->insert("8","8");
    tree->insert("2","2");
    tree->insert("3","3");
    tree->insert("9","9");
    tree->insert("10","10");

    cout << "In Order: ";
    tree->printInOrder(tree->root);
    cout << endl;

    cout << "PreOrder: ";
    tree->printPreOrder(tree->root);
    cout << endl;

    cout << "PostOrder: ";
    tree->printPostOrder(tree->root);
    cout << endl;

    cout << "Heights" << endl;
    tree->printHeightNode(tree->root);



	return 0;
}
