#include "Array.h"
#include <iostream>
#include "integer.h"


Array::Array()
{
    count = 0;
    elements = new Object * ();
}

Array::Array(const Array& other)
{
    count = 0;
    elements = nullptr;
    *this = other;
}

void Array::sort()
{

    for (size_t i = 0; i < count; i++) {
        for (size_t j = i; j < count; j++) {

            Integer* value1 = dynamic_cast<Integer*>(*(elements + i));

            if (value1->less_than(*(elements + j))) {
                Object* aux = *(elements + i);
                *(elements + i) = *(elements + j);
                *(elements + j) = aux;
            }
        }
    }

}

void Array::push_back(Object* _a)
{

    //Es nuevo
    if (count == 0)
    {
        ++count;

        elements = new Object * [count];
        *(elements) = _a;
    }
    else
    {

        ++count;

        Object** new_elements = new Object * [count];

        std::copy(elements, (elements + (count - 1)), new_elements);

        *(new_elements + (count - 1)) = _a;

        delete[] elements;

        elements = new_elements;
    }

}

Object* Array::get(size_t index)
{
    return *(elements + count);
}

void Array::print()
{
    for (size_t i = 0; i < count; i++)
    {

        const Integer* value = dynamic_cast<const Integer*>(*(elements + i));
        std::cout << value->to_string() << " - ";

    }

    std::cout << std::endl;
}

Array& Array::operator=(const Array& a)
{

    if (&a != this) {

        count = 0;
        delete[] elements;

        for (size_t i = 0; i < a.count; i++)
        {
            const Integer* value = dynamic_cast<const Integer*>(*(elements + i));
            push_back(new Integer(value->get()));
        }

    }
    return *this;

}

void Array::clear()
{
    if (count > 0)
    {
        for (size_t i = 0; i < count; i++)
            delete[] elements[i];

        delete[] elements;

        count = 0;

    }


}
