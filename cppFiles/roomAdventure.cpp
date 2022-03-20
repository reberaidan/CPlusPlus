#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;


void createRooms();

class room{
    private:
        string name;
        vector <string> items;
        vector <string> exits;
        
    public:
        room(string n="Room"){
            name = n;
        }

        //setters
        void setName(string n){
            name = n;
        }

        //getters
        string getName(){
            return name;
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

        //item system for the rooms

        void addItem(string s){
            items.push_back(s);
        }

        void delItem(string s){
            items.erase(remove(items.begin(), items.end(), s), items.end());
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
vector<room> allRooms = {room1,room2,room3,room4,room5};

int main(){
    string input;
    string string_split = " ";
    createRooms();
    currentRoom.print();

    while(1){
        getline(cin, input);

        transform(input.begin(), input.end(), input.begin(),
            [](unsigned char c){ return tolower(c); });
        if(input=="exit"){
            break;
        }
        cout << "You're input is: " << input << endl;
    }
}

void createRooms(){
    room1.setName("Bedroom");
    room1.addItem("Bed");
    room1.addItem("Closet");
    room1.addItem("Key");
    room1.addExit(room2.getName());


    currentRoom = room1;
}

