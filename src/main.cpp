#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include "AVLTree.h"

using namespace std;

int main(){
    AVLTree* tree = new AVLTree();

    string numCommands;
    getline(cin, numCommands);
    int turns = stoi(numCommands);

    string userInput;

    while(turns > 0){
        getline(cin,userInput); //gets the user's next input
        auto pos = userInput.find(' ');

        string command = userInput.substr(0,pos);
        if(command == "insert"){

            auto pos_string_start = userInput.find('\"') + 1;
            auto pos_string_end = userInput.substr(pos_string_start).find('\"');

            string name = userInput.substr(pos_string_start,pos_string_end);

            //check if valid name
            if(tree->isValidName(name) == false){
                cout << "unsuccessful" << endl;
            }
            else{
                auto pos_start_id = userInput.find_last_of("\" ");
                string id = userInput.substr(pos_start_id + 1);

                if(!tree->isValidID(id) || id.length() != 8 || tree->searchId(id)){
                    cout << "unsuccessful" << endl;
                }
                else{ //If valid and name in inserts into tree
                    tree->insert(name,id);
                    cout << "successful" << endl;
                }
            }
        }
        else if(command == "remove"){
            string id = userInput.substr(pos + 1);
            if(!tree->isValidID(id) || id.length() != 8 || !tree->searchId(id)){
                cout << "unsuccessful" << endl;
            }
            else{
                tree->removeNode(tree->root,id);
                cout << "successful" << endl;
            }
        }
        else if(command == "search"){
            string searchItem = userInput.substr(pos + 1);
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
                vector<string> foundNames;
                vector<string> foundId;

                tree->searchNames(tree->root,searchItem,foundNames);
                tree->searchNamesID(tree->root,searchItem,foundId);

                if(foundNames.size() == 0){
                    cout << "unsuccessful" << endl;
                }
                else {
                    if(foundNames.size() > 1){ //If more than one of the same name
                        for (int i = 0; i < foundNames.size(); i++){
                            cout << foundNames[i] << endl;
                        }
                    }
                    else{
                        cout << foundNames[0] << endl;
                    }

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
                    cout << ", ";
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
            tree->removeNthNode(tree->root,inOrder);//Get ID that is inorder, since there can be multiple of same name

            if(stoi(removeItem) > inOrder.size()){ //If the nth index DNE
                cout << "unsuccessful" << endl;
            }
            else{
                string nodeToRemove = inOrder[stoi(removeItem)];
                if(tree->searchId(nodeToRemove)){
                    tree->removeNode(tree->root,nodeToRemove);
                    cout << "successful" << endl;
                }
               else{
                   cout << "unsuccessful" << endl;
               }
            }
        }
        else{
            cout << "unsuccessful" << endl;
        }
        turns--;
    }
    return 0;
}
