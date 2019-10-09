#include <iostream>
#include "integer.h"
#include "Array.h"

int main()
{

    Array a;

    a.push_back(new Integer(1)); 
    a.push_back(new Integer(2));
    a.push_back(new Integer(1));
    a.push_back(new Integer(5));
    a.push_back(new Integer(9));
    a.push_back(new Integer(0));

    for (Array::Iterator i = a.begin(); i != a.end(); ++i)
    {
        std::cout << (*i)->to_string() << std::endl;
    }

    
}
