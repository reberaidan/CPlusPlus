#include <iostream>
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

};

class car: public vehicle {
    
};

class truck: public vehicle {

};