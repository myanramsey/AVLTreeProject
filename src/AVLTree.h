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
       for(int i =0; i < name.size(); i++){
           if(isdigit(name[i]) || ispunct(name[i])){
               return false;
           }
       }
       return true;
   }
    AVLNode* insert(AVLNode* root, string name, string id){
        // check to see of name and id are correct

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
