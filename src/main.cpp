#include <iostream>

#include "AVLTree.h"


using namespace std;

int main(){
	cout << "Hello AVL!\n";
    AVLNode* root = nullptr;
    root = insert(root,"Mya","30981303");
    root = insert(root,"Emmy","102345");
    root = insert(root,"Zach","88829201");
    root = insert(root,"9s9sd","009101");
    root = insert(root,"Cielo","2921a");
    root = insert(root,"sdjs/","1890218");
    printAVLTree(root);


	return 0;
}
