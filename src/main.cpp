#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#include <vector>
#include <cmath>

#include "AVLTree.h"

using namespace std;

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

int main(){
	cout << "Hello AVL!\n";

    AVLTree* tree = new AVLTree();

    string numCommands;
    getline(cin, numCommands);
    int turns = stoi(numCommands);

    string userInput;

    while(turns > 0){
        getline(cin,userInput); //gets the user's next input
        auto pos = userInput.find(' ');

        string command = userInput.substr(0,pos);
//        cout << command << endl;
        if(command == "insert"){

            auto pos_string_start = userInput.find('\"') + 1;
            auto pos_string_end = userInput.substr(pos_string_start).find('\"');

            string name = userInput.substr(pos_string_start,pos_string_end);
//            cout << "name:" << name << endl;

            //check if valid name
            if(isValidName(name) == false){
                cout << "unsuccessful" << endl;
            }
            else{
               auto pos_start_id = userInput.find_last_of("\" ");
               string id = userInput.substr(pos_start_id + 1);
//               cout << "id:" << id << endl;

               if(!isValidID(id) || id.length() != 8 || tree->searchId(id)){
                   cout << "unsuccessful" << endl;
               }
               else{
                   tree->insert(name,id);
                   cout << "successful" << endl;
               }
            }
        }
        else if(command == "remove"){
            string id = userInput.substr(pos + 1);
            if(!isValidID(id) || id.length() != 8 || !tree->searchId(id)){
                cout << "unsuccessful" << endl;
            }
            else{
                tree->removeNode(tree->root,id);
                cout << "successful" << endl;
            }
        }
        else if(command == "search"){
            string searchItem = userInput.substr(pos + 1);
            cout << searchItem << endl;
            if(searchItem[0] != '\"'){ //checks to see if searching id
                if(tree->searchId(searchItem)){
                    cout << tree->searchIdName(searchItem) << endl;
                }
                else{
                    cout << "unsuccessful" << endl;
                }
            }
            else{
                searchItem.erase(remove(searchItem.begin(), searchItem.end(), '\"'), searchItem.end());
//                cout << searchItem << endl;
                vector<string> foundNames;
                tree->searchNames(tree->root,searchItem,foundNames);
                if(foundNames.size() > 1){
                    for(int i = 0; i < foundNames.size(); i++){
                        cout << foundNames[i] << endl;
                    }
                }
                else{
                    cout << foundNames[0] << endl;
                }
            }
        }
        else if(command == "printInorder"){
            vector<string> inOrder;
            tree->printInOrder(tree->root,inOrder);
            for(int i=0; i < inOrder.size(); i++){
                cout << inOrder[i];
                if (i != inOrder.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        else if(command == "printPreorder"){
            vector<string> preOrder;
            tree->printPreOrder(tree->root,preOrder);
            for(int i=0; i < preOrder.size(); i++){
                cout << preOrder[i];
                if (i != preOrder.size() - 1) {
                    cout << "successful" << endl;
                }
            }
            cout << endl;
        }
        else if(command == "printPostorder"){
            vector<string> postOrder;
            tree->printPostOrder(tree->root,postOrder);
            for(int i=0; i < postOrder.size(); i++){
                cout << postOrder[i];
                if (i != postOrder.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
        else if(command == "printLevelCount"){
            cout << tree->findLevel(tree->root) << endl;
        }
        else if(command == "removeInorder"){
            string removeItem = userInput.substr(pos + 1);
            vector<string> inOrder;
            tree->removeNthNode(tree->root,inOrder);

            if(stoi(removeItem) > inOrder.size()){
                cout << "unsuccessful" << endl;
            }
            else{
                string nodeToRemove = inOrder[stoi(removeItem)];
                tree->removeNode(tree->root,nodeToRemove);
                cout << "successful" << endl;
            }
        }
        else{
            cout << "unsuccessful" << endl;
        }
        turns--;
    }


	return 0;
}
