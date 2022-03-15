#include <iostream>

int main(){

    std::cout << "Enter you current age.\n";

    int age;
    std::cin >> age;
    int older;
    older = age + 30;

    std::cout << "You current age is " << age << "\n";
    std::cout << "In 30 years, you will be " << older << "\n";
    
}