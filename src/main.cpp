#include <iostream>
#include <string>

#include "AVLTree.h"


using namespace std;

int main(){
	cout << "Hello AVL!\n";
    AVLNode* root = nullptr;
    root = insert(root,"Mya","30981303");
    root = insert(root,"Emmy","102345");
    root = insert(root,"Zach","88829201");
    printAVLTree(root);


	return 0;
}
