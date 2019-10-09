#include "integer.h"

Integer::Integer()
{
    num = 0;

}

Integer::Integer(int _a)
{
    num =_a;
}

std::string Integer::to_string() const
{
    return std::to_string(num);
}

bool Integer::less_than(const Object* obj)
{

    const Integer* value1 = dynamic_cast< const Integer*>(obj);

    return (num < value1->get());
}

int Integer::get() const
{
    return num;
}

void Integer::replace(int _a)
{
    num = _a;

}
