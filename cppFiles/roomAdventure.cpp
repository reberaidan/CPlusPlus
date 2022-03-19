#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


void createRooms();

class room{
    private:
        string name;
        vector <string> items;
        
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

int main(){
    createRooms();
    currentRoom.print();
}

void createRooms(){
    room1.addItem("Bed");
    room1.addItem("Closet");
    room1.addItem("Key");

    currentRoom = room1;
}

