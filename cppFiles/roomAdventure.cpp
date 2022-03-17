#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class room{
    private:
        string name;
        vector <string> items;
        
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

        vector<string> getList(){
            return items;
        }

        void addItem(string s){
            items.push_back(s);
        }

        void delItem(string s){
            items.erase(remove(items.begin(), items.end(), s), items.end());
        }

        string printlist(){
            string s;
            s += items.size();
            for(int i = 0; i < items.size(); i++){
                s += "We're working before";
                s += items[i] + ' ';
                s += "We're working after";
            }
            return s;
        }
        void print(){
            cout << getName() << "\n";
        }
};



int main(){
    room Bedroom("Bedroom");


    Bedroom.print();

    std::string name;
    std::cin >> name;

    Bedroom.setName(name);
    Bedroom.print();
}

