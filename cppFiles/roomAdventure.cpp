#include <iostream>
#include <string>
#include <cstring>
#include <list>
using namespace std;

class room{
    private:
        string name;
        list<string> items;
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
            return name;
        }

        list<string> getList(){
            return items;
        }

        void addItem(string s){
            items.push_front(s);
        }

        void delItem(string s){
            items.remove(s);
        }

        void printlist(){
            for (auto it = items.cbegin(); it != items.cend(); it++) {
                cout << *it << endl;
    }
        }
        void print(){
            cout << getName() << "\n";
        }
};



int main(){
    room room1("Hallway");

    room1.addItem("Headphones");
    room1.addItem("Keys");
    room1.addItem("Cups");

    cout << room1.printlist();
    
   

}

