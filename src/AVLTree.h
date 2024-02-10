#include <iostream>
#include <string>
#include <queue>
#include <cctype>
#include <iomanip>

using namespace std;

class AVLNode {
public:
    string studentName;
    string studentID;
    int hieght;
    AVLNode *left;
    AVLNode *right;

    AVLNode() {
        this->studentName = "Default";
        this->studentID = "00000000";
        this->hieght = 0;
        this->left = nullptr;
        this->right = nullptr;

    }

    AVLNode(string studentName, string studentID) {
        this->studentName = studentName;
        this->studentID = studentID;
        this->hieght = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

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
        if(isValidName(name) && isValidID(id)){
            cout << name << " " << id << " is valid name and id" << endl;
            if(root == nullptr){
                return new AVLNode(name,id);
            }
            else if(id < root->studentID){
                root->left = insert(root->left,name,id);
            }
            else if(id > root->studentID){
                root->right = insert(root->right,name,id);
            }
            return root;
        }
        else{
            cout << name <<" " << id <<  " is not valid name or id" << endl;
            return root;
        }


    }

    void printAVLTree(AVLNode* root){
        if(root == nullptr){
            return;
        }

        queue<AVLNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int n = 0; n < size; n++){
                AVLNode * current = q.front();
                q.pop();

                cout << setw(4) << current->studentID << " ";

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
