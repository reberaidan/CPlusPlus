#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <map>
using namespace std;


void createRooms();
vector<string> split(string str, char delim);

enum class Direction
{
  East, South, West, North, Up, Down
};
class room{
    private:
        string name;
        vector <string> items;
        map<Direction, room> exits;
        map<Direction, room>::iterator it;
        
    public:
    
        room(string n){
            name = n;
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

        void addExit(Direction dir,room r){
            exits.insert(pair<Direction,room>(dir,r));
        }

        void delExit(Direction dir){
            exits.erase(dir);
        }

        room& getExit(Direction dir){
            
            it = exits.find(dir);
            if(it==exits.end()){
                cout << "There is no room that way" << endl;
                return *this;
            }
            else{
                cout << "Changing rooms" << endl;
                return exits.at(dir);
            }
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

room room1("bedroom");
room room2("kitchen");
room room3("hallway");
room room4("garage");
room room5("study");
room allRooms[5]= {room1,room2,room3,room4,room5};

string dir[6] = {"east","south","west","north","up","down"};

room& currentRoom = room1;
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
        
        if(split_input.front()=="go"){
            if(split_input.size()==1){
                cout << "Please input a direction. Example: go east" << endl;
            }
            else{
                for(int i =0; i < sizeof(dir); i++){
                    if(split_input[1]==dir[i]){
                        cout << dir[i] << endl;
                        currentRoom = currentRoom.getExit(Direction(i));
                        currentRoom.print();
                        break;
                    }
                    else if(i==sizeof(dir)-1){
                        cout << "This direction does not exist." << endl;
                    }
                    
                }
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

    room2.addItem("Bottles");

    room3.addItem("Rug");

    room2.setName("kitchen");
    
    room1.addExit(Direction(0), room3);

    room3.addExit(Direction(2), room1);

    


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

