#pragma once
#include "Object.h"

/** Clase de array de objetos
*/
class Array
{

public:

    /** Clase para iterar un array
    */
    class Iterator
    {
        /** Elemento al que apunta
         */
        Object** element;

    public:

        /** Constructor que determina el elemento al que apunta el iterador
        */
        Iterator(Object** _element) : element(_element) {}

        /** Puntero al elemento al que apunta
        */
        inline Object*& operator * ()
        {
            return *element;
        }

        /** Puntero constante al elemento al que apunta
        */
        inline const Object* const& operator * () const
        {
            return *element;
        }

        /** Puntero al elemento al que apunta
        */
        inline Object** operator -> ()
        {
            return element;
        }

        /** Puntero constante al elemento al que apunta
        */
        inline const Object* const* operator -> () const
        {
            return element;
        }

        /** Incremento del operador al que apunta
        */
        inline Iterator& operator ++ ()
        {
            return ++element, * this;
        }

        /** Decremento del operador al que apunta
        */
        inline Iterator& operator -- ()
        {
            return --element, * this;
        }

        /** Operador de posicionamiento aleatorio
        */
        inline Object *& operator [] (size_t index)
        {
            return element[index];
        }

        /** Operador constante de posicionamiento aleatorio
        */
        inline const Object * const & operator [] (size_t index) const
        {
            return element[index];
        }

        /** Operador de suma mas igualacion
        */
        inline Iterator & operator += (ptrdiff_t offset)
        {
            return element += offset, *this;
        }

        /**  Operador de resta menos igualacion
        */
        inline Iterator & operator -= (ptrdiff_t offset)
        {
            return element -= offset, *this;
        }

        /**  Operador comparacion entre iterators
        */
        inline bool operator == (const Iterator& other)
        {
            return element == other.element;
        }

        /**  Operador de distincion entre iterators
        */
        inline bool operator != (const Iterator& other)
        {
            return element != other.element;
        }


    };

private:

    /** Puntero a puntero a objeto
    */
    Object** elements;

    /** Cantidad de elementos que hay en el array
    */
    size_t count;

public:

    /** Devuelve el count del array
    */
    inline size_t get_count() { return count; }

    /** Constructor por defecto
    */
    Array();

    Array(const Array& other);

    /** Iterador al primer elemento
    */
    inline Iterator begin()
    {
        return Iterator(elements);
    }

    /** Iterador al ultimo elemento (No utilizable)
    */
    inline Iterator end()
    {
        return Iterator(elements + count);
    }

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
    void print() const;

    /** Sobrecarga del operacion =
    */
    Array& operator = (const Array& a);

    /** Sobrecarga del  operador []
    */
    const Object * const& operator [] (size_t index) const;

    /** Método que borra todos los elementos del array
    */
    void clear();


};

