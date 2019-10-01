#pragma once

//Clase que permita modificar si tamaño
template <class T>
class Array {

private:

    size_t size;

public:

    T* primerElemento;

public:

    Array();

    Array(size_t _size);

    Array(const Array& other);

    ~Array();

public:

    /**Retorna el numero de elementos que guarda el array
    */
    size_t get_size() const;

    /**Retorna el puntero al ultimo elemento
    */
    T* get_primer_elemento() const;

    /** Añade un entero al final del array
    */
    void push_back(T item);

    /** Quita un entero al final del array
    */
    void pop_back();

    /** Inserta un entero en la posicion index
    */
    void insert(T item, size_t index);

    /** Quita un entero en la posicion index
    */
    void erase(size_t index);

    /** Elimina todos los elementos del array
    */
    void clear();

    /** Pinta la totalidad del array
    */
    void print();

};

template<class T>
inline Array<T>::Array()

{

    //Establecemos el tamaño y el buffer
    size = 0;
    primerElemento = new T;

};

template<class T>
inline Array<T>::Array(size_t _size)
{

    //Establecemos el tamaño y el buffer
    size = _size;
    primerElemento = new T[size];


};

template<class T>
inline Array<T>::Array(const Array& other)
{

    //Establecemos el tamaño y el buffer
    size = other.get_size();
    primerElemento = new T[size];


};

template<class T>
inline Array<T>::~Array()
{
    if (size > 0)
        delete[] primerElemento;
};

template<class T>
inline size_t Array<T>::get_size() const
{
    return size;
};

template<class T>
inline T* Array<T>::get_primer_elemento() const
{
    return primerElemento;
};

template<class T>
inline void Array<T>::push_back(T item)
{

    //1. - Añadimos un new con un buffer del size + 1
    size++;
    T* nuevo_puntero = new T[size];

    //2.- Copiar los valores
    T* ptr1 = primerElemento;
    T* ptr2 = nuevo_puntero;

    for (size_t i = 0; i < size - 1; i++)
    {
        *ptr2 = *ptr1;
        ptr1++; ptr2++;
    }

    *ptr2 = item;

    //3.- Borrar el puntero anterior con delete
    delete primerElemento;

    //4.- Reapuntar el puntero
    primerElemento = nuevo_puntero;

};

template<class T>
inline void Array<T>::pop_back()
{

    if (size > 0) {
        //1. - Añadimos un new con un buffer del size + 1
        size--;
        T* nuevo_puntero = new T[size];

        //2.- Copiar los valores
        T* ptr1 = primerElemento;
        T* ptr2 = nuevo_puntero;

        for (size_t i = 0; i < size; i++)
        {
            *ptr2 = *ptr1;
            ptr1++; ptr2++;
        }

        //3.- Borrar el puntero anterior con delete
        delete primerElemento;

        //4.- Reapuntar el puntero
        primerElemento = nuevo_puntero;
    }

};

template<class T>
inline void Array<T>::insert(T item, size_t index)
{

    //1. - Añadimos un new con un buffer del size + 1
    size++;
    T* nuevo_puntero = new T[size];

    if (index >= size)
        std::cout << ("No se puede insertar un valor, mas grande que el tamaño del array");

    //2.- Copiar los valores
    T* ptr1 = primerElemento;
    T* ptr2 = nuevo_puntero;

    for (size_t i = 0; i < size; i++)
    {
        if (i == index) {
            *ptr2 = item;
            ptr2++;
        }
        else
        {
            *ptr2 = *ptr1;
            ptr1++; ptr2++;

        }
    }

    //3.- Borrar el puntero anterior con delete
    delete primerElemento;

    //4.- Reapuntar el puntero
    primerElemento = nuevo_puntero;

};

template<class T>
inline void Array<T>::erase(size_t index)
{
    //1. - Añadimos un new con un buffer del size + 1
    size--;
    T* nuevo_puntero = new T[size];

    if (index >= size)
        std::cout << ("No se puede eliminar un valor mas grande que el tamaño del array");

    //2.- Copiar los valores
    T* ptr1 = primerElemento;
    T* ptr2 = nuevo_puntero;

    for (size_t i = 0; i < size + 1; i++)
    {
        if (i == index) {
            ptr1++;
        }
        else
        {
            *ptr2 = *ptr1;
            ptr1++; ptr2++;

        }
    }

    //3.- Borrar el puntero anterior con delete
    delete primerElemento;

    //4.- Reapuntar el puntero
    primerElemento = nuevo_puntero;

};

template<class T>
inline void Array<T>::clear()
{

    size = 0;
    delete primerElemento;
    primerElemento = new T;

};

template<class T>
inline void Array<T>::print()
{

    if (size > 0) {

        for (T* i = primerElemento; i != primerElemento + size; i++)
        {
            std::cout << *i << " ";
        }

        std::cout << std::endl;
    }
    else
    {
        std::cout << "No hay ningun valor en el array" << std::endl;
    }
};


