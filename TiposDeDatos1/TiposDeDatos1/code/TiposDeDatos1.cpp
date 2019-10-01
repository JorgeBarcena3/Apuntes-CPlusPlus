#include <iostream>
#include "Array.hpp"
#include "List.hpp"

using namespace std;

int main()
{

    cout << "--- Array ---" << endl << endl;

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


    cout << endl << endl << "--- LISTA ENLAZADAS ---" << endl << endl;

    List<int> c;

    c.push_front(4);
    c.push_front(5);
    c.push_front(6);
    c.push_front(7);
    c.push_front(8);
    c.pop_front();

    c.print();

    c.push_back(0);
    c.push_back(1);
    c.pop_back();

    c.print();

    c.insert(c.first, 99);
    c.print();

    c.erase(c.first);
    c.print();


}
