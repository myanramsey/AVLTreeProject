#include <iostream>

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
    vector<string> inOrder;
    vector<string> preOrder;
    vector<string> postOrder;

	cout << "Hello AVL!\n";

//    AVLTree* tree = new AVLTree();

    string numCommands;
    getline(cin, numCommands);
    int turns = stoi(numCommands);

    string userInput;

    while(turns > 0){
        getline(cin,userInput); //gets the user's next input
        auto pos = userInput.find(' ');

        string command = userInput.substr(0,pos);
        cout << command << endl;
        if(command == "insert"){

            auto pos_string_start = userInput.find('\"') + 1;
            auto pos_string_end = userInput.substr(pos_string_start).find('\"');

            auto name = userInput.substr(pos_string_start,pos_string_end);

            //check if valid name
            if(isValidName(name) == false){
                cout << "unsuccessful" << endl;
            }
            else{
                insert()
            }

        }

    }


	return 0;
}
