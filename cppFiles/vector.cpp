#include <iostream>
#include <vector>
#include <list>
 
int main()
{
    std::list<char> list = { 'a', 'b', 'c' };
 
    std::vector<char> result;
    for (char const &c: list) {
        result.push_back(c);
    }
 
    for (char const &c: result) {
        std::cout << c << ' ';
    }
 
    return 0;
}