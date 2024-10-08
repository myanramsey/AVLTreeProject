#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <cmath>

using namespace std;

class AVLTree {
private:
    struct Node{
        string studentName;
        string studentID;
        int height;
        Node* left;
        Node* right;

        Node(){
            this->studentName = "";
            this->studentID = "";
        }
        Node(string name, string id) {
            this->studentName = name;
            this->studentID = id;
            this->height = 0;
            this->left = nullptr;
            this->right = nullptr;

        }

        Node* insertNode(string name, string id){
            if(stoi(id) < stoi(this->studentID)){
                if(this->left == nullptr){
                    this->left = new Node(name,id);
                }
                else{
                    this->left = this->left->insertNode(name,id);
                }
                return this;
            }
            else if(stoi(id) > stoi(this->studentID)){
                if(this->right == nullptr) {
                    this->right = new Node(name, id);
                }
                else{
                    this->right = this->right->insertNode(name,id);

                }
            }
            return this;
        }
        Node* searchIdNode(Node* n, string id){
            if(n == nullptr || n->studentID == id){
                return n;
            }

            if(stoi(id) < stoi(n->studentID)){
                return searchIdNode(n->left,id);
            }
            else if(stoi(id) > stoi(n->studentID)){
                return searchIdNode((n->right),id);
            }
            return n;
        } //Searches if ID exist

        //rotations
        Node* rotateRightRightCase(){
            Node* grandchild = this->right->left;
            Node* newRoot = this->right;
            newRoot->left = this;
            this->right = grandchild;
            return newRoot;
        }
        Node* rotateLeftLeftCase(){
            Node* grandchild = this->left->right;
            Node* newRoot = this->left;
            newRoot->right = this;
            this->left = grandchild;
            return newRoot;
        }
        Node* rightLeftCase(){
            Node* tempRight = right->rotateLeftLeftCase();
            this->right = tempRight;
            Node* newRoot = this->rotateRightRightCase();
            return newRoot;
        }
        Node* leftRightCase() {
            //Left Right Rotation of AVL
            Node* tempLeft = this->left->rotateRightRightCase();
            this->left = tempLeft;
            Node* newRoot = this->rotateLeftLeftCase();
            return newRoot;
        }

        //
    };
public:

    Node* root;

    AVLTree() {
        this->root= nullptr;
    }

    Node* insert(string name, string id){
        if(root == nullptr){ //If there is nothing in the Tree
            root = new Node(name,id);
            return root;
        }

        root->insertNode(name,id); //Inserts node recursively

        updateHeight(root, root->studentID);// Updates height of node to caculate balance factor
        root = findUnbalancedRotate(root); // Caculates Balance Factor and find first node that needs to be chnage and rotates

        return root;
    }

    Node* findUnbalancedRotate(Node* n){
        if(n == nullptr)
            return nullptr;

        n->right = findUnbalancedRotate(n->right);
        n->left = findUnbalancedRotate(n->left);

        int balanceFactor = checkHeight(n->left) - checkHeight(n->right);
        if(balanceFactor < -1 || balanceFactor > 1){

            if(balanceFactor == -2){ //Right Heavy
                //Check for right left rotation
                if(n->right->right == nullptr){
                    //rotation right left rotation
                    n = n->rightLeftCase();
                    return n;
                }
                else{
                    //right right case
                    n = n->rotateRightRightCase();
                    return n;
                }
            }
            else if(balanceFactor == 2){ //Left Heavy
                if(n->left->left == nullptr){
                    // left right rotation
                    n = n->leftRightCase();
                    return n;
                }
                else{
                    //left left rotation
                    n = n->rotateLeftLeftCase();
                    return n;
                }
            }
        }
        return root;
    }

    int checkHeight(Node* n){
        if(n == nullptr){
            return 0;
        }
        else{
            return n->height;
        }
    } // Check height helper function

    int updateHeightHelp(Node* n, string x, int &h){
        if(n == nullptr){
            return 0;
        }

        int leftHeight = updateHeightHelp(n->left, x, h);
        int rightHeight = updateHeightHelp(n->right,x,h);

        int level = 1 + max(leftHeight,rightHeight);

        n->height = level;

        return level;
    }
    void updateHeight(Node* n, string x){
        int h = -1;
        n->height = updateHeightHelp(n,x,h);
    }

    Node* removeNode(Node* n,string id){
        root = remove(root,id);
        updateHeight(root,root->studentID);
        return root;
    }
    Node* remove(Node* n,string id){
        // Base case
        if (n == nullptr)
            return n;

        // Recursive calls for ancestors of
        // node to be deleted
        if (n->studentID > id) {
            n->left = remove(n->left, id);
            return n;
        }
        else if (n->studentID < id) {
            n->right = remove(n->right, id);
            return n;
        }

        //if one of the children is empty
        if (n->left == nullptr) {
            Node* temp = n->right;
            delete n;
            return temp;
        }
        else if (n->right == nullptr) {
            Node* temp = n->left;
            delete n;
            return temp;
        }
            // If both children exist
        else {
            Node* succParent = n;

            // Find successor
            Node* succ = n->right;
            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }

            if (succParent != n)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            n->studentID = succ->studentID;
            n->studentName = succ->studentName;

            // Delete Successor and return root
            delete succ;
            return n;
        }
        return n;
    }

    bool searchId(string id){
        Node* temp = root->searchIdNode(root,id);
        if(temp == nullptr){
            //ID is not found
            return false;
        }
        //Id found
        return true;
    }
    string searchIdName(string id){
        Node* temp = root->searchIdNode(root,id);
        if(temp == nullptr){ //If name is not found
            return "";
        }
        return temp->studentName ;
    }

    void searchNames(Node* n,string name, vector<string> &names){
        if(n != nullptr) {
            if (n->studentName == name) {
                names.push_back(n->studentID);
            }
            searchNames(n->left, name, names);
            searchNames(n->right, name, names);
        }
    }
    void searchNamesID(Node* n,string name, vector<string> &names){
        if(n != nullptr) {
            if (n->studentName == name) {
                names.push_back(n->studentName);
            }
            searchNamesID(n->left, name, names);
            searchNamesID(n->right, name, names);
        }
    }

    void removeNthNode(Node* n, vector<string> &id){
        //BFT to create preorder vector to find the ID associated with name
        if(n != nullptr){
            removeNthNode(n->left,id);
            id.push_back(n->studentID);
            removeNthNode(n->right,id);
        }
    }

    int findLevel(Node* n){ //finds max level of tree
        if (n == nullptr) {
            return 0;
        }
        else {
            int leftDepth = findLevel(n->left);
            int rightDepth = findLevel(n->right);

            return max(leftDepth,rightDepth) + 1;
        }
    }

    void printInOrder(Node* n, vector<string> &names){
        if(n != nullptr){
            printInOrder(n->left,names);
            names.push_back(n->studentName);
            printInOrder(n->right,names);
        }
    }
    void printPreOrder(Node* n,vector<string> &names){
        if(n != nullptr){
            names.push_back(n->studentName);
            printPreOrder(n->left,names);
            printPreOrder(n->right,names);
        }
    }
    void printPostOrder(Node* n,vector<string> &names){
        if(n != nullptr){
            printPostOrder(n->left,names);
            printPostOrder(n->right,names);
            names.push_back(n->studentName);
        }
    }
    void printHeightNode(Node* n){
        if(n == nullptr){
            return;
        }
        printHeightNode(n->left);
        cout << n->studentName << "  : " << n->height << endl;
        printHeightNode(n->right);
    }

    bool isValidName(string name){
        for(unsigned int i = 0; i < name.length(); i++){
            if(isdigit(name[i]) || ispunct(name[i])){
                return false;
            }
        }
        return true;
    }
    bool isValidID(string id){
        for(unsigned int i = 0; i < id.length(); i++){
            if(!isdigit(id[i])){
                return false;
            }
        }

        return true;
    }
};



