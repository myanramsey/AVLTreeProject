#include <iostream>

#include "AVLTree.h"


using namespace std;

int main(){
	cout << "Hello AVL!\n";
    AVLNode* root = nullptr;
    root = root->insert(root,"5","5");
    root->insert(root,"8","8");
    root->insert(root,"2","2");
    root->insert(root,"3","3");
    root->insert(root,"9","9");
    root->insert(root,"10","10");

    cout << "In Order: ";
    root->printInOrder(root);
    cout << endl;

    cout << "PreOrder: ";
    root->printPreOrder(root);
    cout << endl;

    cout << "PostOrder: ";
    root->printPostOrder(root);
    cout << endl;

    cout << "Heights" << endl;
    root->printHeightNode(root);



	return 0;
}
