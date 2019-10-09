#pragma once
#include "Object.h"

/** Clase de array de objetos
*/
class Array
{

private:

    /** Puntero a puntero a objeto 
    */
    Object** elements;

    /** Cantidad de elementos que hay en el array
    */
    size_t count;

public:

    /** Constructor por defecto
    */
    Array();

    Array(const Array& other);

    /* Ordenacion del array
    */
    void sort();

    /** Introduce un objeto al final del array
    */
    void push_back(Object*);

    /** Se obtiene el objeto en x indice
    */
    Object* get(size_t index);

    /** Pinta el array
    */
    void print();

    /** Sobrecarga del operacion =
    */
    Array & operator = (const Array& a);

    /** Método que borra todos los elementos del array
    */
    void clear();


};

