#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;


void createRooms();
vector<string> split(string str, char delim);

class room{
    protected:
        string name;
        vector <string> items;
        vector <string> exits;
        
    public:
        room(){
            
        }

        //setters
        void setName(string n){
            name = n;
        }

        //getters
        string getName(){
            return this->name;
        }

        vector<string> getList(){
            return items;
        }

        void addExit(string r){
            exits.push_back(r);
        }

        void delExit(string r){
            exits.erase(remove(exits.begin(), exits.end(), r), exits.end());
        }

        bool exitExists(string s){
            exits.begin();
            for (unsigned i=0; i<exits.size();i++){
                if(exits.at(i)==s){
                    return true;
                }
            }
            return false;
        }

        //item system for the rooms

        void addItem(string s){
            items.push_back(s);
        }

        void delItem(string s){
            items.erase(remove(items.begin(), items.end(), s), items.end());
        }

        bool itemExists(string s){
            items.begin();
            for (unsigned i=0; i<items.size();i++){
                if(items.at(i)==s){
                    return true;
                }
            }
            return false;
        }

        void printlist(){
            cout << "The room contains: " << items.size() << " item(s):\n";
            for(int i = 0; i < items.size(); i++){
                cout << items[i] << ' ';
            }
            cout << "\n";
        }
        void print(){
            cout << "You are in: " << getName() << "\n";
            printlist();
        }
};



room currentRoom;
room room1;
room room2;
room room3;
room room4;
room room5;
room allRooms[5]= {room1,room2,room3,room4,room5};

int main(){
    string input;
    createRooms();
    currentRoom.print();

    vector<string> split_input;
    

    while(1){
        getline(cin, input);

        transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c){ return tolower(c); });
        
        split_input = split(input, ' ');

        if(split_input.front()=="exit"){
            break;
        }
        cout << "room 2 name: " << room2.getName() << endl;
        
        if(split_input.front()=="go"){
            if(split_input.size()==1){
                cout << "Please input a location" << endl;
            }
            else if(currentRoom.exitExists(split_input.at(1))){
                for (auto &i : allRooms){
                    i.print();
                    if(split_input.at(1)==i.getName()){
                        currentRoom = i;
                        cout << "Room Changed" << endl;
                        currentRoom.print();
                    }
                }
            }
            else{
                cout << "Room does not exist" << endl;
            }
            
        }
        else if(split_input.front()=="look"){
            cout << split_input.front() << endl;
        }
        else if(split_input.front()=="grab"){
            cout << split_input.front() << endl;
        }
        else{
            cout << "Please type a proper input. " << endl;
        }
    }
}

void createRooms(){
    room1.setName("bedroom");
    room1.addItem("Bed");
    room1.addItem("Closet");
    room1.addItem("Key");

    room2.setName("kitchen");
    room1.addExit(room2.getName());


    currentRoom = room1;
}

vector<string> split(string str, char delimiter) { 
  vector<string> internal; 
  stringstream ss(str); // Turn the string into a stream. 
  string tok; 
 
  while(getline(ss, tok, delimiter)) { 
    internal.push_back(tok); 
  } 
 
  return internal; 
} 

