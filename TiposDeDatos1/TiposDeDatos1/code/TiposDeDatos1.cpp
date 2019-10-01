#include <iostream>
#include "Array.hpp"

using namespace std;

int main()
{

    Array<int> b;

    b.push_back(1001);
    b.push_back(1002);
    b.push_back(1003);
    b.push_back(1005);
    b.print();
    
    b.erase(0);
    b.print(); 
    
    b.pop_back();
    b.print();  
    
    b.insert(1111, 0);
    b.print();

    b.clear();
    b.print();


}
