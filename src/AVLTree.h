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

    };
    public:
    Node* root;
    Node* unbalancedNode;
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

    Node* insert(string name, string id){
        if(root == nullptr){
            root = new Node(name,id);
            return root;
        }

        root->insertNode(name,id);

        updateHeight(root, root->studentID);
        findUnbalanced(root);

        //find unbalanced node
        if(unbalancedNode != nullptr){
            rotation(unbalancedNode);
        }

        return root;
    }

    void findUnbalanced(Node* n){
        if(n == nullptr)
            return;

        int balanceFactor = checkHeight(n->left) - checkHeight(n->right);

        if(balanceFactor < -1 || balanceFactor > 1){
                cout << n->studentName << " is unbalanced. BF: " << balanceFactor << endl;
                unbalancedNode = n;
        }
        findUnbalanced(n->right);
        findUnbalanced(n->left);
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

    void rotation(Node* n){
        int balanceFactor = checkHeight(unbalancedNode->left) - checkHeight(unbalancedNode->right);
        if(balanceFactor == -2){
            cout << "right heavy" << endl;
            //Check for right left rotation
            if(unbalancedNode->right->right == nullptr){
                //rotation right left rotation

            }
            else{
                //right right rotation
            }
        }
        else if(balanceFactor == 2){
            cout << "left heavy" << endl;
            if(unbalancedNode->left->left == nullptr){
                // left right rotation
            }
            else{
                //left left rotation
            }
        }

        unbalancedNode = nullptr;
    }

    void printLevel(){
        if(root == nullptr){
            cout <<"pls"<< endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int n = 0; n < size; n++){
                Node * current = q.front();
                q.pop();

                cout << current->studentName << " ";

                if(current->left != nullptr){
                    q.push(current->left);
                }
                if(current->right != nullptr){
                    q.push(current->right);
                }
            }
            cout << endl;
        }
    }
    void printInOrder(Node* n){
        if(n == nullptr){
            return;
        }
        printInOrder(n->left);
        cout << n->studentName << " ";
        printInOrder(n->right);
    }

    void printPreOrder(Node* n){
        if(n == nullptr){
            return;
        }
        cout << n->studentName << " ";
        printPreOrder(n->left);
        printPreOrder(n->right);
    }
    void printPostOrder(Node* n){
        if(n == nullptr){
            return;
        }
        printPostOrder(n->left);
        printPostOrder(n->right);

        cout << n->studentName << " ";
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



