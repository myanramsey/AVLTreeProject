#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <cmath>


//TODO: Ask Zack how to make test cases on checking height and order of the nodes to ensure insert working properly.
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
        }

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
    AVLTree(string studentName, string studentID) {
        this->root->studentName = studentName;
        this->root->studentID = studentID;
        this->root->height = 0;
        this->root->left = nullptr;
        this->root->right = nullptr;
    }


    Node* insert(string name, string id){
        if(root == nullptr){
            root = new Node(name,id);
            return root;
        }

        root->insertNode(name,id);

        updateHeight(root, root->studentID);
        root = findUnbalancedRotate(root);


        return root;
    }

    Node* findUnbalancedRotate(Node* n){
        if(n == nullptr)
            return nullptr;

        n->right = findUnbalancedRotate(n->right);
        n->left = findUnbalancedRotate(n->left);

        int balanceFactor = checkHeight(n->left) - checkHeight(n->right);
        if(balanceFactor < -1 || balanceFactor > 1){

            cout << n->studentName << " is unbalanced. BF: " << balanceFactor << endl;

            if(balanceFactor == -2){
                cout << "right heavy" << endl;
                //Check for right left rotation
                if(n->right->right == nullptr){
                    //rotation right left rotation
                    cout << "right left rotation" << endl;
                    n = n->rightLeftCase();
                    return n;
                }
                else{
                    //right right
                    cout << "right right" << endl;
                    n = n->rotateRightRightCase();
                    return n;
                }
            }
            else if(balanceFactor == 2){
                cout << "left heavy" << endl;
                if(n->left->left == nullptr){
                    // left right rotation
                    cout << "left-right rotation" << endl;
                    n = n->leftRightCase();
                    return n;
                }
                else{
                    //left left rotation
                    cout << "left-left rotation" << endl;
                    n = n->rotateLeftLeftCase();
                    return n;
                }
            }
        }
        return n;
    }

    int checkHeight(Node* n){
        if(n == nullptr){
            return 0;
        }
        else{
            return n->height;
        }
    }

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

        //if root is to be deleleted
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
            Node* succ = n->left;
            while (succ->right != nullptr) {
                succParent = succ;
                succ = succ->right;
            }

            if (succParent != n)
                succParent->right = succ->left;
            else
                succParent->left = succ->right;

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
//            cout << "not found" << endl;
            return false;
        }
//        cout << "found" << endl;
        return true;
    }
    string searchIdName(string id){
        Node* temp = root->searchIdNode(root,id);
        if(temp == nullptr){
            cout << "not found" << endl;
            return "";
        }
        cout << "found" << endl;
        return temp->studentName ;
    }

    void searchNames(Node* n,string name, vector<string> &names){
        vector<string> namesfound;
        if(n != nullptr) {
            if (n->studentName == name) {
                names.push_back(n->studentID);
            }
            searchNames(n->left, name, names);
            searchNames(n->right, name, names);
        }
    }

    void removeNthNode(int num){


    }


    int findLevel(Node* n){
        if (n == nullptr) {
            return 0;
        }
        else {
            int leftDepth = findLevel(n->left);
            int rightDepth = findLevel(n->right);

            return max(leftDepth,rightDepth);
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

};



