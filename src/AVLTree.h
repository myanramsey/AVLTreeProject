#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <cmath>


using namespace std;

class AVLNode {
    public:
        string studentName;
        string studentID;
        int height;
        AVLNode *left;
        AVLNode *right;
    AVLNode() {
        this->studentName = "Default";
        this->studentID = "00000000";
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;

    }
    AVLNode(string studentName, string studentID) {
        this->studentName = studentName;
        this->studentID = studentID;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
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

    //TODO: Add height update function to the tree so we can update and figure out when we can rotate the tree

    AVLNode* insert(AVLNode* root, string name, string id){
        // check to see of name and id are correct
        //TODO: Figure out why is it checking the name twice.
        //TODO: Ask Zach about the command line and command stuff <3
//        cout << name << " " << id << endl;
        if(root == nullptr){
            return new AVLNode(name,id);
        }
        else if(stoi(id) < stoi(root->studentID)){
            root->left = insert(root->left,name,id);
        }
        else if(stoi(id) > stoi(root->studentID)){
            root->right = insert(root->right,name,id);
        }

        updateHeight();

        return root;
    }
    int updateHeight(){
        int leftHeight = 0;
        int rightHeight = 0;

        if(this->left != nullptr){
            leftHeight = left->updateHeight();
        }
        if(this->right != nullptr){
            rightHeight = right->updateHeight();
        }

        this->height = max(leftHeight,rightHeight);

        return 1 + max(leftHeight,rightHeight);
    }

    void printLevel(AVLNode* root){
        if(root == nullptr){
            cout <<"pls"<< endl;
            return;
        }

        queue<AVLNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int n = 0; n < size; n++){
                AVLNode * current = q.front();
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
    void printInOrder(AVLNode* root){
        if(root == nullptr){
            return;
        }
        printInOrder(root->left);
        cout << root->studentName << " ";
        printInOrder(root->right);
    }
    void printPreOrder(AVLNode* root){
        if(root == nullptr){
            return;
        }
        cout << root->studentName << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
    void printPostOrder(AVLNode* root){
        if(root == nullptr){
            return;
        }
        printPostOrder(root->left);
        printPostOrder(root->right);

        cout << root->studentName << " ";
    }
    void printHeightNode(AVLNode* root){
        if(root == nullptr){
            return;
        }
        printHeightNode(root->left);
        cout << root->studentName << "  : " << root->height << endl;
        printHeightNode(root->right);
    }

};



