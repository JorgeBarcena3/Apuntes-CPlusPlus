#pragma once
#include <iostream>
#include <string> 

/** Clase de la que heredan todos los objetos
*/
class Object
{

public:

    /** Devuelve el valor del objeto como un std::string
    */
    virtual std::string to_string() const { return "Object"; }

    /** Obtiene el nombre de la clase
    */
    virtual const char* get_class_name() const { return "Object"; }

    /** Determina si un objeto es menor a otro
    */
    virtual bool less_than(const Object*) { return false; }

};

