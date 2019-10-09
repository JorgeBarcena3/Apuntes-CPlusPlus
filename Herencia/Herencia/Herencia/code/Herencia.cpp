#include <iostream>
#include "integer.h"
#include "Array.h"

int main()
{

    Array* a = new Array();

    a->push_back(new Integer(1)); 
    a->push_back(new Integer(2));
    a->push_back(new Integer(1));
    a->push_back(new Integer(5));
    a->push_back(new Integer(9));
    a->push_back(new Integer(0));

    a->sort();

    a->print();

    Array b = *a;

    b.print();

    delete a;
    
}
