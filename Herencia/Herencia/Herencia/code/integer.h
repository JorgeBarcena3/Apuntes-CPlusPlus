#pragma once
#include "Object.h"

/** Clase que almacena un entero
*/
class Integer : public Object
{

private:

    /** Valor del numero
    */
    int num;

public:

    /** Constructor por defecto
    */
    Integer();

    /** Constructor con un valor dado por el usuario
    */
    Integer(int _a);

    /** Reimplementacion de la funcion to_string de la clase Object
    */
    std::string to_string() const;

    /** Reimplementacion de la funcion less_than de la clase Object
    */
    bool less_than(const Object*);

    /** Devuelve el valor
    */
    int get() const;

    /** Cambia el valor 
    */
    void replace(int _a);

};

