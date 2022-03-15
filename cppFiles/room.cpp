#include <iostream>
#include <string>
#include <cstring>

class room{
    private:
        std::string name;
        int roomnum;
    public:

        // setters
        void setNum(int n){
            roomnum = n;
        }

        void setName(std::string n){
            name = n;
        }

        //getters
        std::string getName(){
            return name;
        }

        int getNum(){
            return roomnum;
        }

        void print(){
            std::cout << getNum() << " " << getName() << "\n";
        }
};
int main(){
    room Bedroom;

    Bedroom.setName("Bedroom");
    Bedroom.setNum(10);

    Bedroom.print();

    std::string name;
    std::cin >> name;

    Bedroom.setName(name);
    Bedroom.print();
}