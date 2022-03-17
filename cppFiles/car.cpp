#include <iostream>
#include <stdio.h>
using namespace std;

class vehicle {
    private:
        int wheels = 4;
        string brand;
        string model;
        int year;
        string type;
    public:
        
        vehicle(string x, string y, int z){
            brand = x;
            model = y;
            year = z;
        }
        
        //setters
        void setBrand(string b){
            brand = b;
        }
        void setModel(string m){
            model = m;
        }
        void setYear(int y){
            year = y;
        }

        //getters
        string getBrand(){
            return brand;
        }
        string getModel(){
            return model;
        }
        int getYear(){
            return year;
        }
        void print(){
            cout << "Make: " << getBrand() << "\nModel: " << getModel() << "\nYear: " << getYear();
        }

};

class car: public vehicle {
    private:
        string type;
    public:
        car(string x, string y, int z) :
            vehicle(x,y,z){
                type = "Car";
            }
        
        string getType(){
            return type;
        }
    
        void print(){
            cout << "Type: " << type << "\nMake: " << getBrand() << "\nModel: " << getModel() << "\nYear: " << getYear() << "\n";
            
        }
};

class truck: public vehicle {
    private: 
        string type;

    public:
        truck(string x, string y, int z) :
            vehicle(x,y,z){
                type = "truck";
            }
        void print(){
            cout << "Type: " << type << "\nMake: " << getBrand() << "\nModel: " << getModel() << "\nYear: " << getYear() << "\n";
            
        }
};

int main(){
    car car1("Toyota","Nissan",2011);

    car1.print();
     
    car car2 = car1;
    
    car2.setModel("Rogue");

    car2.print();
}